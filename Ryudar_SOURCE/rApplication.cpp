#include "rApplication.h"
#include "CInputManager.h"
#include "CTimeManager.h"
#include "CSceneManager.h"

namespace Ryu
{
	Application::Application()
		: m_Hwnd(nullptr)
		, m_Hdc(nullptr)
		, m_Width(0)
		, m_Height(0)
		, m_BackHdc(nullptr)
		, m_BackBuffer(nullptr)
	{
	}

	Application::~Application()
	{
	}

	void Application::Initialize(HWND _hwnd, UINT _width, UINT _height)
	{
		/*핸들 초기화*/
		m_Hwnd = _hwnd;
		m_Hdc = GetDC(m_Hwnd);

		/*화면 초기화*/
		Adjust_WindowRect(_hwnd, _width, _height);

		/*비트맵생성*/
		Create_Buffer(_width, _height);

		/*컴포넌트 초기화*/
		CInputManager::Initialize();
		CTimeManager::Initialize();

		/*씬 생성 초기화*/
		CSceneManager::Initialize();

	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{
		CTimeManager::Update();
		CInputManager::Update();
		
		/*씬 업데이트*/
		CSceneManager::Update();
	}

	void Application::LateUpdate()
	{
		/*씬 업데이트*/
		CSceneManager::LateUpdate();
	}

	void Application::Render()
	{
		Clear_RenderTarget();

		/*시간 & 프레임 표시*/
		CTimeManager::Render(m_BackHdc);

		/*씬 렌더링*/
		CSceneManager::Render(m_BackHdc);

		/*화면에 출력시킬 원본DC에 복사*/
		Copy_RenderTarget(m_Hdc, m_BackHdc);
	}

	void Application::Clear_RenderTarget()
	{
		Rectangle(m_BackHdc, -1, -1, 1601, 901);
	}

	void Application::Copy_RenderTarget(HDC _dest, HDC _source)
	{
		/*화면에 출력시킬 원본DC에 복사*/
		BitBlt(
			_dest,
			0, 0,
			m_Width,
			m_Height,
			_source,
			0, 0,
			SRCCOPY);
	}

	void Application::Adjust_WindowRect(HWND _hwnd, UINT _width, UINT _height)
	{
		RECT rect{ 0, 0, _width , _height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		m_Width = rect.right - rect.left;
		m_Height = rect.bottom - rect.top;

		SetWindowPos(
			m_Hwnd,
			nullptr,
			0, 0,
			m_Width, m_Height,
			0);
		ShowWindow(m_Hwnd, true);
	}

	void Application::Create_Buffer(UINT _widht, UINT _height)
	{
		//윈도우 해상도에 맞는 백버퍼 생성
		m_BackBuffer = CreateCompatibleBitmap(
			m_Hdc,
			_widht,
			_height);

		// 백버퍼를 가지고 있을 백DC를 생성
		m_BackHdc = CreateCompatibleDC(m_Hdc);

		//백DC에 백버퍼를 연결
		HBITMAP oldBMP = (HBITMAP)SelectObject(m_BackHdc, m_BackBuffer);
		DeleteObject(oldBMP);
	}

	void Application::Initialize_Etc()
	{
	}
}
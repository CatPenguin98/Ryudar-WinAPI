#include "rApplication.h"
#include "CInputManager.h"
#include "CTimeManager.h"

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
		m_Width = _width;
		m_Height = _height;
		RECT rect{0, 0, m_Width , m_Height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);
		SetWindowPos(
			m_Hwnd,
			nullptr,
			0, 0,
			rect.right - rect.left,
			rect.bottom - rect.top,
			0);
		ShowWindow(m_Hwnd, true);

		/*비트맵생성*/
		//윈도우 해상도에 맞는 백버퍼 생성
		m_BackBuffer = CreateCompatibleBitmap(
			m_Hdc,
			m_Width,
			m_Height);
		// 백버퍼를 가지고 있을 백DC를 생성
		m_BackHdc = CreateCompatibleDC(m_Hdc);
		//백DC에 백버퍼를 연결
		HBITMAP oldBMP = (HBITMAP)SelectObject(m_BackHdc, m_BackBuffer);
		DeleteObject(oldBMP);

		/*컴포넌트 초기화*/
		CInputManager::Initialize();
		CTimeManager::Initialize();

		/*오브젝트 초기화*/
		m_Player.Initialize();
		m_Player.Set_Position(0.f, 0.f);
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
		m_Player.Update();
	}

	void Application::LateUpdate()
	{
	}

	void Application::Render()
	{
		Rectangle(m_BackHdc, 0, 0, 1600, 900);

		/*시간 & 프레임 표시*/
		CTimeManager::Render(m_BackHdc);

		m_Player.Render(m_BackHdc);

		/*화면에 출력시킬 원본DC에 복사*/
		BitBlt(
			m_Hdc,
			0, 0,
			m_Width,
			m_Height,
			m_BackHdc,
			0, 0,
			SRCCOPY);
	}
}
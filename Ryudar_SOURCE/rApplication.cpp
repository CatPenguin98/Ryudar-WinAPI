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
		/*�ڵ� �ʱ�ȭ*/
		m_Hwnd = _hwnd;
		m_Hdc = GetDC(m_Hwnd);

		/*ȭ�� �ʱ�ȭ*/
		Adjust_WindowRect(_hwnd, _width, _height);

		/*��Ʈ�ʻ���*/
		Create_Buffer(_width, _height);

		/*������Ʈ �ʱ�ȭ*/
		CInputManager::Initialize();
		CTimeManager::Initialize();

		/*�� ���� �ʱ�ȭ*/
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
		
		/*�� ������Ʈ*/
		CSceneManager::Update();
	}

	void Application::LateUpdate()
	{
		/*�� ������Ʈ*/
		CSceneManager::LateUpdate();
	}

	void Application::Render()
	{
		Clear_RenderTarget();

		/*�ð� & ������ ǥ��*/
		CTimeManager::Render(m_BackHdc);

		/*�� ������*/
		CSceneManager::Render(m_BackHdc);

		/*ȭ�鿡 ��½�ų ����DC�� ����*/
		Copy_RenderTarget(m_Hdc, m_BackHdc);
	}

	void Application::Clear_RenderTarget()
	{
		Rectangle(m_BackHdc, -1, -1, 1601, 901);
	}

	void Application::Copy_RenderTarget(HDC _dest, HDC _source)
	{
		/*ȭ�鿡 ��½�ų ����DC�� ����*/
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
		//������ �ػ󵵿� �´� ����� ����
		m_BackBuffer = CreateCompatibleBitmap(
			m_Hdc,
			_widht,
			_height);

		// ����۸� ������ ���� ��DC�� ����
		m_BackHdc = CreateCompatibleDC(m_Hdc);

		//��DC�� ����۸� ����
		HBITMAP oldBMP = (HBITMAP)SelectObject(m_BackHdc, m_BackBuffer);
		DeleteObject(oldBMP);
	}

	void Application::Initialize_Etc()
	{
	}
}
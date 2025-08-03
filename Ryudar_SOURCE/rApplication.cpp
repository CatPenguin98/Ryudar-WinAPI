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
		/*�ڵ� �ʱ�ȭ*/
		m_Hwnd = _hwnd;
		m_Hdc = GetDC(m_Hwnd);

		/*ȭ�� �ʱ�ȭ*/
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

		/*��Ʈ�ʻ���*/
		//������ �ػ󵵿� �´� ����� ����
		m_BackBuffer = CreateCompatibleBitmap(
			m_Hdc,
			m_Width,
			m_Height);
		// ����۸� ������ ���� ��DC�� ����
		m_BackHdc = CreateCompatibleDC(m_Hdc);
		//��DC�� ����۸� ����
		HBITMAP oldBMP = (HBITMAP)SelectObject(m_BackHdc, m_BackBuffer);
		DeleteObject(oldBMP);

		/*������Ʈ �ʱ�ȭ*/
		CInputManager::Initialize();
		CTimeManager::Initialize();

		/*������Ʈ �ʱ�ȭ*/
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

		/*�ð� & ������ ǥ��*/
		CTimeManager::Render(m_BackHdc);

		m_Player.Render(m_BackHdc);

		/*ȭ�鿡 ��½�ų ����DC�� ����*/
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
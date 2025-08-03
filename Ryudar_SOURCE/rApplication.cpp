#include "rApplication.h"

namespace Ryu
{
	Application::Application()
		: m_Hwnd(nullptr)
		, m_Hdc(nullptr)
	{
	}
	Application::~Application()
	{
	}
	void Application::Initialize(HWND _hwnd)
	{
		m_Hwnd = _hwnd;
		m_Hdc = GetDC(m_Hwnd);

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
		m_Player.Update();
	}
	void Application::LateUpdate()
	{
	}
	void Application::Render()
	{
		m_Player.Render(m_Hdc);
	}
}

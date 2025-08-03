#pragma once

#include "CommonInclude.h"
#include "CGameObject.h"

namespace Ryu{
	class Application
	{
	public:
		Application();
		~Application();

	public:
		void			Initialize(HWND _hwnd);
		void			Run();

		void			Update();
		void			LateUpdate();
		void			Render();

	private:
		HWND			m_Hwnd;
		HDC				m_Hdc;
		
		CGameObject		m_Player;
	};
}


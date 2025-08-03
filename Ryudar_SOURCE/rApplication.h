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
		void			Initialize(HWND _hwnd, UINT _width, UINT _height);
		void			Run();

		void			Update();
		void			LateUpdate();
		void			Render();

	private:
		HWND			m_Hwnd;
		HDC				m_Hdc;
		/*더블 버퍼링 꼼수(?)
		* 원래는 도화지(BITMAP)만 두장 준비하고
		* 한장 그리고 한장 출력하고 다시 교체하고의 반복이지만,
		* 이는 비효율적이므로,
		* 단순히 DC도 하나더 준비하고 Back_DC에서 그림을 그리고
		* 이를 원본_DC에 그대로 옮겨서 화면에 출력시킨다.
		* 출력 시키는 동안 Back_DC에서는 BITMAP에 그냥 덮어서 그림을 그리고
		* 다시 이를 원본_DC에 그대로 옮긴다.
		* 메모리적으로는 사용량이 증가하지만, 연산량은 감소한다.
		*/
		HDC				m_BackHdc;
		HBITMAP			m_BackBuffer;	// 그림그릴 도화지

		UINT			m_Width;
		UINT			m_Height;
		
		CGameObject		m_Player;
	};
}


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
		/*���� ���۸� �ļ�(?)
		* ������ ��ȭ��(BITMAP)�� ���� �غ��ϰ�
		* ���� �׸��� ���� ����ϰ� �ٽ� ��ü�ϰ��� �ݺ�������,
		* �̴� ��ȿ�����̹Ƿ�,
		* �ܼ��� DC�� �ϳ��� �غ��ϰ� Back_DC���� �׸��� �׸���
		* �̸� ����_DC�� �״�� �Űܼ� ȭ�鿡 ��½�Ų��.
		* ��� ��Ű�� ���� Back_DC������ BITMAP�� �׳� ��� �׸��� �׸���
		* �ٽ� �̸� ����_DC�� �״�� �ű��.
		* �޸������δ� ��뷮�� ����������, ���귮�� �����Ѵ�.
		*/
		HDC				m_BackHdc;
		HBITMAP			m_BackBuffer;	// �׸��׸� ��ȭ��

		UINT			m_Width;
		UINT			m_Height;
		
		CGameObject		m_Player;
	};
}


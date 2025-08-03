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
		void			Clear_RenderTarget();
		void			Copy_RenderTarget(HDC _dest, HDC _source);
		void			Adjust_WindowRect(HWND _hwnd, UINT _width, UINT _height);
		void			Create_Buffer(UINT _widht, UINT _height);
		void			Initialize_Etc();

	private:
		HWND						m_Hwnd;			// ����� DC
		HDC							m_Hdc;			// ����� ��ȭ��
		#pragma region ���� ���۸� �ļ�(?)
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
		#pragma endregion
		HDC							m_BackHdc;		// �׸��׸� DC
		HBITMAP						m_BackBuffer;	// �׸��׸� ��ȭ��

		UINT						m_Width;
		UINT						m_Height;
		
		
	};
}


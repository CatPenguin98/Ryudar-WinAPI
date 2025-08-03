#pragma once

#include "CommonInclude.h"

namespace Ryu
{
	/*����
	* static������ Ű�Է��� ���¿� ���� vector�� ����.
	* �̱��� ������ ������ �ص�. �ʿ伺��...����...?
	* 1. Initialize()ȣ���Ͽ� ��� Ű�� ���� �ʱ�ȭ.
	* 2. Upate()ȣ���� ���� Ű ���� ����
	* 3. ���� ����� �÷��̾�� Get___()�Լ��� ���.
	* ***����****
	* �Է��� �ް� �÷��̾ ���Ž������ �ϱ⶧����,
	* �÷��̾�Update�Լ� ȣ��������, Update�� ȣ����Ѿ���.
	*/
	enum class ecKeyState { Down, Pressed, Up, None };

	enum class ecKeyCode
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M, 
		Left, Right, Down, UP,
		LMouse, RMouse,
		END
	};

	class CInputManager
	{
	public:
		struct Key
		{
			ecKeyCode ecKeyCode;
			ecKeyState ecState;
			bool bPressed;
		};

	public:
		/*�̱��� ����ؾߵǳ�?...*/
		static CInputManager*	Get_Instance()
		{
			if (m_pInstance == nullptr)
				m_pInstance = new CInputManager;
			return m_pInstance;
		}
		static void				Destroy_Instance()
		{
			if (m_pInstance)
				delete m_pInstance;
			m_pInstance = nullptr;
		}

	public:
		static void				Initialize();
		static void				Update();

	public:
		static bool				Get_KeyDown(ecKeyCode _keyCode)
		{
			return m_Keys[(UINT)_keyCode].ecState == ecKeyState::Down;
		}
		static bool				Get_KeyPressed(ecKeyCode _keyCode)
		{
			return m_Keys[(UINT)_keyCode].ecState == ecKeyState::Pressed;
		}
		static bool				Get_KeyUp(ecKeyCode _keyCode)
		{
			return m_Keys[(UINT)_keyCode].ecState == ecKeyState::Up;
		}

	private:
		static void				CreateKeys();
		static void				UpdateKeys();
		static void				UpdateKey(Key& _key);

	private:
		static bool				IsKeyDown(ecKeyCode _code);
		static void				UpdateKeyDown(Key& _key);
		static void				UpdateKeyUp(Key& _key);

	private:
		static std::vector<Key>		m_Keys;

		static CInputManager*		m_pInstance;

	};
}


#pragma once

#include "CommonInclude.h"

namespace Ryu
{
	/*사용법
	* static변수로 키입력의 상태에 대해 vector로 관리.
	* 싱글톤 관리는 구현만 해둠. 필요성은...굳이...?
	* 1. Initialize()호출하여 모든 키의 상태 초기화.
	* 2. Upate()호출을 통해 키 상태 갱신
	* 3. 실제 사용은 플레이어에서 Get___()함수로 사용.
	* ***주의****
	* 입력을 받고 플레이어를 갱신시켜줘야 하기때문에,
	* 플레이어Update함수 호출이전에, Update를 호출시켜야함.
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
		/*싱글톤 사용해야되나?...*/
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


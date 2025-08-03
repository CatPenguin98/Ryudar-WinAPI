#include "CInputManager.h"

namespace Ryu
{
	CInputManager* CInputManager::m_pInstance = nullptr;
	std::vector<CInputManager::Key> CInputManager::m_Keys = {};
	
	int ASCII[(UINT)ecKeyCode::END] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M'
	};

	void CInputManager::Initialize()
	{
		/*전체 키 상태 초기화*/
		m_Keys.reserve((size_t)ecKeyCode::END);

		for (size_t i = 0; i < (size_t)ecKeyCode::END; ++i)
		{
			Key key{};
			key.bPressed = false;
			key.ecState = ecKeyState::None;
			key.ecKeyCode = (ecKeyCode)i;

			m_Keys.push_back(key);
		}
	}
	void CInputManager::Update()
	{
		for (size_t i = 0; i < m_Keys.size(); ++i)
		{
			// 현재 눌린 상태에서, 
			if (GetAsyncKeyState(ASCII[i]) & 0x8000)
			{
				// 이전에도 눌렸었다면
				if (m_Keys[i].bPressed == true)
				{
					m_Keys[i].ecState = ecKeyState::Pressed;
				}
				else// 이전에는 안 눌렸었다면
				{
					m_Keys[i].ecState = ecKeyState::Down;
				} 
				m_Keys[i].bPressed = true;
			}
			else// 현재 안눌린 상태에서, 
			{
				// 이전에는 눌렸었다면
				if (m_Keys[i].bPressed == true)
				{
					m_Keys[i].ecState = ecKeyState::Up;
				}
				else// 이전에도 안 눌렸었다면
				{
					m_Keys[i].ecState = ecKeyState::None;
				}
				m_Keys[i].bPressed = false;
			}
		}
	}
}
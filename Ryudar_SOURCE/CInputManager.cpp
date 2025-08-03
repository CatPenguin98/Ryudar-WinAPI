#include "CInputManager.h"

namespace Ryu
{
	CInputManager* CInputManager::m_pInstance = nullptr;
	std::vector<CInputManager::Key> CInputManager::m_Keys = {};
	
	int ASCII[(UINT)ecKeyCode::END] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP,
		MK_LBUTTON, MK_RBUTTON
	};

	void CInputManager::Initialize()
	{
		/*��ü Ű ���� �ʱ�ȭ*/
		CreateKeys();
	}
	void CInputManager::Update()
	{
		UpdateKeys();

	#pragma region �Է·���(����)->UpdateKeys���ؾȵɶ�����
		//for (size_t i = 0; i < m_Keys.size(); ++i)
		//{
		//	// ���� ���� ���¿���, 
		//	if (GetAsyncKeyState(ASCII[i]) & 0x8000)
		//	{
		//		// �������� ���Ⱦ��ٸ�
		//		if (m_Keys[i].bPressed == true)
		//		{
		//			m_Keys[i].ecState = ecKeyState::Pressed;
		//		}
		//		else// �������� �� ���Ⱦ��ٸ�
		//		{
		//			m_Keys[i].ecState = ecKeyState::Down;
		//		}
		//		m_Keys[i].bPressed = true;
		//	}
		//	else// ���� �ȴ��� ���¿���, 
		//	{
		//		// �������� ���Ⱦ��ٸ�
		//		if (m_Keys[i].bPressed == true)
		//		{
		//			m_Keys[i].ecState = ecKeyState::Up;
		//		}
		//		else// �������� �� ���Ⱦ��ٸ�
		//		{
		//			m_Keys[i].ecState = ecKeyState::None;
		//		}
		//		m_Keys[i].bPressed = false;
		//	}
		//}
	#pragma endregion

	}

	void CInputManager::CreateKeys()
	{
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

	void CInputManager::UpdateKeys()
	{
		std::for_each(m_Keys.begin(), m_Keys.end(),
			[](Key& key) -> void
			{
				UpdateKey(key);
			});
	}

	void CInputManager::UpdateKey(Key& _key)
	{
		//���� �ش�Ű�� ������ ��,
		if (IsKeyDown(_key.ecKeyCode))
		{
			UpdateKeyDown(_key);
		}
		else//���� �ش�Ű�� �ȴ����� ��,
		{
			UpdateKeyUp(_key);
		}
	}

	bool CInputManager::IsKeyDown(ecKeyCode _code)
	{
		return GetAsyncKeyState(ASCII[(UINT)_code]) & 0x8000;
	}

	void CInputManager::UpdateKeyDown(Key& _key)
	{
		// �������� ���Ⱦ��ٸ�
		if (_key.bPressed == true)
		{
			_key.ecState = ecKeyState::Pressed;
		}
		else// �������� �� ���Ⱦ��ٸ�
		{
			_key.ecState = ecKeyState::Down;
		}
		_key.bPressed = true;
	}

	void CInputManager::UpdateKeyUp(Key& _key)
	{
		// �������� ���Ⱦ��ٸ�
		if (_key.bPressed == true)
		{
			_key.ecState = ecKeyState::Up;
		}
		else// �������� �� ���Ⱦ��ٸ�
		{
			_key.ecState = ecKeyState::None;
		}
		_key.bPressed = false;
	}
}
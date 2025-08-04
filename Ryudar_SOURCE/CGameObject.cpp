#include "CGameObject.h"
#include "CInputManager.h"
#include "CTimeManager.h"

namespace Ryu
{
	CGameObject::CGameObject()
	{
	}

	CGameObject::~CGameObject()
	{
		Release();
	}

	void CGameObject::Initialize()
	{
		for (CComponent* comp : m_Components)
		{
			comp->Initialize();
		}

	}

	void CGameObject::Update()
	{
		for (CComponent* comp : m_Components)
		{
			comp->Update();
		}
		//const float speed = 500.f;

		//if (CInputManager::Get_KeyPressed(ecKeyCode::A))
		//{
		//	m_X -= speed * CTimeManager::Get_DeltaTime();
		//}
		//if (CInputManager::Get_KeyPressed(ecKeyCode::D))
		//{
		//	m_X += speed * CTimeManager::Get_DeltaTime();
		//}
		//if (CInputManager::Get_KeyPressed(ecKeyCode::W))
		//{
		//	m_Y -= speed * CTimeManager::Get_DeltaTime();
		//}
		//if (CInputManager::Get_KeyPressed(ecKeyCode::S))
		//{
		//	m_Y += speed * CTimeManager::Get_DeltaTime();
		//}
	}

	void CGameObject::LateUpdate()
	{
		for (CComponent* comp : m_Components)
		{
			comp->LateUpdate();
		}
	}

	void CGameObject::Render(HDC _hdc)
	{
		for (CComponent* comp : m_Components)
		{
			comp->Render(_hdc);
		}
		//Rectangle(_hdc, m_X + 500, m_Y + 500, m_X + 600, m_Y + 600);
	}

	void CGameObject::Release()
	{
		for (CComponent* comp : m_Components)
		{
			delete comp;
			comp = nullptr;
		}

		m_Components.clear();
	}
}

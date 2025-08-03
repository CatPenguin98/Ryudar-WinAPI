#include "CGameObject.h"
#include "CInputManager.h"

namespace Ryu
{
	CGameObject::CGameObject()
		: m_X(0.f)
		, m_Y(0.f)
	{
	}

	CGameObject::~CGameObject()
	{
	}

	void CGameObject::Initialize()
	{

	}

	void CGameObject::Update()
	{
		if (CInputManager::Get_KeyPressed(ecKeyCode::A))
		{
			m_X -= 0.01f;
		}
		if (CInputManager::Get_KeyPressed(ecKeyCode::D))
		{
			m_X += 0.01f;
		}
		if (CInputManager::Get_KeyPressed(ecKeyCode::W))
		{
			m_Y -= 0.01f;
		}
		if (CInputManager::Get_KeyPressed(ecKeyCode::S))
		{
			m_Y += 0.01f;
		}
	}

	void CGameObject::LateUpdate()
	{
	}

	void CGameObject::Render(HDC _hdc)
	{
		Rectangle(_hdc, m_X + 500, m_Y + 500, m_X + 600, m_Y + 600);
	}
}

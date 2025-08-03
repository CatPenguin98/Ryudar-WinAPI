#include "CGameObject.h"

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
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			m_X -= 0.01f;
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			m_X += 0.01f;
		}
		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			m_Y -= 0.01f;
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
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

#include "CPlayer.h"
#include "CInputManager.h"
#include "CTimeManager.h"
#include "CTransform.h"

namespace Ryu
{
	CPlayer::CPlayer()
		: CGameObject()
	{
	}

	CPlayer::~CPlayer()
	{
	}

	void CPlayer::Initialize()
	{
		CGameObject::Initialize();
	}

	void CPlayer::Update()
	{
		CGameObject::Update();
	}

	void CPlayer::LateUpdate()
	{
		CGameObject::LateUpdate();

		if (CInputManager::Get_KeyPressed(ecKeyCode::Right))
		{
			CTransform* tr = GetComponent<CTransform>();
			Vector2 pos = tr->Get_Position();
			pos.x += 100.0f * CTimeManager::Get_DeltaTime();
			tr->Set_Position(pos);
			//Test
		}
	}
	
	void CPlayer::Render(HDC _hdc)
	{
		CGameObject::Render(_hdc);
	}
}
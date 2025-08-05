#include "CPlayer.h"

namespace Ryu
{
	CPlayer::CPlayer()
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
	}
	
	void CPlayer::Render(HDC _hdc)
	{
		CGameObject::Render(_hdc);
	}
}
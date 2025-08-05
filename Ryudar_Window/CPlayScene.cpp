#include "CPlayScene.h"
#include "CGameObject.h"
#include "CPlayer.h"
#include "CTransform.h"
#include "CSpriteRenderer.h"

namespace Ryu
{
	CPlayScene::CPlayScene()
		: CScene()
	{
	}
	CPlayScene::~CPlayScene()
	{
	}
	
	void CPlayScene::Initialize()
	{
		CPlayer* bg = new CPlayer();

		CTransform* tr = bg->AddComponent<CTransform>();
		tr->Set_Position(Vector2(0, 0));
		tr->Set_Name(L"TR");

		CSpriteRenderer* sr = bg->AddComponent<CSpriteRenderer>();
		sr->Set_Name(L"SR");
		sr->Image_Load(L"C:\\Users\\Jo_\\source\\repos\\Ryudar-WinAPI\\Ryudar_Window\\CloudOcean.png");
		CScene::Add_GameObject(bg);
	}
	
	void CPlayScene::Update()
	{
		CScene::Update();
	}
	
	void CPlayScene::LateUpdate()
	{
		CScene::LateUpdate();
	}
	void CPlayScene::Render(HDC _hdc)
	{
		CScene::Render(_hdc);
	}
}

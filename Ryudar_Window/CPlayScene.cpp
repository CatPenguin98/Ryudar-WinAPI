#include "CPlayScene.h"
#include "CGameObject.h"

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
		for(size_t i = 0; i < 2000; i++)
		{
			CGameObject* obj = new CGameObject();
			obj->Set_Position(rand() % 1600, rand() % 900);
			Add_GameObject(obj);
		}
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

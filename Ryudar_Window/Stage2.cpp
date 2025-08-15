#include "Stage2.h"
#include "CBackGround.h"
#include "CTransform.h"
#include "CSpriteRenderer.h"

namespace Ryu
{
	Stage2::Stage2()
	{
	}
	Stage2::~Stage2()
	{
	}
	void Stage2::Initialize()
	{
	#pragma region 배경생성
		CBackGround* pBG = new CBackGround;
		
		CTransform* pTR = pBG->AddComponent<CTransform>();
		pTR->Set_Name(L"St2_Bg_TR");
		pTR->Set_Position(Vector2(0.f, 0.f));

		CSpriteRenderer* pSR = pBG->AddComponent<CSpriteRenderer>();
		pSR->Set_Name(L"St2_Bg_SR");
		pSR->Image_Load(L"../KatanaZ/Texture/Stage2bg.bmp");
		
		Add_GameObject(pBG, enums::ecLayerType::BackGround);
	#pragma endregion

	}
	void Stage2::Update()
	{
		CScene::Update();
	}
	void Stage2::LateUpdate()
	{
		CScene::LateUpdate();
	}
	void Stage2::Render(HDC _hdc)
	{
		CScene::Render(_hdc);
	}
}
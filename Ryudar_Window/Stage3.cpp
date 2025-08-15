#include "Stage3.h"
#include "CBackGround.h"
#include "CTransform.h"
#include "CSpriteRenderer.h"

namespace Ryu
{
	Stage3::Stage3()
	{
	}

	Stage3::~Stage3()
	{
	}

	void Stage3::Initialize()
	{
	#pragma region 배경생성
		CBackGround* pBG = new CBackGround;
		
		CTransform* pTR = pBG->AddComponent<CTransform>();
		pTR->Set_Name(L"St3_Bg_TR");
		pTR->Set_Position(Vector2(0.f, 0.f));

		CSpriteRenderer* pSR = pBG->AddComponent<CSpriteRenderer>();
		pSR->Set_Name(L"St3_Bg_SR");
		pSR->Image_Load(L"../KatanaZ/Texture/Stage3bg.bmp");

		Add_GameObject(pBG, ecLayerType::BackGround);
	#pragma endregion

	}

	void Stage3::Update()
	{
		CScene::Update();
	}

	void Stage3::LateUpdate()
	{
		CScene::LateUpdate();
	}

	void Stage3::Render(HDC _hdc)
	{
		CScene::Render(_hdc);
	}
}

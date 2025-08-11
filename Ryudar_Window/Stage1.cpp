#include "Stage1.h"
#include "CBackGround.h"
#include "CTransform.h"
#include "CSpriteRenderer.h"

namespace Ryu
{
	Stage1::Stage1()
		: CScene()
	{
	}

	Stage1::~Stage1()
	{
	}

	void Stage1::Initialize()
	{
	#pragma region 배경생성
		CBackGround* pBG = new CBackGround;

		CTransform* pTR = pBG->AddComponent<CTransform>();
		pTR->Set_Name(L"St1_Bg_TR");
		pTR->Set_Position(Vector2(0.f, 0.f));

		CSpriteRenderer* pSR = pBG->AddComponent<CSpriteRenderer>();
		pSR->Set_Name(L"St1_Bg_SR");
		pSR->Image_Load(L"../KatanaZ/Texture/Stage1bg.bmp");

		CScene::Add_GameObject(pBG, ecLayerType::BackGround);
	#pragma endregion

	}

	void Stage1::Update()
	{
		CScene::Update();
	}

	void Stage1::LateUpdate()
	{
		CScene::LateUpdate();
	}

	void Stage1::Render(HDC _hdc)
	{
		CScene::Render(_hdc);
	}
}

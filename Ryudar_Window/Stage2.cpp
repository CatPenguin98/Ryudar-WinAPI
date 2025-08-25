#include "Stage2.h"
#include "CBackGround.h"
#include "CTransform.h"
#include "CSpriteRenderer.h"
#include "Object.h"
#include "CResources.h"

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
		CBackGround* pBG =
			object::Instantiate<CBackGround>(enums::ecLayerType::BackGround);

		CSpriteRenderer* pSR = pBG->AddComponent<CSpriteRenderer>();
		pSR->Set_Name(L"SR_Stage2_BG");
		graphics::CTexture* pBGTexture =
			CResources::Find<graphics::CTexture>(L"Texture_Stage2_BG");
		pBGTexture->Set_Name(L"Texture_Stage2_BG");
		pSR->Set_Texture(pBGTexture);
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
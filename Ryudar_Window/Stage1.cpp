#include "Stage1.h"
#include "CBackGround.h"
#include "CTransform.h"
#include "CSpriteRenderer.h"
#include "Object.h"
#include "CResources.h"

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
		CBackGround* pBG =
			object::Instantiate<CBackGround>(enums::ecLayerType::BackGround);

		CSpriteRenderer* pSR = pBG->AddComponent<CSpriteRenderer>();
		pSR->Set_Name(L"SR_St1_BG");
		graphics::CTexture* pBGTexture = 
			CResources::Find<graphics::CTexture>(L"Texture_Stage1_BG");
		pBGTexture->Set_Name(L"Texture_Stage1_BG");
		pSR->Set_Texture(pBGTexture);
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

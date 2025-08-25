#include "Stage3.h"
#include "CBackGround.h"
#include "CTransform.h"
#include "CSpriteRenderer.h"
#include "Object.h"
#include "CResources.h"

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
		CBackGround* pBG = 
			object::Instantiate<CBackGround>(enums::ecLayerType::BackGround);

		CSpriteRenderer* pBGSR = pBG->AddComponent<CSpriteRenderer>();
		pBGSR->Set_Name(L"St3_Bg_SR");
		graphics::CTexture* pBGTexture =
			CResources::Find<graphics::CTexture>(L"Texture_Stage3_BG");
		pBGTexture->Set_Name(L"Texture_Stage3_BG");
		pBGSR->Set_Texture(pBGTexture);
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

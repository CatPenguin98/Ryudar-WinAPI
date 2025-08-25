#include "TitleMenu.h"
#include "CBackGround.h"
#include "CTransform.h"
#include "CSpriteRenderer.h"
#include "Object.h"
#include "CResources.h"

/*씬전환 테스트*/
#include "CInputManager.h"
#include "Stage1.h"
#include "CSceneManager.h"

namespace Ryu
{
	TitleMenu::TitleMenu()
	{
	}

	TitleMenu::~TitleMenu()
	{
	}

	void TitleMenu::Initialize()
	{
	#pragma region 배경생성
		CBackGround* pBG = 
			object::Instantiate<CBackGround>(enums::ecLayerType::BackGround);

		CSpriteRenderer* pBGSR = pBG->AddComponent<CSpriteRenderer>();
		pBGSR->Set_Name(L"SR_Title_Bg");
		graphics::CTexture* pBGTexture =
			CResources::Find<graphics::CTexture>(L"Texture_Title_BG");
		pBGSR->Set_Texture(pBGTexture);
	#pragma endregion
	}

	void TitleMenu::Update()
	{
		CScene::Update();
	}

	void TitleMenu::LateUpdate()
	{
		CScene::LateUpdate();
		
		/*씬전환 테스트*/
		if (CInputManager::Get_KeyDown(ecKeyCode::N))
		{
			CSceneManager::LoadScene(L"PlayScene");
		}
	}

	void TitleMenu::Render(HDC _hdc)
	{
		CScene::Render(_hdc);
	}
}
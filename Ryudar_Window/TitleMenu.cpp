#include "TitleMenu.h"
#include "CBackGround.h"
#include "CTransform.h"
#include "CSpriteRenderer.h"

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
		CBackGround* pBG = new CBackGround;

		CTransform* pTR = pBG->AddComponent<CTransform>();
		pTR->Set_Name(L"Title_Bg_TR");
		pTR->Set_Position(Vector2(0.f, 0.f));

		CSpriteRenderer* pSR = pBG->AddComponent<CSpriteRenderer>();
		pSR->Set_Name(L"Title_Bg_SR");
		pSR->Image_Load(L"../KatanaZ/Texture/Title/spr_title_background.png");

		CScene::Add_GameObject(pBG, enums::ecLayerType::BackGround);
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
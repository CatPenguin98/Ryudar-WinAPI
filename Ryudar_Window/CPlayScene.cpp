#include "CPlayScene.h"
//#include "CGameObject.h"
#include "CPlayer.h"
#include "CTransform.h"
#include "CSpriteRenderer.h"

/*씬전환 테스트*/
#include "CInputManager.h"
#include "Stage1.h"
#include "CSceneManager.h"
/*test*/
namespace Ryu
{
	CPlayScene::CPlayScene()
		: CScene()
		, m_pPlayer(nullptr)
	{
	}

	CPlayScene::~CPlayScene()
	{
	}
	
	void CPlayScene::Initialize()
	{
	#pragma region 배경생성
		m_pPlayer = new CPlayer();
		
		CTransform* tr = m_pPlayer->AddComponent<CTransform>();
		tr->Set_Position(Vector2(0, 0));
		tr->Set_Name(L"TR");
		
		CSpriteRenderer* sr = m_pPlayer->AddComponent<CSpriteRenderer>();
		sr->Set_Name(L"SR");
		sr->Image_Load(L"../KatanaZ/CloudOcean.png");
		CScene::Add_GameObject(m_pPlayer, ecLayerType::Player);
	#pragma endregion
	}
	
	void CPlayScene::Update()
	{
		CScene::Update();
	}
	
	void CPlayScene::LateUpdate()
	{
		CScene::LateUpdate();

		/*씬전환 테스트*/
		if (CInputManager::Get_KeyDown(ecKeyCode::N))
		{
			CSceneManager::LoadScene(L"TitleMenu");
		}
	}
	void CPlayScene::Render(HDC _hdc)
	{
		CScene::Render(_hdc);
	}

	void CPlayScene::OnEnter()
	{
	}
	
	void CPlayScene::OnExit()
	{
		CTransform* tr = m_pPlayer->GetComponent<CTransform>();
		tr->Set_Position(Vector2(0, 0));
	}
}

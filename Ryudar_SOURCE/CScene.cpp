#include "CScene.h"

namespace Ryu
{
	CScene::CScene()
		:m_GameObjects{}
	{
	}

	CScene::~CScene()
	{
	}

	void CScene::Initialize()
	{
		
	}

	void CScene::Update()
	{
		for (auto iter = m_GameObjects.begin();
			iter != m_GameObjects.end(); ++iter)
		{
			(*iter)->Update();
		}
	}

	void CScene::LateUpdate()
	{
		for (auto iter = m_GameObjects.begin();
			iter != m_GameObjects.end(); ++iter)
		{
			(*iter)->LateUpdate();
		}
	}

	void CScene::Render(HDC _hdc)
	{
		for (auto iter = m_GameObjects.begin();
			iter != m_GameObjects.end(); ++iter)
		{
			(*iter)->Render(_hdc);
		}
	}
	void CScene::Add_GameObject(CGameObject* _gameObj)
	{
		m_GameObjects.push_back(_gameObj);
	}
}
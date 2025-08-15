#include "CScene.h"

namespace Ryu
{
	CScene::CScene()
		:m_Layers{}
	{
		m_Layers.reserve((UINT)enums::ecLayerType::Max);
		Create_Layers();
	}

	CScene::~CScene()
	{
	}

	void CScene::Initialize()
	{
		for (auto iter = m_Layers.begin();
			iter != m_Layers.end(); ++iter)
		{
			if (*iter == nullptr)
				continue;

			(*iter)->Initialize();
		}
	}

	void CScene::Update()
	{
		for (auto iter = m_Layers.begin();
			iter != m_Layers.end(); ++iter)
		{
			if (*iter == nullptr)
				continue;

			(*iter)->Update();
		}
	}

	void CScene::LateUpdate()
	{
		for (auto iter = m_Layers.begin();
			iter != m_Layers.end(); ++iter)
		{
			if (*iter == nullptr)
				continue;

			(*iter)->LateUpdate();
		}
	}

	void CScene::Render(HDC _hdc)
	{
		for (auto iter = m_Layers.begin();
			iter != m_Layers.end(); ++iter)
		{
			if (*iter == nullptr)
				continue;

			(*iter)->Render(_hdc);
		}
	}

	void CScene::OnEnter()
	{

	}
	
	void CScene::OnExit()
	{

	}

	void CScene::Add_GameObject(CGameObject* _gameObj, const enums::ecLayerType _layerType)
	{
		m_Layers[UINT(_layerType)]->Add_GameObject(_gameObj);
	}

	void CScene::Create_Layers()
	{
		for (int i = 0; i < (UINT)enums::ecLayerType::Max; ++i)
		{
			CLayer* layer = new CLayer;

			m_Layers.push_back(layer);
			
		}
	}
}
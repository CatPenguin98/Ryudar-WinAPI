#include "CLayer.h"

namespace Ryu
{
	CLayer::CLayer()
		: m_ecType(ecLayerType::None)
		, m_GameObjects{}
	{

	}

	CLayer::~CLayer()
	{

	}

	void CLayer::Initialize()
	{
		for (auto iter = m_GameObjects.begin();
			iter != m_GameObjects.end(); ++iter)
		{
			if (*iter == nullptr)
				continue;

			(*iter)->Initialize();
		}
	}

	void CLayer::Update()
	{
		for (auto iter = m_GameObjects.begin();
			iter != m_GameObjects.end(); ++iter)
		{
			if (*iter == nullptr)
				continue;

			(*iter)->Update();
		}
	}

	void CLayer::LateUpdate()
	{
		for (auto iter = m_GameObjects.begin();
			iter != m_GameObjects.end(); ++iter)
		{
			if (*iter == nullptr)
				continue;

			(*iter)->LateUpdate();
		}
	}

	void CLayer::Render(HDC _hdc)
	{
		for (auto iter = m_GameObjects.begin();
			iter != m_GameObjects.end(); ++iter)
		{
			if (*iter == nullptr)
				continue;

			(*iter)->Render(_hdc);
		}
	}

	void CLayer::Add_GameObject(CGameObject* _gameObj)
	{
		if (_gameObj == nullptr)
			return;

		m_GameObjects.push_back(_gameObj);
	}
}
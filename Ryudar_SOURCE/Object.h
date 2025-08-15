#pragma once

#include "CComponent.h"
#include "CTransform.h"
#include "CGameObject.h"
#include "CLayer.h"
#include "CSceneManager.h"
#include "CScene.h"

namespace Ryu::object
{
	template <typename T>
	static T* Instantiate(enums::ecLayerType _LayerType)
	{
		T* gameObj = new T;
		CScene* activeScene = CSceneManager::Get_ActiveScene();
		CLayer* layer = CScene::Get_Layer(_LayerType);
		layer->Add_GameObject(gameObj);

		return gameObj;
	}

	template <typename T>
	static T* Instantiate(enums::ecLayerType _LayerType, math::Vector2 _position)
	{
		T* gameObj = new T;
		CScene* activeScene = CSceneManager::Get_ActiveScene();
		CLayer* layer = activeScene->Get_Layer(_LayerType);
		layer->Add_GameObject(gameObj);

		CTransform* transform = gameObj->GetComponent<CTransform>();
		transform->Set_Position(_position);

		return gameObj;
	}
}
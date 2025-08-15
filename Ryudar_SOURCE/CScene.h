#pragma once

#include "CEntity.h"
#include "CGameObject.h"
#include "CLayer.h"

namespace Ryu
{
	class CScene : public CEntity
	{
	public:
		CScene();
		virtual ~CScene();

	public:
		virtual void			Initialize();
		virtual void			Update();
		virtual void			LateUpdate();
		virtual void			Render(HDC _hdc);
		 
	public:
		virtual void			OnEnter();
		virtual void			OnExit();

	public:
		void					Add_GameObject(CGameObject* _gameObj, const ecLayerType _layerType);

	private:
		void					Create_Layers();
	private:
		std::vector<CLayer*>	m_Layers;
	};
}


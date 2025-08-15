#pragma once
#include "CEntity.h"
#include "CommonInclude.h"
#include "CGameObject.h"

namespace Ryu
{
	class CLayer : public CEntity
	{
	public:
		CLayer(); 
		~CLayer();

	public:
		void			Initialize();
		void			Update();
		void			LateUpdate();
		void			Render(HDC _hdc);

	public:
		void			Add_GameObject(CGameObject* _gameObj);

	private:
		//ecLayerType						m_ecType;
		std::vector<CGameObject*>		m_GameObjects;
	};
}


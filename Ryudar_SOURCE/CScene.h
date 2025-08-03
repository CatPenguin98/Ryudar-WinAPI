#pragma once

#include "CEntity.h"
#include "CGameObject.h"

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
		void					Add_GameObject(CGameObject* _gameObj);

	private:
		std::vector<CGameObject*>		m_GameObjects;
	};
}


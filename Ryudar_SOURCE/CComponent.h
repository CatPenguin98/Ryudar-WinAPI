#pragma once
#include "CEntity.h"

namespace Ryu
{
	class CGameObject;

	class CComponent : public CEntity
	{
	public:
		CComponent();
		~CComponent();

	public:
		virtual void		Initialize();
		virtual void		Update();
		virtual void		LateUpdate();
		virtual void		Render(HDC _hdc);

	public:
		void				Set_Owner(CGameObject* _owner) { m_pOwner = _owner; }
		CGameObject*		Get_Owner() const { return m_pOwner;  }

	private:
		CGameObject*		m_pOwner;
	};
}
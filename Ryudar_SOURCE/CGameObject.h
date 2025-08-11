#pragma once

#include "CommonInclude.h"
#include "CComponent.h"

namespace Ryu
{
	class CGameObject
	{
	public:
		CGameObject();
		~CGameObject();

	public:
		virtual void			Initialize();
		virtual void			Update();
		virtual void			LateUpdate();
		virtual void			Render(HDC _hdc);
		virtual void			Release();

	public:
		template <typename T>
		T* AddComponent()
		{
			T* pComp = new T;
			pComp->Initialize();
			pComp->Set_Owner(this);
			m_Components.push_back(pComp);

			return pComp;
		}

		template <typename T>
		T* GetComponent()
		{
			T* pComponent = nullptr;
			for (CComponent* pComp : m_Components)
			{
				pComponent = dynamic_cast<T*>(pComp);
				if (pComponent)
					break;
			}

			return pComponent;
		}

	private:
		std::vector<CComponent*> m_Components;
	};
}


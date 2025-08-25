#pragma once
#include "CResource.h"

namespace Ryu
{
	class CResources
	{
	public:
		template <typename T>
		static T* Find(const std::wstring& _key)
		{
			auto iter =  m_Resources.find(_key);

			if (iter == m_Resources.end())
			{
				return nullptr;
			}

			return dynamic_cast<T*>(iter->second);
		}

		template <typename T>
		static T* Load(const std::wstring& _key, const std::wstring& _path)
		{
			T* pResource = CResources::Find<T>(_key);
			
			if (pResource != nullptr)
			{
				return pResource;
			}

			pResource = new T;
			if (FAILED(pResource->Load(_path)))
			{
				assert(false);
			}

			pResource->Set_Name(_key);
			pResource->Set_Path(_path);

			m_Resources.insert(std::make_pair(_key, pResource));

			return pResource;
		}

	private:
		static std::map<std::wstring, CResource*> m_Resources;
	};
}


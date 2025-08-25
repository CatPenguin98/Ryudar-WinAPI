#pragma once

#include "CEntity.h"

namespace Ryu
{
	class CResource : public CEntity
	{
		CResource() = delete;
	public:
		CResource(const enums::ecResourceType _ResourceType);
		virtual ~CResource();

	public:
		virtual HRESULT			Load(const std::wstring& path) = 0;

	public:
		const std::wstring&		Get_Path() const { return m_Path; }
	
	public:
		void					Set_Path(const std::wstring& _path) { m_Path = _path; }

	private:
		const enums::ecResourceType		m_ResourceType;
		std::wstring					m_Path;
	};
}


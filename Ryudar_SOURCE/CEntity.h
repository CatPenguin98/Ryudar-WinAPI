#pragma once

#include "CommonInclude.h"

namespace Ryu
{
	class CEntity
	{
	public:
		CEntity();
		virtual ~CEntity();

	public:
		void Set_Name(const std::wstring& _name) { m_wsName = _name; }
		std::wstring& Get_Name() { return m_wsName; }

	private:
		std::wstring m_wsName;
	};
}


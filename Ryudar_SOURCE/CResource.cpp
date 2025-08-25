#include "CResource.h"

namespace Ryu
{
	CResource::CResource(const enums::ecResourceType _ResourceType)
		: CEntity()
		, m_ResourceType(_ResourceType)
	{
	}
	CResource::~CResource()
	{
	}
}
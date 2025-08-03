#pragma once

#include "CommonInclude.h"

namespace Ryu
{
	class CGameObject
	{
	public:
		CGameObject();
		~CGameObject();

	public:
		void Update();
		void LateUpdate();
		void Render(HDC _hdc);
	public:
		void Set_Position(const float x, const float y) { m_X = x; m_Y = y; }
		const float Get_PosiitonX() const { return m_X; }
		const float Get_PositionY() const { return m_Y; }

	private:
		/*게임 오브젝트 좌표*/
		float m_X;
		float m_Y;
	};
}


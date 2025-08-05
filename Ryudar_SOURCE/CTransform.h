#pragma once
#include "CComponent.h"

namespace Ryu
{
	//struct Pos
	//{
	//	int mX;
	//	int mY;
	//};
	using namespace math;

	class CTransform : public CComponent
	{
	public:
		CTransform();
		~CTransform();

	public:
		void				Initialize() override;
		void				Update()  override;
		void				LateUpdate()  override;
		void				Render(HDC hdc)  override;
	
	public:
		void Set_Position(Vector2 _vPos) { m_vPosition = _vPos; }
		const Vector2 Get_Position() const { return m_vPosition; }

	private:
		Vector2 m_vPosition;
	};
}


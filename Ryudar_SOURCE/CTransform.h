#pragma once
#include "CComponent.h"

namespace Ryu
{
	struct Pos
	{
		int mX;
		int mY;
	};

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
		void				SetPos(int x, int y) 
		{ mX = x; mY = y; }
		int					GetX() 
		{ return mX; }
		int					GetY() 
		{ return mY; }

	private:
		int mX;
		int mY;
	};
}


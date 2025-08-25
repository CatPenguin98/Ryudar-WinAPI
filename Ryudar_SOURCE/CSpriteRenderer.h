#pragma once

#include "CEntity.h"
#include "CComponent.h"
#include "CTexture.h"

namespace Ryu
{
	class CSpriteRenderer : public CComponent
	{
	public:
		CSpriteRenderer();
		~CSpriteRenderer();

	public:
		void		Initialize() override;
		void		Update() override;
		void		LateUpdate() override;
		void		Render(HDC _hdc) override;

	public:
		void		Set_Texture(graphics::CTexture* _pTexture) { m_pTexture = _pTexture; }
		void		Set_Size(const math::Vector2& _size) { m_Size = _size; }
	private:
		graphics::CTexture* m_pTexture;
		math::Vector2				m_Size;
	};
}


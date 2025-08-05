#pragma once

#include "CEntity.h"
#include "CComponent.h"

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
		void		Image_Load(const std::wstring& path);

	private:
		Gdiplus::Image*		m_pImage;
		UINT				m_iWidth;
		UINT				m_iHeight;
	};
}


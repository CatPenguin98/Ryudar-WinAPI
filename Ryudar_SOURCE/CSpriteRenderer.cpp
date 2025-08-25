#include "CSpriteRenderer.h"
#include "CGameObject.h"
#include "CTransform.h"

namespace Ryu
{
	CSpriteRenderer::CSpriteRenderer()
		: CComponent()
		, m_pTexture(nullptr)
		, m_Size(Vector2::One)
	{
	}

	CSpriteRenderer::~CSpriteRenderer()
	{

	}

	void CSpriteRenderer::Initialize()
	{

	}

	void CSpriteRenderer::Update()
	{

	}

	void CSpriteRenderer::LateUpdate()
	{

	}

	void CSpriteRenderer::Render(HDC _hdc)
	{
		if (m_pTexture == nullptr)
		{
			assert(false); // 텍스처 세팅 필요.
		}
		
		CTransform* tr = Get_Owner()->GetComponent<CTransform>();
		Vector2 pos = tr->Get_Position();

		if (m_pTexture->Get_TextureType() 
			== graphics::CTexture::ecTextureType::Bmp)
		{
			TransparentBlt(
				_hdc,
				pos.x, pos.y,
				m_pTexture->Get_Width() * m_Size.x, m_pTexture->Get_Height() * m_Size.y,
				m_pTexture->Get_HDC(), 0, 0,
				m_pTexture->Get_Width(), m_pTexture->Get_Height(),
				RGB(255, 0, 255)
			);
		}
		else if (m_pTexture->Get_TextureType()
			== graphics::CTexture::ecTextureType::Png)
		{
			Gdiplus::Graphics graphics(_hdc);
			graphics.DrawImage(
				m_pTexture->Get_Image(),
				Gdiplus::Rect(pos.x, pos.y, 
					m_pTexture->Get_Width() * m_Size.x,
					m_pTexture->Get_Height() * m_Size.y));
		}
		/*이미지 크기만큼 출력*/
		//graphics.DrawImage(
		//	m_pImage,
		//	Gdiplus::Rect(0, 0, 1600, 900),         // 화면에 그릴 크기
		//	0, 0, m_iWidth, m_iHeight,              // 원본 이미지 영역
		//	Gdiplus::UnitPixel);
	}
}
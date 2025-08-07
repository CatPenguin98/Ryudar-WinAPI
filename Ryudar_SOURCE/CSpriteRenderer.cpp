#include "CSpriteRenderer.h"
#include "CGameObject.h"
#include "CTransform.h"

namespace Ryu
{
	CSpriteRenderer::CSpriteRenderer()
		: m_pImage(nullptr)
		, m_iWidth(0)
		, m_iHeight(0)
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
		CTransform* tr = Get_Owner()->GetComponent<CTransform>();

		Vector2 pos = tr->Get_Position();

		Gdiplus::Graphics graphics(_hdc);
		/*윈도우 크기만큼 출력*/
		graphics.DrawImage(
			m_pImage, 
			Gdiplus::Rect(pos.x, pos.y, m_iWidth, m_iHeight));
		/*이미지 크기만큼 출력*/
		//graphics.DrawImage(
		//	m_pImage,
		//	Gdiplus::Rect(0, 0, 1600, 900),         // 화면에 그릴 크기
		//	0, 0, m_iWidth, m_iHeight,              // 원본 이미지 영역
		//	Gdiplus::UnitPixel);
	}

	void CSpriteRenderer::Image_Load(const std::wstring& path)
	{
		/*이미지를 로드해서 해당 이미지의 주소값을 할당.*/
		m_pImage = Gdiplus::Image::FromFile(path.c_str());
		m_iWidth = m_pImage->GetWidth();
		m_iHeight = m_pImage->GetHeight();
	}
}
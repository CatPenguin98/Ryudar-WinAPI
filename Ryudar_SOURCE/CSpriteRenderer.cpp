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
		/*������ ũ�⸸ŭ ���*/
		graphics.DrawImage(
			m_pImage, 
			Gdiplus::Rect(pos.x, pos.y, m_iWidth, m_iHeight));
		/*�̹��� ũ�⸸ŭ ���*/
		//graphics.DrawImage(
		//	m_pImage,
		//	Gdiplus::Rect(0, 0, 1600, 900),         // ȭ�鿡 �׸� ũ��
		//	0, 0, m_iWidth, m_iHeight,              // ���� �̹��� ����
		//	Gdiplus::UnitPixel);
	}

	void CSpriteRenderer::Image_Load(const std::wstring& path)
	{
		/*�̹����� �ε��ؼ� �ش� �̹����� �ּҰ��� �Ҵ�.*/
		m_pImage = Gdiplus::Image::FromFile(path.c_str());
		m_iWidth = m_pImage->GetWidth();
		m_iHeight = m_pImage->GetHeight();
	}
}
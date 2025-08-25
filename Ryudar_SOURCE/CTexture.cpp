#include "CTexture.h"
#include "rApplication.h"

extern Ryu::Application application;

namespace Ryu::graphics
{
	CTexture::CTexture()
		: CResource(enums::ecResourceType::Texture)
		, m_pImage(nullptr)
		, m_Bitmap(nullptr)
		, m_Hdc(nullptr)
		, m_TextureType(ecTextureType::None)
		, m_iWidth(0)
		, m_iHeight(0)

	{
	}

	CTexture::~CTexture()
	{
	}

	HRESULT CTexture::Load(const std::wstring& _path)
	{
		std::wstring ext = _path.substr(_path.find_last_of(L".") + 1);
		// BMP경우
		if (ext == L"bmp")
		{
			m_TextureType = ecTextureType::Bmp;

			m_Bitmap = (HBITMAP)LoadImageW(
				nullptr, _path.c_str(), IMAGE_BITMAP,
				0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

			if (m_Bitmap == nullptr)
			{
				return S_FALSE;
			}

			BITMAP info = {};
			GetObject(m_Bitmap, sizeof(BITMAP), &info);

			m_iWidth = info.bmWidth;
			m_iHeight = info.bmHeight;

			HDC mainDC = application.Get_HDC();
			m_Hdc = CreateCompatibleDC(mainDC);

			HBITMAP oldBitmap = (HBITMAP)SelectObject(m_Hdc, m_Bitmap);
			DeleteObject(oldBitmap);

		}
		else if (ext == L"png")// png경우
		{
			m_TextureType = ecTextureType::Png;
			/*이미지를 로드해서 해당 이미지의 주소값을 할당.*/
			m_pImage = Gdiplus::Image::FromFile(_path.c_str());

			if (m_pImage == nullptr)
			{
				return S_FALSE;
			}

			m_iWidth = m_pImage->GetWidth();
			m_iHeight = m_pImage->GetHeight();
		}
		return S_OK;
	}
}
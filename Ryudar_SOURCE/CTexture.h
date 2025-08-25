#pragma once
#include "CResource.h"

namespace Ryu::graphics
{
    class CTexture : public CResource
    {
    public:
        enum class ecTextureType
        {
            Bmp, Png, None,
        };

    public:
        CTexture();
        ~CTexture();

    public:
        virtual HRESULT     Load(const std::wstring& _path) override;

    public:
        const UINT              Get_Width() const { return m_iWidth; }
        const UINT              Get_Height() const { return m_iHeight; }
        const HDC               Get_HDC() const { return m_Hdc; }
        const ecTextureType     Get_TextureType() const { return m_TextureType; }
        Gdiplus::Image*         Get_Image() const { return m_pImage; }

    private:
        Gdiplus::Image*     m_pImage;   // png파일용 32bit
        HBITMAP             m_Bitmap;   // BMP파일용 24bit
        HDC                 m_Hdc;
        ecTextureType       m_TextureType;

        UINT				m_iWidth;
        UINT				m_iHeight;
    };
}


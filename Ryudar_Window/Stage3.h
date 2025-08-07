#pragma once
#include "../Ryudar_SOURCE/CScene.h"

namespace Ryu
{
    class Stage3 : public CScene
    {
    public:
        Stage3();
        ~Stage3();

    public:
        void			Initialize() override;
        void			Update() override;
        void			LateUpdate() override;
        void			Render(HDC _hdc) override;
    };
}


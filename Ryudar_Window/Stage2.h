#pragma once
#include "../Ryudar_SOURCE/CScene.h"

namespace Ryu
{
    class Stage2 : public CScene
    {
    public:
        Stage2();
        ~Stage2();

    public:
        void			Initialize() override;
        void			Update() override;
        void			LateUpdate() override;
        void			Render(HDC _hdc) override;
    };
}


#pragma once
#include "CGameObject.h"

namespace Ryu
{
    class CPlayer : public CGameObject
    {
    public:
        CPlayer();
        ~CPlayer();

    public:
    public:
        void Initialize() override;
        void Update() override;
        void LateUpdate() override;
        void Render(HDC _hdc) override;
    };
}


#pragma once

#include "../Ryudar_SOURCE/CScene.h"

namespace Ryu
{
	class Stage1 : public CScene
	{
	public:
		Stage1();
		~Stage1();

	public:
		void			Initialize() override;
		void			Update() override;
		void			LateUpdate() override;
		void			Render(HDC _hdc) override;
	};
}


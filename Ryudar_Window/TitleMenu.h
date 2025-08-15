#pragma once

#include "../Ryudar_SOURCE/CScene.h"

namespace Ryu
{
	class TitleMenu : public CScene
	{
	public:
		TitleMenu();
		~TitleMenu();

	public:
		void			Initialize() override;
		void			Update() override;
		void			LateUpdate() override;
		void			Render(HDC _hdc) override;
	};
}


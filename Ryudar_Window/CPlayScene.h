#pragma once
#include "../Ryudar_SOURCE/CScene.h"

namespace Ryu
{
	class CPlayScene : public CScene
	{
	public:
		CPlayScene();
		virtual ~CPlayScene();
	
	public:
		void			Initialize() override;
		void			Update() override;
		void			LateUpdate() override;
		void			Render(HDC _hdc) override;
	
	private:
	};
}


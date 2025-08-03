#pragma once

#include "../Ryudar_SOURCE/CSceneManager.h"
#include "CPlayScene.h"

namespace Ryu
{
	void LoadScenes()
	{
		CSceneManager::CreateScene<CPlayScene>(L"PlayScene");
		CSceneManager::LoadScene(L"PlayScene");
	}
}
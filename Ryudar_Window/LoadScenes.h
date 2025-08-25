#pragma once

#include "../Ryudar_SOURCE/CSceneManager.h"
#include "CPlayScene.h"
#include "TitleMenu.h"
#include "Stage1.h"
#include "Stage2.h"
#include "Stage3.h"


namespace Ryu
{
	void LoadScenes()
	{
		CSceneManager::CreateScene<CPlayScene>(L"PlayScene");
		CSceneManager::CreateScene<TitleMenu>(L"TitleMenu");
		//CSceneManager::CreateScene<Stage1>(L"Stage1");
		//CSceneManager::CreateScene<Stage2>(L"Stage2");
		//CSceneManager::CreateScene<Stage3>(L"Stage3");
		//CSceneManager::LoadScene(L"TitleMenu");
		//CSceneManager::LoadScene(L"Stage1");
		//CSceneManager::LoadScene(L"Stage2");
		//CSceneManager::LoadScene(L"Stage3");
		CSceneManager::LoadScene(L"TitleMenu");
	}
}
#include "CSceneManager.h"

namespace Ryu
{
	std::map<std::wstring, CScene*> CSceneManager::m_Scenes = {};
	CScene* CSceneManager::m_pActiveScene = nullptr;

	void CSceneManager::Initialize()
	{
	}

	void CSceneManager::Update()
	{
		m_pActiveScene->Update();
	}

	void CSceneManager::LateUpdate()
	{
		m_pActiveScene->LateUpdate();
	}

	void CSceneManager::Render(HDC _hdc)
	{
		m_pActiveScene->Render(_hdc);
	}
}

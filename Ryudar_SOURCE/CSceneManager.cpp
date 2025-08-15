#include "CSceneManager.h"

namespace Ryu
{
	std::map<std::wstring, CScene*> CSceneManager::m_Scenes = {};
	CScene* CSceneManager::m_pActiveScene = nullptr;

	CScene* CSceneManager::LoadScene(const std::wstring& _name)
	{
		if (m_pActiveScene)
		{
			m_pActiveScene->OnExit();
		}

		std::map<std::wstring, CScene*>::iterator sceneIter =
			m_Scenes.find(_name);

		if (sceneIter == m_Scenes.end())
		{
			return nullptr;
		}

		m_pActiveScene = sceneIter->second;
		m_pActiveScene->OnEnter();

		return sceneIter->second;
	}

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

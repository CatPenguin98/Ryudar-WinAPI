#pragma once

#include "CScene.h"

namespace Ryu
{
	class CSceneManager
	{
	public:
		template<typename T>
		static CScene*		CreateScene(const std::wstring& _name)
		{
			T* scene = new T();
			scene->Set_Name(_name);
			scene->Initialize();

			m_Scenes.insert(std::make_pair(_name, scene));

			return scene;
		}
		static CScene*		LoadScene(const std::wstring& _name)
		{
			std::map<std::wstring, CScene*>::iterator sceneIter = 
				m_Scenes.find(_name);
		
			if (sceneIter == m_Scenes.end())
			{
				return nullptr;
			}
			
			m_pActiveScene = sceneIter->second;
		
			return sceneIter->second;
		}

	public:
		static void			Initialize();
		static void			Update();
		static void			LateUpdate();
		static void			Render(HDC _hdc);

	private:
		static std::map<std::wstring, CScene*>	m_Scenes;
		static CScene*							m_pActiveScene;
	};
}


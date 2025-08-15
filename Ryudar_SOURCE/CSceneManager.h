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
			m_pActiveScene = scene;
			scene->Initialize();

			m_Scenes.insert(std::make_pair(_name, scene));

			return scene;
		}
		static CScene*		LoadScene(const std::wstring& _name);
		static CScene*		Get_ActiveScene() { return m_pActiveScene; }

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


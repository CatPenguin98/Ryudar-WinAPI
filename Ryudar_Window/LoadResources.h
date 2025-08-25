#pragma once

#include "../Ryudar_SOURCE/CResources.h"
#include "../Ryudar_SOURCE/CTexture.h"

namespace Ryu
{
	void LoadResources()
	{
	#pragma region PlayScene���ҽ�
		//���
		CResources::Load<graphics::CTexture>(L"Texture_PlayScene_BG", L"../KatanaZ/CloudOcean.png");
	#pragma endregion

	#pragma region TitleMenu���ҽ�
		//���
		CResources::Load<graphics::CTexture>(L"Texture_Title_BG", L"../KatanaZ/Texture/Title/spr_title_background.png");
	#pragma endregion

	#pragma region Stage1���ҽ�
		//���
		CResources::Load<graphics::CTexture>(L"Texture_Stage1_BG", L"../KatanaZ/Texture/Stage1bg.bmp");
	#pragma endregion

	#pragma region Stage2���ҽ�
		//���
		CResources::Load<graphics::CTexture>(L"Texture_Stage2_BG", L"../KatanaZ/Texture/Stage2bg.bmp");
	#pragma endregion

	#pragma region Stage3���ҽ�
		//���
		CResources::Load<graphics::CTexture>(L"Texture_Stage3_BG", L"../KatanaZ/Texture/Stage3bg.bmp");
	#pragma endregion


	}
}
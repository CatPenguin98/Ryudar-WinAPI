#include "CTimeManager.h"

namespace Ryu
{
	LARGE_INTEGER	CTimeManager::m_CPUFrequency = {};
	LARGE_INTEGER	CTimeManager::m_PrevCPUFrequency = {};
	LARGE_INTEGER	CTimeManager::m_CurrentCPUFrequency = {};
	float			CTimeManager::m_DeltaTime = 0.f;

	void CTimeManager::Initialize()
	{
		//CPU의 고유 진동수
		QueryPerformanceFrequency(&m_CPUFrequency);

		// 프로그램이 시작했을 때 현재 진동수
		QueryPerformanceCounter(&m_PrevCPUFrequency);
	}

	void CTimeManager::Update()
	{
		QueryPerformanceCounter(&m_CurrentCPUFrequency);

		//현재 진동수에서 이전 진동수를 뺴줌 -> 이전에서 현재까지의 진동수가 나옴.
		float differenceFrequency
			= static_cast<float>(m_CurrentCPUFrequency.QuadPart - m_PrevCPUFrequency.QuadPart);

		// 진동수 / 고유 진동수 = 시간.
		m_DeltaTime = 
			differenceFrequency / static_cast<float>(m_CPUFrequency.QuadPart);

		// 이전 진동수 갱신
		m_PrevCPUFrequency.QuadPart = m_CurrentCPUFrequency.QuadPart;
		//QueryPerformanceCounter(&m_PrevCPUFrequency);
	}

	void CTimeManager::Render(HDC _hdc)
	{
		static float time{};

		time += m_DeltaTime;

		wchar_t str[50]{};
		swprintf_s(str, 50, L"Time: %f", time);
		int len = wcsnlen_s(str, 50);
		TextOut(_hdc, 0, 0, str, len);

		float fps = 1.0f / m_DeltaTime;

		wchar_t str2[50]{};
		swprintf_s(str2, 50, L"FPS: %f", fps);
		int len2 = wcsnlen_s(str2, 50);
		TextOut(_hdc, 0, 80, str2, len2);
	}
}
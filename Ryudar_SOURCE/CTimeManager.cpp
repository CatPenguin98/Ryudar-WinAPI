#include "CTimeManager.h"

namespace Ryu
{
	LARGE_INTEGER	CTimeManager::m_CPUFrequency = {};
	LARGE_INTEGER	CTimeManager::m_PrevCPUFrequency = {};
	LARGE_INTEGER	CTimeManager::m_CurrentCPUFrequency = {};
	float			CTimeManager::m_DeltaTime = 0.f;

	void CTimeManager::Initialize()
	{
		//CPU�� ���� ������
		QueryPerformanceFrequency(&m_CPUFrequency);

		// ���α׷��� �������� �� ���� ������
		QueryPerformanceCounter(&m_PrevCPUFrequency);
	}

	void CTimeManager::Update()
	{
		QueryPerformanceCounter(&m_CurrentCPUFrequency);

		//���� ���������� ���� �������� ���� -> �������� ��������� �������� ����.
		float differenceFrequency
			= static_cast<float>(m_CurrentCPUFrequency.QuadPart - m_PrevCPUFrequency.QuadPart);

		// ������ / ���� ������ = �ð�.
		m_DeltaTime = 
			differenceFrequency / static_cast<float>(m_CPUFrequency.QuadPart);

		// ���� ������ ����
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
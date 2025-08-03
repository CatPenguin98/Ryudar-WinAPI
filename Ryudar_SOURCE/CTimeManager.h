#pragma once

#include "CommonInclude.h"

namespace Ryu
{
	/*사용법
	* 프로그램 실행 환경마다 CPU의 성능이 다르기 때문에 DeltaTime을 두고
	* 연산값을 일정하게 설정.
	* 1. Initialize()로 시간값들 초기화
	* 2. Update()문을 돌면서 DeltaTime계산
	*	a. DeltaTime = 프로그램 루프 한번도는 동안의 진동수 / 고유 진동수
	*	b. 현재 진동수 - 이전 진동수를 통해
	*		루프한번동안의 진동수를 계산할 수 있음.
	*/

	class CTimeManager
	{
	public:
		static void				Initialize();
		static void				Update();
		static void				Render(HDC _hdc);

	public:
		static float				Get_DeltaTime() { return m_DeltaTime; }

	private:
		static LARGE_INTEGER	m_CPUFrequency;
		static LARGE_INTEGER	m_PrevCPUFrequency;
		static LARGE_INTEGER	m_CurrentCPUFrequency;
		static float			m_DeltaTime;
	};
}


#pragma once

#include "CommonInclude.h"

namespace Ryu
{
	/*����
	* ���α׷� ���� ȯ�渶�� CPU�� ������ �ٸ��� ������ DeltaTime�� �ΰ�
	* ���갪�� �����ϰ� ����.
	* 1. Initialize()�� �ð����� �ʱ�ȭ
	* 2. Update()���� ���鼭 DeltaTime���
	*	a. DeltaTime = ���α׷� ���� �ѹ����� ������ ������ / ���� ������
	*	b. ���� ������ - ���� �������� ����
	*		�����ѹ������� �������� ����� �� ����.
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


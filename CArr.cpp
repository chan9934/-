#include "CArr.h"
#include <assert.h>

void CArr::push_back(int _Data)
{
	if (m_iMaxCount <= m_iCount)
	{
		//���Ҵ�
		resize(m_iMaxCount * 2);
	}

	m_pInt[m_iCount++] = _Data;
}

void CArr::resize(int iResizeCount)
{
	//���� �ִ� ���뷮 ���� �� ���� ��ġ�� Ȯ���Ϸ��� ���
	if (m_iMaxCount >= iResizeCount)
	{
		assert(nullptr);

	}

	// 1. �������� ��ų ������ŭ �����Ҵ� �Ѵ�.
	int* pNew = new int[iResizeCount];

	// 2.���� ������ �ִ� �����͵��� ���� �Ҵ��� �������� �����Ų��.
	for (int i = 0; i < m_iCount; ++i)
	{
		pNew[i] = m_pInt[i];

	}

	// 3. ���� ������ �޸� ����
	delete[] m_pInt;

	// 4. �迭�� ���� �Ҵ��� ������ ����Ű�� �Ѵ�.
	m_pInt = pNew;

	// 5. MaxCount ������ ����
	m_iMaxCount = iResizeCount;
}

int& CArr::operator[](int idx)
{
	return m_pInt[idx];
}

CArr::CArr()
	:m_pInt(nullptr)
	, m_iCount(0)
	, m_iMaxCount(0)
{
	m_pInt = new int[2];
}

CArr::~CArr()
{
	delete[] m_pInt;
}

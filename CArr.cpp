//#include "CArr.h"
//#include <assert.h>

void CArr::push_back(int _Data)
{
	if (m_iMaxCount <= m_iCount)
	{
		//���Ҵ�
		resize(m_iMaxCount * 2);
	}

	m_pData[m_iCount++] = _Data;
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
		pNew[i] = m_pData[i];

	}

	// 3. ���� ������ �޸� ����
	delete[] m_pData;

	// 4. �迭�� ���� �Ҵ��� ������ ����Ű�� �Ѵ�.
	m_pData = pNew;

	// 5. MaxCount ������ ����
	m_iMaxCount = iResizeCount;
}

int& CArr::operator[](int idx)
{
	return m_pData[idx];
}

CArr::CArr()
	:m_pData(nullptr)
	, m_iCount(0)
	, m_iMaxCount(0)
{
	m_pData = new int[2];
}

CArr::~CArr()
{
	delete[] m_pData;
}

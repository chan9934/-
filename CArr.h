#pragma once
#include <assert.h>

template<typename T>
class CArr
{


private:
	T* m_pData;
	int m_iCount;
	int m_iMaxCount;

public:
	void push_back(const T& _Data);
	void resize(int iResizeCount);

	T& operator[] (int idx);

public:
	CArr();
	~CArr();

};
template<typename T>
CArr<T>::CArr()
	:m_pData(nullptr)
	, m_iCount(0)
	, m_iMaxCount(2)
{
	m_pData = new T[2];
}
template<typename T>
CArr<T>::~CArr()
{
	delete[] m_pData;
}

template<typename T>
void CArr<T>::push_back(const T& _Data)
{
	if (m_iMaxCount <= m_iCount)
	{
		//���Ҵ�
		resize(m_iMaxCount * 2);
	}

	m_pData[m_iCount++] = _Data;
}

template<typename T>
void CArr<T>::resize(int iResizeCount)
{
	//���� �ִ� ���뷮 ���� �� ���� ��ġ�� Ȯ���Ϸ��� ���
	if (m_iMaxCount >= iResizeCount)
	{
		assert(nullptr);

	}

	// 1. �������� ��ų ������ŭ �����Ҵ� �Ѵ�.
	T* pNew = new T[iResizeCount];

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

template <typename T>
T& CArr<T>::operator[](int idx)
{
	return m_pData[idx];
}


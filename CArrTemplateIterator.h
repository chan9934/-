#pragma once
#include <assert.h>
template<typename T>

class myVector
{
private:
	T* m_pData;
	int m_iCount;
	int m_iMaxCount;
public:
	myVector();
	~myVector();

	void Push_back(const T& _Data);
	void Resize(int iResizeCount);

	T& operator[] (int idx);

	class iterator;
	
	iterator begin();
	iterator end();

	class iterator
	{
	private:
		myVector*	m_pArr;
		T*			m_pData;
		int			m_iIdx;

	public:
		T& operator *()
		{
			if (m_pArr->m_pData != m_pData)
			{
				return m_pData[m_iIdx];
			}
		}

		iterator& operator ++()
		{
			return *this;
		}
		iterator& operator --()
		{
			return *this;
		}

	public:
		iterator()
			: m_pArr(nullptr)
			, m_pData(nullptr)
			, m_iIdx(-1)
		{
		}

		iterator(myVector* _pArr, T* m_pData, int m_iIdx)
			: m_pArr(_pArr)
			, m_pData(m_pData)
			, m_iIdx(m_iIdx)
		{
		}
		~iterator()
		{
		}
	};



};

template<typename T>
myVector<T>::myVector()
	: m_pData(nullptr)
	, m_iCount(0)
	, m_iMaxCount(2)
{
	m_pData = new T[2];

}

template<typename T>
myVector<T>::~myVector()
{
	delete[] m_pData;
}

template<typename T>
void myVector<T>::Push_back(const T& _Data)
{
	if (m_iMaxCount <= m_iCount)
	{
		Resize(m_iMaxCount * 2);
	}

	m_pData[m_iCount++] = _Data;


}
template<typename T>
void myVector<T>::Resize(int iResizeCount)
{
	if (m_iMaxCount >= iResizeCount)
	{
		assert(nullptr);
	}

	T* pNew = new T[iResizeCount];

	for (int i = 0; i < m_iCount; ++i)
	{
		pNew[i] = m_pData[i];
	}

	delete[] m_pData;

	m_pData = pNew;

	m_iMaxCount = iResizeCount;
}

template<typename T>
T& myVector<T>::operator[] (int idx)
{
	return *(m_pData + idx);
}

template<typename T>
typename myVector<T>::iterator myVector<T>::begin()
{

	if (0 == m_iCount)
	{
		return iterator(this, m_pData, -1);
	}
	else
	{
		return iterator(this, m_pData, 0);
	}
}
template<typename T>
typename myVector<T>::iterator myVector<T>::end()
{

		return iterator(this, m_pData, -1);
	
}
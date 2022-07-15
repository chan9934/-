#pragma once

#include <assert.h>
template <typename T>
class CArr
{

private:
	T* m_Ptr;
	int m_Count;
	int m_Max_Count;

public:
	CArr();
	~CArr();
	
	void Push_back(int _Data);
	void Resize(int _CountSize);
	T& operator[](int _Index);

	class iterator;
	iterator begin();
	iterator end();
	iterator erase(const iterator& _iter);

	class iterator
	{
	private:
		CArr* i_ArrPtr;
		T* i_Ptr;
		int i_Index;
		bool i_valid;

	public:
		iterator()
			: i_ArrPtr(nullptr)
			, i_Ptr(nullptr)
			, i_Index(-1)
			, i_valid(false)
		{

		}

		iterator(CArr* _pArr, T* _pData, int _iIdx)
			: i_ArrPtr(_pArr)
			, i_Ptr(_pData)
			, i_Index(_iIdx)
		{

		}
		~iterator()
		{

			
		}

		T& operator*()
		{

			if (i_ArrPtr->m_Ptr != i_Ptr)
				assert(nullptr);

			return *(i_Ptr + i_Index);
		}

		iterator& operator ++()
		{
			if (i_ArrPtr->m_Ptr 1 != m_Ptr || -1 == m_Ptr)
			{
				assert(nullptr);
			}


			if (i_ArrPtr->m_Count - 1 == i_Index)
			{
				i_Index = -1;
			}

			else
			{
				++i_Index;
			}

			return *this;
		}

		bool operator == (const iterator& _otheriter)
		{
			if (i_Ptr == _otheriter.i_Ptr && i_Index == _otheriter.i_Index)
			{
				return true;
			}

				return false;
		}

			bool operator != (const iterator & _otheriter)
			{
				return !(*this == _otheriter);
			}
		
	};

	iterator operator ++(int)
	{
		iterator copy_iter = *this;

		++(*this);

		return copy_iter;
	}

	friend class CArr;

	
};

template<typename T>
CArr<T>::CArr()
	: m_Ptr(nullptr)
	, m_Count(0)
	, m_Max_Count(0)
{
	m_Ptr = new T[2];
}

template<typename T>
CArr<T>::~CArr()
{
	delete[] m_Ptr;
}

template<typename T>
void CArr<T>::Push_back(int _Data)
{
	if (m_Count >= m_Max_Count)
	{
		Resize(m_Max_Count * 2);
	}

	CArr[m_Count] = _Data;
	++m_Count;


}

template<typename T>
void CArr<T>::Resize(int _CountSize)
{
	if (_CountSize <= m_Count)
	{
		assert(nullptr);
	}

	T* NewPtr = new(T)[_CountSize];

	for (int i = 0; i < m_Count; ++i)
	{
		NewPtr[i] = m_Ptr[i];
	}

	delete[] m_Ptr;

	m_Ptr = NewPtr;

	m_Count = _CountSize;
	
}

template<typename T>
T& CArr<T>::operator[](int _Index)
{
	return *(this + _Index);
	
}

template<typename T>
typename CArr<T>::iterator CArr<T>::begin()
{

	if (0 == m_Count)
	{
		return iterator(this, m_Ptr, -1);
	}
	return iterator(this, m_Ptr, 0);
}
template<typename T>

typename CArr<T>::iterator CArr<T>::end()
{


		return iterator(this, m_Ptr, -1);
	
}

template<typename T>
typename CArr<T>::iterator CArr<T>::erase(const iterator& _iter)
{

	if (this != _iter.m_pArr || end() == _ite || m_iCount <= _iter.m_iIdxx)
	{
		assert(nullptr);
	}

	int iLoopCount = m_iCount - (_iter.m_iIdx + 1_;)

		for(int i = 0l i < iL)
	return iterator();
}
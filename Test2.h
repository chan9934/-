#pragma once
#include <assert.h>

template <typename T>
class C_Arr
{
private:
	T* m_Ptr;
	int m_Count;
	int m_Max_Count;

public:
	C_Arr();

	~C_Arr();

	void m_Push_back(const T& i_Data);

	void m_Resize(int i_Size);

	T& operator[](int i_Idx)
	{
		return *(m_Ptr + i_Idx);
	}

	class iterator;
	iterator begin();
	iterator end();

public:
	class iterator
	{
	private:
		C_Arr C1;
		T* m_IPtr;
		int m_Idx;

	public:
		iterator()
			: C1(nullptr)
			, m_IPtr(0)
			, m_Idx(0)
		{

		}

		~iterator();


		iterator(C_Arr i_C1, T* i_IPtr, int i_Idx)
			: C1(i_C1)
			, m_IPtr(i_IPtr)
			, m_Idx(i_Idx)
		{

		}

	public:
		iterator& operator ++()
		{
			if (C1->m_Ptr != m_Iptr || -1 == m_Idx)
			{
				assert(nullptr);
			}

			if (C1->m_Count - 1 == m_Idx)
			{
				m_Idx = -1;
			}
			else
			{
				++m_Idx;
			}

			return *this;
		}
		iterator& operator --()
		{
			if (C1->m_Ptr != m_Iptr || 0 == m_Idx)
			{
				assert(nullptr);
			}

		
				--m_Idx;
			

			return *this;
		}
		iterator operator --(int)
		{
			iterator NewPtr = *this;

			--(*this);
			

			return NewPtr;
		}

		bool operator == (const iterator& _otheriter)
		{
			if (m_IPtr == _otheriter.m_IPtr && m_Idx == _otheriter.m_Idx)
			{
				return true;
			}

			return false;
		}

		bool operator != (const iterator& _otheriter)
		{
			return !(*this == _otheriter);
		}

		iterator operator ++(int)
		{
			iterator copy_iter = *this;

			++(*this);

			return copy_iter;
		}

		
		
	};


};

template <typename T>
C_Arr<T>::C_Arr()
	: m_Ptr(nullptr)
	, m_Count(0)
	, m_Max_Count(2)
{
	m_Ptr = new T[2];
}

template <typename T>
C_Arr<T>::~C_Arr()
{
	delete[] = m_Ptr;
}

template<typename T>
void C_Arr<T>::m_Push_back(const T& i_Data)
{
	if (m_Count >= m_Max_Count)
	{
		resize(m_Max_Count * 2);
	}

	
		m_Ptr[m_Count ++ ] = i_Data;
		
	

}

template<typename T>
void C_Arr<T>::m_Resize(int i_Size)
{
	if (i_size <= m_Max_Count)
	{
		assert(nullptr);
	}

	
		T New_Ptr = new T[i_Size];

		for (int i = 0; i < m_Count; ++i)
		{
			New_Ptr[i] = m_Ptr[i];
		}

		delete[] = m_Ptr;

		m_Ptr = New_Ptr;
		m_Max_Count = i_size;
}

template<typename T>
typename C_Arr<T>::iterator C_Arr<T>::begin()
{
	if (0 == m_Count)
	{
		return iterator(this, m_Ptr, -1);
	}

	else
	{
		return iterator(this, m_Ptr, 0);
	}
}

template<typename T>
typename C_Arr<T>::iterator C_Arr<T>::end()
{
	return iterator(this, m_pData, -1);
}  
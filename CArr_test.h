#pragma once
#include <assert.h>
template<typename T>

class CArr
{
	
	T* IData;
	int Count;
	int MaxCount;

public:

	CArr();
	~CArr();

	void Push_Back(int AddData);
	void Resize(int AddCount);
	T& operator[](int Index);
	
	
	
};

template<typename T>
CArr<T>::CArr()
	:IData(nullptr)
	, Count( 0 )
	, MaxCoumt( 2 )
{
	IData = new T[2];
}

template<typename T>
CArr<T>::~CArr()
{
	delete[] IData;
}

template<typename T>
void CArr<T>::Push_Back(int AddData)
{
	if (Count <= MaxCount)
	{
		Resize(MaxCount * 2);
	}
	IData[Count] = AddData;
	++Count;
}

template<typename T>
void CArr<T>::Resize(int AddCount)
{
	if (MaxCount >= AddCount)
	{
		assert(nullptr);
	}
	T* NewData = new<T>[AddCount];

	for (int i = 0; i < Count; ++i)
	{
		NewData[i] = IData[i];
	}
	delete[] IData;

	IData = NewData;
	MaxCount = AddCount;
}

template<typename T>
T& CArr<T>::operator[](int Index)
{
	return IData[Index];
}


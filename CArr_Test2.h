#pragma once
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
	void Push_Back(T* Data);
	void Resize(int AddSize);




};

template<typename T>
CArr<T>::CArr()
	: Ptr(nullptr)
	, m_Count(0)
	, Max_Count(0)
{
	Max_count = 2;
}

template<typename T>
CArr<T>::CArr()
{
	delete[] m_Ptr;
}


template<typename T>
void CArr<T>::Push_Back(T* Data)
{



}
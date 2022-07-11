#include <iostream>
#include <vector>
#include "CArrTemplateIterator.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;

class CTest
{
private:
	int m_i;

public:
	CTest& operator = (const CTest& _other)
	{
		m_i = _other.m_i;
		return *this;
	}

public:
	CTest()
		: m_i(0)
	{
	}
	CTest(int A)
		: m_i(A)
	{
	}

	

	CTest(const CTest& _other)
		: m_i(_other.m_i)
	{

	}
};

int main()
{
	vector<int> CArr;
	CArr.push_back(1);
	CArr.push_back(10);
	CArr.push_back(20);


	
	
	vector<int>::iterator veciter = CArr.begin();

	for (int i = 0; i < 10; ++i)
	{
		CArr.push_back(i);
	}

	
	myVector<int> mymyvector;
	mymyvector.Push_back(1);
	mymyvector.Push_back(2);
	mymyvector.Push_back(2);

	myVector<int>::iterator myiter = mymyvector.begin();
	int ivalue = *myiter;

	veciter = CArr.begin(); 
	int k = 0;

	CTest t1(100);

	


	CTest t2(t1)l;
}
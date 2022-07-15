#include <iostream>
#include <vector>
#include "CArr_Test3.h"

using std::cout;
using std::vector;
using std::cin;
using std::endl;

class CTest
{
private:
	int m_i;

public:
	CTest& operator =(const CTest& _other)
	{
		m_i = _other.m_i;
		return *this;
	}

public:
	CTest(const CTest& _other)
		: m_i(_other.m_i)
	{

	}
};

int main()
{
	vector<int> vecInt;
	vecInt.push_back(100);
	vecInt.push_back(200);
	vecInt.push_back(300);
	vecInt.push_back(400);

	vector<int>::iterator veciter = vecInt.begin();
	veciter = vecInt.erase(veciter);

	return 0;

	for (int i = 0; i < 10; ++i)
	{
		vecInt.push_back(i);
	}

	CArr<int> myvector;
	myvector.Push_back(10);
	myvector.Push_back(20);
	myvector.Push_back(30);

	veciter = vecInt.end();
	*veciter;

	CArr<int>::iterator myiter = myvector.begin();

	for (; myiter != myvector.end(); ++myiter)
	{
		cout << *myiter << endl;
	}

	myiter = myvector.begin();

	int iData = (*myiter++);



	

	return 0;

}
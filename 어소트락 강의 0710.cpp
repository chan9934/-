#include <iostream>
#include <vector>
#include "CArrTemplateIterator.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;

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
}
#include"ArrTest.h"
#include < iostream >
#include < vector >

using namespace std;

int main()
{

	_TArr s1 = {};

	Initialize(&s1);

	for (int i = 0; i < 10; ++i)
	{
		PushBack(&s1, i);
	}

	Release(&s1);


}
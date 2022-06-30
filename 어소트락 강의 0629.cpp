#include <iostream>
#include "CArr.h"

using namespace std;

int amin()
{
	/*tArr arr = {};
	InitArr[&arr];

	PushBack(&arr, 10);
	PushBack(&arr, 20);
	PushBack(&arr, 30);

	ReleaseARr(&Arr);*/

	CArr carr;
	carr.push_back(10);
	carr.push_back(20);
	carr.push_back(30);

	int iData = carr[1];

	carr[1] = 200;

	return 0;
}
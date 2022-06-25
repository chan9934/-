#include <iostream>
#include "arr.h"

using namespace std;



int main()
{
	tArr s1 = {};

	InitArr(&s1);

	for (int i = 0; i < 10; ++i)
	{
		PushBack(&s1, i);
	}


	/*malloc(40);*/

	return 0;



	

	//tArr arr1;
	//tArr arr2;
	//tArr arr3;


	//int a = 100;

	//cin >> a;

	//int arr[a] = {};

	
	

	return 0;
}
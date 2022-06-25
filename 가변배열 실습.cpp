#include <iostream>
#include "ArrARr.h"

using namespace std;

int main()
{
	tArr s1 = {};

	Initialize(&s1);

	for (int i = 0; i < 10; ++i)
	{
		Pusb_Back(&s1, i);
	}
	


	Release(&s1);
}
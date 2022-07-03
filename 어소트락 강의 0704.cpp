#include <iostream>

#include "list_Test.h"

using namespace std;
	
int main()
{
	CList<int> list;

	for (int i = 0; i < 4; ++i)
	{
		list.push_back(i);
	}

	// C printf
	std::cout << "¾È³ç" << 10 << std::endl;

	// C scanf
	int iInput = 0;
	std::cin >> iInput;


	return 0;
}
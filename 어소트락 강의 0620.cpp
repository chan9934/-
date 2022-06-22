#include <iostream>

using namespace std;

int main()
{
	int*pInt = (int*)malloc(100);

	float* pF = (float*)malloc(4);

	int* pI = (int*)pF;

	*pF = 2.4f;

	int i = *pI;
	
	int* pInt = nullptr;

	int a = 0;
	if (cin >> a)
	{
		pInt = (int*)malloc(100);
	}
	
	if (nullptr != pInt)
	{
		free(pInt);
	}

	return 0;
}

//struct MYST
//{
//	int a;
//	float f;
//};
//
//int main()
//{
//	MYST s = {};
//
//	MYST* pST = &s;
//	pST + 1;
//
//	*pST;
//	(*pST).a;
//	(*pST).a = 100;
//	(*pST).f = 3.14f;
//
//	pST->a;
//	pST->f;
//
//
//
//}
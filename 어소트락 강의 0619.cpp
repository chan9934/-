#include <iostream>
#include "Header.h"
#include "common.h"
#include <wchar.h>

using namespace std;

void Test(int a)
{

}

void Test(float a)
{

}

void Test(int a, int b)
{

}

unsigned int GetLength(const wchar_t*_pStr)
{
	//문자 개수 체크 용도
	int i{ 0 };
	while ('\0' != _pStr[i])
	{
		++i;
	}
	return i;
}

int main()
{
	wchar_t szName[10] = L"Raimond";

	/*int iLen = wcslen(szName);*/

	int iLen = GetLength(szName);

	wchar_t szString[100] = L"abc";

	wcscat_s(szString, 100, L"def");

	cout << *szString << endl;

	wcscat_s(szString, 50, L"def");

	cout << *szString << endl;

	return 0;



}
//int main()
//{
//	char szTest[10] = "abc한글";
//	wchar_t szTestW[10] = L"abc한글";
//	
//
//	int a = 0;
//}

//int main()
//{
//	char c = 'a';
//	wchar_t wc = L'a';
//
//	char szChar[10] = { 97, 98, 99, 100, 101, 102 };
//	wchar_t szWChar[10] = L"abcdef";
//
//	wchar_t* pChar = L"abcdef";
//
//	szWChar[1] = 'z';/*
//	pChar[1] = 'z';
//	*(pChar + 1) = 'z';*/
//
//	short arrShort[10] = { 97, 98, 99, 100, 101, 102 };
//
//	
//	cout << szChar << endl;
//	cout << szWChar << endl;
//	cout << arrShort << endl;
//}

//int main()
//{
//	char c = 65;
//	wchar_t wc = 65;
//
//	c = 59;
//	cout << c << endl;
//	c = '12';
//	cout << c << endl;
//	cout << c << endl;
//
//	cout << "459" << endl;
//	cout << sizeof("459") << endl;
//
//}


//
//void Output(const int* pI)
//{
//
//	int i = *pI;
//	
//}
//
//int main()
//{
//
//	void* pVoid = nullptr;
//	{
//		int a = 0;
//		float f = 0.f;
//		double d = 0;
//		long long ll = 0;
//
//		pVoid = &a;
//		pVoid = &f;
//		pVoid = &d;
//		pVoid = &ll;
//
//		//*pVoid + 1;
//	}
//
//
//	int a = 0;
//	Output(&a);
//
//
//	//const int i = 100;
//
//	//int a = 0;
//	//int* pInt = &a;
//
//	//*pInt = 1;
//	//pInt = nullptr;
//
//	//const int* pConstInt = &a;
//	///**pConstInt;
//	//*pConstInt = 100;*/
//
//	//int b = 0;
//	//pConstInt = &b;
//
//	//int* const pIntConst = &a;
//	//*pIntConst = 400;/*
//	//pIntConst = &b;*/
//
//	//const int* const pConstIntConst = nullptr;
//
//	//int const* p = &a;
//	//{
//		/*int a = 0;
//		const int* pInt = &a;
//
//		a= 100;*/
//
//	
//
//}


//int main()
//{
//	volatile const int cint = 100;
//
//	int* pInt;
//
//	int ii = 10;
//
//	pInt = (int*)&cint;
//	*pInt = 300;
//	cout << cint;
//
//}
// 전역 변수
//int g_i = 0;
//
//// 정적 변수
//static int g_iStatic = 0;
//
//int Test()
//{
//	static int i = 0;
//
//	++g_i;
//	++i;
//	int a = 0;
//
//	return i;
//}
//
//int main()
//{
//	Test();
//	Test();
//	Test();
//	Test();
//	Test();
//
//	g_i = 0;
//
//	cout << g_i;
//
//}

//void name()
//{
//}
//void name()
//{
//}
//
//
//int main()
//{
//	cout << Add(3, 4);
//}

//int Add(int a, int b)
//{
//	return a + b;
//}

////전역변수
//int g_i = 0;
//
//void Test()
//{
//	++g_i;
//}
//
//int main()
//{
//
//	int a = 0;
//	Test();
//	Test();
//	Test();
//	Test();
//	return 0;
//}

//struct _tagMyST
//{
//	int a;
//	float f;
//};
//
//typedef struct _tagMyST
//{
//	int a;
//	float f;
//} MYST;
//
//
//
//struct _TagBig
//{
//	_tagMyST k;
//	int i;
//	char c;
//};
//
//typedef int INT;
//
//int main()
//{
//	int arr[10] = { 1, 2, 3, 4, 5, 6 };
//	
//	MYST t = { 100, 3.14f };
//
//	t.a = 10;
//
//	_tagMyST MYST;
//	_TagBig BIG;
//
//	float f = 10.2415f + (float)20;
//
//	MYST.a;
//
//	cout << sizeof(MYST) << endl;
//}

//int Fibonacci(int _iNum)
//{
//	if (1 == _iNum || 2 == _iNum)
//	{
//		return 1;
//	}
//
//	int iPrev1 = 1;
//	int iPrev2 = 1;
//	int iValve = 0;
//	for (int i = 0; i < _iNum - 2; ++i)
//	{
//		iValve = iPrev1 + iPrev2;
//		iPrev1 = iPrev2;
//		iPrev2 = iValve;
//
//;	}
//
//	return iValve;
//}
//
//int Fibonacci_Re(int _iNum)
//{
//	if (1 == _iNum || 2 == _iNum)
//	{
//		return 1;
//	}
//
//	return Fibonacci_Re(_iNum-1) + Fibonacci_Re(_iNum-2)
//}
//
//
//int main()
//{
//	int iValue = 0;
//
//	iValue = Fibonacci(1);
//
//	return 0;
//}

//int Factorial(int _iNum)
//{
//
//	int iValue = 1;
//	for (int j = 0; j < _iNum - 1; ++j)
//	{
//		iValue *= (j + 2);
//	}
//
//	return iValue;
//}
//int Factorial_Re(int _iNum)
//{
//	if (1 == _iNum)
//	{
//		return 1;
//	}
//
//	return _iNum* Factorial_Re(_iNum - 1);
//}
//
//
//
//int main()
//{
//	int iValue = Factorial(4);
//	iValue = Factorial(1);
//
//	iValue = Factorial_Re(10);
//	cout << iValue;
//
//		return 0; 
//}
//void Test(int a)
//{
//	a = 500;
//}
//int main()
//{
//	int a = 100;
//
//	Test(a);
//
//	cout << a;
//}

//int main()
//{
//	/*int i = 100;
//	float f = 3 / f;
//
//	int* pInt = &i;*/
//
//	/*int* pInt = nullptr;
//
//	char* pChar = nullptr;
//	char* pShort = nullptr;
//
//	int isize = sizeof(pInt);
//
//	int i = 0;
//	pInt = &i;
//	cout << pInt << endl;
//	pInt += 1;
//	cout << pInt << endl;*/
//
//	//int iArr[10] = {};
//
//	//*(iArr + 0) = 10; // = iArr[0]
//	//*(iArr + 1) = 10; // = iArr[0]
//	//cout << iArr[0] << endl;
//	//cout << iArr[1] << endl;
//
//	short sArr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9,10 };
//
//	int* pI = (int*)sArr;
//
//	int iData = *(short*)(pI + 2);
//		
//	char cArr[2] = { 1, 1 };
//	short* pS = (short*)cArr;
//
//	iData = *pS;
//
//	
//	
//}
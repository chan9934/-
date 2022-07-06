#include <iostream>



//class CTest
//{
//
//
//
//	static void MemberFunc()
//	{
//		
//	}
//};

using std::cin;
using std::cout;
using std::wcout;
using std::endl;
void MyEndL()
{
	wprintf(L"\n");
}
class CMyOstream
{

public:
	CMyOstream& operator << (int _idata)
	{
		printf("%d", _idata);
		return *this;
	}

	CMyOstream& operator << (const wchar_t* _pString)
	{
		printf("%s", _pString);
		return *this;
	}

	CMyOstream& operator >> (int& _idata)
	{
		scanf_s("&d", &_idata);
		return *this;
	}

	CMyOstream& operator << (void(*Func)())
	{
		Func();
		return *this;
	}
};

CMyOstream mycout;

namespace MYSPACE
{
	int g_int;
}

namespace OHTERSPACE
{
	int g_int;
}
//
//using namespace MYSPACE;

using std::cout;
using std::cin;

int main()
{
	MYSPACE::g_int = 0;

	cout << "¾È³ç" << 10 << endl;
	wcout << L"¾È³ç" << 10;

	setlocale(LC_ALL, "korean");
	_wsetlocale(LC_ALL, L"korean");

}
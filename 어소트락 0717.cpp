#include <iostream>

#include <map>
#include <set>
#include <string>
#include "CBST.h"

using std::map;
using std::make_pair;
using std::wcout;
using std::endl;

using std::set;
using std::wstring;



#define MAN		1
#define WOMAN	2

struct tStdInfo
{
	wchar_t szName[20];
	unsigned char age;
	unsigned char gender;

	tStdInfo()
		: szName{}
		, age(0)
		, gender(0)
	{

	}
	tStdInfo(const wchar_t* _pName, unsigned char _age, unsigned char _gender)
		: szName{}
		, age(_age)
		, gender(_gender)
	{
		wcscpy_s(szName, _pName);
	}
};

class MyClass
{
private:
	int a;

public:
	bool operator < (const MyClass& _other) const
	{
		if (a < _other.a)
			return true;
		else
			return false;
	}

};

struct pair
{
	const wchar_t*		first;
	tStdInfo			second;
};

//열거형
enum class MY_TYPE
{
	TYPE_1, //0
	TYPE_2, //1
	TYPE_3, //2
	TYPE_4, //3
	TYPE_5 = 100,
	TYPE_6  //101
};

enum class OTHER_TYPE
{
	TYPE_1,
};

#define CLASS_1 0
#define CLASS_2 1
#define CLASS_3 2
#define CLASS_4 3
#define CLASS_5 4

int main()
{
	int a = (int)MY_TYPE::TYPE_1;
	int b = CLASS_1;

	set<int> setInt;

	setInt.insert(100);
	setInt.insert(50);
	setInt.insert(150);

	const wchar_t* poStr = L"문자열";

	map<const wchar_t*, tStdInfo> mapData;

	tStdInfo info(L"홍길동", 18, MAN);
	tStdInfo info2(L"이지혜", 25, WOMAN);

	mapData.insert(make_pair(L"홍길동", info));
	mapData.insert(make_pair(L"이지혜", info2));

	wchar_t szFind[20] = L"이지혜";


	map<const wchar_t*, tStdInfo>::iterator mapiter;
	mapiter = mapData.find(szFind);



	_wsetlocale(LC_ALL, L"korean");

	//찾지 못했다
	if (mapiter == mapData.end())
	{
		wcout << L"데이터를 찾을 수 없다." << endl;

	}
	else
	{
		wcout << L"이름 : " << mapiter->second.szName << endl;
		wcout << L"나이 : " << mapiter->second.age << endl;
		wcout << L"성별 : ";
		if (MAN == mapiter->second.gender)
		{
			wcout << L"남자" << endl;

		}
		else if (WOMAN == mapiter->second.gender)
		{
			wcout << L"여자" << endl;
		}
		else
		{
			wcout << L"알 수 없음" << endl;
		}
	}

	////MyClass a;
	////map<MyClass, tStdInfo> mapStdInfo;
	//mapStdInfo.insert(make_pair(a, info));


	wstring str;

	str = L"abcdef";
	str += L"hijk";
	str += L"lmnop";
	str[1] = L'c';

	str = L"sdafsdafsdafsdafdsafasdfasdf";

	wstring str2;

	if (str < str2)
	{

	}

	CBST<int, int> bstint;
	bstint.insert(make_bstpair(100, 0));
	bstint.insert(make_bstpair(150, 0));
	bstint.insert(make_bstpair(50, 0));

	CBST<int, int>::iterator Iter = bstint.begin();
	Iter = bstint.find(150);

	map<int, int> mapInt;
	mapInt.insert(make_pair(100, 100));

	map<int, int>::iterator iter = mapInt.find(100);
	if (iter == mapInt.end())
	{

	}

	return 0;
}
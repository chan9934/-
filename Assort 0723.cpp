#include <iostream>

#include <map>
#include <set>
#include <string>
#include "CBST.h"

using std::map;
using std::make_pair;
using std::wcout;
using std::endl;
using std::cout;

using std::set;
using std::wstring;

int main()
{
	CBST<int, int> bstInt;
	bstInt.insert(make_bstpair(100, 0)); //       100
	bstInt.insert(make_bstpair(150, 0)); //   50       150
	bstInt.insert(make_bstpair(50, 0)); // 25   75  125    175
	bstInt.insert(make_bstpair(25, 0)); 
	bstInt.insert(make_bstpair(75, 0)); 
	bstInt.insert(make_bstpair(125, 0));
	bstInt.insert(make_bstpair(175, 0));

	CBST<int, int>::iterator Iter = bstInt.begin();
	Iter = bstInt.find(100);
	

	Iter = bstInt.erase(Iter);
	cout << Iter->first;

}
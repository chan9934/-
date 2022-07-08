#include <vector>
#include <list>
#include <iostream>

using std::vector;
using std::cout;
using std::list;
using std::endl;


template<typename T>
class Arr
{
	T* m_pData;
	int m_iCount;
	int m_iMaxCount;
public:
	T* data() {
		return m_pData;
	}
	int size()
	{
		return m_iCount;
	}
	int capacity
	{
		return m_iMaxCount; 
	}
		
		
};
	
int main()
{
	vector<int> vecInt;

	vecInt.push_back(10);
	vecInt.push_back(20);

	list<int> listInt;
	listInt.push_back(10);
	listInt.push_front(100);
	listInt.size();

	vecInt[0] = 100;
	cout << vecInt.at(1);
	cout << vecInt[1];
	vecInt.size();
	vecInt.capacity();

	for (size_t i = 0; vecInt.size(); ++i)
	{
		cout << vecInt.at(i);
		cout << vecInt.[i];
	}

	list<int>::iterator iter = listInt.begin();
	int iData = *iter;





	return 0;
}
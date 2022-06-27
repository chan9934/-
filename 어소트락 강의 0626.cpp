#include <iostream>
#include "ArrTest3.h"
using namespace std;
//void BubbleSort(int* _pData, int _iCount)
//{
//	if (_iCount <= 1)
//		return;
//
//	while (1)
//	{
//	
//
//		bool bFinish = true;
//
//		int Loop = _iCount - 1;
//
//		for (int i = 0; i < Loop; ++i)
//		{
//			if (_pData[i] > _pData[i + 1])
//			{
//				int temp = _pData[i];
//				_pData[i] = _pData[i + 1];
//				_pData[i + 1] = temp;
//
//				bFinish = false;
//			}
//
//		}
//
//		if (bFinish == true)
//			break;
//
//	}
//}
void BubbleSort(int* Ptr, int Count)
{
	if (Count <= 1)
		return;
	bool bFinish = true;
	while(1)
	{
	for (int i = 0; i < Count-1; ++i)
	{
		if (Ptr[i] > Ptr[i + 1])
		{
			int temp = Ptr[i];
			Ptr[i] = Ptr[i + 1];
			Ptr[i + 1] = temp;
			bFinish = false;
	}
		if (bFinish)
		{
			break;
		}
}

void Test()
{

}

int main()
{







	void(*pFunc)(void) = nullptr;
	pFunc = Test;

	pFunc();



	/*int iArr[10] = { 87, 644, 21, 55, 879, 654, 55, 131, };*/

	/*BubbleSort(iArr, 10);*/
	tArr s1 = {};

	Initialize(&s1);

	for (int i = 0; i < 10; ++i)
	{
		
		int num = (rand() % 100 + 1);
	
		Push_Back(&s1, num);
	}

	cout << "sort 전의 가변배열" << endl;
	for (int i = 0; i < s1.Count; ++i)
	{
		cout << s1.IPtr[i] << endl;
	}


	sort(&s1, BubbleSort);



	cout << "sort 후의 가변배열" << endl;
	for (int i = 0; i < s1.Count; ++i)
	{
		cout <<s1.IPtr[i] << endl;
	}
	Release(&s1);


}
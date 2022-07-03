#include <iostream>

using namespace std;
class CTest
{
private:
	int a;
public:
	CTest()
		: a(10)
	{

	}
};

int Add(int a, int b)
{
	return a + b;
}
int Add(float a, float b)
{
	return a + b;
}

template<typename T>
T Add(T a, T b)
{
	return a + b;
}

int main()
{
	int i = Add(10, 20);

}
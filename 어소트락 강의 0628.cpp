#include <iostream>

using namespace std;

class CMy
{
private:
	int m_i;
	float m_f;



public:

	CMy() :m_i(100), m_f(3.14)
	{
	}

	~CMy()
	{
	}


	void SetInt(int i)
	{
		m_i = i;
	}

	// 대입 연산자
	CMy& operator=(const CMy& _Other)
	{
		m_i = _Other.m_i;
		m_f = _Other.m_f;
		return *this;
	}
};

int main()
{
	int i = 0;
	int i2 = 5;
	int i3 = 10;
	i = i2 = i3;

	CMy c;
	c.SetInt(10);
	CMy c2;
	c2.SetInt(100);
	CMy c3;
	c3.SetInt(1000);

}
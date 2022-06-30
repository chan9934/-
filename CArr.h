#pragma once

class CArr
{

private:
	int* m_pInt;
	int m_iCount;
	int m_iMaxCount;

public:
	void push_back(int _Data);
	void resize(int iResizeCount);

	int& operator[] (int idx);

public:
	CArr();
	~CArr();

};


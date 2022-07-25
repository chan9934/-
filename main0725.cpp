#include <iostream>

using std::cout;
using std::endl;

class CParent
{
protected:
	int m_i;

public:
	void SetInt(int _a)
	{
		m_i = _a;
	}

	
	virtual void Output()
	{
		cout << "Parent" << endl;
	}

public:
	CParent()
		: m_i(0)
	{

		cout << "�θ� ������" << endl;
	}

	CParent(int _a)
		: m_i(_a)
	{

	}
	~CParent()
	{
		cout << "�θ� �Ҹ���" << endl;
	}		
};

class CChild : public CParent
{
private:
	float m_f;
	
public:
	void SetFloat(float _f)
	{
		m_f = _f;
		m_i = 100;
	}

	// ��ӹ��� �θ�Ŭ������ �Լ��� ������(�������̵�) ��
	void Output()
	{
		cout << "Child" << endl;
	}

public:

	CChild()
		: m_f(0.f)
	{

		cout << "�ڽ� ������" << endl;
	}

	~CChild()
	{
		cout << "�ڽ� �Ҹ���" << endl;
	}
};

void FuncA()
{
	cout << "Function A" << endl;
}

void FuncB()
{
	FuncA(); 

	cout << "Function B" << endl;
}

int main()
{
	FuncB();
	// ��ü���� ��� Ư¡
	// 1. ĸ��ȭ (���м�)
	// 2. ���
	// 3. ������
	// 4. �߻�ȭ

	/*CParent parent;
	parent.Output();

	CChild child;
	child.CParent::Output();

	parent.SetInt(10);
	child.SetInt(10);*/

	// ���
	// �ڽ� or �θ� Ŭ������ ��Ӱ��迡�� �ٸ� Ŭ������ ����� �ʱ�ȭ �� �� ����.
	// ������ ȣ�� ���� �ڽ� -> �θ�
	// ������ �ʱ�ȭ(����) ���� �θ� -> �ڽ�
	// ���� ���̵�

	// �Ҹ��� ���� �� ȣ�� ����, �ڽ�->�θ�

	// ���� ���̵�
	// �θ� Ŭ������ ����Լ��� �ڽ��ʿ��� ������ �����ν�, �ڽ� Ŭ������ ������ ����� ȣ��ǵ��� �Ѵ�.

	// ��� And ������

	CParent parent;
	CChild child;

	child.Output();
	child.SetInt(10);
	CParent* pParent = &parent; 
	CChild* pChild = &child;

	/*CParent* pParent = &child;*/
	//CChild* pChild = &parent;  --(2) ����

	parent.Output();
	child.Output();

	CParent* pParent = nullptr;

	parent.Output();
	pParent = &parent;
	pParent->Output();

	child.Output();
	pParent = &child;
	pParent->Output();
	((CChild*)pParent->NewFunc();

	CChild* pChild = dynamic_cast<CChild*>(pParent);
	if (nullptr == pChild)
	{
		int a = 0;
	}

	// ������, �����Լ�(virtual)
	// �θ� ������ Ÿ������, �θ� Ŭ�����κ��� �Ļ��Ǵ� �ڽ�Ŭ���� ��ü���� �ּҸ� ����ų �� �ִ�.
	// ��� ��ü�� �θ� Ŭ���� Ÿ������ �ν��ϰ� �Ǳ� ������, ���� ��ü�� �������� �� �� ����.
	// virtual Ű���带 ���ؼ�, �� Ŭ������ �ڽŸ��� ������ �����Լ� ���̺��� ������ �ȴ�.
	// �� Ŭ������ ��ü���� �����Լ� ���̺� �����Ϳ��� �ش� Ŭ������ �´� ���̺��� ����Ű�� �ȴ�
	// �� ���̺��� �ش� Ŭ������ �����Լ����� ����Ѵ�
	

	// �ٿ� ĳ����
	//  �θ� Ŭ�������� ������� ����, ���� �ڽ��ʿ����� �߰��� �Լ��� ȣ�� �ϰ� ���� ��
	// �ڽ� ������Ÿ������ �Ͻ������� ĳ���� �ؼ� ȣ���Ѵ�.
	// ������ �߻� �� �� �ֱ� ������ dynamic_cast�� �����ϰ� Ȯ���� �� �� �ִ�.
	// RTTI(Run Time Type Identification or Information)
	
	// �߻�ȭ
	// ���� ��ü�� ������ ������ Ŭ������ �ƴ�, ����� ���ؼ� �����ؾ��� ������ �����ϴ� ��� �������� ������� Ŭ����
	// virtual , = 0 (1�� �̻��� ���������Լ��� �����ϸ� �߻�Ŭ������ �ȴ�)

	return 0;
}
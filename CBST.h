#pragma once



template<typename T1, typename T2>
struct tPair
{
	T1 first;
	T2 Second;
};

template<typename T1, typename T2>
struct tBSTNode
{
	tPair<T1, T2> Pair;
	tBSTNode* pParent;
	tBSTNode* pLeftChild;
	tBSTNode* pRightChild;

};


template <typename T1, typename T2>
class CBST
{ 
private:
	tBSTNode<T1, T2>*	m_pRoot; // ��Ʈ ��� �ּ�
	int			m_iCount;// ������ ����

public:
	bool insert(const tPair<T1, T2>& _pair);

public:
	CBST()
		: m_pRoot(nullptr)
		, m_iCount(0)
	{

	}
};

template<typename T1, typename T2>
inline bool CBST<T1, T2>::insert(const tPair<T1, T2>& _pair)
{
	tBSTNode<T1, T2>* pNewNode = new tBSTNode<T1, T2>();

	pNewNode->Pair = _pair;

	pNewNode->pParent = nullptr;
	pNewNode->pLeftChild = nullptr;
	pNewNode->pRightChild = nullptr;

	// ù���� ������ ���
	if (nullptr == m_pRoot)
	{
		m_pRoot = pNewNode;
	}

	else
	{

		tBSTNode<T1, T2>* pNode = m_pRoot;
		while (true)
		{
			
			if (pNode->Pair.first < pNewNode->Pair.first)
			{
				if (nullptr == pNode->pRightChild)
				{
					pNode->pRightChild = pNewNode;
					pNewNode->pParent = pNode;
					break;

				}
				else 
				{
					pNode = pNode->pRightChild;
				}
			}

			else if (pNode->Pair.first > pNewNode->Pair.first)
			{
				if (nullptr == pNode->pLeftChild)
				{
					pNode->pLeftChild = pNewNode;
					pNewNode->pParent = pNode;
					break;

				}
				else
				{
					pNode = pNode->pLeftChild;
				}
			}
			else
			{
				return false;
			}
		}

	}
	++m_iCount;

	return true;
}

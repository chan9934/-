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
	tPair<T1, T2> pair;
	tBSTNode<T1, T2>* pParent;
	tBSTNode<T1, T2>* pLeftChild;
	tBSTNode<T1, T2>* pRightChild;

	tBSTNode(const tPair<T1, T2>& _pair)
		: Pair()
		, pParent(nullptr)
		, pLeftChild(nullptr)
		, pRightChild(nullptr)
	{
		Pair = _pair;
	}

	
};

template<typename T1, typename T2>
class CBST
{
private:
	tBSTNode<T1, T2>* m_pRoot;
	int m_iCount;

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
bool CBST<T1, T2> ::insert(const tPair<T1, T2>& _pair)
{
	tBSTNode<T1, T2>* pNewNode = new tBSTNode<T1, T2>(_pair);

	if (nullptr == m_pRoot)
	{
		m_pRoot = pNewNode;
	}

	else
	{
		tBSTNode<T1, T2>* pNode = m_pRoot;
		while (true)
		{
			if (pNode->Pair.first < pNewNode->pair.first)
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

			else if (pNode->pair.first > pNewNode->pair.first)
			{
				if (nullptr == pNode->pLeftChild)
				{
					pNode->pLeftChild = pNewNode;
					pNewNode->pParent = pNode;
				}
				else
				{
					pNode = pNode->pRightChild;
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
#pragma once
enum class NODE_TYPE
{
	PARENT,
	LCHILD,
	RCHILD,
	End
};

template<typename T1, typename T2>
struct tPair
{
	T1 First;
	T2 Second;
	
public:
	tPair<T1, T2> make_bstpair(const T1& _first, const T2& _second)
	{
		return tPair<T1, T2>{_first, _second};
		// 임시객체로 초기화 동시에 리턴
	}
};

template<typename T1, typename T2>
struct tBSTNode
{
	tPair<T1, T2>Pair;
	tBSTNode<T1, T2>* arrNode[(int)NODE_TYPE::End];

	tBSTNode()
		: tpair()
		, arrNode{}
	{

	}
	tBSTNode(const tPair<T1, T2>& _pair, tBSTNode* _pParent, tBSTNode* _pLChild, tBSTNode* _pRchild_)
		: Pair(_pair)
		, arrNode{ _pParent , _pLChild,  _pRChild }
	{

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

	class iterator;
public:
	iterator begin();
	iterator end();
	iterator find(const T1& _find);

public:
	CBST()
		: m_pRoot(nullptr)
		, m_iCount(0)
	{

	}
	class iterator
	{
	private:
		CBST<T1, T2>* m_pBST;
		tBSTNode<T1, T2>* m_pNode;

	public:
		iterator()
			: m_pBST(nullptr)
			, m_pNode(nullptr)
		{

		}

		iterator(CBST<T1, T2>* _pBST, tBSTNode<T1, T2>* _pNode)
			: m_pBST(_pBST)
			, m_pNode(_pNode)
		{

		}
	};
};

template<typename T1, typename T2>
bool CBST<T1, T2>::insert(const tPair<T1, T2>& _pair)
{
	tBSTNode<T1, T2>* pNewNode = new tBSTNode<T1, T2>(_pair, nullptr, nullptr, nullptr);

	if (nullptr == m_pRoot)
	{
		m_pRoot = pNewNode;
	}

	else
	{
		tBSTNode<T1, T2>* pNode = m_pRoot;
		NODE_TYPE node_type = NODE_TYPE::End;

		while (true)
		{
			if (pNode->Pair.First < pNewNode->Pair.First)
			{
				node_type = NODE_TYPE::RCHILD;
			}

			else if (pNode->Pair.First > pNewNode->Pair.First)
			{
				node_Type = NODE_TYPE::LCHILD;
			}
			else
			{
				return false;
			}

			{
				if (nullptr == pNode->arrNode[(int)node_type])
				{
					pNode->arrNode[(int)node_Type] = pNewNode;
					pNewNode->arrNode[(int)NODE_TYPE::PARENT] = pNode;
					break;
				}

				else
				{
					pNode = pNode->arrNode[(int)node_type];
				}
			}
		}

	}
	++m_iCount;

	return true;
}

template<typename T1, typename T2>
typename CBST<T1, T2>::iterator CBST<T1, T2>::begin()
{
	tBSTNode<T1, T2>* pNode = m_pRoot;
	while (pNode->arrNode[(int)NODE_TYPE::LCHILD])
	{
		pNode = pNode->arrNode[(int)NODE_TYPE::LCHILD];
	}
	return iterator(this, pNode);
}

template<typename T1, typename T2>
typename CBST<T1, T2>::iterator CBST<T1, T2>::end()
{
	return iterator(this, nullptr);
}

template<typename T1, typename T2>
typename CBST<T1, T2>::iterator CBST<T1, T2>::find(const T1& _find)
{
	tBSTNode<T1, T2>* PNode = m_pRoot;
	NODE_TYPE node_Type = NODE_TYPE::End;

	while (true)

	{
		if (pNode->Pair.First < _find)
		{
			node_Type = NODE_TYPE::RCHILD;
		}
		else if (pNode->Pair.First > _find)
		{
			node_Type = NODE_TYPE::LCHILD;
		}
		else
		{
			break;
		}

		if (nullptr == pNode->arrNode[(int)node_Type])
		{
			pNode = nullptr;
			break;
		}
		else
		{
			pNode = pNode->arrNode[(int)node_type];
		}
	}

	return iterator(this, pNode);

}
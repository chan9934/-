#pragma once
#include <assert.h>

enum class NODE_TYPE
{
	PARENT,
	LCHILD,
	RCHILD,
	END
};
template<typename T1, typename T2>
struct tPair
{
	T1 First;
	T2 Second;
};

template<typename T1, typename T2>
tPair<T1, T2> make_bstpair(const T1& _first, const T2& _second)
{
	return tPair<T1, T2> {_first, _second};
}

template<typename T1, typename T2>
struct tBSTNode
{
	tPair<T1, T2> Pair;
	tBSTNode<T1, T2>* arrNode[NODE_TYPE::END];

	bool IsRoot()
	{
		if (nullptr == arrNode[NODE_TYPE::PARENT]
			{
				return false;
			}
		return true;
	}

	bool IsLeftChild()
	{
		if (arrNode[NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::LCHILD] == this)
		{
			return true;
		}

		return false;
	}

	bool IsRightChild()
	{
		if (arrNode[NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::RCHILD] == this)
		{
			return true;
		}
		return false;
	}

	bool IsLeaf()
	{
		if (nullptr == arrNode[NODE_TYPE::LCHILD] && nullptr == arrNode[NODE_TYPE::RCHILD])
		{
			return true;
		}
		return false;
	}
	bool IsFull()
	{
		if (arrNode[NODE_TYPE::LCHILD] && arrNode[NODE_TYPE::RCHILD])
		{
			return true;
		}
		return false;
	}

	tBSTNode()
		: Pair()
		, arrNode{}
	{
	}

	tBSTNode(const tPair<T1, T2>& _pair, tBSTNode* _pParent, tBSTNode* _pLChild, tBSTNode* = _pChild)
		: Pair(_pair)
		, arrNode{ _pParent, _pLChild, _pRChild }
	{

	}

};

template <typename T1, typename T2>
class CBST
{
private:
	tBSTNode<T1, T2>* m_pRoot;
	int m_iCount;

public:
	bool insert(const tPair<T1, T2>& _pair);
	tBSTNode<T1, T2>* GetInOrderSuccessor(tBSTNode<T1, T2>* _pNode);
	tBSTNode<T1, T2>* GetInOrderPredecessor(tBSTNode<T1, T2>* _pNode);

	class iterator;

public:
	iterator begin();
	iterator end();
	iterator find(const T1& _find);
	iterator erase(const iterator& _iter);

private:
	tBSTNode<T1, T2>* DeleteNode(tBSTNode<T1, T2>* _pTargetNode);

public:
	CBST()
		: m_pRoot(nullptr)
		, n_iCount(0)
	{

	}

	class iterator
	{
	private:
		CBST<T1, T2>* m_pBST;
		tBSTNode<T1, T2>* m_pNode;

	public:
		bool operator == (const iteraotr& _other)
		{
			if (m_pBST == _other.m_pBST && m_pNode == _other.m_pNode)
			{
				return true;
			}
			return false;
		}

		bool operator != (const iterator& _other)
		{
			return !(*this == other);
		}

		const tPair<T1, T2>& operator *()
		{
			assert(m_pNode);
			return m_pNode->Pair;
		}

		const tPair<T1, T2>* operator ->()
		{
			assert(m_pNode);
			return &m_pNode->Pair;
		}

		iterator& operator ++()
		{
			m_pNode = m_pBST->GetInOrderPredecessor(m_pNode);
			return *this;
		}

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

		friend class CBST<T1, T2>;

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
		NODE_TYPE node_type = 3;

		while (true)
		{
			if (pNode->Pair.First < pNewNode->Pair.First)
			{
				node_type = NODE_TYPE::RCHILD;
			}

			else if (pNode->Pair.First > pNewNode->Pair.First)
			{
				node_type = NODE_TYPE::LCHILD;
			}
			else
			{
				return false;
			}
			{
				if (nullptr == pNode->arrNode[(int)node_type])
				{
					pNode->arrNode[(int)node_type] = pNewNode;
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
	++m_icount;

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

template <typename T1, typename T2>
typename CBST<T1, T2>::iterator CBST<T1, T2>::find(const T1& _find)
{

	tBSTNode<T1, T2>* pNode = m_pRoot;
	NODE_TYPE node_type = NODE_TYPE::END;

	while (true)
	{
		if (pNode->Pair.first < _find)
		{
			node_type = NODE_TYPE::RCHILD;
		}
		else if (pNode->Pair.First > _find)
		{
			node_type = NODE_TYPE::LCHILD;
		}
		else
		{
			break;
		}

		if (nullptr == pNode->arrNode[(int)node_type])
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

template<typename T1, typename T2>
tBSTNode<T1, T2>* CBST<T1, T2>::GetInOrderPredecessor(tBSTNode<T1, T2>* _pNode)
{
	tBSTNode<T1, T2>* pSuccessor = _pNode;
	if (nullptr != _pnode->arrNode[(int)NODE_TYPE::RCHLID])
	{
		pSuccessor = _pNode->arrNode[(int)NODe_TYPE::RCHILD];
		while (pSuccessor->arrNode[(int)NODE_TYPE::LCHILD])
		{
			pSuccessor = pSuccessor->arrNode[(int)NODE_TYPE::LCHILD];
		}
	}

	else
	{
		pSuccessor = _pNode;
		while (true)
		{
			if (pSuccessor->IsRoot())
			{
				return nullptr;
			}

			if (pSuccessor->IsLeftChild())
			{
				pSuccessor = pSuccessor->arrNode[(int)NODE_TYPE::PARENT];
				break;
			}

			else
			{
				pSuccessor = pSuccessor->arrNode[(int)NODE_TYPE::PARENT];
			}
		}
	}
	return pSuccessor;
}

template<typename T1, typename T2>
tBSTNode<T1, T2>* CBST<T1, T2> ::GetInOrderPredecessor(tBSTNode<T1, T2>* _pNodE)
{
	return nullptr;

	template<typename T1, typename T2>
	typename CBST<T1, T2> ::iterator CBST<T1, T2>::erase(const iterator & _iter)
	{
		assert(this == _iter.m_pBST);

		tBSTNode<T1, T2>* pSuccessor = DeleteNode(_iter.m_pNode);
		return iterator(This, pSuccessor);
	}
}

template<typename T1, typename T2>
tBSTNode<T1, T2>* CBST<T1, T2>::DeleteNode(tBSTNode<T1, T2>* _pTargetNode)
{
	tBSTNode<T1, T2>* pSuccessor = nullptr;
	if (_pTargetNode->IsLeaf())
	{
		pSuccessor = GetInOrderSuccessor(_pTargetNode);
		if (_pTargetNode == m_pRoot)
		{
			m_pRoot = nullptr;
		}
		else
		{
			if (_pTargetNode->IsLeftChild())
			{
				_pTargetNode->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::LCHILD] = nullptr;
			}
			else
			{
				_pTargetNode->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::RCHILD] = nullptr;
			}
		}
		delete _pTargetNode;
	}
	else if (_pTArgetNode->IsFull())
	{
	}
	else
	{
	}
	--m_iCount;

	return pSuccessor
}
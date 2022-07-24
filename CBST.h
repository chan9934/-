#pragma once
#include <assert.h>
enum class NODE_TYPE
{
	PARENT, //0
	LCHILD, //1
	RCHILD, //2
	END,	//3
};

template<typename T1, typename T2>
struct tPair
{
	T1 first;
	T2 Second;
};

template<typename T1, typename T2>
tPair<T1, T2> make_bstpair(const T1& _first, const T2& _second)
{
	return tPair<T1, T2>{_first, _second};

}

template<typename T1, typename T2>
struct tBSTNode
{
	tPair<T1, T2> Pair;

	tBSTNode* arrNode[(int)NODE_TYPE::END];

	bool IsRoot()
	{
		if (nullptr == arrNode[(int)NODE_TYPE::PARENT])
			return false;
		return false;
	}

	bool IsLeftChild()
	{
		if (arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::LCHILD] == this)
		{
			return true;
		}

		return false;
	}

	bool IsRightChild()
	{
		if (arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::RCHILD] == this)
		{
			return true;
		}

		return false;
	}

	bool IsLeaf()
	{
		if (nullptr == arrNode[(int)NODE_TYPE::LCHILD] && nullptr == arrNode[(int)NODE_TYPE::RCHILD]
			{
				return true;
			}
		return false;
	}

	bool IsFull()
	{
		if (arrNode[(int)NODE_TYPE::LCHILD] && arrNode[(int)NODE_TYPE::RCHILD])
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

	tBSTNode(const tPair<T1, T2>& _pair, tBSTNode* _pParent, tBSTNode* _pLChild, tBSTNode* _pRChild)
		: Pair(_pair)
		, arrNode{ _pParent, _pLChild, _pRChild }
	{}

};


template <typename T1, typename T2>
class CBST
{
private:
	tBSTNode<T1, T2>* m_pRoot; // ��Ʈ ��� �ּ�
	int			m_iCount;// ������ ����

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
		, m_iCount(0)
	{

	}
	// iterator
	class iterator
	{
	private:
		CBST<T1, T2>* m_pBST;
		tBSTNode<T1, T2>* m_pNode; // null �ΰ�� end iterator

	public:
		bool operator ==(const iterator& _other)
		{
			if (m_pBST == _other.m_pBST && m_pNode == _other.m_pNode)
			{
				return true;
			}
			return false;
		}

		bool operator != (const iterator& _other)
		{
			return !(*this == _other);
		}

		const tPair<T1, T2>& operator *()
		{
			//m_pNode nullptr üũ (end iterator ���� �ƴ���)
			assert(m_pNode);
			return m_pNode->Pair;
		}
		const tPair<T1, T2>* operator ->()
		{
			//m_pNode nullptr üũ (end iterator ���� �ƴ���)
			assert(m_pNode);
			return &m_pNode->Pair;
		}

		iterator& operator ++()
		{
			m_pNode = m_pBST->GetInOrderSuccessor(m_pNode);
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
inline bool CBST<T1, T2>::insert(const tPair<T1, T2>& _pair)
{
	tBSTNode<T1, T2>* pNewNode = new tBSTNode<T1, T2>(_pair, nullptr, nullptr, nullptr);


	// ù���� ������ ���
	if (nullptr == m_pRoot)
	{
		m_pRoot = pNewNode;
	}

	else
	{

		tBSTNode<T1, T2>* pNode = m_pRoot;
		NODE_TYPE node_type = NODE_TYPE::END;

		while (true)
		{

			if (pNode->Pair.first < pNewNode->Pair.first)
			{

				node_type = NODE_TYPE::RCHILD;
			}
			else if (pNode->Pair.first > pNewNode->Pair.first)
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
	++m_iCount;

	return true;
}

template<typename T1, typename T2>
inline typename CBST<T1, T2>::iterator CBST<T1, T2>::begin()
{
	tBSTNode<T1, T2>* pNode = m_pRoot;

	while (pNode->arrNode[(int)NODE_TYPE::LCHILD])
	{
		pNode = pNode->arrNode[(int)NODE_TYPE::LCHILD];
	}
	return iterator(this, pNode);
}

template<typename T1, typename T2>
inline typename CBST<T1, T2>::iterator CBST<T1, T2>::end()
{

	return iterator(this, nullptr);
}

template<typename T1, typename T2>
inline typename CBST<T1, T2>::iterator CBST<T1, T2>::find(const T1& _find)
{

	tBSTNode<T1, T2>* pNode = m_pRoot;
	NODE_TYPE node_type = NODE_TYPE::END;

	while (true)
	{

		if (pNode->Pair.first < _find)
		{

			node_type = NODE_TYPE::RCHILD;
		}
		else if (pNode->Pair.first > _find)
		{
			node_type = NODE_TYPE::LCHILD;
		}
		else
		{
			// pNode�� ���� ã������ ����.
			break;

		}


		if (nullptr == pNode->arrNode[(int)node_type])
		{
			//��ã�Ҵ�. pNode = nullptr ==> enditerator
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
inline tBSTNode<T1, T2>* CBST<T1, T2>::GetInOrderSuccessor(tBSTNode<T1, T2>* _pNode)
{

	tBSTNode<T1, T2>* pSuccessor = _pNode;
	// 1. ������ �ڽ��� �ִ� ���, ������ �ڽ����� ����, ���� �ڽ��� ������ ���� ������
	if (nullptr != _pNode->arrNode[(int)NODE_TYPE::RCHILD])
	{
		pSuccessor = _pNode->arrNode[(int)NODE_TYPE::RCHILD];

		while (pSuccessor->arrNode[(int)NODE_TYPE::LCHILD])
		{
			pSuccessor = pSuccessor->arrNode[(int)NODE_TYPE::LCHILD];
		}
	}


	// 2. �θ�� ���� �����ڽ��� �� ���� ���� �ö�
	//   �׶� �θ� �ļ���
	else
	{
		pSuccessor = _pNode;

		while (true)
		{
			// ���̻� �������� �ö� �� ����. ==> ������ ��忴��.
			if (pSuccessor->IsRoot())
			{
				return nullptr;
			}

			// �θ�� ���� �����ڽ����� üũ
			if (pSuccessor->IsLeftChild())
			{
				// �׶� �θ� �ļ���
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
inline tBSTNode<T1, T2>* CBST<T1, T2>::GetInOrderPredecessor(tBSTNode<T1, T2>* _pNode)
{
	return nullptr;
}

template<typename T1, typename T2>
inline typename CBST<T1, T2>::iterator CBST<T1, T2>::erase(const iterator& _iter)
{
	assert(this == _iter.m_pBST); // �����Ϸ��� �ϴ� _iter�� ����Ű���ִ� BST�� �ش� BST�� �´��� Ȯ�� iter�� �� BST���� �����ϱ� ����

	tBSTNode<T1, T2>* pSuccessor = DeleteNode(_iter.m_pNode);

	return iterator(this, pSuccessor);

	//// 1.�ڽ��� �ϳ��� ���� ���
	//if (_iter.m_pNode->IsLeaf())
	//{
	//	//�θ���� ����, ���� �� ����� �ڽ��� ����Ű�� �����͸� nullptr�� �����
	//	if (_iter.m_pNode->IsLeftChild())
	//	{
	//		nullptr = _iter.m_pNode->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::LCHILD];
	//	}
	//	else
	//	{
	//		nullptr = _iter.m_pNode->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::RCHILD];
	//	}

	//	delete _iter.m_pNode;


}

template<typename T1, typename T2>
inline tBSTNode<T1, T2>* CBST<T1, T2>::DeleteNode(tBSTNode<T1, T2>* _pTargetNode)
{

	tBSTNode<T1, T2>* pSuccessor = nullptr;
	// 1.�ڽ��� �ϳ��� ���� ���
	if (_pTargetNode->IsLeaf())
	{
		//������ų ����� �ļ��� ��带 ã�Ƶд�.
		pSuccessor = GetInOrderSuccessor(_pTargetNode);

		// ������ ��尡 ��Ʈ����(�ڽ��� ���� ��Ʈ ==> BST �ȿ� �����Ͱ� 1�� �ۿ� ����)
		if (_pTargetNode == m_pRoot)
		{
			m_pRoot = nullptr;
		}

		else
		{
			//�θ���� ����, ���� �� ����� �ڽ��� ����Ű�� �����͸� nullptr�� �����
			if (_pTargetNode->IsLeftChild())
			{
				nullptr = _pTargetNodee->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::LCHILD];
			}
			else
			{
				nullptr = _pTargetNode->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::RCHILD];
			}
		}

		delete _pTargetNode;
	}

	// 2. �ڽ��� 2���� ���
	else if (_pTargetNode->IsFull())
	{

	}

	// 3. �ڽ��� 1���� ���
	else
	{


	}

	// ������ ���� ������
	--m_iCount;

	return nullptr;
}

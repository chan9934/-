#pragma once

template<typename T>
struct tListNode
{
	T				data;
	tListNode<T>* pPrev;
	tListNode<T>* pNext;

	tListNode()
		: data()
		, pPrev(nullptr)
		, pNext(nullptr)
	{
	}

	tListNode(const T& _data, tListNode<T>* _pPrev, tListNode<T>* _pNext)
		: data(_data)
		, pPrev(_pPrev)
		, pNext(_pNext)
	{
	}
};

template<typename T>
class CList
{
private:
	tListNode<T>*	m_pHead;
	tListNode<T>*	m_pTail;
	int				m_iCount;

public:
	void push_back(const T& _data);
	void push_front(const T& _data);
	int size()
	{
		return m_iCount;
	}

public:
	class iterator;
	iterator begin();
	iterator end();
	iterator insert(const iterator& _iter, const T& _data);

public:
	CList();
	~CList();

	class iterator
	{
	private:
		CList<T>*		 m_pList;
		tListNode<T>*	 m_pNode;
		bool			m_bValid;


	public:
		iterator()
			: m_plist(nullptr)
			, m_pNode(nullptr)
			, m_bValid(false)
		{
		}

		iterator(CList<T>* _pList, tListNode<T>* _pNode)
			: m_pList(_pList)
			, m_pNode(_pNode)
			, m_bValid(false)
		{
			if (nullptr != _pList && nullptr != _pNode)
			{
				m_bvalid = true;
			}
		}

		~iterator();

	public:
		T& operator* ()
		{
			return m_pNode->data;
		}

	public :
		bool operator == (const iterator& _otheriter)
		{
			if (m_pList == _otheriter.m_pList && m_pNode == _otheriter.m_pNode)
			{
				return true;
			}
			return false;
		}

		bool operator != (const iterator& _otheriter)
		{
			return !(*this == _otheriter);
		}
	};

	iterator& operator ++()
	{
		if (nullptr == m_pNode || !m_valid)
		{
			assert(nullptr);
		}

		m_pNode = m_pNode->pNext;
		return *this;
	}

	iterator operator ++(int)
	{
		iterator copyiter(*this);

		++(*this);

		return copyiter;
	}

};

template<typename T>
void CList<T>::push_back(const T& _data)
{
	tListNode<T>* pNewNode = new tListNode<T>(_data, nullptr, nullptr);

	if (nullptr == m_pHead)
	{
		m_pHead = pNewNode;
		m_pTail = pNewNode;
	}

	else
	{
		m_pTail->pNext = pNewNode;
		pNewNode->pPrev = m_pTail;

		m_pTail = pNewNode;
	}

	++m_iCount;
}

template<typename T>
void CList<T>::push_front(const T& _data)
{
	tListNode<T>* pNewNode = new tListNode<T>(_data, nullptr, nullptr);

	m_pHead->pPrev = pNewNode;

	m_pHead = pNewNode;

	++m_iCount;

}

template<typename T>
CList<T>::CList()
	: m_pHead(nullptr)
	, m_pTail(nullptr)
	, m_iCount(0)
{

}

template<typename T>
CList<T>::~CList()
{

}

template<typename T>
typename CList<T>::iterator  CList<T>::begin()
{
	return iterator(this, m_pHead);
}

template<typename T>
typename CList<T>::iterator CList<T>::end()
{
	return iterator(this, nullptr);
}

template<typename T>
typename CList<T>::iterator CList<T>::insert(const iterator& _iter, const T& _data)
{
	if (end() == _iter)
	{
		assert(nullptr);
	}
	tListNode<T>* pNode = new tListNode<T>(_data, nullptr, nullptr);

	if (_iter.m_pNode == p_Head)
	{
		_iter.m_pNode->pPrev = pNode;
		pNode->pNext = _iter., _pNode;

		m_pHead = pNode;
	}
	else
	{
		_iter.m_pNode->pPrev->pNext = pNode;
		pNode->pPrev = _iter.m_pNde->pPrev;

		_iter.m_pNode->pPrev = pNode;
		pNode->pNext = _iter.m_pNode;
	}

	++m_iCount;

	return iterator(this, pNode);
}
#pragma once
template<typename T>
struct tListNode
{
	T data;
	tListNode<T>* pNext;
	tListNode<T>* pPrev;

	tListNode()
		: data()
		, pNext(nullptr)
		, pPrev(nullptr)
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
	tListNode<T>* m_pHead;
	tListNode<T>* m_pTail;
	int m_iCount;
public:
	void Push_Back(const T& _Data);
	void Push_Front(const T& _Data);
public:
	CList();
	~CList();
};

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
	tlistNode<T>* pDeleteNode = m_pHead;

	while (pDeleteNode)
	{
		tListNode<T>* pNext = pDeleteNode->pNext;
		delete(pDeleteNode);
		pDeleteNode = pNext;
	}

}
template<typename T>
void CList<T>::Push_Back(const T& _Data)
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
void Push_Front(const T& _Data)
{
	tListNode<T>* pNewNode = new tListNode<T>(_data, nullptr, m_pHead);

	m_pHead->pPrev = pNewNode;

	m_pHead = pNewNode;

	++m_iCount;
}
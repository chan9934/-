#pragma once
template <typename T>
struct Node
{
	T TNodeData;
	Node<T>* BeforePtr;
	Node<T>* NextPtr;

	Node()
		: TNodeData()
		, NextPtr(nullptr)
		, BeforePtr(nullptr)
	{
		
	}
	Node(const T& _Data, Node<T>* _BeforePtr, Node<T>* _NextPtr)
		: data(_Data)
		, BeforePtr(_BeforePtr)
		, NextPtr(_NextPtr)
	{

	}
	

};

template <typename T>
class List
{
private:
	Node<T> HeadPtr;
	Node<T> TailPtr;
	int Count;

private:
	List()
	{

	}

	~List()
	{

	}

	void Push_Back(const T& IData);

	void Push_Front(const T& IData);


};

template <typename T>
List<T>::List()
	: HeadPtr(nullptr)
	, TailPtr(nullptr)
	, Count()
{

}

template<typename T>
List<T>::~List()
{

}

template <typename T>
void List<T>::Push_Back(const T& IData)
{
	Node<T> NewPtr = new <Node<T>>

}
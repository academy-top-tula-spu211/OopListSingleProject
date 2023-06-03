#pragma once
#include <iostream>

class ListException
{
	std::string message;
public:
	ListException(std::string message = "List error") : message{message}{}
	std::string Message() { return message; }
};

template <typename T>
struct Node
{
	T value;
	Node<T>* next = nullptr;
};


template <typename T>
class ListSimple
{
	Node<T>* front;
	unsigned int size;
public:
	ListSimple() : size{}, front{ nullptr } {};

	void PushBack(T value);
	void PushFront(T value);
	void Insert(T value, int index);

	T PopBack();
	T PopFront();
	T Remove(int index);

	T& At(int index);
	T& operator[](int index);

	int Size() { return size; }

	void Print();

	Node<T>* NodeCreate(T value);
};

template<typename T>
inline void ListSimple<T>::PushBack(T value)
{
	Node<T>* nodeNew = NodeCreate(value);

	if (front)
	{
		Node<T>* nodeCurrent{ front };
		while (nodeCurrent->next)
			nodeCurrent = nodeCurrent->next;
		nodeCurrent->next = nodeNew;
	}
	else
		front = nodeNew;
	size++;
}

template<typename T>
inline void ListSimple<T>::PushFront(T value)
{
	Node<T>* nodeNew = NodeCreate(value);
	nodeNew->next = front;
	front = nodeNew;
	size++;
}

template<typename T>
inline void ListSimple<T>::Insert(T value, int index)
{
	if (index <= 0)
	{
		PushFront(value);
		return;
	}
	if(index >= size)
	{
		PushBack(value);
		return;
	}

	Node<T>* nodeNew = NodeCreate(value);
	Node<T>* nodeCurrent{ front };
	for (int i = 0; i < index - 1; i++)
		nodeCurrent = nodeCurrent->next;
	nodeNew->next = nodeCurrent->next;
	nodeCurrent->next = nodeNew;
	size++;
}

template<typename T>
inline T ListSimple<T>::PopBack()
{
	if (!front)
		throw new ListException("List is empty");
	
	T value;

	if (size > 1)
	{
		Node<T>* nodeCurrent{ front };
		for (int i = 0; i < size - 2; i++)
			nodeCurrent = nodeCurrent->next;
		value = nodeCurrent->next->value;
		delete nodeCurrent->next;
		nodeCurrent->next = nullptr;
	}
	else
	{
		value = front->value;
		delete front;
		front = nullptr;
	}
	size--;
	return value;
}

template<typename T>
inline T ListSimple<T>::PopFront()
{
	if (!front)
		throw new ListException("List is empty");

	T value = front->value;
	Node<T>* nodeDelete { front };
	front = front->next;
	delete nodeDelete;
	size--;

	return value;
}

template<typename T>
inline T ListSimple<T>::Remove(int index)
{
	if (!front)
		throw new ListException("List is empty");
	if (index <= 0)
		return PopFront();
	if (index >= size - 1)
		return PopBack();

	Node<T>* nodeCurrent{ front };
	for (int i = 0; i < index - 1; i++)
		nodeCurrent = nodeCurrent->next;

	Node<T>* nodeDelete = nodeCurrent->next;
	nodeCurrent->next = nodeDelete->next;

	T value = nodeDelete->value;
	delete nodeDelete;
	size--;

	return value;
}

template<typename T>
inline T& ListSimple<T>::At(int index)
{
	if (!front)
		throw new ListException("List is empty");
	if(index < 0 || index >= size)
		throw new ListException("Out of range in List");
	Node<T>* nodeCurrent{ front };
	for(int i = 0; i < index; i++)
		nodeCurrent = nodeCurrent->next;
	return nodeCurrent->value;
}

template<typename T>
inline T& ListSimple<T>::operator[](int index)
{
	return At(index);
}

template<typename T>
inline void ListSimple<T>::Print()
{
	Node<T>* nodeCurrent{ front };
	while (nodeCurrent)
	{
		std::cout << nodeCurrent->value << " ";
		nodeCurrent = nodeCurrent->next;
	}
	std::cout << "\n";
}

template<typename T>
inline Node<T>* ListSimple<T>::NodeCreate(T value)
{
	Node<T>* nodeNew{ new Node<T>() };
	nodeNew->value = value;
	return nodeNew;
}

#pragma once
#include "ListSimple.h"

template <typename T>
class StackList
{
	ListSimple<T> stack;
public:
	StackList(){}
	void Push(T value);
	T Pop();
	T Peek();

	void Print();
};

template<typename T>
inline void StackList<T>::Push(T value)
{
	stack.PushBack(value);
}

template<typename T>
inline T StackList<T>::Pop()
{
	return stack.PopBack();
}

template<typename T>
inline T StackList<T>::Peek()
{
	return stack[stack.Size() - 1];
}

template<typename T>
inline void StackList<T>::Print()
{
	stack.Print();
}

#include "CustomStack.h"

template<typename T>
CustomStack<T>::CustomStack()
	: capacity(Capacity)
	, Arr(new T[Capacity])
	, length(0)
{
}

template<typename T>
CustomStack<T>::~CustomStack()
{
	Clear();
	delete[] Arr;
}

template<typename T>
void CustomStack<T>::Push(const T& val)
{
	if (length == capacity) {
		T* old = Arr;
		Arr = new T[capacity = capacity * 2];
		copy(old, old + length, Arr);
		delete[] old;
	}
	Arr[length++] = val;
}

template<typename T>
void CustomStack<T>::Pop()
{
	if(length > 0) length--;
}

template<typename T>
lng CustomStack<T>::Num() const
{
	return length;
}

template<typename T>
bool CustomStack<T>::IsEmpty() const
{
	return length == 0;
}

template<typename T>
T CustomStack<T>::Top() const
{
	return *(Arr + length-1);
}

template<typename T>
void CustomStack<T>::Clear()
{
	length = 0;
	delete[] Arr;
	Arr = new T[capacity];
}

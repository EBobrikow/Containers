#include "CustomDeque.h"

template<typename T>
CustomDeque<T>::CustomDeque()
	: Head(new Node())
	, Tail(new Node())
	, length(0)
{
	Head->next = Tail;
	Head->previos = nullptr;
	Tail->previos = Head;
	Tail->next = nullptr;
}

template<typename T>
CustomDeque<T>::~CustomDeque()
{
	delete Head;
	delete Tail;
}

template<typename T>
void CustomDeque<T>::PushFront(const T& val)
{
	if (Head->nodeLength == Head->capacity)
	{
		T* old = Head->Arr;
		Head->Arr = new T[Head->capacity = Head->capacity * 2];
		copy(old, old + Head->nodeLength, Head->Arr);
		delete[] old;
		
	}
	Head->Arr[Head->nodeLength++] = val;
}

template<typename T>
void CustomDeque<T>::PushBack(const T& val)
{
	if (Tail->nodeLength == Tail->capacity)
	{
		T* old = Tail->Arr;
		Tail->Arr = new T[Tail->capacity = Tail->capacity * 2];
		copy(old, old + Tail->nodeLength, Tail->Arr);
		delete[] old;

	}
	Tail->Arr[Tail->nodeLength++] = val;
}

template<typename T>
void CustomDeque<T>::PopFront()
{
	if (Head->nodeLength == 0)
	{
		T* old = Tail->Arr;
		Tail->Arr = new T[Tail->capacity];
		copy(old + 1, old + Tail->nodeLength - 1, Tail->Arr);
		Tail->nodeLength--;
		delete[] old;
	}
	else
	{
		Head->nodeLength--;
	}
	
}

template<typename T>
void CustomDeque<T>::PopBack()
{
	if (Tail->nodeLength == 0)
	{
		T* old = Head->Arr;
		Head->Arr = new T[Head->capacity];
		copy(old + 1, old + Head->nodeLength - 1, Head->Arr);
		Head->nodeLength--;
		delete[] old;
	}
	else
	{
		Tail->nodeLength--;
	}
}

template<typename T>
lng CustomDeque<T>::Num() const
{
	return Head->nodeLength + Tail->nodeLength;
}

template<typename T>
void CustomDeque<T>::Clear()
{
	delete Head;
	delete Tail;
	Head = new Node();
	Tail = new Node();
	Head->next = Tail;
	Tail->previos = Head;
}

template<typename T>
T& CustomDeque<T>::operator[](const lng& index) const
{
	if (index < Head->nodeLength)
	{
		return Head->Arr[Head->nodeLength - 1 - index];
	}
	else
	{
		return Tail->Arr[index - Head->nodeLength];
	}
}

template<typename T>
CustomDeque<T>& CustomDeque<T>::operator=(const CustomDeque& Other)
{
	delete[] Head->Arr;
	delete[] Tail->Arr;
	
	Head->Arr = new T[Other.Head->capacity];
	Tail->Arr = new T[Other.Tail->capacity];
	Head->nodeLength = Other.Head->nodeLength;
	for (int i = 0; i < Other.Head->nodeLength; i++)
	{
		Head->Arr[i] = Other.Head->Arr[i];
	}

	Tail->nodeLength = Other.Tail->nodeLength;
	for (int i = 0; i < Other.Tail->nodeLength; i++)
	{
		Tail->Arr[i] = Other.Tail->Arr[i];
	}

	return *this;
}

template<typename T>
typename CustomDeque<T>::iterator
CustomDeque<T>::begin() const
{
	return iterator(Head,Head->Arr + Head->nodeLength - 1);
}

template<typename T>
typename CustomDeque<T>::iterator
CustomDeque<T>::end() const
{
	return iterator(Tail, Tail->Arr + Tail->nodeLength);
}

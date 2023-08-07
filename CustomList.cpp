#include "CustomList.h"

template<typename T>
CustomList<T>::CustomList()
	: Start(nullptr)
	, End(nullptr)
	, count(0)
{
}

template<typename T>
CustomList<T>::~CustomList()
{
	Clear();
}

template<typename T>
void CustomList<T>::AddToEnd(const T& val)
{
	Node* tmp = new Node;
	tmp->Data = val;
	tmp->next = nullptr;
	tmp->previos = nullptr;
	if (Start == nullptr)
	{
		Start = tmp;
		Start->next = End;
	}
	else if (End == nullptr)
	{
		End = tmp;
		End->previos = Start;
		Start->next = End;
	}
	else
	{
		tmp->previos = End;
		End->next = tmp;
		End = tmp;
	}
	count++;
}

template<typename T>
void CustomList<T>::AddToStart(const T& val)
{
	Node* tmp = new Node;
	tmp->Data = val;
	tmp->next = nullptr;
	tmp->previos = nullptr;
	if (Start == nullptr)
	{
		Start = tmp;
		Start->next = End;
	}
	else
	{
		tmp->next = Start;
		Start = tmp;
	}
	count++;
}

template<typename T>
int CustomList<T>::Num() const
{
	return count;
}

template<typename T>
void CustomList<T>::Clear()
{
	while (Start != nullptr)
	{
		Node* tmp = Start;
		Start = Start->next;
		if (tmp != nullptr)
		delete tmp;
	}
}

template<typename T>
void CustomList<T>::ReversList()
{
	Node* tmpEnd = End;
	Node* tmpStep = End;
	while (tmpStep != nullptr)
	{
		Node* tmp = tmpStep->next;
		tmpStep->next = tmpStep->previos;
		tmpStep->previos = tmp;
		tmpStep = tmpStep->next;
	}
	End = Start;
	Start = tmpEnd;
}

template<typename T>
void CustomList<T>::Insert(CustomList<T>::iterator& it, const T& val)
{
	Node* location = it.ptr;
	if (location != nullptr)
	{
		Node* PrevLoc = location->previos;
		Node* tmp = new Node;

		tmp->Data = val;
		tmp->next = location;
		tmp->previos = location->previos;
		location->previos = tmp;
		if (PrevLoc->next != nullptr)
		{
			PrevLoc->next = tmp;
		}
		count++;
	}
}

template<typename T>
void CustomList<T>::Delete(const T& val)
{

	Node* tmp = Start;
	while (tmp != nullptr)
	{
		if (tmp->Data == val)
		{
			break;
		}
		tmp = tmp->next;
	}

	Node* location = tmp;
	if (location != nullptr)
	{
		Node* locRight = location->next;
		Node* locLeft = location->previos;

		if (locRight != nullptr)
		{
			locRight->previos = locLeft;
			tmp = locRight;
		}
		if (locLeft != nullptr)
		{
			locLeft->next = locRight;
			tmp = locLeft;
		}
		count--;
		if (location == Start)
		{
			Start = tmp;
		}
		delete location;
	}
	

}

template<typename T>
CustomList<T>& CustomList<T>::operator=(const CustomList& Other)
{
	if (this == &Other)
	{
		return *this;
	}
	Clear();
	Node* tmp = Other.Start;
	while (tmp != nullptr)
	{
		AddToEnd(tmp->Data);
		tmp = tmp->next;
	}

	return *this;
}

template <typename T>
typename CustomList<T>::iterator
CustomList<T>::begin() const
{
	return iterator(Start);
}


template <typename T>
typename CustomList<T>::iterator
CustomList<T>::end() const
{
	return iterator(End->next);
}
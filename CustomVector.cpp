#include "CustomVector.h"

template<typename T>
CustomVector<T>::CustomVector(lng n)
	: capacity(n)
	, Arr(new T[n])
	, length(0)
{
}

template<typename T>
CustomVector<T>::~CustomVector()
{
	Clear();
	delete[] Arr;
}

template<typename T>
lng CustomVector<T>::Add(const T& val)
{
	if (length == capacity) {
		T* old = Arr;
		Arr = new T[capacity = capacity * 2];
		copy(old, old + length, Arr);
		delete[] old;
	}
	Arr[length++] = val;
	return length;
}

template<typename T>
T CustomVector<T>::PopBack()
{
	return Arr[length-- - 1];
}

template<typename T>
lng CustomVector<T>::Num() const
{
	return length;
}

template<typename T>
T& CustomVector<T>::operator[](const lng& index) const
{
	if (index >= length)
	{
		exit(0);
	}
	return *(Arr + index);
}

template<typename T>
void CustomVector<T>::Clear()
{
	delete[] Arr;
	length = 0;
	Arr = new T[capacity];
}

template<typename T>
lng CustomVector<T>::Find(const T& val) const
{
	for (lng i = 0; i < length; i++)
	{
		if (Arr[i] == val)
		{
			return i;
		}
	}
	return -1;
}

template<typename T>
CustomVector<T>& CustomVector<T>::operator=(const CustomVector& Other)
{
	if (this == &Other)
	{
		return *this;
	}

	Clear();
	CustomVector::length = Other.length;
	for (lng i = 0; i < CustomVector::Num(); i++)
	{
		CustomVector::Arr[i] = Other[i];
	}
	return *this;
}

template<typename T>
void CustomVector<T>::Sort()
{
	bool swap = false;
	for (lng i = 0; i < length-1; i++)
	{
		swap = false;
		for (lng j = 0; j < length - i - 1; j++)
		{
			if (Arr[j] > Arr[j+1])
			{
				T tmp = Arr[j];
				Arr[j] = Arr[j + 1];
				Arr[j + 1] = tmp;
				swap = true;
			}
		}

	}
}

template <typename T>
typename CustomVector<T>::iterator
CustomVector<T>::begin() const
{
	return iterator(Arr);
}


template <typename T>
typename CustomVector<T>::iterator
CustomVector<T>::end() const
{
	return iterator(Arr + length);
}
#include "CustomMap.h"

template<typename Tkey, typename Tval>
CustomMap<Tkey, Tval>::CustomMap()
	: capacity(Capacity)
	, Arr(new TPair[Capacity])
	, length(0)
{

}

template<typename Tkey, typename Tval>
CustomMap<Tkey, Tval>::~CustomMap()
{
	Clear();
	delete[] Arr;
}

template<typename Tkey, typename Tval>
void CustomMap<Tkey, Tval>::Add(const TPair& val)
{
	if (length == capacity) {
		TPair* old = Arr;
		Arr = new TPair[capacity = capacity * 2];
		copy(old, old + length, Arr);
		delete[] old;
	}
	for (int i = 0; i < length; i++)
	{
		if (Arr[i].key == val.key)
		{
			Arr[i].value = val.value;
			return;
		}
	}
	Arr[length++] = val;
}

template<typename Tkey, typename Tval>
void CustomMap<Tkey, Tval>::Add(const Tkey& key, const Tval& value)
{
	Add(TPair(key, value));
}

template<typename Tkey, typename Tval>
Tval CustomMap<Tkey, Tval>::At(const Tkey& key) const
{
	for (int i = 0; i< length; i++)
	{
		if (Arr[i].key == key)
		{
			return Arr[i].value;
		}
	}
	return Tval();
}

template<typename Tkey, typename Tval>
bool CustomMap<Tkey, Tval>::Contains(const Tkey& key) const
{
	for (int i = 0; i < length; i++)
	{
		if (Arr[i].key == key)
		{
			return true;
		}
	}
	return false;
}

template<typename Tkey, typename Tval>
lng CustomMap<Tkey, Tval>::Count(const Tkey& key) const
{
	lng res = 0;
	for (int i = 0; i < length; i++)
	{
		if (Arr[i].key == key){ res++; }
	}
	return res;
}

template<typename Tkey, typename Tval>
bool CustomMap<Tkey, Tval>::IsEmpty() const
{
	return length == 0;
}

template<typename Tkey, typename Tval>
lng CustomMap<Tkey, Tval>::Num() const
{
	return length;
}

template<typename Tkey, typename Tval>
void CustomMap<Tkey, Tval>::Clear()
{
	delete[] Arr;
	Arr = new TPair[capacity];
	length = 0;
}

template<typename Tkey, typename Tval>
typename CustomMap<Tkey,Tval>::iterator
CustomMap<Tkey, Tval>::begin() const
{
	return iterator(Arr);
}

template<typename Tkey, typename Tval>
typename CustomMap<Tkey, Tval>::iterator
CustomMap<Tkey, Tval>::end() const
{
	return iterator(Arr + length);
}

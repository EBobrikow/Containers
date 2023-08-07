#pragma once
#include "iostream"
using namespace std;
#define lng long long
#define MAX 100

template<typename T>
class CustomVector
{
public:
	explicit CustomVector(lng n = MAX);
	virtual ~CustomVector();

	// Add element to vector
	lng Add(const T& val);

	//Retrieve last vector element
	T PopBack();

	// Returns the number of vector elements
	lng Num() const;

	T& operator[](const lng& index) const;

	CustomVector<T>& operator=(const CustomVector& Other);

	// Clear the vector
	void Clear();

	// Return index of looking value, otherwise -1
	lng Find(const T& val) const;

	void Sort();

	class iterator
	{
	public:

		explicit iterator()
			: ptr(nullptr)
		{}

		explicit iterator(T* val)
			: ptr(val)
		{}

		bool operator==(const iterator& inVal) const
		{
			return ptr == inVal.ptr;
		}

		bool operator!=(const iterator& inVal) const
		{
			return !(*this == inVal);
		}

		T operator*() const
		{
			return *ptr;
		}

		T operator->() const
		{
			return *ptr;
		}

		iterator& operator++()
		{
			++ptr;
			return *this;
		}

		iterator operator++(int)
		{
			iterator temp(*this);
			++* this;
			return temp;
		}

		iterator& operator--()
		{
			--ptr;
			return *this;
		}

		iterator operator--(int)
		{
			iterator temp(*this);
			--* this;
			return temp;
		}

	private:
		T* ptr;
	};

	iterator begin() const;

	iterator end() const;

private:

	T* Arr;
	lng capacity;
	lng length;
};



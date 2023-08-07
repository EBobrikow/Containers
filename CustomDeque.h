#pragma once
#include "iostream"
using namespace std;
#define lng long long
#define Capacity 100

template<typename T>
class CustomDeque
{
	struct Node
	{
		Node* next;
		Node* previos;
		lng capacity;
		lng nodeLength;
		T* Arr;

		
		Node()
			: Arr(new T[Capacity])
			, nodeLength(0)
			, capacity(Capacity)
		{
		};

		~Node()
		{
			delete[] Arr;
		}
		
	};

public:

	explicit CustomDeque();
	virtual ~CustomDeque();

	void PushFront(const T& val);
	void PushBack(const T& val);
	void PopFront();
	void PopBack();
	lng Num() const;
	void Clear();


	T& operator[](const lng& index) const;
	CustomDeque<T>& operator=(const CustomDeque& Other);

	class iterator
	{
	public:

		explicit iterator()
			: node(nullptr)
			, ptr(nullptr)
		{}

		explicit iterator(Node* nodePtr ,T* val)
			: node(nodePtr)
			, ptr(val)
		{}


		bool operator==(const iterator& inVal) const
		{
			return ptr == inVal.ptr;
		}

		bool operator!=(const iterator& inVal) const
		{
			return ptr != inVal.ptr;
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
			if (node->next != nullptr)
			{
				if (ptr == node->Arr)
				{
					node = node->next;
					ptr = node->Arr;
					return *this;
				}
				--ptr;
				return *this;
			}
			++ptr;
			return *this;
		}

		iterator& operator++(int)
		{
			iterator tmp(*this);
			if (node->next != nullptr)
			{
				if (ptr == node->Arr)
				{
					node = node->next;
					ptr = node->Arr;
					return tmp;
				}
				--ptr;
				return tmp;
			}
			++ptr;
			return tmp;
		}

		iterator& operator--()
		{
			if (node->next != nullptr)
			{
				++ptr;
				return *this;
			}
			else
			{
				if (ptr == node->Arr)
				{
					node = node->previos;
					ptr = node->Arr;
					return *this;
				}
				--ptr;
				return *this;
			}
		}

		iterator& operator--(int)
		{
			iterator tmp(*this);
			if (node->next != nullptr)
			{
				++ptr;
				return tmp;
			}
			else
			{
				if (ptr == node->Arr)
				{
					node = node->previos;
					ptr = node->Arr;
					return tmp;
				}
				--ptr;
				return tmp;
			}
		}


	private:
		Node* node;
		T* ptr;
	};

	iterator begin() const;

	iterator end() const;

private:
	
	
	lng length;
	Node* Head;
	Node* Tail;
};



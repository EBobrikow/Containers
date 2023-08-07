#pragma once
#define lng long long
template <typename T>
class CustomList
{
public:

	struct Node
	{
		Node* next;
		Node* previos;
		T Data;
	};

	explicit CustomList();
	virtual ~CustomList();

	// Add element to end of the list
	void AddToEnd(const T& val);

	// Add element to beginig of the list
	void AddToStart(const T& val);

	// Returns a number of elements
	int Num() const;

	// Clear list, delete all elements
	void Clear();

	// Revers list from top to bottom
	void ReversList();

	// Delete list element with particular value
	void Delete(const T& val);
	
	CustomList<T>& operator=(const CustomList& Other);

	class iterator
	{
	public:

		explicit iterator()
			: ptr(nullptr)
		{}

		explicit iterator(Node* val)
			: ptr(val)
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
			return ptr->Data;
		}

		T operator->() const
		{
			return ptr->Data;
		}

		iterator& operator++()
		{
			ptr = ptr->next;
			return *this;
		}

		iterator& operator++ (int)
		{
			iterator tmp(*this);
			ptr = ptr->next;
			return tmp;
		}

		iterator& operator--()
		{
			ptr = ptr->previos;
			return *this;
		}

		iterator& operator--(int)
		{
			iterator tmp(*this);
			ptr = ptr->previos;
			return tmp;
		}

		Node* ptr;
		
	};

	void Insert(CustomList<T>::iterator& it, const T& val);



	iterator begin() const;

	iterator end() const;

private:
	Node* Start;
	Node* End;
	lng count;


};



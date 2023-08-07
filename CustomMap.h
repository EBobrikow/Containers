#pragma once
#define lng long long
#define Capacity 100
using namespace std;

template<typename Tkey, typename Tval>
class CustomMap
{
	

public:

	struct TPair
	{
		Tkey key;
		Tval value;

		TPair()
			: key(Tkey())
			, value(Tval())
		{}

		TPair(const Tkey& _key, const Tval& _val)
			: key(_key)
			, value(_val)
		{}
	};

	explicit CustomMap();
	virtual ~CustomMap();

	void Add(const TPair& val);
	void Add(const Tkey& key, const Tval& value);

	Tval At(const Tkey& key) const;
	bool Contains(const Tkey& key) const;
	lng Count(const Tkey& key) const;
	bool IsEmpty() const;
	lng Num() const;
	void Clear();

	class iterator
	{
	public:
		iterator()
			: ptr(nullptr)
		{}

		iterator(TPair* val)
			: ptr(val)
		{}

		bool operator==(const iterator& inVal) const
		{
			return ptr->key == inVal.ptr->key && ptr->value == inVal.ptr->value;
		}

		bool operator!=(const iterator& inVal) const
		{
			return ptr->key != inVal.ptr->key || ptr->value != inVal.ptr->value;
		}

		TPair operator*() const
		{
			return *ptr;
		}

		TPair operator->() const
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
			++*this;
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
			--*this;
			return temp;
		}

	private:
		TPair* ptr;
	};


	iterator begin() const;

	iterator end() const;
private:

	TPair* Arr;
	lng capacity;
	lng length;
};



#pragma once
#define lng long long
#define Capacity 100

template<typename T>
class CustomStack
{
public:
	explicit CustomStack();
	virtual ~CustomStack();

	void Push(const T& val);
	void Pop();
	lng Num() const;
	bool IsEmpty() const;
	T Top() const;
	void Clear();

private:
	T* Arr;
	lng capacity;
	lng length;
};



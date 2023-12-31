#pragma once
#include <memory>
#include <utility>

template<typename T>
class CList
{
public:
	CList<T>() {};
	~CList<T>() {};

	struct node
	{
		T data;
		struct node* prev;
		struct node* next;
	};
};
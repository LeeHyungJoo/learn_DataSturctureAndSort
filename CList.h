#pragma once
#include <memory>
#include <utility>

template<typename T>
class CList
{
	struct node
	{
		T data;
		struct node* prev;
		struct node* next;
	};

public:
	CList<T>() {};
	~CList<T>() {};


};
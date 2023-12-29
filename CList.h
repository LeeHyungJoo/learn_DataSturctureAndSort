#pragma once
#include <memory>
#include <utility>

template<typename T>
class CList
{
	struct node<T>
	{
		T data;
		struct node<T>* prev;
		struct node<T>* next;
	};
};
#pragma once
#include <memory>
#include <utility>

using namespace std;

template<typename T>
class CVector
{
public:
	CVector() 
	{
		size_t newcap = 0;
		if (_data != nullptr)
		{
			newcap = capacity();
			delete[] _data;
		}

		_size = 0;
		_capacity = newcap == 0 ? 5 : newcap;
		_data = new T[_capacity];
	}

	//fill constructor
	CVector(size_t size, T value)
	{
		size_t newcap = 0;
		if (_data != nullptr)
		{
			newcap = capacity();
			delete[] _data;
		}

		if (newcap < size)
			newcap = size;

		_data = (T*)malloc(sizeof(T) * size);
		for (int i = 0; i < size; i++)
			_data[i] = value;

		_size = size;
		_capacity = newcap;
	}

	//initializer constructor
	CVector(std::initializer_list<T> inits) {
		size_t newcap = 0;
		if (_data != nullptr)
		{
			newcap = capacity();
			delete[] _data;
		}

		if (newcap < inits.size())
			newcap = inits.size();

		_data = (T*)malloc(sizeof(T) * inits.size());
		auto itr = inits.begin();
		for (int i = 0; i < inits.size(); i++)
			_data[i] = *(itr++);

		_size = inits.size();
		_capacity = newcap;
	}

	virtual ~CVector() {}

	void push_back(T value)
	{
		auto cap = capacity();
		if (cap < _size + 1)
		{
			auto next_cap = cap * 2;
			//printf("cap : %d, next_cap : %d, ")
			auto new_data = (T*)malloc(sizeof(T) * (_size + 1));
			for (int i = 0; i < _size; i++)
				new_data[i] = _data[i];

			new_data[_size++] = value;
			free(_data);

			_data = (T*)malloc(sizeof(T) * next_cap);
			move(new_data, new_data + _size, _data);
			_capacity = next_cap;
		}
		else
		{
			_data[_size++] = value;
		}
	}

	void pop_back()
	{
		_data[--_size] = NULL;
	}

	bool empty()
	{
		return _size == 0;
	}

	size_t size()
	{
		return _size;
	}

	size_t capacity()
	{
		return _capacity;
	}

	T& at(size_t index)
	{
		return _data[index];
	}
	
	T& operator[](size_t index)
	{
		return _data[index];
	}

private:
	

private:
	T* _data = nullptr;
	size_t _capacity = 0;
	size_t _size = 0;
};
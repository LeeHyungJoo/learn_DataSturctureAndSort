#pragma once
#include <memory>
#include <utility>
#include <assert.h>

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
			free(_data);
		}

		_size = 0;
		_capacity = newcap == 0 ? 5 : newcap;
		_data = (T*)malloc(sizeof(T) * _capacity);
	}

	//fill constructor
	CVector(size_t size, T value = T())
	{
		size_t newcap = 0;
		if (_data != nullptr)
		{
			newcap = capacity();
			free(_data);
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
			free(_data);
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
			auto new_data = (T*)malloc(sizeof(T) * (_size + 1));
			for (int i = 0; i < _size; i++)
				new_data[i] = _data[i];

			new_data[_size++] = value;
			_data = (T*)realloc(_data, sizeof(T) * next_cap);
			move(new_data, new_data + _size, _data);
	
			_capacity = next_cap;

			free(new_data);
		}
		else
		{
			_data[_size++] = value;
		}
	}

	void insert(size_t position, T value)
	{
		assert(_size + 1 > position);

		auto cap = capacity();
		if (cap < _size + 1)
		{
			auto next_cap = cap * 2;
			auto new_data = (T*)malloc(sizeof(T) * (_size + 1));
			for (int i = 0; i < position; i++)
				new_data[i] = _data[i];

			new_data[position] = value;

			for (int i = position + 1; i < _size + 1; i++)
				new_data[i] = _data[i - 1];

			_data = (T*)realloc(_data, sizeof(T) * next_cap);
			move(new_data, new_data + _size, _data);
			_capacity = next_cap;

			free(new_data);
		}
		else
		{
			for (int i = position + 1; i < _size + 1; i++)
				_data[i] = _data[i - 1];
			_data[position] = value;
		}
	}

	void remove(size_t position)
	{
		assert(_size > 0);
		assert(_size > position);

		for (int i = position; i < _size - 1; i++)
			_data[i] = _data[i + 1];

		_size--;
	}

	void pop_back()
	{
		assert(_size > 0);

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
		assert(index >= 0);
		assert(index < _size);

		return _data[index];
	}
	
	T& operator[](size_t index)
	{
		assert(index >= 0);
		assert(index < _size);

		return _data[index];
	}

private:
	

private:
	T* _data = nullptr;
	size_t _capacity = 0;
	size_t _size = 0;
};
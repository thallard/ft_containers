#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>
#include <iostream>
#include <string>
#include <exception>
#include "Iterators.hpp"

namespace ft
{
	template <class T, class Alloc>
	class Vector;

	template <class T, class Alloc = std::allocator<T> >
	class Vector
	{
	public:
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef typename Alloc::reference reference;
		typedef typename Alloc::const_reference const_reference;
		typedef typename Alloc::pointer pointer;
		typedef typename Alloc::const_pointer const_pointer;
		typedef size_t size_type;
		typedef Iterator<T> iterator;
		typedef Const_Iterator<T> const_iterator;
		typedef Reverse_Iterator<T> reverse_iterator;
		typedef Const_Reverse_Iterator<T> const_reverse_iterator;

	private:
		T *_array;
		size_type _size;
		size_type _count;
		allocator_type _alloc;

	public:
		// Members functions
		explicit Vector(const allocator_type &alloc = allocator_type());													//
		explicit Vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()); //
		Vector(iterator first, iterator last, const allocator_type &alloc = allocator_type());								//
		Vector(const Vector &v);																							//
		Vector &operator=(const Vector &v);																					//
		~Vector();																											//

		// Iterators
		iterator begin();					   //
		iterator end();						   //
		const_iterator begin() const;		   //
		const_iterator end() const;			   //
		reverse_iterator rend();			   //
		reverse_iterator rbegin();			   //
		const_reverse_iterator rbegin() const; //
		const_reverse_iterator rend() const;   //

		// Capacity
		size_type size() const;									 //
		size_type max_size() const;								 //
		void resize(size_type n, value_type val = value_type()); //
		size_type capacity() const;								 //
		bool empty() const;										 //
		void reserve(size_type n);								 //

		// Element access
		reference operator[](size_type n);			   //
		reference at(size_type n);					   //
		reference front();							   //
		reference back();							   //
		const_reference back() const;				   //
		const_reference operator[](size_type n) const; //
		const_reference front() const;				   //
		const_reference at(size_type n) const;		   //

		// Modifiers
		void assign(iterator first, iterator last);							//
		void assign(size_type n, const value_type &val);					//
		void push_back(const value_type &val);								//
		void pop_back();													//
		iterator insert(iterator position, const value_type &val);			//
		void insert(iterator position, size_type n, const value_type &val); //
		void insert(iterator position, iterator first, iterator last);		//
		iterator erase(iterator position);									//
		iterator erase(iterator first, iterator last);						//
		void swap(Vector &x);												//
		void clear();														//

		bool operator==(const Vector<T, Alloc> &rhs);
		bool operator!=(const Vector<T, Alloc> &rhs);
		bool operator<(const Vector<T, Alloc> &rhs);
		bool operator<=(const Vector<T, Alloc> &rhs);
		bool operator>(const Vector<T, Alloc> &rhs);
		bool operator>=(const Vector<T, Alloc> &rhs);
		class OutOfRange : public std::exception
		{
			virtual const char *what() const throw();
		};
		class length_error : public std::exception
		{
			virtual const char *what() const throw();
		};

		void print();
	};

	template <typename T, class Alloc>
	void Vector<T, Alloc>::print()
	{
		for (size_t i = 0; i < _size; i++)
		{
			std::cout << "\e[35mValue at :" << i << " = " << _array[i] << ".\e[0m" << std::endl;
		}
		std::cout << std::endl;
	}

	// Alloc and default constructor
	template <typename T, class Alloc>
	Vector<T, Alloc>::Vector(const allocator_type &alloc) : _size(0), _count(0), _alloc(alloc)
	{
		_array = reinterpret_cast<T *>(_alloc.allocate(sizeof(T *) * 2));
	}

	// Fill constructor
	template <typename T, class Alloc>
	Vector<T, Alloc>::Vector(size_type n, const value_type &val, const allocator_type &alloc) : _size(n), _count(0), _alloc(alloc)
	{
		_array = reinterpret_cast<T *>(_alloc.allocate(sizeof(T *) * _size));
		for (_count = 0; _count < n; _count++)
			_array[_count] = val;
	}

	// Range constructor
	template <typename T, class Alloc>
	Vector<T, Alloc>::Vector(iterator first, iterator last, const allocator_type &alloc) : _size(0), _count(0), _alloc(alloc)
	{
		_array = reinterpret_cast<T *>(_alloc.allocate(sizeof(T *) * 2));
		insert(begin(), first, last);
	}

	// Constructor per copy
	template <typename T, class Alloc>
	Vector<T, Alloc>::Vector(const Vector &v) : _alloc(v._alloc)
	{
		if (*this == v)
			return;
		this->insert(begin(), v.begin(), v.end());
	}

	// Overload operator=
	template <typename T, class Alloc>
	Vector<T, Alloc> &Vector<T, Alloc>::operator=(const Vector &v)
	{
		if (*this == v)
			return *this;
		_array = v._array;
		_size = v._size;
		_count = v._count;
		return *this;
	}

	// Destructor
	template <typename T, class Alloc>
	Vector<T, Alloc>::~Vector()
	{
		_alloc.deallocate(_array, sizeof(T *) * _size);
	}

	// Modifiers push_back
	template <typename T, class Alloc>
	void Vector<T, Alloc>::push_back(const value_type &val)
	{
		if (_count >= _size)
			reserve(_count + 1);
		_count++;
		_array[_count - 1] = val;
	}

	// Modifiers pop_back
	template <typename T, class Alloc>
	void Vector<T, Alloc>::pop_back()
	{
		if (_size <= 0 || _count <= 0)
			return;
		T save[_size];
		for (size_t i = 0; i < _size; i++)
			save[i] = _array[i];
		_alloc.deallocate(_array, sizeof(T *) * _size);
		if (_count - 1 == 0 || !_count)
			_count = 0;
		else
			_count--;

		_array = reinterpret_cast<T *>(_alloc.allocate(sizeof(T *) * _size));
		for (size_t i = 0; i < _size; i++)
			_array[i] = save[i];
	}

	// Modifiers resize
	template <typename T, class Alloc>
	void Vector<T, Alloc>::resize(size_type n, value_type val)
	{
		if (_count > n)
		{
			while (_count != n)
				pop_back();
		}
		else if (_size > n)
		{
			T save[_size];
			size_t save_size = _size;
			for (size_t i = 0; i < _size; i++)
				save[i] = _array[i];
			_alloc.deallocate(_array, sizeof(T *) * _size);
			_size = n;
			_array = reinterpret_cast<T *>(_alloc.allocate(sizeof(T *) * _size));
			for (size_t i = 0; i < save_size; i++)
				_array[i] = save[i];
			for (size_t i = save_size; i < _size; i++)
				_array[i] = val;
			_count = n;
		}
		else
		{
			T save[_size + n];
			for (size_t i = 0; i < _size; i++)
				save[i] = _array[i];
			_alloc.deallocate(_array, sizeof(T *) * _size);
			size_t save_size = _size;
			_size = n;
			_array = reinterpret_cast<T *>(_alloc.allocate(sizeof(T *) * _size));
			for (size_t i = 0; i < save_size; i++)
				_array[i] = save[i];
			for (size_t i = save_size; i < n; i++)
				_array[i] = val;
			_count = n;
		}
	}

	// Modifiers clear
	template <typename T, class Alloc>
	void Vector<T, Alloc>::clear()
	{
		for (size_t i = 0; i < _size; i++)
			_array[i] = static_cast<T>(0);
		_count = 0;
	}

	// Modifiers swap
	template <typename T, class Alloc>
	void Vector<T, Alloc>::swap(Vector &x)
	{
		T *arr = x._array;
		size_t count = x._count;
		size_t size = x._size;
		x._array = _array;
		_array = arr;
		x._size = _size;
		x._count = _count;
		_count = count;
		_size = size;
	}

	// Reserve
	template <typename T, class Alloc>
	void Vector<T, Alloc>::reserve(size_type n)
	{
		if (n > max_size())
			throw Vector::length_error();
		if (n <= _size)
			return;
		size_t save = _count;
		resize(n);
		_count = save;
	}

	// Assign count
	template <typename T, class Alloc>
	void Vector<T, Alloc>::assign(size_type n, const value_type &val)
	{
		while (_size)
			pop_back();
		size_t i = 0;
		while (i < n)
		{
			push_back(val);
			i++;
		}
	}

	// Assign range
	template <typename T, class Alloc>
	void Vector<T, Alloc>::assign(iterator first, iterator last)
	{

		iterator start = first;
		iterator end = last;
		size_t save = _size;
		while (start != end)
			push_back(*start++);
		for (size_t i = 0; i < save; i++)
			erase(begin());
	}
	template <typename T, class Alloc>
	typename Vector<T, Alloc>::iterator Vector<T, Alloc>::insert(iterator position, const value_type &val)
	{

		iterator tmp = position;
		iterator tmp2 = begin();
		T save[_size + 100];
		size_t i = 0;
		if (tmp == end())
		{
			push_back(val);
			return position;
		}
		while (tmp != end())
		{
			save[i++] = *tmp++;
		}

		size_t pos = 0;
		while (tmp2 != position)
		{
			pos++;
			tmp2++;
		}
		size_t idx = i;
		while (idx)
		{
			pop_back();
			idx--;
		}
		push_back(val);
		for (size_t l = 0; l < i; l++)
			push_back(save[l]);
		// print();
		return position;
	}

	template <typename T, class Alloc>
	void Vector<T, Alloc>::insert(iterator position, size_type n, const value_type &val)
	{
		iterator tmp = position;
		T save[_size + 10];
		size_t i = 0;

		while (tmp != end())
			save[i++] = *(tmp++);
		size_t idx = i;
		reserve(_count + n);
		while (idx--)
			pop_back();
		while (n--)
			push_back(val);
		for (size_t l = 0; l < i; l++)
			push_back(save[l]);
	}

	template <typename T, class Alloc>
	void Vector<T, Alloc>::insert(Vector<T, Alloc>::iterator position, Vector<T, Alloc>::iterator first, Vector<T, Alloc>::iterator last)
	{
		size_t insertSize = static_cast<size_t>(last.address() - first.address());
		size_t pos = 0;
		size_t _empty = empty();
		iterator tmp = begin();

		while (tmp++ != position)
			pos++;

		T _save_new[insertSize];
		T _save_old[_count];

		for (size_t j = 0; j < insertSize; j++)
			_save_new[j] = *first++;
		if (!_empty)
			for (size_t l = 0; l < insertSize; l++)
				_save_old[l] = _array[l];
		reserve(_count + insertSize);
		size_t i = 0;

		if (!_empty)
			for (; i < insertSize; i++)
				_array[pos + insertSize + i] = _save_old[i];

		for (i = 0; i < insertSize; i++)
		{
			_array[pos + i] = _save_new[i];
		}
		_count += insertSize;
	}

	// Erase position
	template <typename T, class Alloc>
	typename Vector<T, Alloc>::iterator Vector<T, Alloc>::erase(iterator position)
	{
		T _tmp[_count];
		iterator tmp = begin();
		iterator save = tmp;
		size_t count;
		if (!_count)
			count = 0;
		else
			count = _count - 1;
		int i = -1;
		while (tmp != end())
		{
			if (tmp != position)
				_tmp[++i] = *tmp;
			else
				save = tmp + 1;
			tmp++;
		}
		iterator beg = begin();
		while (beg != end() && _size > 0)
		{
			pop_back();
			beg++;
		}
		for (size_t it = _count; it < count; it++)
			push_back(_tmp[it]);

		return (save);
	}

	// Modifiers erase range
	template <typename T, class Alloc>
	typename Vector<T, Alloc>::iterator Vector<T, Alloc>::erase(iterator start, iterator stop)
	{
		iterator tmp = start;
		size_t count = static_cast<size_t>(stop.address() - start.address());
		while (count-- > 0)
			tmp = erase(tmp);
		return tmp;
	}

	// Overload operator []
	template <typename T, class Alloc>
	typename Vector<T, Alloc>::reference Vector<T, Alloc>::operator[](size_type n)
	{
		if (n > _count || n < 0)
			throw Vector::OutOfRange();
		return (_array[n]);
	}
	template <typename T, class Alloc>
	typename Vector<T, Alloc>::const_reference Vector<T, Alloc>::operator[](size_type n) const
	{
		if (n > _count || n < 0)
			throw Vector::OutOfRange();
		return (_array[n]);
	}

	

	// At
	template <typename T, class Alloc>
	typename Vector<T, Alloc>::reference Vector<T, Alloc>::at(size_type n)
	{
		if (n > _count || n < 0)
			throw Vector::OutOfRange();
		return (_array[n]);
	}
	template <typename T, class Alloc>
	typename Vector<T, Alloc>::const_reference Vector<T, Alloc>::at(size_type n) const
	{
		if (n > _count || n < 0)
			throw Vector::OutOfRange();
		return (_array[n]);
	}

	// Front
	template <typename T, class Alloc>
	typename Vector<T, Alloc>::reference Vector<T, Alloc>::front()
	{
		return (_array[0]);
	}

	template <typename T, class Alloc>
	typename Vector<T, Alloc>::const_reference Vector<T, Alloc>::front() const
	{
		return (_array[0]);
	}

	// Back
	template <typename T, class Alloc>
	typename Vector<T, Alloc>::reference Vector<T, Alloc>::back()
	{
		return (_array[_count - 1]);
	}

	template <typename T, class Alloc>
	typename Vector<T, Alloc>::const_reference Vector<T, Alloc>::back() const
	{
		return (_array[_count - 1]);
	}

	// Max_size
	template <typename T, class Alloc>
	typename Vector<T, Alloc>::size_type Vector<T, Alloc>::max_size() const
	{
		return std::numeric_limits<size_type>::max() / sizeof(*_array);
	}

	// Size
	template <typename T, class Alloc>
	typename Vector<T, Alloc>::size_type Vector<T, Alloc>::size() const
	{
		return _count;
	}

	// Capacity
	template <typename T, class Alloc>
	typename Vector<T, Alloc>::size_type Vector<T, Alloc>::capacity() const
	{
		return _size;
	}

	// Capacity
	template <typename T, class Alloc>
	bool Vector<T, Alloc>::empty() const
	{
		return (_count == 0);
	}

	// New exception out of bounds
	template <typename T, class Alloc>
	const char *Vector<T, Alloc>::OutOfRange::what() const throw()
	{
		return "\e[91mft::Vector error : Out of range!\e[0m";
	}
	template <typename T, class Alloc>
	const char *Vector<T, Alloc>::length_error::what() const throw()
	{
		return "\e[91mft::Vector error : Length error!\e[0m";
	}

	//Iterators
	template <class T, class Alloc>
	typename Vector<T, Alloc>::iterator Vector<T, Alloc>::begin()
	{
		return Iterator<T>(&_array[0]);
	}

	template <class T, class Alloc>
	typename Vector<T, Alloc>::iterator Vector<T, Alloc>::end()
	{
		return Iterator<T>(&_array[_count]);
	}

	template <class T, class Alloc>
	typename Vector<T, Alloc>::const_iterator Vector<T, Alloc>::begin() const
	{
		return Const_Iterator<T>(&_array[0]);
	}

	template <class T, class Alloc>
	typename Vector<T, Alloc>::const_iterator Vector<T, Alloc>::end() const
	{
		return Const_Iterator<T>(&_array[_count]);
	}

	template <class T, class Alloc>
	typename Vector<T, Alloc>::reverse_iterator Vector<T, Alloc>::rbegin()
	{
		return Reverse_Iterator<T>(&_array[_count - 1]);
	}

	template <class T, class Alloc>
	typename Vector<T, Alloc>::reverse_iterator Vector<T, Alloc>::rend()
	{
		return Reverse_Iterator<T>(&_array[-1]);
	}

	template <class T, class Alloc>
	typename Vector<T, Alloc>::const_reverse_iterator Vector<T, Alloc>::rbegin() const
	{
		return Const_Reverse_Iterator<T>(&_array[_count - 1]);
	}

	template <class T, class Alloc>
	typename Vector<T, Alloc>::const_reverse_iterator Vector<T, Alloc>::rend() const
	{
		return Const_Reverse_Iterator<T>(&_array[-1]);
	}

	template <class T, class Alloc>
	bool Vector<T, Alloc>::operator==(const Vector<T, Alloc> &lhs)
	{
		if (_size != lhs._size)
			return false;
		iterator first = begin();
		iterator second = lhs.begin();
		while (first != end() && second != lhs.end())
		{
			if (*first != *second)
				return false;
			first++;
			second++;
		}
		return true;
	}
	template <class T, class Alloc>
	bool Vector<T, Alloc>::operator<(const Vector<T, Alloc> &lhs)
	{
		if (_size >= lhs._size)
			return false;
		iterator first = begin();
		iterator second = lhs.begin();
		while (first != end() && second != lhs.end())
		{
			if (*first >= *second)
				return false;
			first++;
			second++;
		}
		return true;
	}

	template <class T, class Alloc>
	bool Vector<T, Alloc>::operator!=(const Vector<T, Alloc> &lhs)
	{
		return !(*this == lhs);
	}

	template <class T, class Alloc>
	bool Vector<T, Alloc>::operator>(const Vector<T, Alloc> &lhs)
	{
		return (lhs < *this);
	}
	template <class T, class Alloc>
	bool Vector<T, Alloc>::operator>=(const Vector<T, Alloc> &lhs)
	{
		return !(*this < lhs);
	}

	template <class T, class Alloc>
	bool Vector<T, Alloc>::operator<=(const Vector<T, Alloc> &lhs)
	{
		return !(lhs < *this);
	}
}

#endif
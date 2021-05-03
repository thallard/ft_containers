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
		template <class InputIterator>
		Vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type()); //
		Vector(const Vector &v);																		 //
		Vector &operator=(const Vector &v);																 //
		~Vector();																						 //

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
		template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last); //
		iterator erase(iterator position);										 //
		iterator erase(iterator first, iterator last);							 //
		void swap(Vector &x);													 //
		void clear();															 //

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
	};

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
	template <class InputIterator>
	Vector<T, Alloc>::Vector(InputIterator first, InputIterator last, const allocator_type &alloc) : _alloc(alloc)
	{
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
		// dprintf(1, "\e[91mval en entree de push back  et la size %d %lu\e[0m\n", val, _size);
		if (!_size)
		{
			_size = 2;
			_array = reinterpret_cast<T *>(_alloc.allocate(sizeof(T *) * _size));
			// dprintf(1, "debug size %lu et count %lu\n", _size, _count);
			_array[_count] = val;
			_count += 1;
			// dprintf(1, "debug size %lu et count %lu\n", _size, _count);
		}
		else if (_count + 1 > _size)
		{
			T save[_count];
			size_t save_size = _count;
			for (size_t i = 0; i < _count; i++)
			{
				save[i] = _array[i];
				// dprintf(1, "debug de save = %d\n", save[i]);
			}
			_alloc.deallocate(_array, sizeof(T *) * _size);
			_size = _size * _size;
			// dprintf(1, "debug size %lu et count %lu\n", _size, _count);
			_array = reinterpret_cast<T *>(_alloc.allocate(sizeof(T *) * _size));
			for (size_t i = 0; i < save_size; i++)
			{
				_array[i] = save[i];
				// dprintf(1, "content de array = %d\n", _array[i]);
			}
			_array[_count++] = val;
		}
		else
		{
			// dprintf(1, "\e[92mval en entree du dernier else de push back  et la size %d %lu\e[0m\n", val, _size);
			_array[_count++] = val;
		}
	}

	// Modifiers pop_back
	template <typename T, class Alloc>
	void Vector<T, Alloc>::pop_back()
	{
		if (_size <= 0)
		{
			// dprintf(1, "ici\n");
			return;
		}

		T save[_size];
		for (size_t i = 0; i < _size; i++)
			save[i] = _array[i];
		_alloc.deallocate(_array, sizeof(T *) * _size);
		_size--;

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
		if (_size > n)
		{
			T save[_size];
			size_t save_size = _size;
			for (size_t i = 0; i < _size; i++)
				save[i] = _array[i];
			_alloc.deallocate(_array, sizeof(T *) * _size);
			_size = _size * _size;
			_array = reinterpret_cast<T *>(_alloc.allocate(sizeof(T *) * _size));
			for (size_t i = 0; i < save_size; i++)
				_array[i] = save[i];
			for (size_t i = save_size; i < _size; i++)
				_array[i] = val;
		}
		else
		{
			T save[_size];
			for (size_t i = 0; i < _size; i++)
				save[i] = _array[i];
			_alloc.deallocate(_array, sizeof(T *) * _size);
			_size = n;
			_array = reinterpret_cast<T *>(_alloc.allocate(sizeof(T *) * _size));
			for (size_t i = 0; i < n; i++)
				_array[i] = save[i];
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
		resize(n);
	}

	// Assign count
	template <typename T, class Alloc>
	void Vector<T, Alloc>::assign(size_type n, const value_type &val)
	{
		(void)n;
		(void)val;
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
		(void)first;
		(void)last;
		iterator start = first;
		iterator end = last;
		size_t save = _size;
		// while (_size)
		// 	pop_back();
		while (start != end)
			push_back(*start++);
		// start++;
		for (size_t i = 0; i < save; i++)
			erase(begin());
		// erase(begin());
		// erase(begin());
		// erase(begin());
		// erase(begin());
		// erase(begin());
		// iterator tmp = begin();
		// while (i > 0)
		// {
		// 	dprintf(1, "debug de int = %lu\n", i);
		// 	erase(begin());
		// 	i--;
		// }
	}
	template <typename T, class Alloc>
	typename Vector<T, Alloc>::iterator Vector<T, Alloc>::insert(iterator position, const value_type &val)
	{

		iterator tmp = position;
		iterator tmp2 = begin();
		T save[_size];
		size_t i = 0;
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
		return position;
	}

	template <typename T, class Alloc>
	void Vector<T, Alloc>::insert(iterator position, size_type n, const value_type &val)
	{
		iterator tmp = position;
		iterator tmp2 = begin();
		T save[_size];
		size_t i = 0;
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
		while (n--)
			push_back(val);
		for (size_t l = 0; l < i; l++)
			push_back(save[l]);
	}

	template <typename T, class Alloc>
	template <class InputIterator>
	void Vector<T, Alloc>::insert(iterator position, InputIterator first, InputIterator last)
	{
		if (std::is_integral<InputIterator>::value)
		{
			size_t i = 0;
			T save[_size];
			while (first[i] != last[i])
				save[i] = first[i];
			size_t pos = _size - i;
			size_t idx = pos;
			while (idx)
			{
				pop_back();
				idx--;
			}
			size_t j = 0;
			while (pos)
			{
				push_back(first[j++]);
				pos--;
			}
			for (size_t l = 0; l < i; l++)
				push_back(save[l]);
		}
		iterator tmp = position;
		iterator tmp2 = begin();
		InputIterator it = first;
		T save[_size];
		size_t i = 0;
		while (tmp != end())
		{
			save[i++] = *tmp++;
		}
		size_t pos = 0;
		size_t idx = i;
		while (tmp2 != position)
		{
			pos++;
			tmp2++;
		}

		while (idx)
		{
			pop_back();
			idx--;
		}
		while (it != last)
		{
			push_back(*it++);
		}

		for (size_t l = 0; l < i; l++)
			push_back(save[l]);
	}

	// Erase position
	template <typename T, class Alloc>
	typename Vector<T, Alloc>::iterator Vector<T, Alloc>::erase(iterator position)
	{
		T _tmp[_count];
		iterator tmp = begin();
		iterator save = tmp;
		// dprintf(1, "\e[35mCount : %lu\n", _count);
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
		// if (position != end())
		// 	_tmp[++i] = *tmp;
		iterator beg = begin();
		while (beg != end() && _size > 0)
		{
			pop_back();
			beg++;
		}
		for (size_t it = 0; it < count; it++)
		{
			// dprintf(1, "\e[92mdebug de la value de it = %lu et count = %lu\n", it, count);
			push_back(_tmp[it]);
		}

		return (save);
	}

	// Modifiers erase range
	template <typename T, class Alloc>
	typename Vector<T, Alloc>::iterator Vector<T, Alloc>::erase(iterator start, iterator stop)
	{
		iterator tmp = start;
		// size_t count = 0;
		while (tmp != stop)
		{
			erase(tmp);
			tmp++;
		}
		return (stop);
		// while (tmp != stop)
		// {
		// 	count++;
		// 	tmp++;
		// }
		// resize(_count - count);
		// tmp = begin();
		// while (tmp != end())
		// {
		// 	if (tmp == start)
		// 		while (tmp != stop)
		// 			tmp++;
		// 	push_back(*tmp);
		// 	tmp++;
		// }
		// return (stop);
		// iterator tmp = start;
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

	template <typename T, class Alloc>
	bool Vector<T, Alloc>::operator==(const Vector<T, Alloc> &rhs)
	{
		return (_size == rhs._size);
	}
	template <typename T, class Alloc>
	bool Vector<T, Alloc>::operator!=(const Vector<T, Alloc> &rhs)
	{
		return (_size != rhs._size);
	}
	template <typename T, class Alloc>
	bool Vector<T, Alloc>::operator<(const Vector<T, Alloc> &rhs)
	{
		return (_size < rhs._size);
	}
	template <typename T, class Alloc>
	bool Vector<T, Alloc>::operator<=(const Vector<T, Alloc> &rhs)
	{
		return (_size <= rhs._size);
	}
	template <typename T, class Alloc>
	bool Vector<T, Alloc>::operator>(const Vector<T, Alloc> &rhs)
	{
		return (_size > rhs._size);
	}
	template <typename T, class Alloc>
	bool Vector<T, Alloc>::operator>=(const Vector<T, Alloc> &rhs)
	{
		return (_size <= rhs._size);
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
		return (_array[_count]);
	}

	template <typename T, class Alloc>
	typename Vector<T, Alloc>::const_reference Vector<T, Alloc>::back() const
	{
		return (_array[_count]);
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
}

#endif
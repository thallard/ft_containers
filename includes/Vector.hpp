#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>
#include <iostream>
#include <string>
#include <math.h>

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

	private:
		T *_array;
		size_type _size;
		size_type _count;
		allocator_type _alloc;

	public:
		// Members functions
		explicit Vector(const allocator_type &alloc = allocator_type());
		explicit Vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type());
		template <class InputIterator>
		Vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type());
		Vector(const Vector &v);
		Vector &operator=(const Vector &v);
		~Vector();

		// Iterators

		// Capacity
		size_type size() const;
		size_type max_size() const;
		void resize(size_type n, value_type val = value_type());
		size_type capacity() const;
		bool empty() const;
		void reserve(size_type n);

		// Element access
		reference operator[](size_type n);
		reference at(size_type n);
		reference front();
		reference back();
		const_reference back() const;
		const_reference operator[](size_type n) const;
		const_reference front() const;
		const_reference at(size_type n) const;

		// Modifiers
		template <class InputIterator>
		void assign(InputIterator first, InputIterator last);
		void assign(size_type n, const value_type &val);
		void push_back(const value_type &val);
		void pop_back();
		// iterator insert(iterator position, const value_type &val);
		// void insert(iterator position, size_type n, const value_type &val);
		template <class InputIterator>
		// void insert(iterator position, InputIterator first, InputIterator last);
		// iterator erase(iterator position);
		// iterator erase(iterator first, iterator last);
		void swap(Vector &x);
		void clear();

		friend bool operator==(const Vector<T, Alloc> &lhs, const Vector<T, Alloc> &rhs);
	};

	// Alloc and default constructor
	template <typename T, class Alloc>
	Vector<T, Alloc>::Vector(const allocator_type &alloc) : _size(2), _count(0), _alloc(alloc)
	{
		_array = reinterpret_cast<T *>(_alloc.allocate(sizeof(T *) * _size));
	}

	// Destructor
	template <typename T, class Alloc>
	Vector<T, Alloc>::~Vector()
	{
	}
	// Modifiers push_back
	template <typename T, class Alloc>
	void Vector<T, Alloc>::push_back(const value_type &val)
	{
		if (_count + 1 > _size)
		{
			return;
		}
		size_t i;
		for (i = 0; i < _count; i++)
			;
		_array[i] = val;
	}

}

#endif
#ifndef LIST_HPP
#define LIST_HPP
#include <iostream>
#include <string>

namespace ft
{
	template <class T, class Alloc>
	class List;
	template <typename T>
	class Element
	{
	public:
		T _content;
		Element *_next;
		Element *_prev;

		Element(const T &cont) : _content(cont), _next(NULL), _prev(NULL) {}
		Element(Element *pre, const T &cont, Element *next) : _content(cont), _next(next), _prev(pre) {}
		Element() : _content(T()), _next(NULL), _prev(NULL) {}
		Element &operator=(const Element &obj)
		{
			if (this == &obj)
				return (*this);
			return (*new (this) Element(obj));
		};
	};
	template <class T, class Alloc = std::allocator<T> >
	class List : public std::allocator<T>
	{
	private:
		Element<T> *_nodes;
		size_t _size;

	public:
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef size_t size_type;
		typedef ptrdiff_t difference_type;
		typedef typename Alloc::reference reference;
		typedef value_type &const_reference;
		typedef typename Alloc::pointer pointer;
		typedef typename Alloc::const_pointer const_pointer;

		List() {}
		List(size_t size, const T &val);
		~List() {}
		Element<T> *getNode() { return _nodes; };
		List<T, Alloc> &operator=(List const &ref);

		// Access members
		reference front();
		const_reference front() const;
		reference back();
		const_reference back() const;

		// Capacity members
		bool empty() const;
		size_type size() const;

		// Modifiers members
		void clear();
		// iterator insert(iterator pos, const T &value);
		// void insert(iterator pos, size_type count, const T &value);
		// template <class InputIt>
		// void insert(iterator pos, InputIt first, InputIt last);
		// iterator erase(iterator pos);
		// iterator erase(iterator first, iterator last);
		void push_back(const T &value);
		void pop_back();
		void push_front(const T &value);
		void pop_front();
		void resize(size_type count, T value = T());
		void swap(List &other);
	};

	// Fill constructor
	template <class T, class Alloc>
	List<T, Alloc>::List(size_t size, const T &val) : _size(size)
	{
		_nodes = new Element<T>();
		Element<T> *tmp = _nodes;
		_nodes->_content = static_cast<T>(size);

		for (unsigned int i = 0; i < size; i++)
		{
			Element<T> *next = new Element<T>(tmp, val, NULL);
			tmp->_next = next;
			tmp = tmp->_next;
		}

		Element<T> *next = new Element<T>(tmp, static_cast<T>(size), NULL);
		tmp->_next = next;
	}

	// Access Member
	// Front access member
	template <class T, class Alloc>
	typename List<T, Alloc>::reference List<T, Alloc>::front()
	{
		return (_nodes->_next->_content);
	}
	// Front access const member
	template <class T, class Alloc>
	typename List<T, Alloc>::const_reference List<T, Alloc>::front() const
	{
		return (_nodes->_next->_content);
	}

	// Back access member
	template <class T, class Alloc>
	typename List<T, Alloc>::reference List<T, Alloc>::back()
	{
		Element<T> *tmp = _nodes->_next;
		for (size_t i = 1; i < _size; i++)
			tmp = tmp->_next;
		return (tmp->_content);
	}
	// Back access const member
	template <class T, class Alloc>
	typename List<T, Alloc>::const_reference List<T, Alloc>::back() const
	{
		Element<T> *tmp = _nodes->_next;
		for (size_t i = 1; i < _size; i++)
			tmp = tmp->_next;
		return (tmp->_content);
	}

	//Capacity Members
	template <class T, class Alloc>
	bool List<T, Alloc>::empty() const
	{
		return (_size ? true : false);
	}

	template <class T, class Alloc>
	typename List<T, Alloc>::size_type List<T, Alloc>::size() const
	{
		return _size;
	}
}
#endif
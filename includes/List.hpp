#ifndef LIST_HPP
#define LIST_HPP
#include <iostream>
#include <string>
#include <memory>
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
		Element<T> *operator++(int junk)
		{
			(void)junk;
			std::cout << "mes couilles et ";
			Element tmp = *this;
			*this = *this->_next;
			return tmp;
		};
	};

	template<typename T>
	class Iterator
	{
		public:
			typedef Iterator self_type;
			typedef T value_type;
			typedef T& reference;
			typedef T* pointer;
			typedef std::forward_iterator_tag iterator_category;
			typedef int difference_type;
			Iterator(pointer ptr) : ptr_(ptr) { };
			Iterator &operator=(Iterator const &ref) { ptr_ = ref._ptr; return (*this);};
			self_type operator++() {self_type i = *this; ptr_->_next; return i; }
			self_type operator++(int junk) {(void) junk; ptr_ = ptr_->_next; return *this; }
			reference operator*() { return *ptr_; }
			pointer operator->() { return ptr_; }
			bool operator==(const self_type& rhs) { return ptr_ == rhs.ptr_; }
			bool operator!=(const self_type& rhs) { return ptr_ != rhs.ptr_; }
		private:
			pointer ptr_;
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
		typedef Iterator<Element<T> > iterator;

		List();
		explicit List(size_type size, const T &val);
		List(iterator first, iterator last);
		List(const List &other);
		~List();
		List<T, Alloc> &operator=(List const &ref);

		// Iterator
		iterator begin();
		iterator end();

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

	// Default constructor
	template<class T, class Alloc>
	List<T, Alloc>::List()
	{
		_nodes = reinterpret_cast<Element<T> *>(allocator_type::allocate(1));
		_size = 0;
	}

	// Range constructor
	template<class T, class Alloc>
	List<T, Alloc>::List(List<T, Alloc>::iterator first, List<T, Alloc>::iterator last)
	{
		int		size = 0;

		while (first != last)
		{
			size++;
			first++;
		}
		_size = size;
		_nodes = reinterpret_cast<Element<T> *>(allocator_type::allocate(_size));
		// Malloc previous tout remplir avec val et next et prev
		while (first != last)
		{
			
			first++;
		}
	}

	// Fill constructor
	template <class T, class Alloc>
	List<T, Alloc>::List(size_t size, const T &val) : _size(size)
	{
		_nodes = reinterpret_cast<Element<T> *>(allocator_type::allocate(size));
		Element<T> *tmp = _nodes;
		_nodes->_content = static_cast<T>(size);

		for (unsigned int i = 0; i < size; i++)
		{
				// Malloc previous tout remplir avec val et next et prev
			Element<T> *next = reinterpret_cast<Element<T> *>(this->allocate(sizeof(Element<T> *)));
			*next = val;
			tmp->_next = next;
			tmp = tmp->_next;
		}
		Element<T> *next = reinterpret_cast<Element<T> *>(this->allocate(sizeof(Element<T> *)));
		*next = static_cast<T>(size);
		tmp->_next = next;
	}

	// Range constructor
	

	// Destructor
	template <class T, class Alloc>
	List<T, Alloc>::~List()
	{
		for (unsigned int i = 0; i <= _size; i++)
		{
			this->deallocate(reinterpret_cast<int *>(_nodes), _size);
			_nodes = _nodes->_next;
		}
		this->deallocate(reinterpret_cast<int *>(_nodes), _size);
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

	// Members access
	template <class T, class Alloc>
	void List<T, Alloc>::clear()
	{
		for (unsigned int i = 0; i < _size; i++)
			;
	}
	
	//Iterators
	template <class T, class Alloc>
	typename List<T, Alloc>::iterator List<T, Alloc>::begin()
	{
		return Iterator<Element<T> >(_nodes->_next);
	};

	template <class T, class Alloc>
	typename List<T, Alloc>::iterator List<T, Alloc>::end()
	{ 
			
			Element<T> *tmp = _nodes->_next;
			for (size_t i = 1; i < _size; i++)
				tmp = tmp->_next;
			return Iterator<Element<T> >(tmp);
		};
}

template <typename T>
std::ostream &operator<<(std::ostream &output, const ft::Element<T> &e)
{
	output << e._content;
	return output;
}

#endif
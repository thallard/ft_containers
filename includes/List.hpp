
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
			Element tmp = *this;
			*this = *this->_next;
			return tmp;
		};
	};

	template <typename T>
	class Iterator
	{
	public:
		typedef Iterator self_type;
		typedef T value_type;
		typedef T &reference;
		typedef T *pointer;
		typedef std::forward_iterator_tag iterator_category;
		typedef int difference_type;
		Iterator(pointer ptr) : ptr_(ptr){};
		Iterator &operator=(Iterator const &ref)
		{
			ptr_ = ref._ptr;
			return (*this);
		};
		self_type operator++()
		{
			ptr_ = ptr_->_next;
			return *this;
		}
		self_type operator++(int n)
		{
			(void)n;
			self_type i = *this;
			ptr_ = ptr_->_next;
			return i;
		}
		self_type operator--()
		{
			ptr_ = ptr_->_prev;
			return *this;
		}
		self_type operator--(int n)
		{
			(void)n;
			self_type i = *this;
			ptr_ = ptr_->_prev;
			return i;
		}
		reference operator*() { return *ptr_; }
		pointer operator->() { return ptr_; }
		bool operator==(const self_type &rhs) { return ptr_ == rhs.ptr_; }
		bool operator!=(const self_type &rhs) { return ptr_ != rhs.ptr_; }

	private:
		pointer ptr_;
	};

	template <typename T>
	class Const_Iterator
	{
	public:
		typedef Const_Iterator self_type;
		typedef T value_type;
		typedef T &reference;
		typedef T *pointer;
		typedef std::forward_iterator_tag iterator_category;
		typedef int difference_type;
		Const_Iterator(pointer ptr) : ptr_(ptr){};
		Const_Iterator &operator=(Const_Iterator const &ref)
		{
			ptr_ = ref._ptr;
			return (*this);
		};
		self_type operator++()
		{
			ptr_ = ptr_->_next;
			return *this;
		}
		self_type operator++(int n)
		{
			(void)n;
			self_type i = *this;
			ptr_ = ptr_->_next;
			return i;
		}
		self_type operator--()
		{
			ptr_ = ptr_->_prev;
			return *this;
		}
		self_type operator--(int n)
		{
			(void)n;
			self_type i = *this;
			ptr_ = ptr_->_prev;
			return i;
		}
		reference operator*() { return *ptr_; }
		pointer operator->() { return ptr_; }
		bool operator==(const self_type &rhs) { return ptr_ == rhs.ptr_; }
		bool operator!=(const self_type &rhs) { return ptr_ != rhs.ptr_; }

	private:
		pointer ptr_;
	};

	template <typename T>
	class Reverse_Iterator
	{
	public:
		typedef Reverse_Iterator self_type;
		typedef T value_type;
		typedef T &reference;
		typedef T *pointer;
		typedef std::forward_iterator_tag iterator_category;
		typedef int difference_type;
		Reverse_Iterator(pointer ptr) : ptr_(ptr){};
		Reverse_Iterator &operator=(Reverse_Iterator const &ref)
		{
			ptr_ = ref._ptr;
			return (*this);
		};
		self_type operator++()
		{
			ptr_ = ptr_->_prev;
			return *this;
		}
		self_type operator++(int n)
		{
			(void)n;
			self_type i = *this;
			ptr_ = ptr_->_prev;
			return i;
		}
		self_type operator--()
		{
			ptr_ = ptr_->_next;
			return *this;
		}
		self_type operator--(int n)
		{
			(void)n;
			self_type i = *this;
			ptr_ = ptr_->_next;
			return i;
		}
		self_type operator[](int n)
		{
			for (int i = 0; i < n; i++)
				ptr_ = ptr_->_prev;
			return ptr_;
		}
		self_type base() { return ptr_->_next; };
		reference operator*() { return *ptr_; }
		pointer operator->() { return ptr_; }
		bool operator==(const self_type &rhs) { return ptr_ == rhs.ptr_; }
		bool operator!=(const self_type &rhs) { return ptr_ != rhs.ptr_; }

	private:
		pointer ptr_;
	};

	template <typename T>
	class Const_Reverse_Iterator
	{
	public:
		typedef Const_Reverse_Iterator self_type;
		typedef T value_type;
		typedef T &reference;
		typedef T *pointer;
		typedef std::forward_iterator_tag iterator_category;
		typedef int difference_type;
		Const_Reverse_Iterator(pointer ptr) : ptr_(ptr){};
		Const_Reverse_Iterator &operator=(Const_Reverse_Iterator const &ref)
		{
			ptr_ = ref._ptr;
			return (*this);
		};
		self_type operator++()
		{
			ptr_ = ptr_->_prev;
			return *this;
		}
		self_type operator++(int n)
		{
			(void)n;
			self_type i = *this;
			ptr_ = ptr_->_prev;
			return i;
		}
		self_type operator--()
		{
			ptr_ = ptr_->_next;
			return *this;
		}
		self_type operator--(int n)
		{
			(void)n;
			self_type i = *this;
			ptr_ = ptr_->_next;
			return i;
		}
		self_type operator[](int n)
		{
			for (int i = 0; i < n; i++)
				ptr_ = ptr_->_prev;
			return ptr_;
		}
		self_type base() { return ptr_->_next; };
		reference operator*() { return *ptr_; }
		pointer operator->() { return ptr_; }
		bool operator==(const self_type &rhs) { return ptr_ == rhs.ptr_; }
		bool operator!=(const self_type &rhs) { return ptr_ != rhs.ptr_; }

	private:
		pointer ptr_;
	};

	template <class T, class Alloc = std::allocator<T> >
	class List : public std::allocator<T>
	{
	private:
		Element<T> *_nodes;
		size_t _size;
		size_t _count;

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
		typedef Const_Iterator<Element<T> > const_iterator;
		typedef Reverse_Iterator<Element<T> > reverse_iterator;
		typedef Const_Reverse_Iterator<Element<T> > const_reverse_iterator;

		List();
		explicit List(size_type size, const T &val);
		List(iterator first, iterator last);
		List(const List &other);
		~List();
		List<T, Alloc> &operator=(List const &ref);

		// Iterator
		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;
		reverse_iterator rbegin();
		reverse_iterator rend();
		const_reverse_iterator crbegin() const;
		const_reverse_iterator crend() const;

		// Access members
		reference front();
		const_reference front() const;
		reference back();
		const_reference back() const;

		// Capacity members
		bool empty() const;
		size_type size() const;
		size_type max_size() const;

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
		void resize(size_type count);
		void swap(List &other);
		void reverse();
	};

	// Default constructor
	template <class T, class Alloc>
	List<T, Alloc>::List()
	{
		_nodes = reinterpret_cast<Element<T> *>(allocator_type::allocate(sizeof(Element<T> *)));
		_size = 0;
		_count = 0;
	}

	// Range constructor
	template <class T, class Alloc>
	List<T, Alloc>::List(List<T, Alloc>::iterator first, List<T, Alloc>::iterator last)
	{
		int size = 0;

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
		_nodes = reinterpret_cast<Element<T> *>(this->allocate(sizeof(Element<T> *)));
		Element<T> *tmp = _nodes;
		_nodes->_content = static_cast<T>(size);
		tmp->_next = reinterpret_cast<Element<T> *>(this->allocate(sizeof(Element<T> *)));
		tmp = tmp->_next;
		tmp->_prev = _nodes;
		for (unsigned int i = 0; i < size; i++)
		{
			// Malloc previous tout remplir avec val et next et prev
			tmp->_next = reinterpret_cast<Element<T> *>(this->allocate(sizeof(Element<T> *)));
			tmp->_content = val;
			tmp->_next->_prev = tmp;
			tmp = tmp->_next;
		}
		tmp->_content = static_cast<T>(size);
		tmp->_next = NULL;
	}

	// Overload operator=
	template <class T, class Alloc>
	List<T, Alloc> &List<T, Alloc>::operator=(List const &ref)
	{
		if (*this == ref)
			return *this;
		_size = ref._size;
		_count = ref._count;
		// for (unsigned int i = 0; i <)
		_nodes = ref._nodes;
		return *this;
	}

	// Destructor
	template <class T, class Alloc>
	List<T, Alloc>::~List()
	{
		Element<T> *next;
		Element<T> *elem;

		elem = _nodes;
		for (unsigned int i = 0; i < _size + 2; i++)
		{
			next = elem->_next;
			if (next)
				elem = next;
			else
				this->deallocate(reinterpret_cast<int *>(elem), sizeof(Element<T> *));
			if (next)
				this->deallocate(reinterpret_cast<int *>(next->_prev), sizeof(Element<T> *));
			next = NULL;
		}
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

	template <class T, class Alloc>
	typename List<T, Alloc>::size_type List<T, Alloc>::max_size() const
	{

		return std::min<size_type>(allocator_type::max_size(), static_cast<size_type>(std::numeric_limits<difference_type>::max())) / sizeof(size_type);
	}

	// Members access
	template <class T, class Alloc>
	void List<T, Alloc>::clear()
	{
		for (unsigned int i = 0; i < _size; i++)
			;
	}

	// Members access push_back
	template <class T, class Alloc>
	void List<T, Alloc>::push_back(const T &value)
	{
		resize(_size + 1);
		Element<T> *tmp = _nodes->_next;
		for (size_t i = 1; i < _size; i++)
			tmp = tmp->_next;
		tmp->_content = value;
	}

	// Members access push_front
	template <class T, class Alloc>
	void List<T, Alloc>::push_front(const T &value)
	{
		resize(_size + 1);
		Element<T> *tmp = _nodes->_next;
		for (size_t i = 1; i < _size; i++)
			tmp = tmp->_next;
		tmp->_content = value;
		tmp->_prev->_next = tmp->_next;
		tmp->_next->_prev = tmp->_prev;
		tmp->_next = _nodes->_next;
		tmp->_next->_prev = tmp;
		_nodes->_next = tmp;
		tmp->_prev = _nodes;
	}

		// Members access reverse
	template <class T, class Alloc>
	void List<T, Alloc>::reverse()
	{
		T swap;
		Element<T> *first = _nodes->_next;
		Element<T> *last = _nodes->_next;
		for (size_t i = 1; i < _size; i++)
			last = last->_next;
		for (size_t i = 0; i < _size / 2; i++)
		{
			swap = first->_content;
			first->_content = last->_content;
			last->_content = swap;
			last = last->_prev;
			first = first->_next;
		}
	}

	// Members access resize
	template <class T, class Alloc>
	void List<T, Alloc>::resize(size_type count)
	{
		if (_size < count)
		{
			Element<T> *tmp = _nodes;

			for (size_t i = 0; i < _size; i++)
				tmp = tmp->_next;
			Element<T> *end = tmp->_next;
			for (size_t i = 0; i < count - _size; i++)
			{
				tmp->_next = reinterpret_cast<Element<T> *>(this->allocate(sizeof(Element<T> *)));
				tmp->_next->_content = T();
				tmp->_next->_prev = tmp;
				tmp = tmp->_next;
			}
			tmp->_next = end;
			end->_prev = tmp;
			end->_content = static_cast<T>(count);
			_nodes->_content = static_cast<T>(count);
			_size = count;
		}
	}

	//Iterators
	template <class T, class Alloc>
	typename List<T, Alloc>::iterator List<T, Alloc>::begin()
	{
		return Iterator<Element<T> >(_nodes->_next);
	}

	template <class T, class Alloc>
	typename List<T, Alloc>::iterator List<T, Alloc>::end()
	{
		Element<T> *tmp = _nodes->_next;
		for (size_t i = 1; i <= _size; i++)
			tmp = tmp->_next;
		return Iterator<Element<T> >(tmp);
	}

	template <class T, class Alloc>
	typename List<T, Alloc>::const_iterator List<T, Alloc>::begin() const
	{
		return Const_Iterator<Element<T> >(_nodes->_next);
	}

	template <class T, class Alloc>
	typename List<T, Alloc>::const_iterator List<T, Alloc>::end() const
	{
		Element<T> *tmp = _nodes->_next;
		for (size_t i = 1; i < _size; i++)
			tmp = tmp->_next;
		return Const_Iterator<Element<T> >(tmp);
	}

	template <class T, class Alloc>
	typename List<T, Alloc>::reverse_iterator List<T, Alloc>::rbegin()
	{
		Element<T> *tmp = _nodes->_next;
		for (size_t i = 1; i < _size; i++)
			tmp = tmp->_next;
		return Reverse_Iterator<Element<T> >(tmp);
	}

	template <class T, class Alloc>
	typename List<T, Alloc>::reverse_iterator List<T, Alloc>::rend()
	{
		return Reverse_Iterator<Element<T> >(_nodes);
	}

	template <class T, class Alloc>
	typename List<T, Alloc>::const_reverse_iterator List<T, Alloc>::crbegin() const
	{
		Element<T> *tmp = _nodes->_next;
		for (size_t i = 1; i < _size; i++)
			tmp = tmp->_next;
		return Const_Reverse_Iterator<Element<T> >(tmp);
	}

	template <class T, class Alloc>
	typename List<T, Alloc>::const_reverse_iterator List<T, Alloc>::crend() const
	{
		return Const_Reverse_Iterator<Element<T> >(_nodes);
	}
}

template <typename T>
std::ostream &operator<<(std::ostream &output, const ft::Element<T> &e)
{
	output << e._content;
	return output;
}

#endif
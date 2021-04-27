
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
		typedef Element<T> value_type;
		typedef Element<T> &reference;
		typedef Element<T> *pointer;
		typedef std::forward_iterator_tag iterator_category;
		typedef int difference_type;
		Iterator(pointer ptr) : _ptr(ptr){};
		Iterator &operator=(Iterator const &ref)
		{
			_ptr = ref._ptr;
			return (*this);
		};
		self_type operator++()
		{
			_ptr = _ptr->_next;
			return *this;
		}
		self_type operator++(int n)
		{
			(void)n;
			self_type i = *this;
			_ptr = _ptr->_next;
			return i;
		}
		self_type operator--()
		{
			_ptr = _ptr->_prev;
			return *this;
		}
		self_type operator--(int n)
		{
			(void)n;
			self_type i = *this;
			_ptr = _ptr->_prev;
			return i;
		}
		T operator*() { return _ptr->_content; }
		pointer operator->() { return _ptr; }
		bool operator==(const self_type &rhs) { return _ptr == rhs._ptr; }
		bool operator!=(const self_type &rhs) { return _ptr != rhs._ptr; }

	private:
		pointer _ptr;
	};

	template <typename T>
	class Const_Iterator
	{
	public:
		typedef Const_Iterator self_type;
		typedef Element<T> value_type;
		typedef Element<T> &reference;
		typedef Element<T> *pointer;
		typedef std::forward_iterator_tag iterator_category;
		typedef int difference_type;
		Const_Iterator(pointer ptr) : _ptr(ptr){};
		Const_Iterator &operator=(Const_Iterator const &ref)
		{
			_ptr = ref._ptr;
			return (*this);
		};
		self_type operator++()
		{
			_ptr = _ptr->_next;
			return *this;
		}
		self_type operator++(int n)
		{
			(void)n;
			self_type i = *this;
			_ptr = _ptr->_next;
			return i;
		}
		self_type operator--()
		{
			_ptr = _ptr->_prev;
			return *this;
		}
		self_type operator--(int n)
		{
			(void)n;
			self_type i = *this;
			_ptr = _ptr->_prev;
			return i;
		}
		T operator*() { return _ptr->_content; }
		pointer operator->() { return _ptr; }
		bool operator==(const self_type &rhs) { return _ptr == rhs._ptr; }
		bool operator!=(const self_type &rhs) { return _ptr != rhs._ptr; }

	private:
		pointer _ptr;
	};

	template <typename T>
	class Reverse_Iterator
	{
	public:
		typedef Reverse_Iterator self_type;
		typedef Element<T> value_type;
		typedef Element<T> &reference;
		typedef Element<T> *pointer;
		typedef std::forward_iterator_tag iterator_category;
		typedef int difference_type;
		Reverse_Iterator(pointer ptr) : _ptr(ptr){};
		Reverse_Iterator &operator=(Reverse_Iterator const &ref)
		{
			_ptr = ref._ptr;
			return (*this);
		};
		self_type operator++()
		{
			_ptr = _ptr->_prev;
			return *this;
		}
		self_type operator++(int n)
		{
			(void)n;
			self_type i = *this;
			_ptr = _ptr->_prev;
			return i;
		}
		self_type operator--()
		{
			_ptr = _ptr->_next;
			return *this;
		}
		self_type operator--(int n)
		{
			(void)n;
			self_type i = *this;
			_ptr = _ptr->_next;
			return i;
		}
		T operator*() { return _ptr->_content; }
		pointer operator->() { return _ptr; }
		bool operator==(const self_type &rhs) { return _ptr == rhs._ptr; }
		bool operator!=(const self_type &rhs) { return _ptr != rhs._ptr; }

	private:
		pointer _ptr;
	};

	template <typename T>
	class Const_Reverse_Iterator
	{
	public:
		typedef Const_Reverse_Iterator self_type;
		typedef Element<T> value_type;
		typedef Element<T> &reference;
		typedef Element<T> *pointer;
		typedef std::forward_iterator_tag iterator_category;
		typedef int difference_type;
		Const_Reverse_Iterator(pointer ptr) : _ptr(ptr){};
		Const_Reverse_Iterator &operator=(Const_Reverse_Iterator const &ref)
		{
			_ptr = ref._ptr;
			return (*this);
		};
		self_type operator++()
		{
			_ptr = _ptr->_prev;
			return *this;
		}
		self_type operator++(int n)
		{
			(void)n;
			self_type i = *this;
			_ptr = _ptr->_prev;
			return i;
		}
		self_type operator--()
		{
			_ptr = _ptr->_next;
			return *this;
		}
		self_type operator--(int n)
		{
			(void)n;
			self_type i = *this;
			_ptr = _ptr->_next;
			return i;
		}
		T operator*() { return _ptr->_content; }
		pointer operator->() { return _ptr; }
		bool operator==(const self_type &rhs) { return _ptr == rhs._ptr; }
		bool operator!=(const self_type &rhs) { return _ptr != rhs._ptr; }

	private:
		pointer _ptr;
	};

	template <class T, class Alloc = std::allocator<T> >
	class List : public std::allocator<T>
	{
	private:
		Element<T> *_nodes;
		size_t _size;
		size_t _count;
		Alloc _alloc;

	public:
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef size_t size_type;
		typedef ptrdiff_t difference_type;
		typedef typename Alloc::reference reference;
		typedef value_type &const_reference;
		typedef typename Alloc::pointer pointer;
		typedef typename Alloc::const_pointer const_pointer;
		typedef Iterator<T> iterator;
		typedef Const_Iterator<T> const_iterator;
		typedef Reverse_Iterator<T> reverse_iterator;
		typedef Const_Reverse_Iterator<T> const_reverse_iterator;

		List();
		explicit List(const Alloc &alloc);
		explicit List(size_type size, const T &val = value_type());
		template <class InputIterator>
		List(InputIterator first, InputIterator last);
		List(List &other);
		~List();
		List<T, Alloc> &operator=(List const &ref);

		// Iterator
		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;
		reverse_iterator rbegin();
		reverse_iterator rend();
		const_reverse_iterator rbegin() const;
		const_reverse_iterator rend() const;

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
		void assign(size_type n, const value_type &val);
		void assign(iterator first, iterator last);
		iterator insert(iterator pos, const T &value);
		void insert(iterator pos, size_type count, const T &value);
		void insert(iterator pos, iterator first, iterator last);
		iterator erase(iterator pos);
		iterator erase(iterator first, iterator last);
		void push_back(const T &value);
		void pop_back();
		void push_front(const T &value);
		void pop_front();
		void resize(size_type count);
		void swap(List &other);
		void reverse();
		void remove(const T &value);

		template <class UnaryPredicate>
		void remove_if(UnaryPredicate p);
		void unique();
		template <class BinaryPredicate>
		void unique(BinaryPredicate binary_pred);
		void sort();
		template <class Compare>
		void sort(Compare p);
		void merge(List &x);
		template <class Compare>
		void merge(List &x, Compare p);
		void splice(iterator position, List &x);
		void splice(iterator pos, List &other, iterator it);
		void splice(iterator pos, List &other, iterator first, iterator last);
	};

	// Default constructor
	template <class T, class Alloc>
	List<T, Alloc>::List()
	{
		_nodes = reinterpret_cast<Element<T> *>(this->allocate(sizeof(Element<T> *)));
		_nodes->_content = 0;
		_nodes->_prev = _nodes;
		_nodes->_next = _nodes;
		_size = 0;
		_count = 0;
	}

	// Allocator constructor
	template <class T, class Alloc>
	List<T, Alloc>::List(const Alloc &alloc)
	{
		(void)alloc;
		_nodes = reinterpret_cast<Element<T> *>(this->allocate(sizeof(Element<T> *)));
		_nodes->_content = 0;
		_nodes->_prev = _nodes;
		_nodes->_next = _nodes;
		_size = 0;
		_count = 0;
	}

	// Fill constructor
	template <class T, class Alloc>
	List<T, Alloc>::List(size_t size, const T &val) : _size(size), _count(0)
	{
		_nodes = reinterpret_cast<Element<T> *>(this->allocate(sizeof(Element<T> *)));
		Element<T> *tmp = _nodes;
		for (size_t i = 0; i < _size; i++)
		{
			tmp->_next = reinterpret_cast<Element<T> *>(this->allocate(sizeof(Element<T> *)));
			if (val == T())
				tmp->_content = T();
			else
				tmp->_content = val;
			tmp->_next->_prev = tmp;
			tmp = tmp->_next;
			_count++;
		}
		tmp->_content = static_cast<T>(size);
		tmp->_next = _nodes;
		_nodes->_prev = tmp;
	}

	// Range constructor
	template <class T, class Alloc>
	template <class InputIterator>
	List<T, Alloc>::List(InputIterator first, InputIterator last)
	{
		if (std::is_integral<InputIterator>::value)
		{
			_size = static_cast<size_t>(first);
			_nodes = reinterpret_cast<Element<T> *>(this->allocate(sizeof(Element<T> *)));
			Element<T> *tmp = _nodes;
			for (size_t i = 0; i < _size; i++)
			{
				tmp->_next = reinterpret_cast<Element<T> *>(this->allocate(sizeof(Element<T> *)));
				tmp->_content = static_cast<T>(last);
				tmp->_next->_prev = tmp;
				tmp = tmp->_next;
				_count++;
			}
			tmp->_content = static_cast<T>(_size);
			tmp->_next = _nodes;
			_nodes->_prev = tmp;
			return;
		}
		_size = 0;
		InputIterator copy = first;
		InputIterator it = first;
		while (copy != last)
		{
			copy++;
			_size++;
		}
		_nodes = reinterpret_cast<Element<T> *>(this->allocate(sizeof(Element<T> *)));
		Element<T> *tmp = _nodes;
		Element<T> save;
		while (it != last)
		{
			tmp->_next = reinterpret_cast<Element<T> *>(this->allocate(sizeof(Element<T> *)));
			save._content = static_cast<T>(it);
			tmp->_content = save._content;
			tmp->_next->_prev = tmp;
			tmp = tmp->_next;
			it++;
			_count++;
		}
		tmp->_content = static_cast<T>(_size);
		tmp->_next = _nodes;
		_nodes->_prev = tmp;
	}

	// Constructor per copy
	template <class T, class Alloc>
	List<T, Alloc>::List(List<T, Alloc> &ref)
	{
		_size = 0;
		_count = ref._count;
		_nodes = reinterpret_cast<Element<T> *>(this->allocate(sizeof(Element<T> *)));
		_nodes->_next = _nodes;
		_nodes->_prev = _nodes;
		if (ref._size > 0)
			insert(begin(), ref.begin(), ref.end());
		_nodes = _nodes->_next;
	}

	// Overload operator=
	template <class T, class Alloc>
	List<T, Alloc> &List<T, Alloc>::operator=(List const &ref)
	{
		if (*this == ref)
			return *this;
		if (_size > 0)
			clear();
		_nodes = reinterpret_cast<Element<T> *>(this->allocate(sizeof(Element<T> *)));
		_nodes->_next = _nodes;
		_nodes->_prev = _nodes;
		insert(begin(), ref.begin(), ref.end());
		_nodes = _nodes->_next;
		return *this;
	}

	// Destructor
	template <class T, class Alloc>
	List<T, Alloc>::~List()
	{
		Element<T> *next;
		Element<T> *elem;

		elem = _nodes;
		for (unsigned int i = 0; i < _size + 1; i++)
		{
			next = elem->_next;
			if (i + 1 < _size + 1)
				elem = next;
			else
				this->deallocate(reinterpret_cast<T *>(elem), sizeof(Element<T> *));
			if (i + 1 < _size + 1)
				this->deallocate(reinterpret_cast<T *>(next->_prev), sizeof(Element<T> *));
			next = NULL;
		}
	}

	// Access Member
	// Front access member
	template <class T, class Alloc>
	typename List<T, Alloc>::reference List<T, Alloc>::front()
	{
		return (_nodes->_content);
	}
	// Front access const member
	template <class T, class Alloc>
	typename List<T, Alloc>::const_reference List<T, Alloc>::front() const
	{
		return (_nodes->_content);
	}

	// Back access member
	template <class T, class Alloc>
	typename List<T, Alloc>::reference List<T, Alloc>::back()
	{
		// Element<T> *tmp = _nodes->_next;
		// for (size_t i = 1; i < _size; i++)
		// 	tmp = tmp->_next;
		return (_nodes->_prev->_prev->_content);
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
		return (_size ? false : true);
	}

	template <class T, class Alloc>
	typename List<T, Alloc>::size_type List<T, Alloc>::size() const
	{
		return _size;
	}

	template <class T, class Alloc>
	typename List<T, Alloc>::size_type List<T, Alloc>::max_size() const
	{
		return std::numeric_limits<size_type>::max() / sizeof(*_nodes);
	}

	// Members access push_back
	template <class T, class Alloc>
	void List<T, Alloc>::push_back(const T &value)
	{
		resize(_size + 1);
		Element<T> *tmp = _nodes->_prev->_prev;
		tmp->_content = value;
		_count++;
	}

	template <class T, class Alloc>
	void List<T, Alloc>::pop_back()
	{
		if (!_size)
			return;
		Element<T> *last = _nodes->_prev->_prev;
		last->_prev->_next = last->_next;
		last->_next->_prev = last->_prev;
		this->deallocate(reinterpret_cast<T *>(last), sizeof(Element<T> *));
		_size--;
		_count--;
	}

	// Members access push_front
	template <class T, class Alloc>
	void List<T, Alloc>::push_front(const T &value)
	{
		resize(_size + 1);
		Element<T> *elem = _nodes->_prev->_prev;
		Element<T> *last = elem->_prev;
		Element<T> *end = _nodes->_prev;
		elem->_content = value;
		last->_next = end;
		end->_prev = last;
		end->_next = elem;
		elem->_prev = end;
		elem->_next = _nodes;
		_nodes->_prev = elem;
		_nodes = elem;
	}

	template <class T, class Alloc>
	void List<T, Alloc>::pop_front()
	{
		if (!_size)
			return;
		Element<T> *first = _nodes;
		_nodes->_prev->_next = _nodes->_next;
		_nodes->_next->_prev = _nodes->_prev;
		_nodes = _nodes->_next;
		this->deallocate(reinterpret_cast<T *>(first), sizeof(Element<T> *));
		_size--;
		_count--;
	}

	// Members access reverse
	template <class T, class Alloc>
	void List<T, Alloc>::reverse()
	{
		size_t i = 0;
		Element<T> *tmp = _nodes;
		Element<T> *end = _nodes->_prev;
		Element<T> *begin = end->_prev;
		while (i != _size + 1)
		{
			Element<T> *tmp2 = tmp;
			tmp = tmp->_next;
			Element<T> *tmp3 = tmp2->_prev;
			tmp2->_prev = tmp2->_next;
			tmp2->_next = tmp3;
			++i;
		}
		_nodes = begin;
	}

	// Modifiers resize
	template <class T, class Alloc>
	void List<T, Alloc>::resize(size_type count)
	{
		if (count == 1)
		{
			_nodes->_prev->_prev->_content = static_cast<T>(count);
			return;
		}
		if (_size < count)
		{
			Element<T> *tmp = _nodes;
			Element<T> *end = tmp->_prev;
			tmp = end->_prev;
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
			_size = count;
		}
		else
		{

			Element<T> *tmp = _nodes;
			size_t i;
			for (i = 1; i < count; i++)
				tmp = tmp->_next;
			Element<T> *last = tmp;
			tmp = tmp->_next;
			for (size_t j = ++i; j < _size; j++)
			{
				tmp = tmp->_next;
				this->deallocate(reinterpret_cast<T *>(tmp->_prev), sizeof(Element<T> *));
			}
			Element<T> *end = tmp->_next;
			this->deallocate(reinterpret_cast<T *>(tmp), sizeof(Element<T> *));
			last->_next = end;
			end->_prev = last;
			end->_content = static_cast<T>(count);
			_size = count;
			_count = count;
		}
	}

	// Modifiers erase
	template <class T, class Alloc>
	typename List<T, Alloc>::iterator List<T, Alloc>::erase(List<T, Alloc>::iterator pos)
	{
		List<T, Alloc>::iterator start = begin();
		Element<T> *tmp = _nodes;
		while (start != pos)
		{
			tmp = tmp->_next;
			start++;
		}
		tmp->_prev->_next = tmp->_next;
		tmp->_next->_prev = tmp->_prev;
		this->deallocate(reinterpret_cast<T *>(tmp), sizeof(Element<T> *));
		_size--;
		_count--;
		_nodes->_prev->_content = static_cast<T>(_size);
		return start;
	}

	// Modifiers erase range
	template <class T, class Alloc>
	typename List<T, Alloc>::iterator List<T, Alloc>::erase(List<T, Alloc>::iterator first, List<T, Alloc>::iterator last)
	{
		List<T, Alloc>::iterator start = first;
		List<T, Alloc>::iterator begin = this->begin();
		Element<T> *save = _nodes;
		while (begin != first)
		{
			begin++;
			save = save->_next;
		}
		Element<T> *tmp = save->_next;
		while (start != last && _size-- && _count--)
		{
			tmp = tmp->_next;
			this->deallocate(reinterpret_cast<T *>(tmp->_prev), sizeof(Element<T> *));
			start++;
		}
		save->_next = tmp;
		tmp->_prev = save;
		_nodes->_prev->_content = static_cast<T>(_size);
		return start;
	}

	// Modifiers insert
	template <class T, class Alloc>
	typename List<T, Alloc>::iterator List<T, Alloc>::insert(List<T, Alloc>::iterator pos, const T &value)
	{
		List<T, Alloc>::iterator copy = pos;
		List<T, Alloc>::iterator start = this->begin();
		Element<T> *tmp = _nodes;

		while (start != copy)
		{
			tmp = tmp->_next;
			start++;
		}
		Element<T> *save = tmp->_prev;
		if (save != _nodes->_prev)
		{
			Element<T> *elem = reinterpret_cast<Element<T> *>(this->allocate(sizeof(Element<T> *)));
			elem->_content = value;
			tmp->_prev = elem;
			save->_next = elem;
			elem->_prev = save;
			elem->_next = tmp;
			_size++;
			_count++;
		}
		else
			push_front(value);
		return (++copy);
	}

	// Modifiers insert pos with count
	template <class T, class Alloc>
	void List<T, Alloc>::insert(List<T, Alloc>::iterator pos, size_type count, const T &value)
	{
		Element<T> *H = _nodes->_prev;
		Element<T> *D = _nodes->_prev->_prev;
		Element<T> *B = pos->_prev->_next;
		Element<T> *A = pos->_prev;
		resize(_size + count);
		Element<T> *G = _nodes->_prev->_prev;
		Element<T> *E = G;
		for (size_t i = 0; i < count; i++)
		{
			E->_content = value;
			E = E->_prev;
		}
		E = E->_next;

		E->_prev = A;
		A->_next = E;

		B->_prev = G;
		G->_next = B;

		D->_next = H;
		H->_prev = D;
		if (B == _nodes)
			_nodes = E;
	}

	// Modifiers insert range
	template <class T, class Alloc>
	void List<T, Alloc>::insert(List<T, Alloc>::iterator pos, List<T, Alloc>::iterator first, List<T, Alloc>::iterator last)
	{

		List<T, Alloc>::iterator start = static_cast<List<T, Alloc>::iterator>(first);

		size_t count = 0;
		while (start != last)
		{
			start++;
			count++;
		}
		resize(_size + count);
		Element<T> *save = pos->_next;
		Element<T> *tmp = save;
		List<T, Alloc>::iterator copy = first;
		while (copy != last)
		{
			tmp->_content = copy->_content;
			tmp = tmp->_next;
			copy++;
		}
		save->_prev = tmp;
		tmp->_next = save;
	}

	// Modifiers assign
	template <class T, class Alloc>
	void List<T, Alloc>::assign(size_type n, const value_type &val)
	{
		resize(n);
		Element<T> *tmp = _nodes;
		for (size_t i = 0; i < n; i++)
		{
			tmp->_content = val;
			tmp = tmp->_next;
		}
	}

	// Modifiers assign range
	template <class T, class Alloc>
	void List<T, Alloc>::assign(List<T, Alloc>::iterator first, List<T, Alloc>::iterator last)
	{
		List<T, Alloc>::iterator copy = first;
		List<T, Alloc>::iterator start = first;
		size_t size = 0;
		while (copy != last)
		{
			copy++;
			size++;
		}
		resize(size);
		Element<T> *tmp = _nodes;
		while (start != last)
		{
			tmp->_content = start->_content;
			tmp = tmp->_next;
			start++;
		}
	}

	template <class T, class Alloc>
	void List<T, Alloc>::clear()
	{
		Element<T> *tmp = _nodes;
		Element<T> *end = _nodes->_prev;
		while (tmp != end)
		{
			tmp = tmp->_next;
			this->deallocate(reinterpret_cast<T *>(tmp->_prev), sizeof(Element<T> *));
		}
		_nodes = end;
		_nodes->_next = _nodes;
		_nodes->_prev = _nodes;
		_nodes->_content = static_cast<T>(0);
		_count = 0;
		_size = 0;
	}

	template <class T, class Alloc>
	void List<T, Alloc>::remove(const T &value)
	{
		Element<T> *tmp = _nodes;
		Element<T> *end = _nodes->_prev;

		while (tmp != end)
		{
			if (tmp->_content == value)
			{
				tmp->_prev->_next = tmp->_next;
				tmp->_next->_prev = tmp->_prev;
				Element<T> *to_delete = tmp;
				tmp = tmp->_next;
				this->deallocate(reinterpret_cast<T *>(to_delete), sizeof(Element<T> *));
				_count--;
				_size--;
			}
			else
				tmp = tmp->_next;
		}
	}

	template <class T, class Alloc>
	template <class UnaryPredicate>
	void List<T, Alloc>::remove_if(UnaryPredicate p)
	{
		Element<T> *tmp = _nodes;
		Element<T> *end = _nodes->_prev;

		while (tmp != end)
		{
			if (p(tmp->_content))
			{
				tmp->_prev->_next = tmp->_next;
				tmp->_next->_prev = tmp->_prev;
				Element<T> *to_delete = tmp;
				tmp = tmp->_next;
				if (to_delete == _nodes)
					_nodes = tmp;
				this->deallocate(reinterpret_cast<T *>(to_delete), sizeof(Element<T> *));
				_count--;
				_size--;
			}
			else
				tmp = tmp->_next;
		}
	}

	template <class T, class Alloc>
	void List<T, Alloc>::unique()
	{
		Element<T> *tmp = _nodes;
		Element<T> *end = _nodes->_prev;

		while (tmp != end)
		{
			Element<T> *begin = tmp->_next;
			while (begin != end && begin->_content == tmp->_content)
			{
				tmp->_next = begin->_next;
				begin->_next->_prev = tmp;
				Element<T> *to_delete = begin;
				begin = begin->_next;
				this->deallocate(reinterpret_cast<T *>(to_delete), sizeof(Element<T> *));
				_count--;
				_size--;
			}
			tmp = tmp->_next;
		}
	}

	template <class T, class Alloc>
	template <class BinaryPredicate>
	void List<T, Alloc>::unique(BinaryPredicate p)
	{
		Element<T> *tmp = _nodes;
		Element<T> *end = _nodes->_prev;

		while (tmp != end)
		{
			Element<T> *begin = tmp->_next;
			while (begin != end && p(begin->_content, tmp->_content))
			{
				tmp->_next = begin->_next;
				begin->_next->_prev = tmp;
				Element<T> *to_delete = begin;
				begin = begin->_next;
				this->deallocate(reinterpret_cast<T *>(to_delete), sizeof(Element<T> *));
				_count--;
				_size--;
			}
			tmp = tmp->_next;
		}
	}

	template <class T, class Alloc>
	void List<T, Alloc>::sort()
	{
		Element<T> *tmp = _nodes;
		Element<T> *end = _nodes->_prev;

		while (tmp != end)
		{
			Element<T> *tn = tmp->_next;
			Element<T> *begin = tmp;
			while (begin != end)
			{
				if (begin != tmp && begin->_content < tmp->_content)
				{
					Element<T> *b_prev = begin->_prev;
					Element<T> *b_next = begin->_next;
					Element<T> *t_prev = tmp->_prev;
					Element<T> *t_next = tmp->_next;

					if (begin == tmp->_next)
					{
						t_prev->_next = begin;
						begin->_prev = t_prev;
						b_next->_prev = tmp;
						tmp->_next = b_next;
						begin->_next = tmp;
						tmp->_prev = begin;
					}
					else
					{
						t_prev->_next = begin;
						t_next->_prev = begin;
						begin->_prev = t_prev;
						begin->_next = t_next;

						b_prev->_next = tmp;
						b_next->_prev = tmp;
						tmp->_prev = b_prev;
						tmp->_next = b_next;
					}
					if (tmp == _nodes)
						_nodes = begin;
					begin = begin->_next;
				}
				else
				{
					begin = begin->_next;
				}
			}
			tmp = tn;
		}
	}

	template <class T, class Alloc>
	template <class Compare>
	void List<T, Alloc>::sort(Compare p)
	{
		Element<T> *tmp = _nodes;
		Element<T> *end = _nodes->_prev;

		while (tmp != end)
		{
			Element<T> *tn = tmp->_next;
			Element<T> *begin = tmp;
			while (begin != end)
			{
				if (begin != tmp && p(begin->_content, tmp->_content))
				{
					Element<T> *b_prev = begin->_prev;
					Element<T> *b_next = begin->_next;
					Element<T> *t_prev = tmp->_prev;
					Element<T> *t_next = tmp->_next;

					if (begin == tmp->_next)
					{
						t_prev->_next = begin;
						begin->_prev = t_prev;
						b_next->_prev = tmp;
						tmp->_next = b_next;
						begin->_next = tmp;
						tmp->_prev = begin;
					}
					else
					{
						t_prev->_next = begin;
						t_next->_prev = begin;
						begin->_prev = t_prev;
						begin->_next = t_next;

						b_prev->_next = tmp;
						b_next->_prev = tmp;
						tmp->_prev = b_prev;
						tmp->_next = b_next;
					}
					if (tmp == _nodes)
						_nodes = begin;
					begin = begin->_next;
				}
				else
				{
					begin = begin->_next;
				}
			}
			tmp = tn;
		}
	}
	template <class T, class Alloc>
	void List<T, Alloc>::merge(List &x)
	{
		_count += x._size;
		_size += x._size;
		Element<T> *end = _nodes->_prev;
		Element<T> *last = end->_prev;
		Element<T> *tmp = x._nodes;
		x._nodes = x._nodes->_prev;
		while (tmp != x._nodes)
		{
			last->_next = tmp;
			tmp->_prev = last;
			last = tmp;
			tmp = tmp->_next;
		}
		last->_next = end;
		end->_prev = last;
		x._nodes->_prev = x._nodes;
		x._nodes->_next = x._nodes;
		x._count = 0;
		x._size = 0;
	}
	template <class T, class Alloc>
	void List<T, Alloc>::splice(iterator position, List &x)
	{
		_count += x._size;
		_size += x._size;
		Element<T> *save = position->_next->_prev;
		Element<T> *tmp = x._nodes;
		Element<T> *xend = tmp->_prev;

		xend->_prev->_next = save;
		save->_prev->_next = tmp;
		tmp->_prev = save->_prev;
		save->_prev = xend->_prev;

		_nodes->_prev->_content = static_cast<T>(_size);
		xend->_content = 0;
		x._nodes = xend;
		xend->_prev = xend;
		xend->_next = xend;
		x._count = 0;
		x._size = 0;
		if (position == begin())
			_nodes = tmp;
	}

	template <class T, class Alloc>
	void List<T, Alloc>::splice(iterator pos, List &list, iterator it)
	{
		_count += 1;
		_size += 1;
		Element<T> *save = pos->_next->_prev;
		Element<T> *tmp = it->_prev->_next;
		Element<T> *xend = tmp->_prev;

		xend->_next = tmp->_next;
		tmp->_next->_prev = xend;

		tmp->_prev = save->_prev;
		tmp->_prev->_next = tmp;
		save->_prev = tmp;
		tmp->_next = save;
		_nodes->_prev->_content = static_cast<T>(_size);

		if (pos == begin())
			_nodes = tmp;
		if (it == list.begin())
			list._nodes = xend->_next;
		list._nodes->_prev->_content -= 1;
		list._count -= 1;
		list._size -= 1;
	}

	template <class T, class Alloc>
	void List<T, Alloc>::swap(List &list)
	{
		Element<T> *tmp = list._nodes;
		list._nodes = _nodes;
		_nodes = tmp;
		size_t i;
		i = list._size;
		list._size = _size;
		_size = i;
		i = list._count;
		list._count = _count;
		_count = i;
	}

	template <class T, class Alloc>
	void List<T, Alloc>::splice(iterator pos, List &other, iterator first, iterator last)
	{
		Element<T> *A = pos->_prev;
		Element<T> *B = A->_next;
		Element<T> *E = first->_next->_prev;
		Element<T> *F = last->_prev;
		Element<T> *end = F->_next;
		Element<T> *tmp = E;

		while (tmp != end)
		{
			tmp = tmp->_next;
			_size++;
			_count++;
			other._size--;
			other._count--;
		}
		E->_prev->_next = F->_next;
		F->_next->_prev = E->_prev;

		A->_next = E;
		E->_prev = A;

		F->_next = B;
		B->_prev = F;
		if (pos == begin())
			_nodes = E;
		if (first == other.begin())
			other._nodes = end;
		_nodes->_prev->_content = static_cast<T>(_size);
		other._nodes->_prev->_content = static_cast<T>(other._size);
	}

	//Iterators
	template <class T, class Alloc>
	typename List<T, Alloc>::iterator List<T, Alloc>::begin()
	{
		return Iterator<T>(_nodes);
	}

	template <class T, class Alloc>
	typename List<T, Alloc>::iterator List<T, Alloc>::end()
	{
		return Iterator<T>(_nodes->_prev);
	}

	template <class T, class Alloc>
	typename List<T, Alloc>::const_iterator List<T, Alloc>::begin() const
	{
		return Const_Iterator<T>(_nodes->_next);
	}

	template <class T, class Alloc>
	typename List<T, Alloc>::const_iterator List<T, Alloc>::end() const
	{
		return Const_Iterator<T>(_nodes);
	}

	template <class T, class Alloc>
	typename List<T, Alloc>::reverse_iterator List<T, Alloc>::rbegin()
	{
		return Reverse_Iterator<T>(_nodes->_prev->_prev);
	}

	template <class T, class Alloc>
	typename List<T, Alloc>::reverse_iterator List<T, Alloc>::rend()
	{
		return Reverse_Iterator<T>(_nodes->_prev);
	}

	template <class T, class Alloc>
	typename List<T, Alloc>::const_reverse_iterator List<T, Alloc>::rbegin() const
	{
		return Const_Reverse_Iterator<T>(_nodes->_prev->_prev);
	}

	template <class T, class Alloc>
	typename List<T, Alloc>::const_reverse_iterator List<T, Alloc>::rend() const
	{
		return Const_Reverse_Iterator<T>(_nodes->_prev);
	}

}

template <typename T>
std::ostream &operator<<(std::ostream &output, const ft::Element<T> &e)
{
	output << e._content;
	return output;
}

#endif

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
			ptr_ = ref.ptr_;
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
		void unique (BinaryPredicate binary_pred);
		void sort();
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
	List<T, Alloc>::List(List<T, Alloc>::iterator first, List<T, Alloc>::iterator last) : _size(0)
	{
		List<T, Alloc>::iterator copy = first;
		List<T, Alloc>::iterator it = first;
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
			save = *it;
			tmp->_content = save._content;
			tmp->_next->_prev = tmp;
			tmp = tmp->_next;
			it++;
		}
		tmp->_content = static_cast<T>(_size);
		tmp->_next = _nodes;
		_nodes->_prev = tmp;
	}

	// Fill constructor
	template <class T, class Alloc>
	List<T, Alloc>::List(size_t size, const T &val) : _size(size)
	{
		_nodes = reinterpret_cast<Element<T> *>(this->allocate(sizeof(Element<T> *)));
		Element<T> *tmp = _nodes;
		for (unsigned int i = 0; i < size; i++)
		{
			tmp->_next = reinterpret_cast<Element<T> *>(this->allocate(sizeof(Element<T> *)));
			tmp->_content = val;
			tmp->_next->_prev = tmp;
			tmp = tmp->_next;
		}
		tmp->_content = static_cast<T>(size);
		tmp->_next = _nodes;
		_nodes->_prev = tmp;
	}

	// Overload operator=
	template <class T, class Alloc>
	List<T, Alloc> &List<T, Alloc>::operator=(List const &ref)
	{
		if (*this == ref)
			return *this;
		_size = ref._size;
		_count = ref._count;
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
		for (unsigned int i = 0; i < _size + 1; i++)
		{
			next = elem->_next;
			if (i + 1 < _size + 1)
				elem = next;
			else
				this->deallocate(reinterpret_cast<int *>(elem), sizeof(Element<T> *));
			if (i + 1 < _size + 1)
				this->deallocate(reinterpret_cast<int *>(next->_prev), sizeof(Element<T> *));
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
		this->deallocate(reinterpret_cast<int *>(last), sizeof(Element<T> *));
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
		;
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
		this->deallocate(reinterpret_cast<int *>(first), sizeof(Element<T> *));
		_size--;
		_count--;
	}

	// Members access reverse
	template <class T, class Alloc>
	void List<T, Alloc>::reverse()
	{
		/*Element<T> *first = _nodes->_next;
		Element<T> *last = _nodes;
		for (size_t i = 0; i < _size; i++)
			last = last->_next;
		for (size_t i = 0; i < _size; i++)
		{
			
		}*/
	}

	// Modifiers resize
	template <class T, class Alloc>
	void List<T, Alloc>::resize(size_type count)
	{
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
				this->deallocate(reinterpret_cast<int *>(tmp->_prev), sizeof(Element<T> *));
			}
			Element<T> *end = tmp->_next;
			this->deallocate(reinterpret_cast<int *>(tmp), sizeof(Element<T> *));
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
		this->deallocate(reinterpret_cast<int *>(tmp), sizeof(Element<T> *));
		_size--;
		_count--;
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
			this->deallocate(reinterpret_cast<int *>(tmp->_prev), sizeof(Element<T> *));
			start++;
		}
		save->_next = tmp;
		tmp->_prev = save;
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

	// Modifiers assign
	template <class T, class Alloc>
	void List<T, Alloc>::assign(size_type n, const value_type &val)
	{
		if (n > _size)
		{
			size_t save = _size;
			this->resize(n);
			(void)val;
			Element<T> *tmp = _nodes->_prev->_prev;
			for (size_t i = save; i < n; i++)
			{
				Element<T> *elem = reinterpret_cast<Element<T> *>(this->allocate(sizeof(Element<T> *)));
				elem->_content = val;
				tmp->_next = elem;
				elem->_prev = tmp->_prev;
				tmp = tmp->_next;
			}
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
			this->deallocate(reinterpret_cast<int *>(tmp->_prev), sizeof(Element<T> *));
		}
		_nodes = tmp;
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
				this->deallocate(reinterpret_cast<int *>(to_delete), sizeof(Element<T> *));
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
				this->deallocate(reinterpret_cast<int *>(to_delete), sizeof(Element<T> *));
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
				this->deallocate(reinterpret_cast<int *>(to_delete), sizeof(Element<T> *));
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
			while (begin != end && p(begin->_content,tmp->_content))
			{
				tmp->_next = begin->_next;
				begin->_next->_prev = tmp;
				Element<T> *to_delete = begin;
				begin = begin->_next;
				this->deallocate(reinterpret_cast<int *>(to_delete), sizeof(Element<T> *));
				_count--;
				_size--;
			}
			tmp = tmp->_next;
		}
	}

	template <class T, class Alloc>
	void  List<T, Alloc>::sort()
	{
		Element<T> *tmp = _nodes;
		Element<T> *end = _nodes->_prev;

		while (tmp != end)
		{
			Element<T> *begin = _nodes;
			while (begin != end)
			{
				if (begin != tmp && begin->_content < tmp->_content)
				{
					Element<T> *begin_prev = begin->_prev;
					Element<T> *tmp_next = tmp->_next;
					Element<T> *begin_next = begin->_next;
					Element<T> *tmp_prev = tmp->_prev;

					begin_prev->_next = tmp;
					tmp->_prev = begin_prev;
					tmp->_next = begin_next;
					begin_next->_prev = tmp;
					tmp_prev->_next = begin;
					begin->_prev = tmp_prev;
					begin->_next = tmp_next;
					tmp_next->_prev = begin;
					begin = _nodes;
				}
				else
					begin = begin->_next;
			}
			tmp = tmp->_next;
		}
	}

	//Iterators
	template <class T, class Alloc>
	typename List<T, Alloc>::iterator List<T, Alloc>::begin()
	{
		return Iterator<Element<T> >(_nodes);
	}

	template <class T, class Alloc>
	typename List<T, Alloc>::iterator List<T, Alloc>::end()
	{
		return Iterator<Element<T> >(_nodes->_prev);
	}

	template <class T, class Alloc>
	typename List<T, Alloc>::const_iterator List<T, Alloc>::begin() const
	{
		return Const_Iterator<Element<T> >(_nodes->_next);
	}

	template <class T, class Alloc>
	typename List<T, Alloc>::const_iterator List<T, Alloc>::end() const
	{
		return Const_Iterator<Element<T> >(_nodes);
	}

	template <class T, class Alloc>
	typename List<T, Alloc>::reverse_iterator List<T, Alloc>::rbegin()
	{
		return Reverse_Iterator<Element<T> >(_nodes->_prev);
	}

	template <class T, class Alloc>
	typename List<T, Alloc>::reverse_iterator List<T, Alloc>::rend()
	{
		return Reverse_Iterator<Element<T> >(_nodes);
	}

	template <class T, class Alloc>
	typename List<T, Alloc>::const_reverse_iterator List<T, Alloc>::rbegin() const
	{
		return Const_Reverse_Iterator<Element<T> >(_nodes->_prev);
	}

	template <class T, class Alloc>
	typename List<T, Alloc>::const_reverse_iterator List<T, Alloc>::rend() const
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
#ifndef ITERATORS_HPP
#define ITERATORS_HPP

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
	Iterator(pointer ptr) : _ptr(ptr){};
	Iterator &operator=(Iterator const &ref)
	{
		_ptr = ref._ptr;
		return (*this);
	};
	self_type operator++()
	{
		_ptr++;
		return *this;
	}
	self_type operator++(int n)
	{
		(void)n;
		self_type i = *this;
		++_ptr;
		return i;
	}
	self_type operator--()
	{
		_ptr--;
		return *this;
	}
	self_type operator--(int n)
	{
		(void)n;
		self_type i = *this;
		--_ptr;
		return i;
	}
	self_type operator+(int n)
	{
		self_type other = *this;
		for (int i = 0; i < n; i++)
			other._ptr++;
		return other;
	}
	self_type operator-(int n)
	{
		self_type other = *this;
		for (int i = 0; i < n; i++)
			other._ptr--;
		return other;
	}
	self_type operator+=(int n)
	{
		for (int i = 0; i < n; i++)
			_ptr++;
		return *this;
	}
	self_type operator-=(int n)
	{
		for (int i = 0; i < n; i++)
			_ptr--;
		return *this;
	}
	reference operator[](int n)
	{
		self_type i = *this;
		if (n < 0)
			i -= n;
		else
			i += n;
		return *i;
	}
	reference operator*() { return *_ptr; }
	pointer operator->() { return _ptr; }
	bool operator==(const self_type &other) { return _ptr == other._ptr; }
	bool operator!=(const self_type &other) { return _ptr != other._ptr; }
	bool operator>=(const self_type &other) { return _ptr >= other._ptr; }
	bool operator<=(const self_type &other) { return _ptr <= other._ptr; }
	bool operator>(const self_type &other) { return _ptr > other._ptr; }
	bool operator<(const self_type &other) { return _ptr < other._ptr; }

private:
	pointer _ptr;
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
	Const_Iterator(pointer ptr) : _ptr(ptr){};
	Const_Iterator &operator=(Const_Iterator const &ref)
	{
		_ptr = ref._ptr;
		return (*this);
	};
	self_type operator++()
	{
		_ptr++;
		return *this;
	}
	self_type operator++(int n)
	{
		(void)n;
		self_type i = *this;
		++_ptr;
		return i;
	}

	self_type operator--()
	{
		_ptr--;
		return *this;
	}
	self_type operator--(int n)
	{
		(void)n;
		self_type i = *this;
		--_ptr;
		return i;
	}
	self_type operator+(int n)
	{
		self_type other = *this;
		for (int i = 0; i < n; i++)
			other._ptr++;
		return other;
	}
	self_type operator-(int n)
	{
		self_type other = *this;
		for (int i = 0; i < n; i++)
			other._ptr--;
		return other;
	}
	self_type operator+=(int n)
	{
		for (int i = 0; i < n; i++)
			_ptr++;
		return *this;
	}
	self_type operator-=(int n)
	{
		for (int i = 0; i < n; i++)
			_ptr--;
		return *this;
	}
	reference operator[](int n)
	{
		self_type i = *this;
		if (n < 0)
			i -= n;
		else
			i += n;
		return *i;
	}
	reference operator*() { return *_ptr; }
	pointer operator->() { return _ptr; }
	bool operator==(const self_type &other) { return _ptr == other._ptr; }
	bool operator!=(const self_type &other) { return _ptr != other._ptr; }
	bool operator>=(const self_type &other) { return _ptr >= other._ptr; }
	bool operator<=(const self_type &other) { return _ptr <= other._ptr; }
	bool operator>(const self_type &other) { return _ptr > other._ptr; }
	bool operator<(const self_type &other) { return _ptr < other._ptr; }

private:
	pointer _ptr;
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
	Reverse_Iterator(pointer ptr) : _ptr(ptr){};
	Reverse_Iterator &operator=(Reverse_Iterator const &ref)
	{
		_ptr = ref._ptr;
		return (*this);
	};
	self_type operator++()
	{
		_ptr--;
		return *this;
	}
	self_type operator++(int n)
	{
		(void)n;
		self_type i = *this;
		--_ptr;
		return i;
	}

	self_type operator--()
	{
		_ptr++;
		return *this;
	}
	self_type operator--(int n)
	{
		(void)n;
		self_type i = *this;
		++_ptr;
		return i;
	}
	self_type operator+(int n)
	{
		self_type other = *this;
		for (int i = 0; i < n; i++)
			other._ptr--;
		return other;
	}
	self_type operator-(int n)
	{
		self_type other = *this;
		for (int i = 0; i < n; i++)
			other._ptr++;
		return other;
	}
	self_type operator+=(int n)
	{
		for (int i = 0; i < n; i++)
			_ptr--;
		return *this;
	}
	self_type operator-=(int n)
	{
		for (int i = 0; i < n; i++)
			_ptr++;
		return *this;
	}
	reference operator[](int n)
	{
		self_type i = *this;
		if (n < 0)
			i -= n;
		else
			i += n;
		return *i;
	}
	reference operator*() { return *_ptr; }
	pointer operator->() { return _ptr; }
	bool operator==(const self_type &other) { return _ptr == other._ptr; }
	bool operator!=(const self_type &other) { return _ptr != other._ptr; }
	bool operator>=(const self_type &other) { return _ptr >= other._ptr; }
	bool operator<=(const self_type &other) { return _ptr <= other._ptr; }
	bool operator>(const self_type &other) { return _ptr > other._ptr; }
	bool operator<(const self_type &other) { return _ptr < other._ptr; }

private:
	pointer _ptr;
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
	Const_Reverse_Iterator(pointer ptr) : _ptr(ptr){};
	Const_Reverse_Iterator &operator=(Const_Reverse_Iterator const &ref)
	{
		_ptr = ref._ptr;
		return (*this);
	};
	self_type operator++()
	{
		_ptr--;
		return *this;
	}
	self_type operator++(int n)
	{
		(void)n;
		self_type i = *this;
		--_ptr;
		return i;
	}
	self_type operator--()
	{
		_ptr++;
		return *this;
	}
	self_type operator--(int n)
	{
		(void)n;
		self_type i = *this;
		++_ptr;
		return i;
	}
	self_type operator+(int n)
	{
		self_type other = *this;
		for (int i = 0; i < n; i++)
			other._ptr--;
		return other;
	}
	self_type operator-(int n)
	{
		self_type other = *this;
		for (int i = 0; i < n; i++)
			other._ptr++;
		return other;
	}
	self_type operator+=(int n)
	{
		for (int i = 0; i < n; i++)
			_ptr--;
		return *this;
	}
	self_type operator-=(int n)
	{
		for (int i = 0; i < n; i++)
			_ptr++;
		return *this;
	}
	reference operator[](int n)
	{
		self_type i = *this;
		if (n < 0)
			i -= n;
		else
			i += n;
		return *i;
	}
	reference operator*() { return *_ptr; }
	pointer operator->() { return _ptr; }
	bool operator==(const self_type &other) { return _ptr == other._ptr; }
	bool operator!=(const self_type &other) { return _ptr != other._ptr; }
	bool operator>=(const self_type &other) { return _ptr >= other._ptr; }
	bool operator<=(const self_type &other) { return _ptr <= other._ptr; }
	bool operator>(const self_type &other) { return _ptr > other._ptr; }
	bool operator<(const self_type &other) { return _ptr < other._ptr; }

private:
	pointer _ptr;
};

#endif

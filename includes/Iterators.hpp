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
		self_type i = *this;
		_ptr++;
		return i;
	}
	self_type operator++(int junk)
	{
		(void)junk;
		++_ptr;
		return *this;
	}
	reference operator*() { return *_ptr; }
	pointer operator->() { return _ptr; }
	bool operator==(const self_type &rhs) { return _ptr == rhs._ptr; }
	bool operator!=(const self_type &rhs) { return _ptr != rhs._ptr; }

private:
	pointer _ptr;
};

#endif
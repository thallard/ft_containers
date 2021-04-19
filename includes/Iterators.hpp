#ifndef ITERATORS_HPP
# define ITERATORS_HPP

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
		self_type operator++() {self_type i = *this; ptr_++;return i; }
		self_type operator++(int junk) {(void) junk; ++ptr_; return *this; }
		reference operator*() { return *ptr_; }
		pointer operator->() { return ptr_; }
		bool operator==(const self_type& rhs) { return ptr_ == rhs.ptr_; }
		bool operator!=(const self_type& rhs) { return ptr_ != rhs.ptr_; }
	private:
		pointer ptr_;
};

#endif
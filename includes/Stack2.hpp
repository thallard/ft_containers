#ifndef STACK_HPP
#define STACK_HPP
#include <deque>

namespace ft
{
	template <class T, class Container>
	class Stack;

	template <class T, class Container = std::deque<T> >
	class Stack
	{
	public:
		typedef Container container_type;
		typedef typename Container::value_type value_type;
		typedef typename Container::size_type size_type;

		explicit Stack(const Container &cont = Container());
		Stack(const Stack &other);
		~Stack();
		Stack &operator=(const Stack &other);

		value_type &top();
		const value_type &top() const;
		bool empty() const;
		size_type size() const;
		void push(const value_type &value);
		void pop();
		bool operator==(const Stack &other);
		bool operator!=(const Stack &other);
		bool operator<(const Stack &other);
		bool operator<=(const Stack &other);
		bool operator>(const Stack &other);
		bool operator>=(const Stack &other);
	protected:
		container_type c;
	};

	template <typename T, class Container>
	Stack<T, Container>::Stack(const Container &cont) : c(cont)
	{
	}

	template <typename T, class Container>
	Stack<T, Container>::Stack(const Stack &other)
	{
		if (other.c == this->c)
			return;
		c = other.c;
	}

	template <typename T, class Container>
	Stack<T, Container> &Stack<T, Container>::operator=(const Stack &other)
	{
		if (other == *this)
			return *this;
		stack(other.stack);
		return *this;
	}

	template <typename T, class Container>
	typename Stack<T, Container>::value_type &Stack<T, Container>::top()
	{
		return (c.back());
	}

	template <typename T, class Container>
	const typename Stack<T, Container>::value_type &Stack<T, Container>::top() const
	{
		return (c.back());
	}

	template <typename T, class Container>
	Stack<T, Container>::~Stack()
	{
	}

	template <typename T, class Container>
	bool Stack<T, Container>::empty() const
	{
		return (c.empty());
	}

	template <typename T, class Container>
	typename Stack<T, Container>::size_type Stack<T, Container>::size() const
	{
		return (c.size());
	}

	template <typename T, class Container>
	void Stack<T, Container>::push(const Stack<T, Container>::value_type &value)
	{
		c.push_back(value);
	}

	template <typename T, class Container>
	void Stack<T, Container>::pop()
	{
		c.pop_back();
	}
	template <typename T, class Container>
	bool Stack<T, Container>::operator==(const Stack<T, Container> &other)
	{
		return (other.c == c);
	}

	template <typename T, class Container>
	bool Stack<T, Container>::operator!=(const Stack<T, Container> &other)
	{
		return (other.c != c);
	}

	template <typename T, class Container>
	bool Stack<T, Container>::operator<(const Stack<T, Container> &other)
	{
		return (c < other.c);
	}

	template <typename T, class Container>
	bool Stack<T, Container>::operator<=(const Stack<T, Container> &other)
	{
		return (c <= other.c);
	}

	template <typename T, class Container>
	bool Stack<T, Container>::operator>(const Stack<T, Container> &other)
	{
		return (c > other.c);
	}
	template <typename T, class Container>
	bool Stack<T, Container>::operator>=(const Stack<T, Container> &other)
	{
		return (c >= other.c);
	}
}

#endif
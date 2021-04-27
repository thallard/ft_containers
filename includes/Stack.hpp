#ifndef STACK_HPP
#define STACK_HPP
#include <deque>
#include <memory>
#include <iostream>
#include "List.hpp"

namespace ft
{
	template <class T, class Container>
	class Stack;

	template <class T, class Container = ft::List<T> >
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
		friend bool operator==(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs);
		friend bool operator!=(const Stack &lhs, const Stack &rhs);
		friend bool operator<(const Stack &lhs, const Stack &rhs);
		friend bool operator<=(const Stack &lhs, const Stack &rhs);
		friend bool operator>(const Stack &lhs, const Stack &rhs);
		friend bool operator>=(const Stack &lhs, const Stack &rhs);
	protected:
		Container c;

		
	};

	template <typename T, class Container>
	Stack<T, Container>::Stack(const Container &cont) : c(cont)
	{
	}

	template <typename T, class Container>
	Stack<T, Container>::Stack(const Stack &other)
	{
		if (other == this)
			return;
		c(other.c);
	}

	template <typename T, class Container>
	Stack<T, Container> &Stack<T, Container>::operator=(const Stack &other)
	{
		if (other == this)
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
	bool operator==(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs)
	{
		return (lhs.c == rhs.c);
	}

	template <typename T, class Container>
	bool operator!=(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs)
	{
		return (lhs.c != rhs.c);
	}

	template <typename T, class Container>
	bool operator<(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs)
	{
		return (lhs.c < rhs.c);
	}

	template <typename T, class Container>
	bool operator<=(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs)
	{
		return (lhs.c <= rhs.c);
	}

	template <typename T, class Container>
	bool operator>(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs)
	{
		return (lhs.c > rhs.c);
	}
	template <typename T, class Container>
	bool operator>=(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs)
	{
		return (lhs.c >= rhs.c);
	}
} // namespace ft

#endif
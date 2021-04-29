#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "List.hpp"
#include <deque>

namespace ft
{
	template <class T, class Container>
	class Queue;

	template <class T, class Container = std::deque<T> >
	class Queue
	{
	public:
		typedef Container container_type;
		typedef typename Container::value_type value_type;
		typedef typename Container::size_type size_type;

		explicit Queue(const Container &cont = Container());
		Queue(const Queue &other);
		~Queue();
		Queue &operator=(const Queue &other);

		value_type &front();
		value_type &back();
		const value_type &front() const;
		const value_type &back() const;
		bool empty() const;
		size_type size() const;
		void push(const value_type &value);
		void pop();
		bool operator==(const Queue &other);
		bool operator!=(const Queue &other);
		bool operator<(const Queue &other);
		bool operator<=(const Queue &other);
		bool operator>(const Queue &other);
		bool operator>=(const Queue &other);

	protected:
		container_type c;
	};

	template <typename T, class Container>
	Queue<T, Container>::Queue(const Container &cont) : c(cont)
	{
	}

	template <typename T, class Container>
	Queue<T, Container>::Queue(const Queue &other)
	{
		if (other.c == this->c)
			return;
		c = other.c;
	}

	template <typename T, class Container>
	Queue<T, Container> &Queue<T, Container>::operator=(const Queue &other)
	{
		if (other.c == this->c)
			return *this;
		Queue(other.Queue);
		return *this;
	}

	template <typename T, class Container>
	typename Queue<T, Container>::value_type &Queue<T, Container>::front()
	{
		return (c.front());
	}

	template <typename T, class Container>
	const typename Queue<T, Container>::value_type &Queue<T, Container>::front() const
	{
		return (c.front());
	}

	template <typename T, class Container>
	typename Queue<T, Container>::value_type &Queue<T, Container>::back()
	{
		return (c.back());
	}

	template <typename T, class Container>
	const typename Queue<T, Container>::value_type &Queue<T, Container>::back() const
	{
		return (c.back());
	}

	template <typename T, class Container>
	Queue<T, Container>::~Queue()
	{
	}

	template <typename T, class Container>
	bool Queue<T, Container>::empty() const
	{
		return (c.empty());
	}

	template <typename T, class Container>
	typename Queue<T, Container>::size_type Queue<T, Container>::size() const
	{
		return (c.size());
	}

	template <typename T, class Container>
	void Queue<T, Container>::push(const Queue<T, Container>::value_type &value)
	{
		c.push_back(value);
	}

	template <typename T, class Container>
	void Queue<T, Container>::pop()
	{
		c.pop_front();
	}
	template <typename T, class Container>
	bool Queue<T, Container>::operator==(const Queue<T, Container> &other)
	{
		return (c == other.c);
	}

	template <typename T, class Container>
	bool Queue<T, Container>::operator!=(const Queue<T, Container> &other)
	{
		return (c != other.c);
	}

	template <typename T, class Container>
	bool Queue<T, Container>::operator<(const Queue<T, Container> &other)
	{
		return (c < other.c);
	}

	template <typename T, class Container>
	bool Queue<T, Container>::operator<=(const Queue<T, Container> &other)
	{
		return (c <= other.c);
	}

	template <typename T, class Container>
	bool Queue<T, Container>::operator>(const Queue<T, Container> &other)
	{
		return (c > other.c);
	}
	template <typename T, class Container>
	bool Queue<T, Container>::operator>=(const Queue<T, Container> &other)
	{
		return (c >= other.c);
	}
}

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 18:10:53 by thallard          #+#    #+#             */
/*   Updated: 2021/05/03 15:35:35 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP
#include <memory>

namespace ft
{
	template <class T>
	struct less : std::binary_function<T, T, bool>
	{
		bool operator()(const T &x, const T &y) const { return x < y; }
	};

	template <class Key, class T>
	class pair;
	template <class Key, class T>
	class pair
	{

	public:
		Key first;
		T second;
		pair() : first(0), second(T())
		{
		}
		explicit pair(Key k, T val)
		{
			first = k;
			second = val;
		}
		pair(pair const &);
		pair &operator=(pair const &);
		~pair() {}

		// Setters & getters
		void setVal(const T &val) { second = val; }
		void setKey(const Key &k) { first = k; }
		T &getVal() { return second; }
		Key &getKey() { return first; }
		const T &getVal() const { return second; }
		const Key &getKey() const { return first; }
	};

	template <class Key, class T>
	class Node;
	template <class Key, class T>
	class Node
	{
	protected:
		ft::pair<Key, T> node;
		bool is_end;
		Node *left;
		Node *right;
		Node *top;

	public:
		Node();
		~Node();

		// Setters & getters
		ft::pair<Key, T> *getPair() { return &node; }
		Node *getRight() { return right; }
		Node *getLeft() { return left; }
		Node *getTop() { return top; }
		void setRight(Node &n)
		{
			right = &n;
			if (n.getTop())
				n.getTop()->setIsEnd(false);
		}
		void setTop(Node &n) { top = &n; }
		void setNode(Key const &k, T const &val)
		{
			node.setKey(k);
			node.setVal(val);
		}
		void setValue(const T &val) { node.setVal(val); }
		void setKey(const Key &k) { node.setKey(k); }

		bool getIsEnd() { return is_end; }
		void setIsEnd(bool val) { is_end = val; }
		void setValues(const Key &k, const T &val, bool condi = true)
		{
			node.setVal(val);
			node.setKey(k);
			setIsEnd(condi);
		}
		// void createNode();

		// Operators
		Node &operator=(const Node &ref)
		{
			(void)ref;
		};
	};

	template <typename Key, typename T>
	class MapIterator
	{
	public:
		typedef MapIterator self_type;
		typedef Node<Key, T> node;

		MapIterator(Node<Key, T> *p) : _ptr(p) {}
		~MapIterator() {}
		self_type operator++()
		{
			_ptr = _ptr->getRight();
			return *this;
		}
		self_type operator++(int n)
		{
			(void)n;
			self_type i = *this;
			_ptr = _ptr->getRight();
			return i;
		}
		self_type operator--()
		{
			_ptr = _ptr->getTop();
			return *this;
		}
		self_type operator--(int n)
		{
			(void)n;
			self_type i = *this;
			_ptr = _ptr->getTop();
			return i;
		}

		ft::pair<Key, T> &getPair() { return *_ptr->getPair(); }
		ft::pair<Key, T> *operator->() { return _ptr->getPair(); }
		node *operator*() { return _ptr;};

		bool operator==(const self_type &other) { return _ptr == other._ptr; }
		bool operator!=(const self_type &other) { return _ptr != other._ptr; }
		bool operator>=(const self_type &other) { return _ptr >= other._ptr; }
		bool operator<=(const self_type &other) { return _ptr <= other._ptr; }
		bool operator>(const self_type &other) { return _ptr > other._ptr; }
		bool operator<(const self_type &other) { return _ptr < other._ptr; }

	private:
		node *_ptr;
	};

	template <typename Key, typename T>
	class ConstMapIterator
	{
	public:
		typedef ConstMapIterator self_type;
		typedef Node<Key, T> node;

		ConstMapIterator(Node<Key, T> *p) : _ptr(p) {}
		~ConstMapIterator() {}
		self_type operator++()
		{
			_ptr = _ptr->getRight();
			return *this;
		}
		self_type operator++(int n)
		{
			(void)n;
			self_type i = *this;
			_ptr = _ptr->getRight();
			return i;
		}
		self_type operator--()
		{
			_ptr = _ptr->getTop();
			return *this;
		}
		self_type operator--(int n)
		{
			(void)n;
			self_type i = *this;
			_ptr = _ptr->getTop();
			return i;
		}

		// ft::pair<Key, T> &operator.() { return _ptr->getPair(); }
		ft::pair<Key, T> *operator->() { return _ptr->getPair(); }
		node *operator*() { return _ptr;};

		bool operator==(const self_type &other) { return _ptr == other._ptr; }
		bool operator!=(const self_type &other) { return _ptr != other._ptr; }
		bool operator>=(const self_type &other) { return _ptr >= other._ptr; }
		bool operator<=(const self_type &other) { return _ptr <= other._ptr; }
		bool operator>(const self_type &other) { return _ptr > other._ptr; }
		bool operator<(const self_type &other) { return _ptr < other._ptr; }

	private:
		node *_ptr;
	};
	template <typename Key, typename T>
	class ReverseMapIterator
	{
	public:
		typedef ReverseMapIterator self_type;
		typedef Node<Key, T> node;

		ReverseMapIterator(Node<Key, T> *p) : _ptr(p) {}
		~ReverseMapIterator() {}
		self_type operator--()
		{
			_ptr = _ptr->getRight();
			return *this;
		}
		self_type operator--(int n)
		{
			(void)n;
			self_type i = *this;
			_ptr = _ptr->getRight();
			return i;
		}
		self_type operator++()
		{
			_ptr = _ptr->getTop();
			return *this;
		}
		self_type operator++(int n)
		{
			(void)n;
			self_type i = *this;
			_ptr = _ptr->getTop();
			return i;
		}

		// ft::pair<Key, T> &operator.() { return _ptr->getPair(); }
		ft::pair<Key, T> *operator->() { return _ptr->getPair(); }
		node *operator*() { return _ptr;};

		bool operator==(const self_type &other) { return _ptr == other._ptr; }
		bool operator!=(const self_type &other) { return _ptr != other._ptr; }
		bool operator>=(const self_type &other) { return _ptr >= other._ptr; }
		bool operator<=(const self_type &other) { return _ptr <= other._ptr; }
		bool operator>(const self_type &other) { return _ptr > other._ptr; }
		bool operator<(const self_type &other) { return _ptr < other._ptr; }

	private:
		node *_ptr;
	};

	template <typename Key, typename T>
	class ConstReverseMapIterator
	{
	public:
		typedef ConstReverseMapIterator self_type;
		typedef Node<Key, T> node;

		ConstReverseMapIterator(Node<Key, T> *p) : _ptr(p) {}
		~ConstReverseMapIterator() {}
		self_type operator--()
		{
			_ptr = _ptr->getRight();
			return *this;
		}
		self_type operator--(int n)
		{
			(void)n;
			self_type i = *this;
			_ptr = _ptr->getRight();
			return i;
		}
		self_type operator++()
		{
			_ptr = _ptr->getTop();
			return *this;
		}
		self_type operator++(int n)
		{
			(void)n;
			self_type i = *this;
			_ptr = _ptr->getTop();
			return i;
		}

		// ft::pair<Key, T> &operator.() { return _ptr->getPair(); }
		ft::pair<Key, T> *operator->() { return _ptr->getPair(); }
		node *operator*() { return _ptr;};

		bool operator==(const self_type &other) { return _ptr == other._ptr; }
		bool operator!=(const self_type &other) { return _ptr != other._ptr; }
		bool operator>=(const self_type &other) { return _ptr >= other._ptr; }
		bool operator<=(const self_type &other) { return _ptr <= other._ptr; }
		bool operator>(const self_type &other) { return _ptr > other._ptr; }
		bool operator<(const self_type &other) { return _ptr < other._ptr; }

	private:
		node *_ptr;
	};
	template <class Key, class T, class Compare, class Alloc>
	class Map;

	template <class Key, class T, class Compare = less<Key>, class Alloc = std::allocator<std::pair<const Key, T> > >
	class Map
	{
	public:
		typedef Key key_type;								//	The first template parameter (Key)
		typedef T mapped_type;								//	The second template parameter (T)
		typedef ft::pair<key_type, mapped_type> value_type; //
		typedef ft::Node<Key, T> node;
		typedef Compare key_compare;									  //	The third template parameter (Compare)	defaults to: less<key_type>
		typedef T value_compare;										  //	Nested function class to compare elements	see value_comp
		typedef Alloc allocator_type;									  //	The fourth template parameter (Alloc)	defaults to: allocator<value_type>
		typedef typename allocator_type::reference reference;			  //		for the default allocator: value_type&
		typedef typename allocator_type::const_reference const_reference; //for the default allocator: const value_type&
		typedef typename allocator_type::pointer pointer;				  //for the default allocator: value_type*
		typedef typename allocator_type::const_pointer const_pointer;	  //	allocator_type::const_pointer	for the default allocator: const value_type*
		typedef typename ft::MapIterator<Key, T> iterator;				  //	a bidirectional iterator to value_type	convertible to const_iterator
		typedef typename ft::ConstMapIterator<Key, T> const_iterator;	  //a bidirectional iterator to const value_type
		typedef typename ft::ReverseMapIterator<Key, T> reverse_iterator;
		typedef typename ft::ConstReverseMapIterator<Key, T> const_reverse_iterator; //reverse_iterator<const_iterator>
		typedef ptrdiff_t difference_type;											 // a signed integral type, identical to: iterator_traits<iterator>::difference_type	usually the same as ptrdiff_t
		typedef size_t size_type;													 // an unsigned integral type that can represent any non-negative value of difference_type	usually the same as size_t
	private:
		Node<Key, T> *_nodes;
		allocator_type _alloc;
		key_compare _comp;
		size_t _size;

		void print(); // A SUPPRIMER DEBUG FUNCTION
	public:
		explicit Map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type());
		template <class InputIterator>
		Map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type());
		Map(const Map &);
		Map &operator=(const Map &);
		~Map();

		// Iterators functions
		iterator begin();						//
		iterator end();							//
		const_iterator begin() const;			//
		const_iterator end() const;				//
		reverse_iterator rbegin();				//
		reverse_iterator rend();				//
		const_reverse_iterator rbegin() const;	//
		const_reverse_iterator rend() const;	//
		// Modifiers functions
		ft::pair<iterator, bool> insert(const value_type &val);
		iterator insert (iterator position, const value_type& val);
		void insert (iterator first, iterator last);

		// Operations functions
		iterator find(const key_type &k);				//
		const_iterator find(const key_type &k) const;	//
		// Informations
		bool empty() const;							//
		size_type size() const;						//
		size_type max_size() const;					//
		size_type count (const key_type& k) const;	//
		mapped_type operator[](const key_type &k);
		key_compare key_comp() const;				//

		// Access
		iterator upper_bound (const key_type& k);
		const_iterator upper_bound (const key_type& k) const;
		iterator lower_bound (const key_type& k);
		const_iterator lower_bound (const key_type& k) const;
	};

	// A SUPPRIMER DEBUG FUNCTION
	template <typename Key, typename T, class Compare, class Alloc>
	void Map<Key, T, Compare, Alloc>::print()
	{
		node *tmp = _nodes;
		size_t count = 0;
		while (!tmp->getIsEnd() && count != _size)
		{
			std::cout << "\e[91mKey : " << tmp->getPair()->getKey() << " \e[0m| \e[95mValue : " << tmp->getPair()->getVal() << ".\e[0m" << std::endl;
			tmp = tmp->getRight();
			if (tmp->getIsEnd())
				std::cout << "\e[91mKey : " << tmp->getPair()->getKey() << " \e[0m| \e[95mValue : " << tmp->getPair()->getVal() << ".\e[0m" << std::endl;
			count++;
		}
	}

	// Default constructor
	template <typename Key, typename T, class Compare, class Alloc>
	Map<Key, T, Compare, Alloc>::Map(const key_compare &comp, const allocator_type &alloc) : _nodes(NULL), _alloc(alloc), _comp(comp), _size(0)
	{
		_nodes = reinterpret_cast<Node<Key, T> *>(_alloc.allocate(sizeof(value_type *)));
		_nodes->setKey("Start");
		_nodes->setValue(10);
		Node<Key, T> *new_node = reinterpret_cast<Node<Key, T> *>(_alloc.allocate(sizeof(value_type *)));
		new_node->setValues("second", 11, true);
		new_node->setTop(*_nodes);
		_nodes->setRight(*new_node);
		_size++;
		_size++;
		_size++;
		dprintf(1, "%d\n", _nodes->getPair()->getVal());
		dprintf(1, "%d\n", _nodes->getRight()->getPair()->getVal());
		dprintf(1, "%d\n", _nodes->getRight()->getTop()->getPair()->getVal());
		// print();
	}

	// Destructor
	template <typename Key, typename T, class Compare, class Alloc>
	Map<Key, T, Compare, Alloc>::~Map()
	{
	}

	template <typename Key, typename T, class Compare, class Alloc>
	typename Map<Key, T, Compare, Alloc>::iterator Map<Key, T, Compare, Alloc>::find(const key_type &k)
	{
		iterator tmp = begin();
		while (tmp != end() && tmp->first != k )
			tmp++;
		return tmp;
	}

	template <typename Key, typename T, class Compare, class Alloc>
	typename Map<Key, T, Compare, Alloc>::const_iterator Map<Key, T, Compare, Alloc>::find(const key_type &k) const
	{
		const_iterator tmp = begin();
		while (tmp != end() && tmp->first != k )
			tmp++;
		return tmp;
	}

	template <typename Key, typename T, class Compare, class Alloc>
	ft::pair<typename Map<Key, T, Compare, Alloc>::iterator, bool> Map<Key, T, Compare, Alloc>::insert(const value_type &val)
	{
		Node<Key, T> *tmp = _nodes;
		ft::pair<iterator, bool> res;
		while (!tmp->getIsEnd())
		{
			MapIterator<Key, T> it(tmp);
			if (tmp->getPair()->getKey() == tmp->getRight()->getPair()->getKey())
			{
				res.setKey(tmp);
				res.setVal(false);
				return (res);
			}
			else
				tmp = tmp->getRight();
		}

		Node<Key, T> *new_node = reinterpret_cast<Node<Key, T> *>(_alloc.allocate(sizeof(value_type *)));
		new_node->setValues(val.getKey(), val.getVal(), true);
		new_node->setTop(*tmp);
		tmp->setRight(*new_node);
		res.setKey(tmp);
		res.setVal(true);
		_size++;
		return res;
	}

	// Insert with position
	template <typename Key, typename T, class Compare, class Alloc>
	typename Map<Key, T, Compare, Alloc>::iterator Map<Key, T, Compare, Alloc>::insert(iterator position, const value_type &val)
	{
		iterator it = begin();
		node *tmp = _nodes;
		while (it != position)
		{
			it++;
			tmp = tmp->getRight();
		}
			
		node *new_node = reinterpret_cast<Node<Key, T> *>(_alloc.allocate(sizeof(node *)));
		new_node->setValues(val.getKey(), val.getVal(), true);
		if (position != begin())
		{
			new_node->setTop(*(tmp->getTop()));
			tmp->getTop()->setRight(*new_node);
		}
		else
			_nodes = new_node;
		tmp->setTop(*new_node);
		new_node->setRight(*tmp);
		return it;
	}

	// Insert start last
	template <typename Key, typename T, class Compare, class Alloc>
	void Map<Key, T, Compare, Alloc>::insert(iterator first, iterator last)
	{
		iterator tmp = first;
		while (tmp != last)
			insert(tmp.getPair());
	}
	template <typename Key, typename T, class Compare, class Alloc>
	bool Map<Key, T, Compare, Alloc>::empty() const
	{
		return (!_size);
	}

	template <typename Key, typename T, class Compare, class Alloc>
	typename Map<Key, T, Compare, Alloc>::size_type Map<Key, T, Compare, Alloc>::size() const
	{
		return _size;
	}

	template <typename Key, typename T, class Compare, class Alloc>
	typename Map<Key, T, Compare, Alloc>::size_type Map<Key, T, Compare, Alloc>::max_size() const
	{
		return std::numeric_limits<size_type>::max() / sizeof(*_nodes);
	}

	template <typename Key, typename T, class Compare, class Alloc>
	typename Map<Key, T, Compare, Alloc>::size_type Map<Key, T, Compare, Alloc>::count(const Map<Key, T, Compare, Alloc>::key_type &k) const
	{
		return (find(k) != end());
	}
	template <typename Key, typename T, class Compare, class Alloc>
	typename Map<Key, T, Compare, Alloc>::key_compare Map<Key, T, Compare, Alloc>::key_comp() const
	{
		return _comp;
	}


	// Operator
	template <typename Key, typename T, class Compare, class Alloc>
	typename Map<Key, T, Compare, Alloc>::mapped_type Map<Key, T, Compare, Alloc>::operator[](const Map<Key, T, Compare, Alloc>::key_type &k)
	{
		
		return insert(pair<Key, T>(k,mapped_type())).second;
	}

	// Access
	template <typename Key, typename T, class Compare, class Alloc>
	typename Map<Key, T, Compare, Alloc>::iterator Map<Key, T, Compare, Alloc>::upper_bound(const Map<Key, T, Compare, Alloc>::key_type &k)
	{
		iterator tmp = find(k);
		if (tmp != end())
			++tmp;
		return (tmp);
	}
		template <typename Key, typename T, class Compare, class Alloc>
	typename Map<Key, T, Compare, Alloc>::const_iterator Map<Key, T, Compare, Alloc>::upper_bound(const Map<Key, T, Compare, Alloc>::key_type &k) const
	{
		const_iterator tmp = find(k);
		if (tmp != end())
			++tmp;
		return (tmp);
	}
		template <typename Key, typename T, class Compare, class Alloc>
	typename Map<Key, T, Compare, Alloc>::iterator Map<Key, T, Compare, Alloc>::lower_bound(const Map<Key, T, Compare, Alloc>::key_type &k)
	{
		iterator tmp = find(k);
		return (tmp);
	}
		template <typename Key, typename T, class Compare, class Alloc>
	typename Map<Key, T, Compare, Alloc>::const_iterator Map<Key, T, Compare, Alloc>::lower_bound(const Map<Key, T, Compare, Alloc>::key_type &k) const
	{
		const_iterator tmp = find(k);
		return (tmp);
	}


	template <typename Key, typename T, class Compare, class Alloc>
	typename Map<Key, T, Compare, Alloc>::iterator Map<Key, T, Compare, Alloc>::begin()
	{
		return (MapIterator<Key, T>(&_nodes[0]));
	}

	template <typename Key, typename T, class Compare, class Alloc>
	typename Map<Key, T, Compare, Alloc>::iterator Map<Key, T, Compare, Alloc>::end()
	{
		node *tmp = _nodes;
		while (!tmp->getIsEnd())
			tmp = tmp->getRight();
		return (MapIterator<Key, T>(tmp->getRight()));
	}
	template <typename Key, typename T, class Compare, class Alloc>
	typename Map<Key, T, Compare, Alloc>::const_iterator Map<Key, T, Compare, Alloc>::begin() const
	{
		return (ConstMapIterator<Key, T>(&_nodes[0]));
	}

	template <typename Key, typename T, class Compare, class Alloc>
	typename Map<Key, T, Compare, Alloc>::const_iterator Map<Key, T, Compare, Alloc>::end() const
	{
		node *tmp = _nodes;
		while (!tmp->getIsEnd())
			tmp = tmp->getRight();
		return (ConstMapIterator<Key, T>(tmp->getRight()));
	}
	template <typename Key, typename T, class Compare, class Alloc>
	typename Map<Key, T, Compare, Alloc>::reverse_iterator Map<Key, T, Compare, Alloc>::rend()
	{
		node *tmp = _nodes;
		return (ReverseMapIterator<Key, T>(tmp->getTop()));
	}

	template <typename Key, typename T, class Compare, class Alloc>
	typename Map<Key, T, Compare, Alloc>::reverse_iterator Map<Key, T, Compare, Alloc>::rbegin()
	{
		node *tmp = _nodes;
		while (!tmp->getIsEnd())
			tmp = tmp->getRight();
		return (ReverseMapIterator<Key, T>(tmp));
	}
	template <typename Key, typename T, class Compare, class Alloc>
	typename Map<Key, T, Compare, Alloc>::const_reverse_iterator Map<Key, T, Compare, Alloc>::rend() const
	{
		node *tmp = _nodes;
		return (ConstReverseMapIterator<Key, T>(tmp->getTop()));
	}

	template <typename Key, typename T, class Compare, class Alloc>
	typename Map<Key, T, Compare, Alloc>::const_reverse_iterator Map<Key, T, Compare, Alloc>::rbegin() const
	{
		node *tmp = _nodes;
		while (!tmp->getIsEnd())
			tmp = tmp->getRight();
		return (ConstReverseMapIterator<Key, T>(tmp));
	}

}

#endif
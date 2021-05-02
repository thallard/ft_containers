/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 18:10:53 by thallard          #+#    #+#             */
/*   Updated: 2021/05/02 21:06:56 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP
#include <memory>

namespace ft
{
    template <class T> struct less : std::binary_function <T,T,bool> {
    bool operator() (const T& x, const T& y) const {return x<y;}
    };
    
    template <class Key, class T>
    class pair;
    template <class Key, class T>
    class pair
    {
       
            
        public:
        Key first;
            T second;
            pair() { first = NULL; second = NULL; }
            explicit pair(Key k, T val) { first = k; second = val; }
            pair(pair const &);
            pair &operator=(pair const &);
            ~pair() {}

            // Setters & getters
            void setVal(const T & val) { second = val; }
            void setKey(const Key & k) { first = k; }
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
            ft::pair<Key, T> &getNode() { return node; }
            Node *getRight() { return right; }
            Node *getLeft() { return left; }
            Node *getTop() { return top; }
            void setRight(Node  & n) 
            {
                right = &n;
                if (n.getTop())
                    n.getTop()->setIsEnd(false); 
            }
            void setTop(Node & n) { top = &n;}
            void setNode(Key const &k, T const & val) {  node.setKey(k); node.setVal(val); }
            void setValue(const T &val) { node.setVal(val); }
            void setKey(const Key &k) { node.setKey(k); }
           
            bool getIsEnd() { return is_end;}
            void setIsEnd(bool val) { is_end = val; }
            void setValues(const Key &k, const T &val, bool condi = true) { node.setVal(val); node.setKey(k); setIsEnd(condi); }
            // void createNode();
    };

    template <typename Key, typename T>
    class MapIterator
    {
        public:
            typedef MapIterator self_type;
            typedef Node<Key, T> node;

            MapIterator(Node<Key, T> *p) : _ptr(p) { }
            ~MapIterator() {}
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

            // ft::pair<Key, T> &operator.() { return _ptr->getNode(); }
            ft::pair<Key, T> &operator->() { return _ptr->getNode(); }

        private:
            node *_ptr;

    };
    template <class Key, class T, class Compare, class Alloc>
    class Map;

    template <class Key, class T, class Compare = less<Key>, class Alloc = std::allocator<std::pair<const Key,T> > >
    class Map
    {
        public:
            typedef Key key_type; //	The first template parameter (Key)	
            typedef T mapped_type; //	The second template parameter (T)	
            typedef ft::pair<key_type, mapped_type> value_type; //	
            typedef ft::Node<Key, T> node;
            typedef Compare key_compare; //	The third template parameter (Compare)	defaults to: less<key_type>
            typedef T value_compare; //	Nested function class to compare elements	see value_comp
            typedef Alloc allocator_type; //	The fourth template parameter (Alloc)	defaults to: allocator<value_type>
            typedef typename allocator_type::reference reference; //		for the default allocator: value_type&
            typedef typename allocator_type::const_reference const_reference; //for the default allocator: const value_type&
            typedef typename allocator_type::pointer pointer;		//for the default allocator: value_type*
            typedef typename allocator_type::const_pointer const_pointer; //	allocator_type::const_pointer	for the default allocator: const value_type*
            typedef typename ft::MapIterator<Key, T> iterator; //	a bidirectional iterator to value_type	convertible to const_iterator
            // const_iterator	a bidirectional iterator to const value_type	
            // reverse_iterator	reverse_iterator<iterator>	
            // const_reverse_iterator	reverse_iterator<const_iterator>	
            typedef ptrdiff_t difference_type;	// a signed integral type, identical to: iterator_traits<iterator>::difference_type	usually the same as ptrdiff_t
            typedef size_t size_type;	// an unsigned integral type that can represent any non-negative value of difference_type	usually the same as size_t
        private:
            Node<Key, T>     *_nodes;
            allocator_type  _alloc;
            key_compare     _comp;
            size_t          _size;

            void print(); // A SUPPRIMER DEBUG FUNCTION 
        public:
            explicit Map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
            template <class InputIterator>
            Map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
            Map(const Map &);
            Map &operator=(const Map &);
            ~Map();

            // Iterators functions
            iterator begin();					   //
		    iterator end();	
            // Modifiers functions
            const T & insert (const value_type& val);

            // Operations functions
            T &find (const key_type& k);
    };

     // A SUPPRIMER DEBUG FUNCTION 
    template <typename Key, typename T, class Compare, class Alloc>
    void Map<Key, T, Compare, Alloc>::print()
    {
        node *tmp = _nodes;
        size_t count = 0;
        while (!tmp->getIsEnd() && count != _size)
        {
           std::cout << "\e[91mKey : " << tmp->getNode().getKey() << " \e[0m| \e[95mValue : " << tmp->getNode().getVal() << ".\e[0m" << std::endl;
            tmp = tmp->getRight();
            if (tmp->getIsEnd())
              std::cout << "\e[91mKey : " << tmp->getNode().getKey() << " \e[0m| \e[95mValue : " << tmp->getNode().getVal() << ".\e[0m" << std::endl;
            count++;
        }
    }

    // Default constructor
    template <typename Key, typename T, class Compare, class Alloc>
    Map<Key, T, Compare, Alloc>::Map(const key_compare& comp, const allocator_type& alloc) : _nodes(NULL), _alloc(alloc), _comp(comp), _size(0)
    {
        _nodes = reinterpret_cast<Node<Key, T>*>(_alloc.allocate(sizeof(value_type*)));
        _nodes->setKey("Start");
        _nodes->setValue(10);
        Node<Key, T> *new_node = reinterpret_cast<Node<Key, T>*>(_alloc.allocate(sizeof(value_type*)));
        new_node->setValues("second", 11, true);
        new_node->setTop(*_nodes);
        _nodes->setRight(*new_node);
        _size++;
        _size++;
        dprintf(1, "%d\n", _nodes->getNode().getVal());
        dprintf(1, "%d\n", _nodes->getRight()->getNode().getVal());
        dprintf(1, "%d\n", _nodes->getRight()->getTop()->getNode().getVal());
        // print();
    }

    // Destructor
    template <typename Key, typename T, class Compare, class Alloc>
    Map<Key, T, Compare, Alloc>::~Map()
    {
        
    }

    template <typename Key, typename T, class Compare, class Alloc>
    T &Map<Key, T, Compare, Alloc>::find(const key_type& k)
    {
            (void)k;
            return T();
    }

    template <typename Key, typename T, class Compare, class Alloc>
    const T& Map<Key, T, Compare, Alloc>::insert (const value_type& val)
    {
        // MAUVAISE SIGNATURE CHANGER QUAND theo aura fait les iterateurs uwu
        // Idem pour le const en entree
        iterator it = begin();
        // std::cout << "debug de mon iterator : " << it->second << std::endl;
        Node<Key, T> *tmp = _nodes;
        while (!tmp->getIsEnd())
        {
            tmp = tmp->getRight();
        }

        Node<Key, T> *new_node = reinterpret_cast<Node<Key, T>*>(_alloc.allocate(sizeof(value_type*)));
        new_node->setValues(val.getKey(), val.getVal(), true);
        new_node->setTop(*tmp);
        tmp->setRight(*new_node);
        print();
        return val.getVal();

    }
    
    template <typename Key, typename T, class Compare, class Alloc>
    typename Map<Key, T, Compare, Alloc>::iterator Map<Key, T, Compare, Alloc>::begin()
    {
        return (MapIterator<Key, T>(&_nodes[0]));
    }	
}


#endif
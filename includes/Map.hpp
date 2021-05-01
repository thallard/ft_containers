/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 18:10:53 by thallard          #+#    #+#             */
/*   Updated: 2021/05/01 23:46:44 by thallard         ###   ########lyon.fr   */
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
    class pair
    {
        protected:
            Key key;
            T value;
            pair *left;
            pair *right;
        public:
            pair() { key = NULL; value = NULL; }
            pair(Key k, T val) { key = k; value = val; }
            pair(pair const &);
            pair &operator=(pair const &);
            ~pair();

    };
    template <class Key, class T, class Compare, class Alloc>
    class Map;

    template <class Key, class T, class Compare = less<Key>, class Alloc = std::allocator<std::pair<const Key,T> > >
    class Map
    {
        public:
            typedef Key key_type; //	The first template parameter (Key)	
            typedef T mapped_type; //	The second template parameter (T)	
            typedef pair<const key_type,mapped_type> value_type; //	
            typedef Compare key_compare; //	The third template parameter (Compare)	defaults to: less<key_type>
            typedef T value_compare; //	Nested function class to compare elements	see value_comp
            typedef Alloc allocator_type; //	The fourth template parameter (Alloc)	defaults to: allocator<value_type>
            typedef typename allocator_type::reference reference; //		for the default allocator: value_type&
            typedef typename allocator_type::const_reference const_reference; //for the default allocator: const value_type&
            typedef typename allocator_type::pointer pointer;		//for the default allocator: value_type*
            typedef typename allocator_type::const_pointer const_pointer; //	allocator_type::const_pointer	for the default allocator: const value_type*
            // iterator	a bidirectional iterator to value_type	convertible to const_iterator
            // const_iterator	a bidirectional iterator to const value_type	
            // reverse_iterator	reverse_iterator<iterator>	
            // const_reverse_iterator	reverse_iterator<const_iterator>	
            typedef ptrdiff_t difference_type;	// a signed integral type, identical to: iterator_traits<iterator>::difference_type	usually the same as ptrdiff_t
            typedef size_t size_type;	// an unsigned integral type that can represent any non-negative value of difference_type	usually the same as size_t
        private:
            value_type      *_pairs;
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

            // Modifiers functions
            // pair<iterator,bool> insert (const value_type& val);
    };

     // A SUPPRIMER DEBUG FUNCTION 
    template <typename Key, typename T, class Compare, class Alloc>
    void Map<Key, T, Compare, Alloc>::print()
    {

    }

    // Default constructor
    template <typename Key, typename T, class Compare, class Alloc>
    Map<Key, T, Compare, Alloc>::Map(const key_compare& comp, const allocator_type& alloc) : _pairs(NULL), _alloc(alloc), _comp(comp), _size(0)
    {
        _pairs = reinterpret_cast<value_type*>(_alloc.allocate(sizeof(value_type*)));
    }

    // Destructor
     template <typename Key, typename T, class Compare, class Alloc>
    Map<Key, T, Compare, Alloc>::~Map()
    {
        
    }

    // template <typename Key, typename T, class Compare, class Alloc>
    // pair<iterator,bool>  Map<Key, T, Compare, Alloc>::insert (const value_type& val)
    // {

    // }
}


#endif
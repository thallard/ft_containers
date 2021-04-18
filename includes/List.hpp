/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:20:43 by thallard          #+#    #+#             */
/*   Updated: 2021/04/18 23:02:41 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
#define LIST_HPP
#include <iostream>
#include <string>

namespace ft
{
template <typename T>
class Element
{
public:
    T content;
    Element *next;
    Element *prev;

    Element(const T &cont) : content(cont), next(NULL), prev(NULL) {}
    Element(Element *pre, const T &cont, Element *_next) : content(cont), next(_next), prev(pre) {}
    Element() : content(T()), next(NULL), prev(NULL) {}
};

template <class T, class Alloc = std::allocator<T>>
class List : public std::allocator<T>
{
private:
public:
    typedef T value_type;
    typedef Alloc allocator_type;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef Alloc::reference &reference;
    typedef Alloc::const_reference &const_reference;
    typedef Alloc::pointer pointer;
    typedef Alloc::const_pointer const_pointer;
    List() { allocator_type = allocator_type(); }
    List(size_t size, const value_type &val = value_type(),
         const allocator_type &alloc = allocator_type());
    List();
    ~List();
};

} // namespace ft

// template <class T, class Alloc = std::allocator<T>>
// List<T>::List(void)
// {

// }
// // List::List(/* args */)
// {
// }

// List::~List()
// {
// }

#endif
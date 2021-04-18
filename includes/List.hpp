/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:20:43 by thallard          #+#    #+#             */
/*   Updated: 2021/04/18 21:50:43 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
#define LIST_HPP
#include <iostream>
#include <string>

namespace ft
{

template <class T, class Alloc = std::allocator<T>>
class List : public std::allocator<T>
{
private:
    typedef T value_type;
    typedef Alloc allocator_type;

    size_t size_type;
    ptrdiff_t difference_type;
    Alloc::reference reference;

public:
    List() { allocator_type = allocator_type(); }
    List(size_t size, const value_type &val = value_type(),
         const allocator_type &alloc = allocator_type());
    List();
    ~List();
};

} 

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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 18:10:53 by thallard          #+#    #+#             */
/*   Updated: 2021/05/01 18:22:37 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP
#include <memory>

namespace ft
{
    template <class T> struct less : binary_function <T,T,bool> {
    bool operator() (const T& x, const T& y) const {return x<y;}
};
    template <class Key, class T, class Compare = less<Key>, class Alloc = std::allocator<std::pair<const Key,T> > >
    class Map;

    template <class Key, class T, class Compare = less<Key>, class Alloc = std::allocator<std::pair<const Key,T> > >
    class Map
    {
        
    };
}


#endif
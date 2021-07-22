/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 13:03:09 by hwinston          #+#    #+#             */
/*   Updated: 2021/07/23 01:09:36 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

#ifdef STD
    #include <map>
    namespace ft = std;
#else
    #include "../inc/map.hpp"
    #include "../../utility/binary_search_tree.hpp"
#endif

#define VALUE_TYPE_1 int
#define VALUE_TYPE_2 int

typedef ft::map<const VALUE_TYPE_1, VALUE_TYPE_2> map_type;

void intro()
{
    std::cout << "--------------------------------------------------------" << std::endl;
    #ifdef STD
        std::cout << "------------------------- std::map ---------------------" << std::endl;
    #else
        std::cout << "------------------------- ft::map ----------------------" << std::endl;
    #endif
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << std::endl;
}

void get_info(map_type& map)
{
    std::cout << std::endl;
    std::cout << "--- info:" << std::endl;
    std::cout << std::endl;

    std::cout << "  empty: " << map.empty() << std::endl;
    std::cout << "   size: " << map.size() << std::endl;
}

void get_access(map_type& map)
{
    std::cout << std::endl;
    std::cout << "--- access:" << std::endl;
    std::cout << std::endl;

    std::cout << "  begin: " << map.begin()->first;
    std::cout << " => " << map.begin()->second << std::endl;

    std::cout << "    end: " << map.end()->first;
    std::cout << " => " << map.end()->second << std::endl;

    // std::cout << " rbegin: " << map.rbegin()->first;
    // std::cout << " => " << map.rbegin()->second << std::endl;

    // std::cout << "   rend: " << map.rend()->first;
    // std::cout << " => " << map.rend()->second << std::endl;
}

void get_content(map_type& map)
{
    std::cout << std::endl;
    std::cout << "--- content:" << std::endl;
    std::cout << std::endl;

    map_type::iterator it = map.begin();

    for (; it != map.end(); it++)
    {
        std::cout << " " << it->first << " => " << it->second << std::endl;  
    }
}

/* ----------------------------------------------------------------------------------- */
/* ----------------------------------------------------------------------------------- */

int main()
{
    intro();

    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "---------------- empty map constructor -----------------" << std::endl;

    // {
    //     map_type map;
    //     get_info(map);
    //     get_content(map);
    // }

    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "------------------- insert one element -----------------" << std::endl;

    // {
    //     map_type first;
    //     first.insert(ft::make_pair(100,100));
    //     first.insert(ft::make_pair(10,10));
    //     first.insert(ft::make_pair(100,100));
    //     first.insert(ft::make_pair(150,150));
    //     get_info(first);
    //     get_access(first);
    //     get_content(first);
    //     first.insert(ft::make_pair(5,5));
    //     first.insert(ft::make_pair(20,20));
    //     get_info(first);
    //     get_access(first);
    //     get_content(first);
    // }
    
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "------------------- range constructor ------------------" << std::endl;

    // {
    //     map_type first; 
    //     first.insert(ft::make_pair(100,100));
    //     first.insert(ft::make_pair(10,10));
    //     first.insert(ft::make_pair(150,150));
    //     first.insert(ft::make_pair(5,5));
    //     first.insert(ft::make_pair(20,20));
    //     map_type second(first.begin(), first.end());
    //     get_info(second);
    //     get_access(second);
    //     get_content(second);
    // }

    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "------------------ copy constructor (1) ----------------" << std::endl;

    // {
    //     map_type first; 
    //     first.insert(ft::make_pair(100,100));
    //     first.insert(ft::make_pair(10,10));
    //     first.insert(ft::make_pair(150,150));
    //     first.insert(ft::make_pair(5,5));
    //     first.insert(ft::make_pair(20,20));
    //     map_type* second(&first);
    //     get_info(*second);
    //     get_access(*second);
    //     get_content(*second);
    // }

    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "------------------ copy constructor (2) ----------------" << std::endl;

    // {
    //     map_type first;
    //     map_type* second(&first);
    //     get_info(*second);
    //     get_access(*second);
    //     get_content(*second);
    // }

    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "----------------------- iterator -----------------------" << std::endl; 
 
    {
        map_type first;
        map_type::iterator it;
        first.insert(ft::make_pair(2,2));
        first.insert(ft::make_pair(1,1));
        first.insert(ft::make_pair(3,3));
        get_info(first);
        get_access(first);
        get_content(first);
        std::cout << std::endl;
        std::cout << "--- iterating:" << std::endl;
        std::cout << std::endl;
        it = first.begin();
        std::cout << " [ it   ] "  << it->first << " => " << it->second << std::endl;
        std::cout << " [ it++ ] " << it->first << " => " << (it++)->second << std::endl;
        std::cout << " [ it   ] " << it->first << " => " << it->second << std::endl;
        std::cout << " [ ++it ] " << (++it)->first << " => " << it->second << std::endl;
        // std::cout << " [ ++it ] " << (++it)->first << " => " << it->second << std::endl;
        // std::cout << " [ ++it ] " << (++it)->first << " => " << it->second << std::endl;
        std::cout << " [ ++it ] " << (++it)->first << " => " << it->second << std::endl;
        std::cout << " [ it-- ] " << it->first << " => " << (it--)->second << std::endl;
        std::cout << " [ it   ] " << it->first << " => " << it->second << std::endl;
        std::cout << " [ --it ] " << (--it)->first << " => " << it->second << std::endl;
        std::cout << " [ --it ] " << (--it)->first << " => " << it->second << std::endl;
        std::cout << " [ --it ] " << (--it)->first << " => " << it->second << std::endl;
        std::cout << " [ --it ] " << (--it)->first << " => " << it->second << std::endl;
    }

    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "--------------- lower_bound / upper_bound -------------" << std::endl;

    // {
    //     map_type first;
    //     map_type::iterator it;
    //     first.insert(ft::make_pair(20,20));
    //     first.insert(ft::make_pair(10,10));
    //     first.insert(ft::make_pair(30,30));
    //     first.insert(ft::make_pair(5,5));
    //     first.insert(ft::make_pair(12,12));
    //     get_info(first);
    //     get_access(first);
    //     get_content(first);
    //     it = first.lower_bound(3);
    //     std::cout << " [lower bound] " << it->first << " => " << it->second << std::endl;
    //     it = first.upper_bound(3);
    //     std::cout << " [upper bound] " << it->first << " => " << it->second << std::endl;
    //     it = first.lower_bound(5);
    //     std::cout << " [lower bound] " << it->first << " => " << it->second << std::endl;
    //     it = first.upper_bound(5);
    //     std::cout << " [upper bound] " << it->first << " => " << it->second << std::endl;
    //     it = first.lower_bound(20);
    //     std::cout << " [lower bound] " << it->first << " => " << it->second << std::endl;
    //     it = first.upper_bound(20);
    //     std::cout << " [upper bound] " << it->first << " => " << it->second << std::endl;
    //     it = first.lower_bound(30);
    //     std::cout << " [lower bound] " << it->first << " => " << it->second << std::endl;
    //     it = first.upper_bound(30);
    //     std::cout << " [upper bound] " << it->first << " => " << it->second << std::endl;
    //     it = first.lower_bound(50);
    //     std::cout << " [lower bound] " << it->first << " => " << it->second << std::endl;
    //     it = first.upper_bound(50);
    //     std::cout << " [upper bound] " << it->first << " => " << it->second << std::endl;
    // }

    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "-------------------------- find ------------------------" << std::endl;

    // {
    //     map_type first;
    //     map_type::iterator it;
    //     first.insert(ft::make_pair(20,20));
    //     first.insert(ft::make_pair(10,10));
    //     first.insert(ft::make_pair(30,30));
        
    //     first.insert(ft::make_pair(5,5));
    //     first.insert(ft::make_pair(12,12));
    //     it = first.find(5);
    //     std::cout << " find(5): " << it->first << " => " << it->second << std::endl;
    //     it = first.find(10);
    //     std::cout << " find(10): " << it->first << " => " << it->second << std::endl;
    //     it = first.find(12);
    //     std::cout << " find(12): " << it->first << " => " << it->second << std::endl;
    //     it = first.find(30);
    //     std::cout << " find(30): " << it->first << " => " << it->second << std::endl;
    //     it = first.find(50);
    //     std::cout << " find(50): " << it->first << " => " << it->second << std::endl;
    // }
    
    return 0;
}
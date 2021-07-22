/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 13:03:09 by hwinston          #+#    #+#             */
/*   Updated: 2021/07/22 14:10:09 by hwinston         ###   ########.fr       */
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

#define VALUE_TYPE_1 const int
#define VALUE_TYPE_2 int

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

void get_info(ft::map<VALUE_TYPE_1, VALUE_TYPE_2>& map)
{
    std::cout << std::endl;
    std::cout << "--- info:" << std::endl;
    std::cout << std::endl;

    std::cout << "  empty: " << map.empty() << std::endl;
    std::cout << "   size: " << map.size() << std::endl;
}

void get_access(ft::map<VALUE_TYPE_1, VALUE_TYPE_2>& map)
{
    std::cout << std::endl;
    std::cout << "--- access:" << std::endl;
    std::cout << std::endl;

    std::cout << "  begin: " << map.begin()->first;
    std::cout << " => " << map.begin()->second << std::endl;

    std::cout << "    end: " << map.end()->first;
    std::cout << " => " << map.end()->second << std::endl;

    // std::cout << "rbegin = " << map.rbegin()->first;
    // std::cout << " => " << map.rbegin()->second << std::endl;

    // std::cout << "  rend = " << map.rend()->first;
    // std::cout << " => " << map.rend()->second << std::endl;
}

void get_content(ft::map<VALUE_TYPE_1, VALUE_TYPE_2>& map)
{
    std::cout << std::endl;
    std::cout << "--- content:" << std::endl;
    std::cout << std::endl;

    ft::map<VALUE_TYPE_1, VALUE_TYPE_2>::iterator it = map.begin();

    std::cout << it->first << " => " << it->second << std::endl;

    ft::mapNode<ft::map<VALUE_TYPE_1, VALUE_TYPE_2>::value_type>* n = it.base()->left;
    
    std::cout << it->first << " => " << it->second << std::endl;


    // for (; it != map.end(); it++)
    //     std::cout << " " << it->first << " => " << it->second << std::endl;
}

/* ----------------------------------------------------------------------------------- */
/* ----------------------------------------------------------------------------------- */

int main()
{
    intro();

    std::cout << "--------------------------------------------------------" << std::endl;
    {
        std::cout << "---------------- empty map constructor -----------------" << std::endl;

        ft::map<VALUE_TYPE_1, VALUE_TYPE_2> map;
        get_info(map);
        get_content(map);
    }
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    {
        std::cout << "------------------- range constructor ------------------" << std::endl;

        ft::map<VALUE_TYPE_1, VALUE_TYPE_2> first;
        ft::map<VALUE_TYPE_1, VALUE_TYPE_2>::iterator it;
        
        first.insert(ft::make_pair(1,10));
        first.insert(ft::make_pair(1,10));
        first.insert(ft::make_pair(1,20));
        first.insert(ft::make_pair(2,30));
        first.insert(ft::make_pair(3,30));

        get_info(first);

        get_access(first);
        get_content(first);


        // ft::map<VALUE_TYPE_1, VALUE_TYPE_2>::iterator i = (first.end())--;
        // std::cout << it->first << " => " << it->second << std::endl;     

        // std::cout << std::endl;
        // std::cout << "---------" << std::endl;
        // std::cout << std::endl;
        
        // ft::map<VALUE_TYPE_1, VALUE_TYPE_2> second(first.begin(), first.end());
        // get_info(second);
        // get_content(second);
        
    }
    // std::cout << std::endl;
    // std::cout << "--------------------------------------------------------" << std::endl;
    // {
    //     std::cout << "-------------------- copy constructor ------------------" << std::endl; 
    // }
    // std::cout << "--------------------------------------------------------" << std::endl;

    // std::cout << std::endl;
    // std::cout << "--------------------------------------------------------" << std::endl;
    // {
    //     std::cout << "------------------------ iterator ----------------------" << std::endl; 

    //         ft::map<VALUE_TYPE_1, VALUE_TYPE_2> first;
    //         ft::map<VALUE_TYPE_1, VALUE_TYPE_2>::iterator it;
        
    //         first.insert(ft::make_pair(1,10));
    //         // first.insert(ft::make_pair(2,30));
    //         // first.insert(ft::make_pair(3,30));

    //         get_info(first);
    //         get_access(first);
    //         get_content(first);

    //         std::cout << std::endl;
    //         std::cout << "---------" << std::endl;
    //         std::cout << std::endl;
            
    //         it = first.begin();
            
    //         std::cout << " [before ++] "  << it->first << " => " << it->second << std::endl;
    //         it++;
    //         std::cout << " [ after ++] " << it->first << " => " << it->second << std::endl;
    //         it--;
    //         std::cout << " [ after --] " << it->first << " => " << it->second << std::endl;
    //         it--;
    //         std::cout << " [ after --] " << it->first << " => " << it->second << std::endl;
    
    // }
    // std::cout << "--------------------------------------------------------" << std::endl;

    
    return 0;
}
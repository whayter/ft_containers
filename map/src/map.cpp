/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 13:03:09 by hwinston          #+#    #+#             */
/*   Updated: 2021/07/24 23:51:11 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include <list>

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

/* ----------------------------------------------------------------------------------- */
/* ----------------------------------------------------------------------------------- */
/* ----------------------------------------------------------------------------------- */

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
/* ----------------------------------------------------------------------------------- */

int main()
{
    intro();

    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "---------------- empty map constructor -----------------" << std::endl;
    std::cout << std::endl;

    // {
    //     map_type map;
    //     get_info(map);
    //     get_content(map);
    // }

    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "----------------- insert one element -------------------" << std::endl;
    std::cout << std::endl;

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
    std::cout << "------------ insert multiple elements (1) --------------" << std::endl;
    std::cout << std::endl;

    // {
    //     map_type first;
    //     first.insert(ft::make_pair(12,12));
    //     first.insert(ft::make_pair(17,17));
    //     first.insert(ft::make_pair(9,9));
    //     first.insert(ft::make_pair(14,14));
    //     first.insert(ft::make_pair(3,3));
    //     first.insert(ft::make_pair(25,25));
    //     map_type second;
    //     second.insert(first.find(9), first.end());
    //     get_info(second);
    //     get_access(second);
    //     get_content(second);
    // }

    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "------------ insert multiple elements (2) --------------" << std::endl;
    std::cout << std::endl;

    // {
    //     map_type first;
    //     first.insert(ft::make_pair(12,12));
    //     first.insert(ft::make_pair(17,17));
    //     first.insert(ft::make_pair(9,9));
    //     first.insert(ft::make_pair(14,14));
    //     first.insert(ft::make_pair(3,3));
    //     first.insert(ft::make_pair(25,25));
    //     map_type second;
    //     second.insert(first.begin(), first.end());
    //     get_info(second);
    //     get_access(second);
    //     get_content(second);
    // }

    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "------------ insert multiple elements (3) --------------" << std::endl;
    std::cout << std::endl;

    // {
    //     map_type first;
    //     first.insert(ft::make_pair(12,12));
    //     first.insert(ft::make_pair(17,17));
    //     first.insert(ft::make_pair(9,9));
    //     first.insert(ft::make_pair(14,14));
    //     first.insert(ft::make_pair(3,3));
    //     first.insert(ft::make_pair(25,25));
    //     map_type second;
    //     second.insert(first.begin(), first.begin());
    //     get_info(second);
    //     get_access(second);
    //     get_content(second);
    // }

    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "------------ insert multiple elements (4) --------------" << std::endl;
    std::cout << std::endl;

    // {
    //     map_type first;
    //     first.insert(ft::make_pair(12,12));
    //     first.insert(ft::make_pair(17,17));
    //     first.insert(ft::make_pair(9,9));
    //     first.insert(ft::make_pair(14,14));
    //     first.insert(ft::make_pair(3,3));
    //     first.insert(ft::make_pair(25,25));
    //     map_type second;
    //     second.insert(first.end(), first.end());
    //     get_info(second);
    //     get_access(second);
    //     get_content(second);
    // }
    
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "------------------ range constructor -------------------" << std::endl;
    std::cout << std::endl;

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
    std::cout << std::endl;

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
    std::cout << std::endl;

    // {
    //     map_type first;
    //     map_type* second(&first);
    //     get_info(*second);
    //     get_access(*second);
    //     get_content(*second);
    // }

    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "------------------------- find -------------------------" << std::endl;
    std::cout << std::endl;
    
    // {
    //     map_type first;
    //     map_type::iterator it;
    //     int key;
    //     first.insert(ft::make_pair(20,20));
    //     first.insert(ft::make_pair(10,10));
    //     first.insert(ft::make_pair(8,8));
    //     first.insert(ft::make_pair(30,30)); 
    //     first.insert(ft::make_pair(5,5));
    //     first.insert(ft::make_pair(12,12));
    //     key = 8;
    //     if ((it = first.find(key)) != first.end())
    //         std::cout << key << " is a valid key." << std::endl;
    //     else   
    //         std::cout << key << " is not a valid key." << std::endl;
    //     key = 2;   
    //     if ((it = first.find(key)) != first.end())
    //         std::cout << key << " is a valid key." << std::endl;
    //     else   
    //         std::cout << key << " is not a valid key." << std::endl;
    //     key = 100;
    //     if ((it = first.find(key)) != first.end())
    //         std::cout << key << " is a valid key." << std::endl;
    //     else   
    //         std::cout << key << " is not a valid key." << std::endl;
    // }

    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "--------------------- find / count ---------------------" << std::endl;
    std::cout << std::endl;

    // {
    //     map_type first;
    //     map_type::iterator it;
    //     map_type::const_iterator const_it;
    //     first.insert(ft::make_pair(20,20));
    //     first.insert(ft::make_pair(10,10));
    //     first.insert(ft::make_pair(0,10));
    //     first.insert(ft::make_pair(30,30)); 
    //     first.insert(ft::make_pair(5,5));
    //     first.insert(ft::make_pair(12,12));
    //     it = first.find(5);
    //     const_it = first.find(5);
    //     std::cout << " find(5): " << it->first << " => " << it->second << std::endl;
    //     std::cout << " find(5): " << const_it->first << " => " << const_it->second << std::endl;
    //     std::cout << "count(5): " << first.count(5) << std::endl;
    //     it = first.find(10);
    //     const_it = first.find(10);
    //     std::cout << " find(10): " << it->first << " => " << it->second << std::endl;
    //     std::cout << " find(10): " << const_it->first << " => " << const_it->second << std::endl;
    //     std::cout << "count(10): " << first.count(10) << std::endl;
    //     it = first.find(12);
    //     std::cout << " find(12): " << it->first << " => " << it->second << std::endl;
    //     std::cout << "count(12): " << first.count(12) << std::endl;
    //     it = first.find(30);
    //     std::cout << " find(30): " << it->first << " => " << it->second << std::endl;
    //     std::cout << "count(30): " << first.count(30) << std::endl;
    //     it = first.find(50);
    //     const_it = first.find(50);
    //     std::cout << " find(50): " << it->first << " => " << it->second << std::endl;
    //     std::cout << " find(50): " << const_it->first << " => " << const_it->second << std::endl;
    //     std::cout << "count(50): " << first.count(50) << std::endl;
    //     it = first.find(0);
    //     std::cout << " find(0): " << it->first << " => " << it->second << std::endl;
    //     std::cout << "count(0): " << first.count(0) << std::endl;
    // }

    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "--------------- lower_bound / upper_bound -------------" << std::endl;
    std::cout << std::endl;

    // {
    //     map_type first;
    //     map_type::iterator it;
    //     map_type::const_iterator const_it;
    //     first.insert(ft::make_pair(20,20));
    //     first.insert(ft::make_pair(10,10));
    //     first.insert(ft::make_pair(30,30));
    //     first.insert(ft::make_pair(5,5));
    //     first.insert(ft::make_pair(12,12));
    //     get_info(first);
    //     get_access(first);
    //     get_content(first);
    //     std::cout << std::endl;
    //     it = first.lower_bound(3);
    //     const_it = first.lower_bound(3);
    //     std::cout << " [lower bound] " << it->first << " => " << it->second << std::endl;
    //     std::cout << " [lower bound] " << const_it->first << " => " << const_it->second << std::endl;
    //     const_it = first.lower_bound(3);
    //     std::cout << " [lower bound] " << const_it->first << " => " << const_it->second << std::endl;
    //     it = first.upper_bound(3);
    //     const_it = first.upper_bound(3);
    //     std::cout << " [upper bound] " << it->first << " => " << it->second << std::endl;
    //     std::cout << " [upper bound] " << const_it->first << " => " << const_it->second << std::endl;
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
    //     const_it = first.lower_bound(50);
    //     std::cout << " [lower bound] " << it->first << " => " << it->second << std::endl;
    //     std::cout << " [lower bound] " << const_it->first << " => " << const_it->second << std::endl;
    //     it = first.upper_bound(50);
    //     const_it = first.upper_bound(50);
    //     std::cout << " [upper bound] " << it->first << " => " << it->second << std::endl;
    //     std::cout << " [upper bound] " << const_it->first << " => " << const_it->second << std::endl;
    // }

    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "---------------------- equal range ---------------------" << std::endl;
    std::cout << std::endl;

    // {
    //     map_type first;
    //     ft::pair<map_type::iterator, map_type::iterator> pair;
    //     ft::pair<map_type::const_iterator, map_type::const_iterator> const_pair;  
    //     first.insert(ft::make_pair(5,5));
    //     first.insert(ft::make_pair(3,3));
    //     first.insert(ft::make_pair(8,8));
    //     first.insert(ft::make_pair(4,4));
    //     first.insert(ft::make_pair(7,7));
    //     first.insert(ft::make_pair(2,2));
    //     first.insert(ft::make_pair(12,12));
    //     pair = first.equal_range(3);
    //     const_pair = first.equal_range(3);
    //     std::cout << " equal_range(3): " << pair.first->first << " | " << pair.second->first << std::endl;
    //     std::cout << " equal_range(3): " << const_pair.first->first << " | " << const_pair.second->first << std::endl;
    //     pair = first.equal_range(12);
    //     const_pair = first.equal_range(12);
    //     std::cout << "equal_range(12): " << pair.first->first << " | " << pair.second->first << std::endl;
    //     std::cout << "equal_range(12): " << const_pair.first->first << " | " << const_pair.second->first << std::endl;
    //     pair = first.equal_range(13);
    //     const_pair = first.equal_range(13);
    //     std::cout << "equal_range(13): " << pair.first->first << " | " << pair.second->first << std::endl;
    //     std::cout << "equal_range(13): " << const_pair.first->first << " | " << const_pair.second->first << std::endl;
    // }

    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "----------------- erase one element (1) ----------------" << std::endl;
    std::cout << std::endl;

    // {
    //     map_type first;
    //     first.insert(ft::make_pair(5,5)); 
    //     first.insert(ft::make_pair(3,3));
    //     first.insert(ft::make_pair(8,8));  
    //     first.insert(ft::make_pair(4,4));           
    //     first.insert(ft::make_pair(7,7)); 
    //     first.insert(ft::make_pair(2,2)); 
    //     first.insert(ft::make_pair(1,1));     
    //     first.insert(ft::make_pair(6,6));
    //     get_info(first);
    //     get_access(first);
    //     get_content(first);
    //     first.erase(first.find(3));
    //     get_info(first);
    //     get_access(first);
    //     get_content(first);
    //     first.erase(first.find(6));
    //     get_info(first);
    //     get_access(first);
    //     get_content(first);
    //     first.erase(first.find(5));
    //     get_info(first);
    //     get_access(first);
    //     get_content(first);
    //     first.erase(first.find(7));
    //     get_info(first);
    //     get_access(first);
    //     get_content(first);
    //     first.erase(first.find(1));
    //     first.erase(first.find(4));
    //     first.erase(first.find(8));
    //     get_info(first);
    //     get_access(first);
    //     get_content(first);
    //     first.erase(first.find(2));
    //     get_info(first);
    //     get_access(first);
    //     get_content(first);
    // }
    
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "----------------- erase one element (2) ----------------" << std::endl;
    std::cout << std::endl;
    
    // {
    //     map_type first;
    //     first.insert(ft::make_pair(5,5)); 
    //     first.insert(ft::make_pair(3,3));
    //     first.insert(ft::make_pair(8,8));  
    //     first.insert(ft::make_pair(4,4));           
    //     first.insert(ft::make_pair(7,7)); 
    //     first.insert(ft::make_pair(2,2)); 
    //     first.insert(ft::make_pair(1,1));     
    //     first.insert(ft::make_pair(6,6));
    //     std::cout << "--> before erase:" << std::endl;
    //     get_info(first);
    //     get_access(first);
    //     get_content(first);
    //     first.erase(first.begin());
    //     std::cout << std::endl;
    //     std::cout << "--> after erase:" << std::endl;
    //     get_info(first);
    //     get_access(first);
    //     get_content(first);
    // }
    
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "----------------- erase one element (3) ----------------" << std::endl;
    std::cout << std::endl;
    
    // {
    //     map_type first;
    //     first.insert(ft::make_pair(5,5)); 
    //     first.insert(ft::make_pair(3,3));
    //     first.insert(ft::make_pair(8,8));  
    //     first.insert(ft::make_pair(4,4));           
    //     first.insert(ft::make_pair(7,7)); 
    //     first.insert(ft::make_pair(2,2)); 
    //     first.insert(ft::make_pair(1,1));     
    //     first.insert(ft::make_pair(6,6));
    //     std::cout << "--> before erase:" << std::endl;
    //     get_info(first);
    //     get_access(first);
    //     get_content(first);
    //     first.erase(first.end());
    //     std::cout << std::endl;
    //     std::cout << "--> after erase:" << std::endl;
    //     get_info(first);
    //     get_access(first);
    //     get_content(first);
    // }
  
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "-------------- erase multiple elements (1) -------------" << std::endl;
    std::cout << std::endl;
    
    // {
    //     map_type first;
    //     first.insert(ft::make_pair(5,5)); 
    //     first.insert(ft::make_pair(3,3));
    //     first.insert(ft::make_pair(8,8));  
    //     first.insert(ft::make_pair(4,4));           
    //     first.insert(ft::make_pair(7,7)); 
    //     first.insert(ft::make_pair(2,2)); 
    //     first.insert(ft::make_pair(1,1));     
    //     first.insert(ft::make_pair(6,6));
    //     std::cout << "--> before erase:" << std::endl;
    //     get_info(first);
    //     get_access(first);
    //     get_content(first);
    //     first.erase(first.find(5), first.find(8));
    //     std::cout << std::endl;
    //     std::cout << "--> after erase:" << std::endl;
    //     get_info(first);
    //     get_access(first);
    //     get_content(first);
    // }

    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "-------------- erase multiple elements (2) -------------" << std::endl;
    std::cout << std::endl;
    
    // {
    //     map_type first;
    //     first.insert(ft::make_pair(5,5)); 
    //     first.insert(ft::make_pair(3,3));
    //     first.insert(ft::make_pair(8,8));  
    //     first.insert(ft::make_pair(4,4));           
    //     first.insert(ft::make_pair(7,7)); 
    //     first.insert(ft::make_pair(2,2)); 
    //     first.insert(ft::make_pair(1,1));     
    //     first.insert(ft::make_pair(6,6));
    //     std::cout << "--> before erase:" << std::endl;
    //     get_info(first);
    //     get_access(first);
    //     get_content(first);
    //     first.erase(first.begin(), first.find(8));
    //     std::cout << std::endl;
    //     std::cout << "--> after erase:" << std::endl;
    //     get_info(first);
    //     get_access(first);
    //     get_content(first);
    // }
    
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "-------------- erase multiple elements (3) -------------" << std::endl;
    std::cout << std::endl;
    
    // {
    //     map_type first;
    //     first.insert(ft::make_pair(5,5)); 
    //     first.insert(ft::make_pair(3,3));
    //     first.insert(ft::make_pair(8,8));  
    //     first.insert(ft::make_pair(4,4));           
    //     first.insert(ft::make_pair(7,7)); 
    //     first.insert(ft::make_pair(2,2)); 
    //     first.insert(ft::make_pair(1,1));     
    //     first.insert(ft::make_pair(6,6));
    //     std::cout << "--> before erase:" << std::endl;
    //     get_info(first);
    //     get_access(first);
    //     get_content(first);
    //     first.erase(first.begin(), first.end());
    //     std::cout << std::endl;
    //     std::cout << "--> after erase:" << std::endl;
    //     get_info(first);
    //     get_access(first);
    //     get_content(first);
    // }


    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "------------------------- swap -------------------------" << std::endl;
    std::cout << std::endl;

    // {
    //     map_type first;
    //     first.insert(ft::make_pair(5,5)); 
    //     first.insert(ft::make_pair(3,3));
    //     first.insert(ft::make_pair(8,8));  
    //     map_type second;
    //     second.insert(ft::make_pair(4,4)); 
    //     second.insert(ft::make_pair(7,7)); 
    //     second.insert(ft::make_pair(2,2)); 
    //     second.insert(ft::make_pair(1,1));     
    //     second.insert(ft::make_pair(6,6));
    //     std::cout << "--> first:" << std::endl;
    //     get_content(first);
    //     std::cout << std::endl;
    //     std::cout << "--> second:" << std::endl;
    //     get_content(second);
    //     first.swap(second);
    //     std::cout << std::endl;
    //     std::cout << "*°*.*.°* SWAP *°*.*.°*" << std::endl;
    //     std::cout << std::endl;
    //     std::cout << "--> first:" << std::endl;
    //     get_content(first);
    //     std::cout << std::endl;
    //     std::cout << "--> second:" << std::endl;
    //     get_content(second);
    // }

    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "------------------------ clear -------------------------" << std::endl;
    std::cout << std::endl;
    
    // {
    //     map_type first;
    //     first.insert(ft::make_pair(5,5)); 
    //     first.insert(ft::make_pair(3,3));
    //     first.insert(ft::make_pair(8,8));  
    //     first.insert(ft::make_pair(4,4));           
    //     first.insert(ft::make_pair(7,7)); 
    //     first.insert(ft::make_pair(2,2)); 
    //     first.insert(ft::make_pair(1,1));     
    //     first.insert(ft::make_pair(6,6));
    //     get_info(first);
    //     get_access(first);
    //     get_content(first);
    //     first.clear();
    //     std::cout << std::endl;
    //     get_info(first);
    //     get_access(first);
    //     get_content(first);
    // }

    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "-------------------- element access --------------------" << std::endl;
    std::cout << std::endl;
    
    // {
    //     map_type first;
    //     first.insert(ft::make_pair(5,5)); 
    //     first.insert(ft::make_pair(3,3));
    //     first.insert(ft::make_pair(8,8));  
    //     get_content(first);
    //     std::cout << std::endl;
    //     std::cout << "first[3] = " << first[3] << std::endl;
    //     std::cout << "first[8] = " << first[8] << std::endl;
    //     std::cout << "first[2] = " << first[2] << std::endl;
    //     get_content(first);
    // }

    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "----------------------- iterator -----------------------" << std::endl; 
    std::cout << std::endl;
 
    // {
    //     map_type first;
    //     map_type::iterator it;
    //     first.insert(ft::make_pair(2,2));
    //     first.insert(ft::make_pair(1,1));
    //     first.insert(ft::make_pair(3,3));
    //     get_info(first);
    //     get_access(first);
    //     get_content(first);
    //     std::cout << std::endl;
    //     std::cout << "--- iterating:" << std::endl;
    //     std::cout << std::endl;
    //     it = first.begin();
    //     std::cout << " [ it   ] "  << it->first << " => " << it->second << std::endl;
    //     std::cout << " [ it++ ] " << it->first << " => " << (it++)->second << std::endl;
    //     std::cout << " [ it   ] " << it->first << " => " << it->second << std::endl;
    //     std::cout << " [ ++it ] " << (++it)->first << " => " << it->second << std::endl;
    //     std::cout << " [ ++it ] " << (++it)->first << " => " << it->second << std::endl;
    //     std::cout << " [ it-- ] " << it->first << " => " << (it--)->second << std::endl;
    //     std::cout << " [ it   ] " << it->first << " => " << it->second << std::endl;
    //     std::cout << " [ --it ] " << (--it)->first << " => " << it->second << std::endl;
    //     std::cout << " [ --it ] " << (--it)->first << " => " << it->second << std::endl;
    //     std::cout << " [ --it ] " << (--it)->first << " => " << it->second << std::endl;
    //     std::cout << " [ --it ] " << (--it)->first << " => " << it->second << std::endl;
    // }

    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "-------------------- const_iterator --------------------" << std::endl; 
    std::cout << std::endl;
 
    // {
    //     map_type first;
    //     map_type::const_iterator it;
    //     first.insert(ft::make_pair(2,2));
    //     first.insert(ft::make_pair(1,1));
    //     first.insert(ft::make_pair(3,3));
    //     get_info(first);
    //     get_access(first);
    //     get_content(first);
    //     std::cout << std::endl;
    //     std::cout << "--- iterating:" << std::endl;
    //     std::cout << std::endl;
    //     it = first.begin();
    //     std::cout << " [ it   ] "  << it->first << " => " << it->second << std::endl;
    //     std::cout << " [ it++ ] " << it->first << " => " << (it++)->second << std::endl;
    //     std::cout << " [ it   ] " << it->first << " => " << it->second << std::endl;
    //     std::cout << " [ ++it ] " << (++it)->first << " => " << it->second << std::endl;
    //     std::cout << " [ ++it ] " << (++it)->first << " => " << it->second << std::endl;
    //     std::cout << " [ it-- ] " << it->first << " => " << (it--)->second << std::endl;
    //     std::cout << " [ it   ] " << it->first << " => " << it->second << std::endl;
    //     std::cout << " [ --it ] " << (--it)->first << " => " << it->second << std::endl;
    //     std::cout << " [ --it ] " << (--it)->first << " => " << it->second << std::endl;
    //     std::cout << " [ --it ] " << (--it)->first << " => " << it->second << std::endl;
    //     std::cout << " [ --it ] " << (--it)->first << " => " << it->second << std::endl;
    // }
    
    return 0;
}
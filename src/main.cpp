/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 12:21:07 by hwinston          #+#    #+#             */
/*   Updated: 2021/06/23 23:58:06 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/vector.hpp"
#include <vector>
#include <iostream>
#include <iomanip>


template <class T>
std::string get_info(ft::vector<T>& vector, std::string name)
{
    std::string ret;
    ret += "\n- INFOS\n";
    ret += "empty = ";
    ret += std::to_string(vector.empty());
    ret += " | size = ";
    ret += std::to_string(vector.size());
    ret += " | max size = ";
    ret += std::to_string(vector.max_size());
    ret += " | capacity = ";
    ret += std::to_string(vector.capacity());
    ret += "\n\n";
    ret += "- CONTENT\n";
    for (typename ft::vector<T>::iterator it = vector.begin(); it != vector.end(); ++it)
    {
        ret += ' ';
        ret += std::to_string(*it);
    }
    ret += "\n\n";
    return ret;
}
template <class T>
std::string get_info(std::vector<T>& vector, std::string name)
{
    std::string ret;
    ret += "\n- INFOS\n";
    ret += "empty = ";
    ret += std::to_string(vector.empty());
    ret += " | size = ";
    ret += std::to_string(vector.size());
    ret += " | max size = ";
    ret += std::to_string(vector.max_size());
    ret += " | capacity = ";
    ret += std::to_string(vector.capacity());
    ret += "\n\n";
    ret += "- CONTENT\n";
    for (typename std::vector<T>::iterator it = vector.begin(); it != vector.end(); ++it)
    {
        ret += ' ';
        ret += std::to_string(*it);
    }
    ret += "\n\n";
    return ret;
}

void print_result(std::string std_ret, std::string ft_ret)
{
    if (!ft_ret.compare(std_ret))
        std::cout << "OK" << std::endl;
    else
    {
        std::cout << std::endl;
        std::cout << "---    your output:" << std::endl;
        std::cout << ft_ret << std::endl;
        std::cout << "--- expected output:" << std::endl;
        std::cout << std_ret << std::endl;
    }
}

/* ---------------------------------------------------------------------------------------- */

int main(void)
{

    std::string std_return;
    std::string ft_return;

    /* -------------------------- VECTOR -------------------------- */

    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "-------------------- VECTOR < INT > --------------------" << std::endl;
    std::cout << std::endl;

    {
        std::cout << std::setw(52) << std::left;
        std::cout << "default constructor";
        {
            std::vector<int> std_vector;
            ft::vector<int> ft_vector;

            std_return = get_info(std_vector, "STD");
            ft_return = get_info(ft_vector, "FT");
            print_result(std_return, ft_return);
        }
        std_return.clear();
        ft_return.clear(); 
        std::cout << "--------------------------------------------------------" << std::endl;
        std::cout << std::setw(52) << std::left;
        std::cout << "fill constructor";
        {
            std::vector<int> std_vector(2);
            ft::vector<int> ft_vector(2);

            std_return = get_info(std_vector, "STD");
            ft_return = get_info(ft_vector, "FT");
            print_result(std_return, ft_return);
        }
        std_return.clear();
        ft_return.clear(); 
        std::cout << "--------------------------------------------------------" << std::endl;
        std::cout << std::setw(52) << std::left;
        std::cout << "push / pop";
        {
            std::vector<int> std_vector;
            ft::vector<int> ft_vector;

            std_vector.push_back(1);
            std_vector.push_back(2);
            std_vector.push_back(3);
            std_vector.push_back(4);
            ft_vector.push_back(1);
            ft_vector.push_back(2);
            ft_vector.push_back(3);
            ft_vector.push_back(4);

            std_return = get_info(std_vector, "STD");
            ft_return = get_info(ft_vector, "FT");
            print_result(std_return, ft_return);

            std_vector.pop_back();
            std_vector.pop_back();
            ft_vector.pop_back();
            ft_vector.pop_back();

            std_return = get_info(std_vector, "STD");
            ft_return = get_info(ft_vector, "FT");
            std::cout << std::setw(52) << std::left << " ";
            print_result(std_return, ft_return);

            std_return.clear();
            ft_return.clear(); 

            std_vector.pop_back();
            std_vector.pop_back();
            ft_vector.pop_back();
            ft_vector.pop_back();

            std_return = get_info(std_vector, "STD");
            ft_return = get_info(ft_vector, "FT");
            std::cout << std::setw(52) << std::left << " ";
            print_result(std_return, ft_return);
        }
        std_return.clear();
        ft_return.clear(); 
        std::cout << "--------------------------------------------------------" << std::endl;
        std::cout << std::setw(52) << std::left;
        std::cout << "element access";
        {
            std::vector<int> std_vector;
            ft::vector<int> ft_vector;

            std_vector.push_back(1);
            std_vector.push_back(2);
            std_vector.push_back(3);
            std_vector.push_back(4);
            ft_vector.push_back(1);
            ft_vector.push_back(2);
            ft_vector.push_back(3);
            ft_vector.push_back(4);

            std_return += "at(0) = ";
            std_return += std::to_string(std_vector.at(0));
            std_return += '\n';
            std_return += "vector[1] = ";
            std_return += std::to_string(std_vector[1]);
            std_return += '\n';
            std_return += "front() = ";
            std_return += std::to_string(std_vector.front());
            std_return += '\n';
            std_return += "back() = ";
            std_return += std::to_string(std_vector.back());
            std_return += '\n';

            ft_return += "at(0) = ";
            ft_return += std::to_string(ft_vector.at(0));
            ft_return += '\n';
            ft_return += "vector[1] = ";
            ft_return += std::to_string(ft_vector[1]);
            ft_return += '\n';
            ft_return += "front() = ";
            ft_return += std::to_string(ft_vector.front());
            ft_return += '\n';
            ft_return += "back() = ";
            ft_return += std::to_string(ft_vector.back());
            ft_return += '\n';

            std_return += get_info(std_vector, "STD");
            ft_return += get_info(ft_vector, "FT");
            print_result(std_return, ft_return);
        }
        std_return.clear();
        ft_return.clear(); 
        std::cout << "--------------------------------------------------------" << std::endl;
        std::cout << std::setw(52) << std::left;
        std::cout << "range constructor";
        {
            std::vector<int> std_vector;
            ft::vector<int> ft_vector;

            std_vector.push_back(1);
            std_vector.push_back(2);
            std_vector.push_back(3);
            std_vector.push_back(4);
            ft_vector.push_back(1);
            ft_vector.push_back(2);
            ft_vector.push_back(3);
            ft_vector.push_back(4);

            std::vector<int> std_range_vector(std_vector.begin(), std_vector.begin() + 2);
            ft::vector<int> ft_range_vector(ft_vector.begin(), ft_vector.begin() + 2);

            std_return += get_info(std_vector, "STD");
            ft_return += get_info(ft_vector, "FT");
            print_result(std_return, ft_return);
        }
        std_return.clear();
        ft_return.clear(); 
        std::cout << "--------------------------------------------------------" << std::endl;
        std::cout << std::setw(52) << std::left;
        std::cout << "copy constructor";
        {
            std::vector<int> std_vector;
            ft::vector<int> ft_vector;

            std_vector.push_back(1);
            std_vector.push_back(2);
            std_vector.push_back(3);
            std_vector.push_back(4);
            ft_vector.push_back(1);
            ft_vector.push_back(2);
            ft_vector.push_back(3);
            ft_vector.push_back(4);

            std::vector<int> std_range_vector(std_vector.begin(), std_vector.begin() + 2);
            ft::vector<int> ft_range_vector(ft_vector.begin(), ft_vector.begin() + 2);

            std::vector<int> std_copy_vector(std_range_vector);
            ft::vector<int> ft_copy_vector(ft_range_vector);

            std_return += get_info(std_vector, "STD");
            ft_return += get_info(ft_vector, "FT");
            print_result(std_return, ft_return);
        }
        std_return.clear();
        ft_return.clear(); 
        std::cout << "--------------------------------------------------------" << std::endl;
        std::cout << std::setw(52) << std::left;
        std::cout << "insert a single element";
        {
            std::vector<int> std_vector((size_t)2, 10);
            ft::vector<int> ft_vector((size_t)2, 10);

            std::vector<int>::iterator std_ret;
            ft::vector<int>::iterator ft_ret;

            std_return += "insert() return = ";
            std_ret = std_vector.insert(std_vector.begin(), 2);
            std_return += std::to_string(*std_ret);
            std_return += "\n";
            std_return += "insert() return = ";
            std_ret =  std_vector.insert(std_vector.end(), 1);
            std_return += std::to_string(*std_ret);
            std_return += "\n";

            ft_return += "insert() return = ";
            ft_ret = ft_vector.insert(ft_vector.begin(), 2);
            ft_return += std::to_string(*ft_ret);
            ft_return += "\n";
            ft_return += "insert() return = ";
            ft_ret = ft_vector.insert(ft_vector.end(), 1);
            ft_return += std::to_string(*ft_ret);
            ft_return += "\n";

            std_return += get_info(std_vector, "STD");
            ft_return += get_info(ft_vector, "FT");
            print_result(std_return, ft_return);
        }
        std_return.clear();
        ft_return.clear(); 
        std::cout << "--------------------------------------------------------" << std::endl;
        std::cout << std::setw(52) << std::left;
        std::cout << "insert (fill)";
        {
            std::vector<int> std_vector(4);
            ft::vector<int> ft_vector(4);

            unsigned int n = 2;
            int val = 9;

            std_vector.insert(std_vector.begin() + 1, n, val);
            std_vector.insert(std_vector.end(), n, val);

            ft_vector.insert(ft_vector.begin() + 1, n, val);
            ft_vector.insert(ft_vector.end(), n, val);

            std_return += get_info(std_vector, "STD");
            ft_return += get_info(ft_vector, "FT");
            print_result(std_return, ft_return);
        }
        std_return.clear();
        ft_return.clear(); 
        std::cout << "--------------------------------------------------------" << std::endl;
        std::cout << std::setw(52) << std::left;
        std::cout << "insert (range)";
        {
            std::vector<int> std_vector;
            ft::vector<int> ft_vector;

            std_vector.push_back(1);
            std_vector.push_back(2);
            std_vector.push_back(3);
            std_vector.push_back(4);
            ft_vector.push_back(1);
            ft_vector.push_back(2);
            ft_vector.push_back(3);
            ft_vector.push_back(4);

            std::vector<int> std_new_vector;
            ft::vector<int> ft_new_vector;

            std_new_vector.insert(std_new_vector.begin(), std_vector.begin(), std_vector.begin() + 2);
            std_new_vector.insert(std_new_vector.end(), std_vector.begin() + 2, std_vector.end());

            ft_new_vector.insert(ft_new_vector.begin(), ft_vector.begin(), ft_vector.begin() + 2);
            ft_new_vector.insert(ft_new_vector.end(), ft_vector.begin() + 2, ft_vector.end());

            std_return += get_info(std_vector, "STD");
            ft_return += get_info(ft_vector, "FT");
            print_result(std_return, ft_return);
        }
        std_return.clear();
        ft_return.clear(); 
        std::cout << "--------------------------------------------------------" << std::endl;
        std::cout << std::setw(52) << std::left;
        std::cout << "erase one element";
        {
            std::vector<int> std_vector(2);
            ft::vector<int> ft_vector(2);
            std::vector<int>::iterator std_ret;
            ft::vector<int>::iterator ft_ret;

            std_vector.insert(std_vector.begin(), 2);
            std_vector.insert(std_vector.begin(), 1);
            std_vector.insert(std_vector.begin(), 3);
            std_vector.insert(std_vector.begin(), 4);
            std_vector.erase(std_vector.begin() + 1);
            std_ret = std_vector.erase(std_vector.begin(), std_vector.begin() + 1);

            ft_vector.insert(ft_vector.begin(), 2);
            ft_vector.insert(ft_vector.begin(), 1);
            ft_vector.insert(ft_vector.begin(), 3);
            ft_vector.insert(ft_vector.begin(), 4);
            ft_vector.erase(ft_vector.begin() + 1);
            ft_ret = ft_vector.erase(ft_vector.begin(), ft_vector.begin() + 1);

            std_return += "erase() return = ";
            std_return += std::to_string(*std_ret);
            ft_return += "erase() return = ";
            ft_return += std::to_string(*ft_ret);
            std_return += get_info(std_vector, "STD");
            ft_return += get_info(ft_vector, "FT");
            print_result(std_return, ft_return);
        }
        std_return.clear();
        ft_return.clear(); 
        std::cout << "--------------------------------------------------------" << std::endl;
        std::cout << std::setw(52) << std::left;
        std::cout << "erase (range)";
        {
            std::vector<int> std_vector;
            ft::vector<int> ft_vector;
            std::vector<int>::iterator std_ret;
            ft::vector<int>::iterator ft_ret;

            std_vector.insert(std_vector.begin(), 1);
            std_vector.insert(std_vector.begin(), 2);
            std_vector.insert(std_vector.begin(), 3);
            std_vector.insert(std_vector.begin(), 4);
            std_ret = std_vector.erase(std_vector.begin() + 1, std_vector.begin() + 3);

            ft_vector.insert(ft_vector.begin(), 1);
            ft_vector.insert(ft_vector.begin(), 2);
            ft_vector.insert(ft_vector.begin(), 3);
            ft_vector.insert(ft_vector.begin(), 4);
            ft_ret = ft_vector.erase(ft_vector.begin() + 1, ft_vector.begin() + 3);

            std_return += "erase() return = ";
            std_return += std::to_string(*std_ret);
            ft_return += "erase() return = ";
            ft_return += std::to_string(*ft_ret);
            std_return += get_info(std_vector, "STD");
            ft_return += get_info(ft_vector, "FT");
            print_result(std_return, ft_return);
        }
        std_return.clear();
        ft_return.clear(); 
        std::cout << "--------------------------------------------------------" << std::endl;
        std::cout << std::setw(52) << std::left;
        std::cout << "resize (smaller)";
        {
            std::vector<int> std_vector((size_t)20, 100);
            ft::vector<int> ft_vector((size_t)20, 100);

            std_vector.insert(std_vector.begin(), 1);
            std_vector.insert(std_vector.begin(), 2);
            std_vector.insert(std_vector.begin(), 3);
            std_vector.insert(std_vector.begin(), 4);
            std_vector.resize(2);

            ft_vector.insert(ft_vector.begin(), 1);
            ft_vector.insert(ft_vector.begin(), 2);
            ft_vector.insert(ft_vector.begin(), 3);
            ft_vector.insert(ft_vector.begin(), 4);
            ft_vector.resize(2);

            std_return += get_info(std_vector, "STD");
            ft_return += get_info(ft_vector, "FT");
            print_result(std_return, ft_return);
        }
        std_return.clear();
        ft_return.clear(); 
        std::cout << "--------------------------------------------------------" << std::endl;
        std::cout << std::setw(52) << std::left;
        std::cout << "resize (bigger)";
        {
            std::vector<int> std_vector(2);
            ft::vector<int> ft_vector(2);

            std::cout << "\nstd cap = " <<  std_vector.capacity() << std::endl;
            std_vector.insert(std_vector.begin(), 1);
            std::cout << "std cap = " <<  std_vector.capacity() << std::endl;
            std_vector.insert(std_vector.begin(), 2);
            std::cout << "std cap = " <<  std_vector.capacity() << std::endl;
            std_vector.insert(std_vector.begin(), 3);
            std::cout << "std cap = " <<  std_vector.capacity() << std::endl;
            std_vector.insert(std_vector.begin(), 4);
            std::cout << "std cap = " <<  std_vector.capacity() << std::endl;
            std_vector.resize(10);
            std::cout << "std cap = " <<  std_vector.capacity() << std::endl;

            std::cout << "ft cap = " <<  ft_vector.capacity() << std::endl;
            ft_vector.insert(ft_vector.begin(), 1);
            std::cout << "ft cap = " <<  ft_vector.capacity() << std::endl;
            ft_vector.insert(ft_vector.begin(), 2);
            std::cout << "ft cap = " <<  ft_vector.capacity() << std::endl;
            ft_vector.insert(ft_vector.begin(), 3);
            std::cout << "ft cap = " <<  ft_vector.capacity() << std::endl;
            ft_vector.insert(ft_vector.begin(), 4);
            std::cout << "ft cap = " <<  ft_vector.capacity() << std::endl;
            ft_vector.resize(10);
            std::cout << "ft cap = " <<  ft_vector.capacity() << std::endl;

            std_return += get_info(std_vector, "STD");
            ft_return += get_info(ft_vector, "FT");
            print_result(std_return, ft_return);
        }
        std_return.clear();
        ft_return.clear(); 
        std::cout << "--------------------------------------------------------" << std::endl;
        std::cout << std::setw(52) << std::left;
        std::cout << "assign (range)";
        {
            std::vector<int> std_vector_1;
            std::vector<int> std_vector_2;
            ft::vector<int> ft_vector_1;
            ft::vector<int> ft_vector_2;

            std_vector_1.push_back(1);
            std_vector_1.push_back(2);
            std_vector_1.push_back(3);
            std_vector_1.push_back(4);
            std_vector_2.push_back(100);
            std_vector_2.push_back(200);
            std_vector_1.assign(std_vector_2.begin(), std_vector_2.end());
            
            ft_vector_1.push_back(1);
            ft_vector_1.push_back(2);
            ft_vector_1.push_back(3);
            ft_vector_1.push_back(4);
            ft_vector_2.push_back(100);
            ft_vector_2.push_back(200);
            ft_vector_1.assign(ft_vector_2.begin(), ft_vector_2.end());

            std_return += get_info(std_vector_1, "STD");
            ft_return += get_info(ft_vector_1, "FT");
            print_result(std_return, ft_return);
        }
        std_return.clear();
        ft_return.clear(); 
        std::cout << "--------------------------------------------------------" << std::endl;
        std::cout << std::setw(52) << std::left;
        std::cout << "assign (fill)";
        {
            std::vector<int> std_vector;
            ft::vector<int> ft_vector;

            unsigned int n = 4;
            int val = 100;

            std_vector.assign(n, val);
            ft_vector.assign(n, val);

            std_return += get_info(std_vector, "STD");
            ft_return += get_info(ft_vector, "FT");
            print_result(std_return, ft_return);
        }
        std_return.clear();
        ft_return.clear(); 
        std::cout << "--------------------------------------------------------" << std::endl;
        std::cout << std::setw(52) << std::left;
        std::cout << "clear";
        {
            std::vector<int> std_vector;
            ft::vector<int> ft_vector;

            std_vector.insert(std_vector.begin(), 1);
            std_vector.insert(std_vector.begin(), 2);
            std_vector.insert(std_vector.begin(), 3);
            std_vector.insert(std_vector.begin(), 4);
            std_vector.clear();

            ft_vector.insert(ft_vector.begin(), 1);
            ft_vector.insert(ft_vector.begin(), 2);
            ft_vector.insert(ft_vector.begin(), 3);
            ft_vector.insert(ft_vector.begin(), 4);
            ft_vector.clear();

            std_return += get_info(std_vector, "STD");
            ft_return += get_info(ft_vector, "FT");
            print_result(std_return, ft_return);
        }
        std_return.clear();
        ft_return.clear();
        std::cout << "--------------------------------------------------------" << std::endl;
        std::cout << std::setw(52) << std::left;
        std::cout << "iterator";
        {
            std::vector<int> std_vector;
            ft::vector<int> ft_vector;

            std_vector.push_back(1);
            std_vector.push_back(2);
            std_vector.push_back(3);
            std_vector.push_back(4);
            ft_vector.push_back(1);
            ft_vector.push_back(2);
            ft_vector.push_back(3);
            ft_vector.push_back(4);

            std::vector<int>::iterator std_it(std_vector.begin());
            ft::vector<int>::iterator ft_it(ft_vector.begin());

            std_return += "pre inc : ";
            std_return += std::to_string(*(++std_it));
            std_return += " | ";
            std_return += std::to_string(*std_it);

            std_return += "\npost inc : ";
            std_return += std::to_string(*(std_it++));
            std_return += " | ";
            std_return += std::to_string(*std_it);

            std_return += "\npre dec : ";
            std_return += std::to_string(*(--std_it));
            std_return += " | ";
            std_return += std::to_string(*std_it);

            std_return += "\npost dec : ";
            std_return += std::to_string(*(std_it--));
            std_return += " | ";
            std_return += std::to_string(*std_it);


            ft_return += "pre inc : ";
            ft_return += std::to_string(*(++ft_it));
            ft_return += " | ";
            ft_return += std::to_string(*ft_it);

            ft_return += "\npost inc : ";
            ft_return += std::to_string(*(ft_it++));
            ft_return += " | ";
            ft_return += std::to_string(*ft_it);

            ft_return += "\npre dec : ";
            ft_return += std::to_string(*(--ft_it));
            ft_return += " | ";
            ft_return += std::to_string(*ft_it);

            ft_return += "\npost dec : ";
            ft_return += std::to_string(*(ft_it--));
            ft_return += " | ";
            ft_return += std::to_string(*ft_it);

            print_result(std_return, ft_return);
        }
        std_return.clear();
        ft_return.clear();
        std::cout << "--------------------------------------------------------" << std::endl;
        std::cout << std::setw(52) << std::left;
        std::cout << "reverse iterator";
        {
            std::vector<int> std_vector;
            ft::vector<int> ft_vector;

            std_vector.push_back(1);
            std_vector.push_back(2);
            std_vector.push_back(3);
            std_vector.push_back(4);
            ft_vector.push_back(1);
            ft_vector.push_back(2);
            ft_vector.push_back(3);
            ft_vector.push_back(4);

            std::vector<int>::reverse_iterator std_it(std_vector.begin());
            ft::vector<int>::reverse_iterator ft_it(ft_vector.begin());

            std_return += "\npre dec : ";
            std_return += std::to_string(*(--std_it));
            std_return += " | ";
            std_return += std::to_string(*std_it);

            std_return += "\npost dec : ";
            std_return += std::to_string(*(std_it--));
            std_return += " | ";
            std_return += std::to_string(*std_it);

            std_return += "\npost dec : ";
            std_return += std::to_string(*(std_it--));
            std_return += " | ";
            std_return += std::to_string(*std_it);

            std_return += "\npre inc : ";
            std_return += std::to_string(*(++std_it));
            std_return += " | ";
            std_return += std::to_string(*std_it);

            std_return += "\npost inc : ";
            std_return += std::to_string(*(std_it++));
            std_return += " | ";
            std_return += std::to_string(*std_it);


            ft_return += "\npre dec : ";
            ft_return += std::to_string(*(--ft_it));
            ft_return += " | ";
            ft_return += std::to_string(*ft_it);

            ft_return += "\npost dec : ";
            ft_return += std::to_string(*(ft_it--));
            ft_return += " | ";
            ft_return += std::to_string(*ft_it);

            ft_return += "\npost dec : ";
            ft_return += std::to_string(*(ft_it--));
            ft_return += " | ";
            ft_return += std::to_string(*ft_it);

            ft_return += "\npre inc : ";
            ft_return += std::to_string(*(++ft_it));
            ft_return += " | ";
            ft_return += std::to_string(*ft_it);

            ft_return += "\npost inc : ";
            ft_return += std::to_string(*(ft_it++));
            ft_return += " | ";
            ft_return += std::to_string(*ft_it);

            print_result(std_return, ft_return);
        }
        std_return.clear();
        ft_return.clear(); 
        std::cout << "--------------------------------------------------------" << std::endl;
        std::cout << std::setw(52) << std::left;
        std::cout << "swap";
        {
            std::vector<int> std_vector_1;
            std::vector<int> std_vector_2;
            ft::vector<int> ft_vector_1;
            ft::vector<int> ft_vector_2;

            std_vector_1.push_back(1);
            std_vector_1.push_back(2);
            std_vector_1.push_back(3);
            std_vector_1.push_back(4);
            std_vector_2.push_back(100);
            std_vector_2.push_back(200);
            
            ft_vector_1.push_back(1);
            ft_vector_1.push_back(2);
            ft_vector_1.push_back(3);
            ft_vector_1.push_back(4);
            ft_vector_2.push_back(100);
            ft_vector_2.push_back(200);

            std_vector_1.swap(std_vector_2);
            ft_vector_1.swap(ft_vector_2);

            std_return += "\nvector_1:\n";
            std_return += get_info(std_vector_1, "STD");
            ft_return += "\nvector_1:\n";
            ft_return += get_info(ft_vector_1, "FT");
            print_result(std_return, ft_return);

            std_return.clear();
            ft_return.clear(); 

            std_return += "vector_2:\n";
            std_return += get_info(std_vector_2, "STD");
            ft_return += "vector_2:\n";
            ft_return += get_info(ft_vector_2, "FT");
            std::cout << std::setw(52) << std::left << " ";
            print_result(std_return, ft_return);
        }
        std_return.clear();
        ft_return.clear(); 
        std::cout << "--------------------------------------------------------" << std::endl;
        std::cout << std::setw(52) << std::left;
        std::cout << "test";
        {
            ft::vector<int>	ft_vector((size_t)4, 42);
            ft::vector<int>	ft_vector_2;
            ft_vector_2.insert(ft_vector_2.begin(), 4);
            ft_vector_2.push_back(5);
	        ft_vector_2.push_back(2);
	        ft_vector_2.push_back(4);
	        ft_vector_2.push_back(10);
	        ft_vector_2.push_back(15);
	        ft_vector_2.push_back(7);
	        ft_vector_2.push_back(1);
            ft_vector_2.push_back(2);
	        ft_vector_2.push_back(90);
            ft_vector_2.insert(ft_vector_2.begin() + 3, (size_t)7, 5555);
            ft_vector.insert(ft_vector.begin() + 2, ft_vector_2.begin(), ft_vector_2.end());

            std::vector<int> std_vector((size_t)4, 42);
            std::vector<int> std_vector_2;
            std_vector_2.insert(std_vector_2.begin(), 4);
            std_vector_2.push_back(5);
	        std_vector_2.push_back(2);
	        std_vector_2.push_back(4);
	        std_vector_2.push_back(10);
	        std_vector_2.push_back(15);
	        std_vector_2.push_back(7);
	        std_vector_2.push_back(1);
            std_vector_2.push_back(2);
	        std_vector_2.push_back(90);
            std_vector_2.insert(std_vector_2.begin() + 3, (size_t)7, 5555);
            std_vector.insert(std_vector.begin() + 2, std_vector_2.begin(), std_vector_2.end());

            std_return += get_info(std_vector, "STD");
            ft_return += get_info(ft_vector, "FT");
            print_result(std_return, ft_return);
        }
    }

    // std::cout << "--------------------------------------------------------" << std::endl;
    // std::cout << "------------------ VECTOR < STRING > -------------------" << std::endl;
    // std::cout << std::endl;

    // {
    //     std::cout << std::setw(52) << std::left;
    //     std::cout << "default constructor";
    //     {
    //         std::vector<std::string> std_vector;
    //         ft::vector<std::string> ft_vector;

    //         std_return = get_info(std_vector, "STD");
    //         ft_return = get_info(ft_vector, "FT");
    //         print_result(std_return, ft_return);
    //     }
    //     std_return.clear();
    //     ft_return.clear(); 
        // std::cout << "--------------------------------------------------------" << std::endl;
        // std::cout << std::setw(52) << std::left;
        // std::cout << "fill constructor";
        // {
        //     std::vector<std::string> std_vector(2);
        //     ft::vector<std::string> ft_vector(2);

        //     std_return = get_info(std_vector, "STD");
        //     ft_return = get_info(ft_vector, "FT");
        //     print_result(std_return, ft_return);
        // }
        // std_return.clear();
        // ft_return.clear(); 
        // std::cout << "--------------------------------------------------------" << std::endl;
        // std::cout << std::setw(52) << std::left;
        // std::cout << "push / pop";
        // {
        //     std::vector<std::string> std_vector;
        //     ft::vector<std::string> ft_vector;

        //     std_vector.push_back("ok_1");
        //     std_vector.push_back("ok_2");
        //     std_vector.push_back("ok_3");
        //     std_vector.push_back("ok_4");
        //     ft_vector.push_back("ok_1");
        //     ft_vector.push_back("ok_2");
        //     ft_vector.push_back("ok_3");
        //     ft_vector.push_back("ok_4");

        //     std_return = get_info(std_vector, "STD");
        //     ft_return = get_info(ft_vector, "FT");
        //     print_result(std_return, ft_return);

        //     std_vector.pop_back();
        //     std_vector.pop_back();
        //     ft_vector.pop_back();
        //     ft_vector.pop_back();

        //     std_return = get_info(std_vector, "STD");
        //     ft_return = get_info(ft_vector, "FT");
        //     std::cout << std::setw(52) << std::left << " ";
        //     print_result(std_return, ft_return);

        //     std_return.clear();
        //     ft_return.clear(); 

        //     std_vector.pop_back();
        //     std_vector.pop_back();
        //     ft_vector.pop_back();
        //     ft_vector.pop_back();

        //     std_return = get_info(std_vector, "STD");
        //     ft_return = get_info(ft_vector, "FT");
        //     std::cout << std::setw(52) << std::left << " ";
        //     print_result(std_return, ft_return);
        // }
        // std_return.clear();
        // ft_return.clear(); 
        // std::cout << "--------------------------------------------------------" << std::endl;
        // std::cout << std::setw(52) << std::left;
        // std::cout << "element access";
        // {
        //     std::vector<std::string> std_vector;
        //     ft::vector<std::string> ft_vector;

        //     std_vector.push_back("ok_1");
        //     std_vector.push_back("ok_2");
        //     std_vector.push_back("ok_3");
        //     std_vector.push_back("ok_4");
        //     ft_vector.push_back("ok_1");
        //     ft_vector.push_back("ok_2");
        //     ft_vector.push_back("ok_3");
        //     ft_vector.push_back("ok_4");

        //     std_return += "at(0) = ";
        //     std_return += std::to_string(std_vector.at(0));
        //     std_return += '\n';
        //     std_return += "vector[1] = ";
        //     std_return += std::to_string(std_vector[1]);
        //     std_return += '\n';
        //     std_return += "front() = ";
        //     std_return += std::to_string(std_vector.front());
        //     std_return += '\n';
        //     std_return += "back() = ";
        //     std_return += std::to_string(std_vector.back());
        //     std_return += '\n';

        //     ft_return += "at(0) = ";
        //     ft_return += std::to_string(ft_vector.at(0));
        //     ft_return += '\n';
        //     ft_return += "vector[1] = ";
        //     ft_return += std::to_string(ft_vector[1]);
        //     ft_return += '\n';
        //     ft_return += "front() = ";
        //     ft_return += std::to_string(ft_vector.front());
        //     ft_return += '\n';
        //     ft_return += "back() = ";
        //     ft_return += std::to_string(ft_vector.back());
        //     ft_return += '\n';

        //     std_return += get_info(std_vector, "STD");
        //     ft_return += get_info(ft_vector, "FT");
        //     print_result(std_return, ft_return);
        // }
        // std_return.clear();
        // ft_return.clear(); 
        // std::cout << "--------------------------------------------------------" << std::endl;
        // std::cout << std::setw(52) << std::left;
        // std::cout << "range constructor";
        // {
        //     std::vector<std::string> std_vector;
        //     ft::vector<std::string> ft_vector;

        //     std_vector.push_back("ok_1");
        //     std_vector.push_back("ok_2");
        //     std_vector.push_back("ok_3");
        //     std_vector.push_back("ok_4");
        //     ft_vector.push_back("ok_1");
        //     ft_vector.push_back("ok_2");
        //     ft_vector.push_back("ok_3");
        //     ft_vector.push_back("ok_4");

        //     std::vector<std::string> std_range_vector(std_vector.begin(), std_vector.begin() + 2);
        //     ft::vector<std::string> ft_range_vector(ft_vector.begin(), ft_vector.begin() + 2);

        //     std_return += get_info(std_vector, "STD");
        //     ft_return += get_info(ft_vector, "FT");
        //     print_result(std_return, ft_return);
        // }
        // std_return.clear();
        // ft_return.clear(); 
        // std::cout << "--------------------------------------------------------" << std::endl;
        // std::cout << std::setw(52) << std::left;
        // std::cout << "copy constructor";
        // {
        //     std::vector<std::string> std_vector;
        //     ft::vector<std::string> ft_vector;

        //     std_vector.push_back("ok_1");
        //     std_vector.push_back("ok_2");
        //     std_vector.push_back("ok_3");
        //     std_vector.push_back("ok_4");
        //     ft_vector.push_back("ok_1");
        //     ft_vector.push_back("ok_2");
        //     ft_vector.push_back("ok_3");
        //     ft_vector.push_back("ok_4");

        //     std::vector<std::string> std_range_vector(std_vector.begin(), std_vector.begin() + 2);
        //     ft::vector<std::string> ft_range_vector(ft_vector.begin(), ft_vector.begin() + 2);

        //     std::vector<std::string> std_copy_vector(std_range_vector);
        //     ft::vector<std::string> ft_copy_vector(ft_range_vector);

        //     std_return += get_info(std_vector, "STD");
        //     ft_return += get_info(ft_vector, "FT");
        //     print_result(std_return, ft_return);
        // }
        // std_return.clear();
        // ft_return.clear(); 
        // std::cout << "--------------------------------------------------------" << std::endl;
        // std::cout << std::setw(52) << std::left;
        // std::cout << "insert a single element";
        // {
        //     std::vector<std::string> std_vector(2);
        //     ft::vector<std::string> ft_vector(2);

        //     std::vector<std::string>::iterator std_ret;
        //     ft::vector<std::string>::iterator ft_ret;

        //     std_return += "insert() return = ";
        //     std_ret = std_vector.insert(std_vector.begin(), 2);
        //     std_return += std::to_string(*std_ret);
        //     std_return += "\n";
        //     std_return += "insert() return = ";
        //     std_ret =  std_vector.insert(std_vector.end(), 1);
        //     std_return += std::to_string(*std_ret);
        //     std_return += "\n";

        //     ft_return += "insert() return = ";
        //     ft_ret = ft_vector.insert(ft_vector.begin(), 2);
        //     ft_return += std::to_string(*ft_ret);
        //     ft_return += "\n";
        //     ft_return += "insert() return = ";
        //     ft_ret = ft_vector.insert(ft_vector.end(), 1);
        //     ft_return += std::to_string(*ft_ret);
        //     ft_return += "\n";

        //     std_return += get_info(std_vector, "STD");
        //     ft_return += get_info(ft_vector, "FT");
        //     print_result(std_return, ft_return);
        // }
        // std_return.clear();
        // ft_return.clear(); 
        // std::cout << "--------------------------------------------------------" << std::endl;
        // std::cout << std::setw(52) << std::left;
        // std::cout << "insert (fill)";
        // {
        //     std::vector<std::string> std_vector(2);
        //     ft::vector<std::string> ft_vector(2);

        //     unsigned int n = 2;
        //     std::string val = "warzouz";

        //     std_vector.insert(std_vector.begin(), n, val);
        //     std_vector.insert(std_vector.end(), n, val);

        //     ft_vector.insert(ft_vector.begin(), n, val);
        //     ft_vector.insert(ft_vector.end(), n, val);

        //     std_return += get_info(std_vector, "STD");
        //     ft_return += get_info(ft_vector, "FT");
        //     print_result(std_return, ft_return);
        // }
        // std_return.clear();
        // ft_return.clear(); 
        // std::cout << "--------------------------------------------------------" << std::endl;
        // std::cout << std::setw(52) << std::left;
        // std::cout << "insert (range)";
        // {
        //     std::vector<std::string> std_vector;
        //     ft::vector<std::string> ft_vector;

        //     std_vector.push_back("ok_1");
        //     std_vector.push_back("ok_2");
        //     std_vector.push_back("ok_3");
        //     std_vector.push_back("ok_4");
        //     ft_vector.push_back("ok_1");
        //     ft_vector.push_back("ok_2");
        //     ft_vector.push_back("ok_3");
        //     ft_vector.push_back("ok_4");

        //     std::vector<std::string> std_new_vector;
        //     ft::vector<std::string> ft_new_vector;

        //     std_new_vector.insert(std_new_vector.begin(), std_vector.begin(), std_vector.begin() + 2);
        //     std_new_vector.insert(std_new_vector.end(), std_vector.begin() + 2, std_vector.end());

        //     ft_new_vector.insert(ft_new_vector.begin(), ft_vector.begin(), ft_vector.begin() + 2);
        //     ft_new_vector.insert(ft_new_vector.end(), ft_vector.begin() + 2, ft_vector.end());

        //     std_return += get_info(std_vector, "STD");
        //     ft_return += get_info(ft_vector, "FT");
        //     print_result(std_return, ft_return);
        // }
        // std_return.clear();
        // ft_return.clear(); 
        // std::cout << "--------------------------------------------------------" << std::endl;
        // std::cout << std::setw(52) << std::left;
        // std::cout << "erase one element";
        // {
        //     std::vector<std::string> std_vector(2);
        //     ft::vector<std::string> ft_vector(2);
        //     std::vector<std::string>::iterator std_ret;
        //     ft::vector<std::string>::iterator ft_ret;

        //     std_vector.insert(std_vector.begin(), 2);
        //     std_vector.insert(std_vector.begin(), 1);
        //     std_vector.insert(std_vector.begin(), 3);
        //     std_vector.insert(std_vector.begin(), 4);
        //     std_vector.erase(std_vector.begin() + 1);
        //     std_ret = std_vector.erase(std_vector.begin(), std_vector.begin() + 1);

        //     ft_vector.insert(ft_vector.begin(), 2);
        //     ft_vector.insert(ft_vector.begin(), 1);
        //     ft_vector.insert(ft_vector.begin(), 3);
        //     ft_vector.insert(ft_vector.begin(), 4);
        //     ft_vector.erase(ft_vector.begin() + 1);
        //     ft_ret = ft_vector.erase(ft_vector.begin(), ft_vector.begin() + 1);

        //     std_return += "erase() return = ";
        //     std_return += std::to_string(*std_ret);
        //     ft_return += "erase() return = ";
        //     ft_return += std::to_string(*ft_ret);
        //     std_return += get_info(std_vector, "STD");
        //     ft_return += get_info(ft_vector, "FT");
        //     print_result(std_return, ft_return);
        // }
        // std_return.clear();
        // ft_return.clear(); 
        // std::cout << "--------------------------------------------------------" << std::endl;
        // std::cout << std::setw(52) << std::left;
        // std::cout << "erase (range)";
        // {
        //     std::vector<std::string> std_vector;
        //     ft::vector<std::string> ft_vector;
        //     std::vector<std::string>::iterator std_ret;
        //     ft::vector<std::string>::iterator ft_ret;

        //     std_vector.insert(std_vector.begin(), 1);
        //     std_vector.insert(std_vector.begin(), 2);
        //     std_vector.insert(std_vector.begin(), 3);
        //     std_vector.insert(std_vector.begin(), 4);
        //     std_ret = std_vector.erase(std_vector.begin() + 1, std_vector.begin() + 3);

        //     ft_vector.insert(ft_vector.begin(), 1);
        //     ft_vector.insert(ft_vector.begin(), 2);
        //     ft_vector.insert(ft_vector.begin(), 3);
        //     ft_vector.insert(ft_vector.begin(), 4);
        //     ft_ret = ft_vector.erase(ft_vector.begin() + 1, ft_vector.begin() + 3);

        //     std_return += "erase() return = ";
        //     std_return += std::to_string(*std_ret);
        //     ft_return += "erase() return = ";
        //     ft_return += std::to_string(*ft_ret);
        //     std_return += get_info(std_vector, "STD");
        //     ft_return += get_info(ft_vector, "FT");
        //     print_result(std_return, ft_return);
        // }
        // std_return.clear();
        // ft_return.clear(); 
        // std::cout << "--------------------------------------------------------" << std::endl;
        // std::cout << std::setw(52) << std::left;
        // std::cout << "resize (smaller)";
        // {
        //     std::vector<std::string> std_vector;
        //     ft::vector<std::string> ft_vector;

        //     std_vector.insert(std_vector.begin(), 1);
        //     std_vector.insert(std_vector.begin(), 2);
        //     std_vector.insert(std_vector.begin(), 3);
        //     std_vector.insert(std_vector.begin(), 4);
        //     std_vector.resize(2);

        //     ft_vector.insert(ft_vector.begin(), 1);
        //     ft_vector.insert(ft_vector.begin(), 2);
        //     ft_vector.insert(ft_vector.begin(), 3);
        //     ft_vector.insert(ft_vector.begin(), 4);
        //     ft_vector.resize(2);

        //     std_return += get_info(std_vector, "STD");
        //     ft_return += get_info(ft_vector, "FT");
        //     print_result(std_return, ft_return);
        // }
        // std_return.clear();
        // ft_return.clear(); 
        // std::cout << "--------------------------------------------------------" << std::endl;
        // std::cout << std::setw(52) << std::left;
        // std::cout << "resize (bigger)";
        // {
        //     std::vector<std::string> std_vector(2);
        //     ft::vector<std::string> ft_vector(2);

        //     std_vector.insert(std_vector.begin(), 1);
        //     std_vector.insert(std_vector.begin(), 2);
        //     std_vector.insert(std_vector.begin(), 3);
        //     std_vector.insert(std_vector.begin(), 4);
        //     std_vector.resize(10);

        //     ft_vector.insert(ft_vector.begin(), 1);
        //     ft_vector.insert(ft_vector.begin(), 2);
        //     ft_vector.insert(ft_vector.begin(), 3);
        //     ft_vector.insert(ft_vector.begin(), 4);
        //     ft_vector.resize(10);

        //     std_return += get_info(std_vector, "STD");
        //     ft_return += get_info(ft_vector, "FT");
        //     print_result(std_return, ft_return);
        // }
        // std_return.clear();
        // ft_return.clear(); 
        // std::cout << "--------------------------------------------------------" << std::endl;
        // std::cout << std::setw(52) << std::left;
        // std::cout << "assign (range)";
        // {
        //     std::vector<std::string> std_vector_1;
        //     std::vector<std::string> std_vector_2;
        //     ft::vector<std::string> ft_vector_1;
        //     ft::vector<std::string> ft_vector_2;

        //     std_vector_1.push_back("ok_1");
        //     std_vector_1.push_back("ok_2");
        //     std_vector_1.push_back("ok_3");
        //     std_vector_1.push_back("ok_4");
        //     std_vector_2.push_back("yo_1");
        //     std_vector_2.push_back("yo_2");
        //     std_vector_1.assign(std_vector_2.begin(), std_vector_2.end());

        //     ft_vector_1.push_back("ok_1");
        //     ft_vector_1.push_back("ok_2");
        //     ft_vector_1.push_back("ok_3");
        //     ft_vector_1.push_back("ok_4");
        //     ft_vector_2.push_back("yo_1");
        //     ft_vector_2.push_back("yo_2");
        //     ft_vector_1.assign(ft_vector_2.begin(), ft_vector_2.end());

        //     std_return += get_info(std_vector_1, "STD");
        //     ft_return += get_info(ft_vector_1, "FT");
        //     print_result(std_return, ft_return);
        // }
        // std_return.clear();
        // ft_return.clear(); 
        // std::cout << "--------------------------------------------------------" << std::endl;
        // std::cout << std::setw(52) << std::left;
        // std::cout << "assign (fill)";
        // {
        //     std::vector<std::string> std_vector;
        //     std::vector<std::string> ft_vector;

        //     unsigned int n = 4;
        //     std::string val = "warzouz";

        //     std_vector.assign(n, val);
        //     ft_vector.assign(n, val);

        //     std_return += get_info(std_vector, "STD");
        //     ft_return += get_info(ft_vector, "FT");
        //     print_result(std_return, ft_return);
        // }
        // std_return.clear();
        // ft_return.clear(); 
        // std::cout << "--------------------------------------------------------" << std::endl;
        // std::cout << std::setw(52) << std::left;
        // std::cout << "clear";
        // {
        //     std::vector<std::string> std_vector;
        //     std::vector<std::string> ft_vector;

        //     std_vector.insert(std_vector.begin(), 1);
        //     std_vector.insert(std_vector.begin(), 2);
        //     std_vector.insert(std_vector.begin(), 3);
        //     std_vector.insert(std_vector.begin(), 4);
        //     std_vector.clear();

        //     ft_vector.insert(ft_vector.begin(), 1);
        //     ft_vector.insert(ft_vector.begin(), 2);
        //     ft_vector.insert(ft_vector.begin(), 3);
        //     ft_vector.insert(ft_vector.begin(), 4);
        //     ft_vector.clear();

        //     std_return += get_info(std_vector, "STD");
        //     ft_return += get_info(ft_vector, "FT");
        //     print_result(std_return, ft_return);
        // }
        // std_return.clear();
        // ft_return.clear(); 
        // std::cout << "--------------------------------------------------------" << std::endl;
        // std::cout << std::setw(52) << std::left;
        // std::cout << "swap";
        // {
        //     std::vector<std::string> std_vector_1;
        //     std::vector<std::string> std_vector_2;
        //     ft::vector<std::string> ft_vector_1;
        //     ft::vector<std::string> ft_vector_2;

        //     std_vector_1.push_back("ok_1");
        //     std_vector_1.push_back("ok_2");
        //     std_vector_1.push_back("ok_3");
        //     std_vector_1.push_back("ok_4");
        //     std_vector_2.push_back("yo_1");
        //     std_vector_2.push_back("yo_2");

        //     ft_vector_1.push_back("ok_1");
        //     ft_vector_1.push_back("ok_2");
        //     ft_vector_1.push_back("ok_3");
        //     ft_vector_1.push_back("ok_4");
        //     ft_vector_2.push_back("yo_1");
        //     ft_vector_2.push_back("yo_2");

        //     std_vector_1.swap(std_vector_2);
        //     ft_vector_1.swap(ft_vector_2);

        //     std_return += "\nvector_1:\n";
        //     std_return += get_info(std_vector_1, "STD");
        //     ft_return += "\nvector_1:\n";
        //     ft_return += get_info(ft_vector_1, "FT");
        //     print_result(std_return, ft_return);

        //     std_return.clear();
        //     ft_return.clear(); 

        //     std_return += "vector_2:\n";
        //     std_return += get_info(std_vector_2, "STD");
        //     ft_return += "vector_2:\n";
        //     ft_return += get_info(ft_vector_2, "FT");
        //     std::cout << std::setw(52) << std::left << " ";
        //     print_result(std_return, ft_return);
        // }
    // }

    return 0;
}
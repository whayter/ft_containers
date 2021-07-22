/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 13:03:35 by hwinston          #+#    #+#             */
/*   Updated: 2021/07/19 12:55:53 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <list>

#ifdef STD
    #include <vector>
    namespace ft = std;
#else
    #include "../inc/vector.hpp"
#endif

#define VALUE_TYPE int

void intro()
{
    std::cout << "--------------------------------------------------------" << std::endl;
    #ifdef STD
        std::cout << "----------------------- std::vector --------------------" << std::endl;
    #else
        std::cout << "----------------------- ft::vector ---------------------" << std::endl;
    #endif
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << std::endl;
}

template <class T>
void get_capacities(ft::vector<T>& vector)
{
    std::cout << std::endl;
    std::cout << "-- capacities:" << std::endl;
    std::cout << std::endl;
    std::cout << std::setw(21) << std::left;
    std::cout << "empty: " << vector.empty() << std::endl;
    std::cout << std::setw(21) << std::left;
    std::cout << "size: " << vector.size() << std::endl;
    std::cout << std::setw(21) << std::left;
    std::cout << "max size: " << vector.max_size() << std::endl;
    std::cout << std::setw(21) << std::left;
    std::cout << "capacity: " << vector.capacity() << std::endl;
}

template <class T>
void get_access(ft::vector<T> vector)
{
    std::cout << std::endl;
    std::cout << "-- access:" << std::endl;
    std::cout << std::endl;
    std::cout << std::setw(21) << std::left;
	std::cout << "Front: " << vector.front() << std::endl;
    std::cout << std::setw(21) << std::left;
	std::cout << "Back: " << vector.back() << std::endl;
}

template <class T>
void get_content(ft::vector<T> vector)
{
    std::cout << std::endl;
    std::cout << "-- content:" << std::endl;
    std::cout << std::endl;
    std::cout << std::setw(20) << std::left;
    std::cout << "using []:";
    for (size_t i = 0; i < vector.size(); i++)
        std::cout << " " << vector[i];
    std::cout << std::endl;
    std::cout << std::setw(20) << std::left;
    std::cout << "using at:";
    for (size_t i = 0; i < vector.size(); i++)
        std::cout << " " << vector.at(i);
    std::cout << std::endl;
    std::cout << std::setw(20) << std::left;
    std::cout << "using iterator:";
    for (typename ft::vector<T>::iterator it = vector.begin(); it != vector.end(); it++)
        std::cout << " " << *it;
    std::cout << std::endl;
    std::cout << std::setw(20) << std::left;
    std::cout << "using rev iterator:";
    for (typename ft::vector<T>::reverse_iterator it = vector.rbegin(); it != vector.rend(); it++)
        std::cout << " " << *it;
    std::cout << std::endl;
}

void    iterator_tests(ft::vector<VALUE_TYPE> &vct)
{
        ft::vector<VALUE_TYPE>::iterator it = vct.begin();
        ft::vector<VALUE_TYPE>::iterator it_tmp;

        std::cout << "Pre inc" << std::endl;
        it_tmp = ++it;
        std::cout << *it_tmp << " | " << *it << std::endl;

        std::cout << "Pre dec" << std::endl;
        it_tmp = --it;
        std::cout << *it_tmp << " | " << *it << std::endl;

        std::cout << "Post inc" << std::endl;
        it_tmp = it++;
        std::cout << *it_tmp << " | " << *it << std::endl;

        std::cout << "Post dec" << std::endl;
        it_tmp = it--;
        std::cout << *it_tmp << " | " << *it << std::endl;
        std::cout << std::endl;
}

/* ----------------------------------------------------------------------------------- */
/* ----------------------------------------------------------------------------------- */

int main()
{
    //intro();
    std::cout << "--------------------------------------------------------" << std::endl;
    {
        std::cout << "----------------- default constructor ------------------" << std::endl;

        ft::vector<VALUE_TYPE> empty_vector;

        get_capacities(empty_vector);
        get_content(empty_vector);
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    {
        std::cout << "----------------- fill constructor (1)------------------" << std::endl;

        ft::vector<VALUE_TYPE> fill_vector(5);

        get_capacities(fill_vector);
        get_access(fill_vector);
        get_content(fill_vector);
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    {
        std::cout << "----------------- fill constructor (2) -----------------" << std::endl;

        ft::vector<VALUE_TYPE> fill_vector(5, 50);

        get_capacities(fill_vector);
        get_access(fill_vector);
        get_content(fill_vector);
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    {
        std::cout << "----------------- fill constructor (3) -----------------" << std::endl;

        ft::vector<VALUE_TYPE> fill_vector(0, 50);

        get_capacities(fill_vector);
        get_content(fill_vector);
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    {
        std::cout << "----------------- range constructor (1) ----------------" << std::endl;

        ft::vector<VALUE_TYPE> fill_vector(10, 50);
        ft::vector<VALUE_TYPE> range_vector(fill_vector.begin(), fill_vector.begin() + 2);

        get_capacities(range_vector);
        get_access(range_vector);
        get_content(range_vector);
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    {
        std::cout << "----------------- range constructor (2) ----------------" << std::endl;

        ft::vector<VALUE_TYPE> fill_vector(10, 50);
        ft::vector<VALUE_TYPE> range_vector(fill_vector.begin(), fill_vector.begin());

        get_capacities(range_vector);
        get_content(range_vector);
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    {
        std::cout << "------------------ copy constructor (1) ----------------" << std::endl;

        ft::vector<VALUE_TYPE> fill_vector(10, 50);
        ft::vector<VALUE_TYPE> copy_vector(fill_vector);

        get_capacities(copy_vector);
        get_access(copy_vector);
        get_content(copy_vector);
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    {
        std::cout << "------------------ copy constructor (2) ----------------" << std::endl;

        ft::vector<VALUE_TYPE> empty_vector;
        ft::vector<VALUE_TYPE> copy_vector(empty_vector);

        get_capacities(copy_vector);
        get_content(copy_vector);
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    {
        std::cout << "---------------------- push / pop ----------------------" << std::endl;

        ft::vector<VALUE_TYPE> vector;

        vector.push_back(50);
        vector.push_back(51);
        vector.push_back(52);
        vector.push_back(53);

        get_capacities(vector);
        get_access(vector);
        get_content(vector);
        std::cout << std::endl;

        vector.pop_back();
        vector.pop_back();
        vector.pop_back();

        get_capacities(vector);
        get_access(vector);
        get_content(vector);
        std::cout << std::endl;

        vector.pop_back();

        get_capacities(vector);
        get_content(vector);
        std::cout << std::endl;        
    }
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    {
        std::cout << "----------------- insert (single element) --------------" << std::endl;

        ft::vector<VALUE_TYPE> vector;

        vector.insert(vector.begin(), 42);

        get_capacities(vector);
        get_access(vector);
        get_content(vector);
        std::cout << std::endl;

        vector.insert(vector.begin(), 57);

        get_capacities(vector);
        get_access(vector);
        get_content(vector);
        std::cout << std::endl;

        vector.insert(vector.end(), 58);

        get_capacities(vector);
        get_access(vector);
        get_content(vector);
        std::cout << std::endl;

        vector.insert(vector.begin() + 1, 1);
        vector.insert(vector.begin() + 1, 2);

        get_capacities(vector);
        get_access(vector);
        get_content(vector);
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    {
        std::cout << "---------------------- insert (fill) -------------------" << std::endl;

        ft::vector<VALUE_TYPE> vector;

        vector.insert(vector.begin(), 8, 61);

        get_capacities(vector);
        get_access(vector);
        get_content(vector);
        std::cout << std::endl;

        vector.insert(vector.begin()+ 4, 2, 80);

        get_capacities(vector);
        get_access(vector);
        get_content(vector);
        std::cout << std::endl;

        vector.insert(vector.begin()+ 5, 7, 81);

        get_capacities(vector);
        get_access(vector);
        get_content(vector);
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    {
        std::cout << "------------------- insert (range) (1) -----------------" << std::endl;

        ft::vector<VALUE_TYPE> vector;
        ft::vector<VALUE_TYPE> vector_2;

        vector.insert(vector.begin(), 8, 48);
        vector.insert(vector.begin()+ 4, 2, 49);
        vector.insert(vector.begin()+ 5, 7, 50);

        vector_2.insert(vector_2.begin(), vector.begin() + 2, vector.begin() + 7);

        get_capacities(vector_2);
        get_access(vector_2);
        get_content(vector_2);
        std::cout << std::endl;

        vector_2.insert(vector_2.end(), vector.begin() + 12, vector.begin() + 14);

        get_capacities(vector_2);
        get_access(vector_2);
        get_content(vector_2);
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    {
        std::cout << "------------------- insert (range) (2) -----------------" << std::endl;

        ft::vector<VALUE_TYPE> vector;
        ft::vector<VALUE_TYPE> vector_2(4, 48);

        vector.insert(vector.begin(), 8, 49);
        vector.insert(vector.begin()+ 4, 2, 50);
        vector.insert(vector.begin()+ 5, 7, 51);

        vector_2.insert(vector_2.begin(), vector.begin() + 2, vector.begin() + 7);

        get_capacities(vector_2);
        get_access(vector_2);
        get_content(vector_2);
        std::cout << std::endl;

        vector_2.insert(vector_2.end(), vector.begin() + 12, vector.begin() + 14);

        get_capacities(vector_2);
        get_access(vector_2);
        get_content(vector_2);
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    {
        std::cout << "--------------------- assign (fill) --------------------" << std::endl;

        ft::vector<VALUE_TYPE> vector;

        vector.assign(10, 100);

        get_capacities(vector);
        get_access(vector);
        get_content(vector);
        std::cout << std::endl;

        vector.assign(8, 48);

        get_capacities(vector);
        get_access(vector);
        get_content(vector);
        std::cout << std::endl;

        vector.assign(15, 50);

        get_capacities(vector);
        get_access(vector);
        get_content(vector);
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    {
        std::cout << "-------------------- assign (range) --------------------" << std::endl;

        ft::vector<VALUE_TYPE> vector;
        ft::vector<VALUE_TYPE> vector_2;

        vector.insert(vector.begin(), 8, 48);
        vector.insert(vector.begin()+ 4, 2, 49);
        vector.insert(vector.begin()+ 5, 7, 50);

        vector_2.assign(vector.begin() + 2, vector.end());

        get_capacities(vector_2);
        get_access(vector_2);
        get_content(vector_2);
        std::cout << std::endl;

        vector_2.assign(vector.begin() + 4, vector.end());

        get_capacities(vector_2);
        get_access(vector_2);
        get_content(vector_2);
        std::cout << std::endl;

        vector_2.assign(vector.begin(), vector.end());

        get_capacities(vector_2);
        get_access(vector_2);
        get_content(vector_2);
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    {
        std::cout << "-------------------- resize (smaller) ------------------" << std::endl;

        ft::vector<VALUE_TYPE> vector;

        vector.insert(vector.begin(), 8, 48);
        vector.insert(vector.begin()+ 4, 2, 49);
        vector.insert(vector.begin()+ 5, 7, 50);

        vector.resize(2);

        get_capacities(vector);
        get_access(vector);
        get_content(vector);
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    {
        std::cout << "--------------------- resize (bigger) ------------------" << std::endl;

        ft::vector<VALUE_TYPE> vector;

        vector.insert(vector.begin(), 8, 48);
        vector.insert(vector.begin()+ 4, 2, 49);
        vector.insert(vector.begin()+ 5, 7, 50);

        vector.resize(50);

        get_capacities(vector);
        get_access(vector);
        get_content(vector);
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    {
        std::cout << "-------------------------- clear -----------------------" << std::endl;

        ft::vector<VALUE_TYPE> vector;

        vector.insert(vector.begin(), 8, 48);
        vector.insert(vector.begin()+ 4, 2, 49);
        vector.insert(vector.begin()+ 5, 7, 50);

        vector.clear();

        get_capacities(vector);
        get_content(vector);
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    {
        std::cout << "----------------- erase (single element) ---------------" << std::endl;

        ft::vector<VALUE_TYPE> vector;

        vector.insert(vector.begin(), 8, 48);
        vector.insert(vector.begin()+ 4, 2, 49);
        vector.insert(vector.begin()+ 5, 7, 50);

        vector.erase(vector.begin());
        vector.erase(vector.begin() + 6);

        get_capacities(vector);
        get_access(vector);
        get_content(vector);
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    {
        std::cout << "--------------------- iterator (1) ----------------------" << std::endl;

        const int size = 5;
        ft::vector<VALUE_TYPE> vct(size);
        ft::vector<VALUE_TYPE>::iterator it = vct.begin();
        ft::vector<VALUE_TYPE>::const_iterator ite = vct.begin();

        for (int i = 0; i < size; ++i)
            it[i] = (size - i) * 5;
        iterator_tests(vct);

        it = it + 5;
        it = 1 + it;
        it = it - 4;
        std::cout << *(it += 2) << std::endl;
        std::cout << *(it -= 1) << std::endl;

        *(it -= 2) = 42;
        *(it += 2) = 21;

        std::cout << "const_ite +=/-=: " << *(ite += 2) << " | " << *(ite -= 2) << std::endl;

        std::cout << "(it == const_it): " << (ite == it) << std::endl;
        std::cout << "(const_ite - it): " << (ite - it) << std::endl;
        std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;

        get_capacities(vct);
    }
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    {
        std::cout << "--------------------- iterator (2) ----------------------" << std::endl;

        const int size = 5;
        ft::vector<VALUE_TYPE> vct(size);
        ft::vector<VALUE_TYPE>::reverse_iterator it = vct.rbegin();
        ft::vector<VALUE_TYPE>::const_reverse_iterator ite = vct.rbegin();

        for (int i = 0; i < size; ++i)
            it[i] = (size - i) * 5;
        
        get_capacities(vct);
        get_access(vct);
        get_content(vct);

        it = it + 5;
        it = 1 + it;
        it = it - 4;
        std::cout << *(it += 2) << std::endl;
        std::cout << *(it -= 1) << std::endl;

        *(it -= 2) = 42;
        *(it += 2) = 21;

        std::cout << "const_ite +=/-=: " << *(ite += 2) << " | " << *(ite -= 2) << std::endl;

        std::cout << "(it == const_it): " << (ite == it) << std::endl;
        std::cout << "(const_ite - it): " << (ite - it) << std::endl;
        std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;

        get_capacities(vct);
        get_access(vct);
        get_content(vct);
    }
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    {
        std::cout << "----------------------- swap ---------------------------" << std::endl;

        ft::vector<VALUE_TYPE> foo(3, 15);
        ft::vector<VALUE_TYPE> bar(5, 42);
        
        ft::vector<VALUE_TYPE>::const_iterator it_foo = foo.begin();
        ft::vector<VALUE_TYPE>::const_iterator it_bar = bar.begin();

        std::cout << "BEFORE SWAP" << std::endl;

        std::cout << "foo contains:" << std::endl;
        get_capacities(foo);
        get_access(foo);
        get_content(foo);
        std::cout << "bar contains:" << std::endl;
        get_capacities(bar);
        get_access(bar);
        get_content(bar);

        foo.swap(bar);

        std::cout << "AFTER SWAP" << std::endl;

        std::cout << "foo contains:" << std::endl;
        get_capacities(foo);
        get_access(foo);
        get_content(foo);
        std::cout << "bar contains:" << std::endl;
        get_capacities(bar);
        get_access(bar);
        get_content(bar);

        std::cout << "Iterator validity:" << std::endl;
        std::cout << (it_foo == bar.begin()) << std::endl;
        std::cout << (it_bar == foo.begin()) << std::endl;
    }
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    {
        std::cout << "---------------------- hard test 1 ---------------------" << std::endl;

        ft::vector<VALUE_TYPE> vec(4, 42);
        ft::vector<VALUE_TYPE> vec_2;

        vec_2.insert(vec_2.begin(), 4);
        vec_2.push_back(5);
        vec_2.push_back(2);
        vec_2.push_back(4);
        vec_2.push_back(10);
        vec_2.push_back(15);
        vec_2.push_back(7);
        vec_2.push_back(1);
        vec_2.push_back(2);
        vec_2.push_back(90);

        vec_2.insert(vec_2.begin() + 2, 42);
        vec_2.insert(vec_2.begin() + 3, 7, 5555);

        std::cout << "--- vec" << std::endl;
        get_capacities(vec);
        get_access(vec);
        get_content(vec);
        std::cout << std::endl;

        std::cout << "--- vec.insert(vec.begin() + 2, vec_2.begin(), vec_2.end())" << std::endl;

        vec.insert(vec.begin() + 2, vec_2.begin(), vec_2.end());

        get_capacities(vec);
        get_access(vec);
        get_content(vec);
        std::cout << std::endl;

        std::cout << "--- vec.resize(9)" << std::endl;

        vec.resize(9);

        get_capacities(vec);
        get_access(vec);
        get_content(vec);
        std::cout << std::endl;

        std::cout << "--- vec.resize(19, 1111)" << std::endl;

        vec.resize(19, 1111);

        get_capacities(vec);
        get_access(vec);
        get_content(vec);
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    {
        std::cout << "---------------------- hard test 2 ---------------------" << std::endl;

        ft::vector<VALUE_TYPE> vct(5);
        ft::vector<VALUE_TYPE>::iterator it = vct.begin();
        ft::vector<VALUE_TYPE>::iterator ite = vct.end();

        std::cout << "len: " << (ite - it) << std::endl;
        for (; it != ite; ++it)
                *it = (ite - it);

        it = vct.begin();
        ft::vector<VALUE_TYPE> vct_range(it, --(--ite));
        for (int i = 0; it != ite; ++it)
                *it = ++i * 5;

        it = vct.begin();
        ft::vector<VALUE_TYPE> vct_copy(vct);
        for (int i = 0; it != ite; ++it)
                *it = ++i * 7;
        vct_copy.push_back(42);
        vct_copy.push_back(21);

        get_capacities(vct);
        get_capacities(vct_range);
        get_capacities(vct_copy);
        std::cout << std::endl;

        vct = vct_copy;
        vct_copy = vct_range;
        vct_range.clear();

        get_capacities(vct);
        get_capacities(vct_range);
        get_capacities(vct_copy);
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    {
        std::cout << "---------------------- hard test 3 ---------------------" << std::endl;

        ft::vector<VALUE_TYPE> vct(7);
        ft::vector<VALUE_TYPE> vct_two(4);
        ft::vector<VALUE_TYPE> vct_three;
        ft::vector<VALUE_TYPE> vct_four;

        for (unsigned long int i = 0; i < vct.size(); ++i)
                vct[i] = (vct.size() - i) * 3;
        for (unsigned long int i = 0; i < vct_two.size(); ++i)
                vct_two[i] = (vct_two.size() - i) * 5;

        std::cout << "--- vct:" << std::endl;
        get_capacities(vct);
        std::cout << "--- vct_two:" << std::endl;
        get_capacities(vct_two);

        vct_three.assign(vct.begin(), vct.end());
        vct.assign(vct_two.begin(), vct_two.end());
        vct_two.assign(2, 42);
        vct_four.assign(4, 21);

        std::cout << "--- vct:" << std::endl;
        get_capacities(vct);
        std::cout << "--- vct_two:" << std::endl;
        get_capacities(vct_two);
        std::cout << "--- vct_three:" << std::endl;
        get_capacities(vct_three);
        std::cout << "--- vct_four:" << std::endl;
        get_capacities(vct_four);

        vct_four.assign(6, 84);
        std::cout << "--- vct_four:" << std::endl;
        get_capacities(vct_four);

        vct.assign(5, 53);
        vct_two.assign(vct_three.begin(), vct_three.begin() + 3);

        std::cout << "--- vct:" << std::endl;
        get_capacities(vct);
        std::cout << "--- vct_two:" << std::endl;
        get_capacities(vct_two);
    }
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    {
         std::cout << "---------------------- hard test 4 ---------------------" << std::endl;

        ft::vector<VALUE_TYPE> vct(10);
        ft::vector<VALUE_TYPE> vct2;

        for (unsigned long int i = 0; i < vct.size(); ++i)
            vct[i] = (vct.size() - i) * 3;
        get_capacities(vct);
        get_access(vct);
        get_content(vct);

        vct2.insert(vct2.end(), 42);
        get_capacities(vct2);
        get_access(vct2);
        get_content(vct2);
    
        vct2.insert(vct2.begin(), 2, 21);
        get_capacities(vct2);
        get_access(vct2);
        get_content(vct2);

        vct2.insert(vct2.end() - 2, 42);
        get_capacities(vct2);

        vct2.insert(vct2.end(), 2, 84);
        get_capacities(vct2);

        vct2.resize(4);
        get_capacities(vct2);

        vct2.insert(vct2.begin() + 2, vct.begin(), vct.end());
        vct.clear();
        get_capacities(vct2);

        get_capacities(vct);
    }
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    {
        std::cout << "---------------------- hard test 5 ---------------------" << std::endl;

        ft::vector<VALUE_TYPE> vct(5);
        ft::vector<VALUE_TYPE> vct2;
        const int cut = 3;

        for (unsigned long int i = 0; i < vct.size(); ++i)
                vct[i] = (vct.size() - i) * 7;
        get_capacities(vct);

        vct2.insert(vct2.begin(), vct.begin(), vct.begin() + cut);
        get_capacities(vct2);
        vct2.insert(vct2.begin(), vct.begin() + cut, vct.end());
        get_capacities(vct2);
        vct2.insert(vct2.end(), vct.begin(), vct.begin() + cut);
        get_capacities(vct2);

        std::cout << "insert return:" << std::endl;

        std::cout << *vct2.insert(vct2.end(), 42) << std::endl;
        std::cout << *vct2.insert(vct2.begin() + 5, 84) << std::endl;

        get_capacities(vct2);
    }
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    {
        std::cout << "---------------------- hard test 6 ---------------------" << std::endl;

        size_t start_size = 7;
        ft::vector<VALUE_TYPE> vct(start_size, 20);
        ft::vector<VALUE_TYPE> vct2;
        ft::vector<VALUE_TYPE>::iterator it = vct.begin();

        for (size_t i = 2; i < start_size; ++i)
            it[i] = (start_size - i) * 3;

        get_capacities(vct);
        get_access(vct);
        get_content(vct);

        vct.resize(10, 42);
        get_capacities(vct);
        get_access(vct);
        get_content(vct);

        vct.resize(18, 43);
        get_capacities(vct);
        get_access(vct);
        get_content(vct);

        vct.resize(10);
        get_capacities(vct);
        get_access(vct);
        get_content(vct);

        vct.resize(23, 44);
        get_capacities(vct);
        get_access(vct);
        get_content(vct);

        vct.resize(5);
        get_capacities(vct);
        get_access(vct);
        get_content(vct);

        vct.reserve(5);
        vct.reserve(3);
        get_capacities(vct);
        get_access(vct);
        get_content(vct);

        vct.resize(87);
        vct.resize(5);
        get_capacities(vct);
        get_access(vct);
        get_content(vct);

        get_capacities(vct2);

        vct2 = vct;
        get_capacities(vct2);

        vct.reserve(vct.capacity() + 1);
        get_capacities(vct);
        get_access(vct);
        get_content(vct);
        get_capacities(vct2);
        get_access(vct2);
        get_content(vct2);

        vct2.resize(0);
        get_capacities(vct2);
    }
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    {
        std::cout << "---------------------- hard test 7 ---------------------" << std::endl;

        std::list<VALUE_TYPE> lst;
        std::list<VALUE_TYPE>::iterator lst_it;
        for (int i = 1; i < 5; ++i)
            lst.push_back(i * 3);

        ft::vector<VALUE_TYPE> vct(lst.begin(), lst.end());
        get_capacities(vct);

        lst_it = lst.begin();
        for (int i = 1; lst_it != lst.end(); ++i)
            *lst_it++ = i * 5;
        vct.assign(lst.begin(), lst.end());
        get_capacities(vct);

        vct.insert(vct.end(), lst.rbegin(), lst.rend());
        get_capacities(vct);
    }
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    {
        std::cout << "-------------------- vector<string> --------------------" << std::endl;

        ft::vector<std::string> vct(8);
        ft::vector<std::string> vct2;
        ft::vector<std::string>::iterator it = vct.begin();

        for (unsigned long int i = 0; i < vct.size(); ++i)
                it[i] = std::string((vct.size() - i), i + 65);

        get_capacities(vct);
        get_access(vct);
        get_content(vct);

        std::cout << "push_back():\n" << std::endl;

        vct.push_back("One long string");
        vct2.push_back("Another long string");

        get_capacities(vct);
        get_content(vct);
        get_capacities(vct2);
        get_content(vct2);

        vct.pop_back();
        vct2.pop_back();

        get_capacities(vct);
        get_capacities(vct2);
    }
    return 0;
}
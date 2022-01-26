/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 13:03:09 by hwinston          #+#    #+#             */
/*   Updated: 2021/07/28 12:35:33 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <deque>
// #include <chrono>

#ifdef STD
    #include <vector>
    #include <stack>
    namespace ft = std;
#else
    #include "stack.hpp"
#endif

#define VALUE_TYPE int

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

static void intro()
{
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "-------------------------- stack -----------------------" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << std::endl;
}

template <class T>
static void get_info(ft::stack<T>& stack)
{
    std::cout << std::endl;
    std::cout << "--- info:" << std::endl;
    std::cout << std::endl;
    std::cout << std::setw(21) << std::left;
    std::cout << "empty: " << stack.empty() << std::endl;
    std::cout << std::setw(21) << std::left;
    std::cout << "size: " << stack.size() << std::endl;
    std::cout << std::setw(21) << std::left;
    std::cout << "top: " << stack.top() << std::endl;
}

template <class T, class CONTAINER>
static void get_info(ft::stack<T, CONTAINER>& stack)
{
    std::cout << std::endl;
    std::cout << "--- info:" << std::endl;
    std::cout << std::endl;
    std::cout << std::setw(21) << std::left;
    std::cout << "empty: " << stack.empty() << std::endl;
    std::cout << std::setw(21) << std::left;
    std::cout << "size: " << stack.size() << std::endl;
    std::cout << std::setw(21) << std::left;
    std::cout << "top: " << stack.top() << std::endl;
}

template <class T>
static void get_content(ft::stack<T> stack)
{
    std::cout << std::endl;
    std::cout << "--- content:" << std::endl;
    std::cout << std::endl;
    for (; !stack.empty(); stack.pop())
        std::cout << stack.top() << std::endl;
}

template <class T, class CONTAINER>
static void get_content(ft::stack<T, CONTAINER> stack)
{
    std::cout << std::endl;
    std::cout << "--- content:" << std::endl;
    std::cout << std::endl;
    for (; !stack.empty(); stack.pop())
        std::cout << stack.top() << std::endl;
}

template <class T>
static void compare(ft::stack<T>& left, ft::stack<T>& right)
{
    if (left == right)
        std::cout << "left = right" << std::endl;
	if (left != right)
        std::cout << "left != right" << std::endl; 
	if (left < right)
        std::cout << "left < right" << std::endl; 
	if (left > right)
        std::cout << "left > right" << std::endl; 
	if (left <= right)
        std::cout << "left <= right" << std::endl; 
	if (left >= right)
        std::cout << "left >= right" << std::endl; 
}

template <class T, class CONTAINER>
static void compare(ft::stack<T, CONTAINER>& left, ft::stack<T, CONTAINER>& right)
{
    if (left == right)
        std::cout << "left = right" << std::endl;
	if (left != right)
        std::cout << "left != right" << std::endl; 
	if (left < right)
        std::cout << "left < right" << std::endl; 
	if (left > right)
        std::cout << "left > right" << std::endl; 
	if (left <= right)
        std::cout << "left <= right" << std::endl; 
	if (left >= right)
        std::cout << "left >= right" << std::endl; 
}

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

int test_stack()
{
    intro();
    // auto start = std::chrono::high_resolution_clock::now();

    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "-------------------- push / pop (1) --------------------" << std::endl;
    std::cout << std::endl;
    
    {
        ft::stack<VALUE_TYPE> stack;
        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);
        get_info(stack);
        get_content(stack);
        stack.pop();
        stack.pop();
        get_info(stack);
        get_content(stack);
    }
   
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "-------------------- push / pop (2) --------------------" << std::endl;
    std::cout << std::endl;
    
    {
        ft::stack<VALUE_TYPE> stack;
        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);
        get_info(stack);
        get_content(stack);
        stack.pop();
        stack.pop();
        get_info(stack);
        get_content(stack);
        stack.pop();
        stack.pop();
        std::cout << std::endl;
        std::cout << "empty : " << stack.empty() << std::endl;
        get_content(stack);
    }
   
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "----------- specified container construction -----------" << std::endl;
    std::cout << std::endl;
   
    {
        ft::vector<VALUE_TYPE> vector(12, 42);
        ft::stack<VALUE_TYPE, ft::vector<VALUE_TYPE> > stack(vector);
        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);
        get_info(stack);
        get_content(stack);
        stack.pop();
        stack.pop();
        get_info(stack);
        get_content(stack);
        std::cout << std::endl;
        std::cout << "vector content: ";
        for (ft::vector<VALUE_TYPE>::iterator it = vector.begin(); it != vector.end(); it++)
            std::cout << " " << *it;
        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "------------------------- copy -------------------------" << std::endl;
    std::cout << std::endl;

    {
        ft::stack<VALUE_TYPE> stack_1;
        ft::stack<VALUE_TYPE> stack_2;
        stack_1.push(1);
        stack_1.push(2);
        stack_1.push(3);
        stack_1.push(4);
        stack_2 = stack_1;
        std::cout << "--- stack_1:" << std::endl;
        get_info(stack_1);
        get_content(stack_1);
        std::cout << "--- stack_2:" << std::endl;
        get_info(stack_2);
        get_content(stack_2);
    }

    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "---------------------- empty copy ----------------------" << std::endl;
    std::cout << std::endl;
    
    {
        ft::stack<VALUE_TYPE> stack_1;
        ft::stack<VALUE_TYPE> stack_2;
        stack_2 = stack_1;
        std::cout << "--- stack_1:" << std::endl;
        std::cout << "empty : " << stack_1.empty() << std::endl;
        get_content(stack_1);
        std::cout << "--- stack_2:" << std::endl;
        std::cout << "empty : " << stack_2.empty() << std::endl;
        get_content(stack_2);
    }
    
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "---------------------- comparison ----------------------" << std::endl;
    std::cout << std::endl;
    
    {
        ft::stack<VALUE_TYPE> stack_1;
        ft::stack<VALUE_TYPE> stack_2;
        ft::stack<VALUE_TYPE> stack_3;
        stack_1.push(1);
        stack_1.push(2);
        stack_1.push(3);
        stack_2.push(1);
        stack_2.push(2);
        stack_2.push(3);
        stack_3.push(2);
        stack_3.push(3);
        stack_3.push(1);
        compare(stack_1, stack_2);
        compare(stack_1, stack_3);
    }
    
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "------------- value_type = std::string (1) -------------" << std::endl;
    std::cout << std::endl;
    
    {
        ft::stack<std::string> stack;
        stack.push("ok");
        stack.push("yes");
        get_info(stack);
        for (; !stack.empty(); stack.pop())
            std::cout << stack.top() << std::endl;
        stack.push("lalala");
        stack.push("..");
        get_info(stack);
        for (; !stack.empty(); stack.pop())
            std::cout << stack.top() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "------------- value_type = std::string (2) -------------" << std::endl;
    std::cout << std::endl;
    
    {
        ft::stack<std::string> stack;
        stack.push("ok azertyuiopqsdfghjklmwxcvbn,;azrtyu");
        stack.push("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
        get_info(stack);
        for (; !stack.empty(); stack.pop())
            std::cout << stack.top() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "------------- using std::deque as container ------------" << std::endl;
    std::cout << std::endl;
    
    {
        ft::stack<int, std::deque<int> > stack;
        stack.push(3);
        stack.push(7);
        stack.push(5);
        get_info(stack);
        get_content(stack);   
        stack.pop();
        get_info(stack);
        get_content(stack); 
    }

    // auto stop = std::chrono::high_resolution_clock::now();
    // auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    // std::cout << "Time taken by function: "
    //      << duration.count() << " microseconds" << std::endl;
         
    return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 13:03:09 by hwinston          #+#    #+#             */
/*   Updated: 2021/07/25 00:07:46 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

#ifdef STD
    #include <vector>
    #include <stack>
    namespace ft = std;
#else
    #include "../inc/stack.hpp"
#endif

#define VALUE_TYPE int

void intro()
{
    std::cout << "--------------------------------------------------------" << std::endl;
    #ifdef STD
        std::cout << "------------------------ std::stack --------------------" << std::endl;
    #else
        std::cout << "------------------------ ft::stack ---------------------" << std::endl;
    #endif
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << std::endl;
}

template <class T>
void get_info(ft::stack<T>& stack)
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
void get_info(ft::stack<T, CONTAINER>& stack)
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
void get_content(ft::stack<T> stack)
{
    std::cout << std::endl;
    std::cout << "--- content:" << std::endl;
    std::cout << std::endl;
    for (; !stack.empty(); stack.pop())
        std::cout << stack.top() << std::endl;
}
template <class T, class CONTAINER>
void get_content(ft::stack<T, CONTAINER> stack)
{
    std::cout << std::endl;
    std::cout << "--- content:" << std::endl;
    std::cout << std::endl;
    for (; !stack.empty(); stack.pop())
        std::cout << stack.top() << std::endl;
}

template <class T>
void compare(ft::stack<T> left, ft::stack<T> right)
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
void get_content(ft::stack<T, CONTAINER> left, ft::stack<T, CONTAINER> right)
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

/* ----------------------------------------------------------------------------------- */
/* ----------------------------------------------------------------------------------- */

int main()
{
    //intro();  
    std::cout << "--------------------------------------------------------" << std::endl;
    {
        std::cout << "------------------------ test 1 ------------------------" << std::endl;

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
    {
        std::cout << "------------------------ test 2 ------------------------" << std::endl;

        ft::vector<VALUE_TYPE> vector(21, 42);
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
    }
    std::cout << "--------------------------------------------------------" << std::endl;
    {
        std::cout << "------------------------ test 3 ------------------------" << std::endl;

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
    std::cout << "--------------------------------------------------------" << std::endl;
    {
        std::cout << "------------------------ test 4 ------------------------" << std::endl;

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
    std::cout << "--------------------------------------------------------" << std::endl;
    {
        std::cout << "------------------------ test 5 ------------------------" << std::endl;

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
    std::cout << "--------------------------------------------------------" << std::endl;
    {
        std::cout << "------------------------ test 6 ------------------------" << std::endl;

        ft::stack<std::string> stack;

        stack.push("ok");
        stack.push("yes");

        get_info(stack);
        get_content(stack);        
    }

    return 0;
}
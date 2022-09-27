/*
 * stack.hpp
 *
 *  Created on: Sep 21, 2022
 *      Author: chiemekakalu
 */

#ifndef STACK_HPP_
#define STACK_HPP_

#include <iostream>
#include <list>
using namespace std;

struct Stack
{
    list<int *> stack;
    int * currentarray;
    int topElement;
    int * arraymaker;
    int size;

    void push(int i);
    bool top(int &i);
    bool pop();
    void destroy();
    Stack(int size);

};

#endif /* STACK_HPP_ */

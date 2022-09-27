/*
 * stack.cpp
 *
 *  Created on: Sep 21, 2022
 *      Author: chiemekakalu
 */

#include "stack.hpp"

Stack::Stack(int arraysize)
{
    arraymaker = new int[arraysize];
    topElement = 0;
    stack.push_front(arraymaker);
    size = arraysize;
    currentarray = nullptr;
}


void Stack::push(int i)
{
    if(stack.empty())
    {
        arraymaker = new int[size];
        stack.push_front(arraymaker);
        topElement = 0;
        currentarray = stack.front();
    }
    if(topElement == size)
    {
            arraymaker = new int[size];
            stack.push_front(arraymaker);
            topElement = 0;  // Fake constructor
            currentarray = stack.front();
            currentarray[topElement] = i;
            topElement++;
    }
    else
    {
        currentarray = stack.front();
        currentarray[topElement] = i;
        topElement++;
    }
    
}

bool Stack::top(int &i)
{
    if(stack.empty() || topElement == 0)
    {
        return false;
    }
    else
    {
        currentarray = stack.front();
        i = currentarray[topElement - 1];
        return true;
    }
}

void Stack::destroy()
{
    while(!stack.empty())
    {
        delete [] stack.front();
        stack.pop_front();
    }
}

bool Stack::pop()
{
    if(stack.empty() || topElement == 0)
    {
        return false;
    }
    else
    {
        topElement--;
        if(topElement == 0)
        {
            delete [] stack.front();
            stack.pop_front();
            if(!stack.empty())
            {
                currentarray = stack.front();
                topElement = size;
            }
        }
        return true;
    }
}





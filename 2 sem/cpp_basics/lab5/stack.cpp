#include "stack.h"

#include <exception>
#include <iostream>

using namespace std;


class stackFullException : public exception
{
public:
    const char* what() const throw ()
    {
        return "Stack is full";
    }
};

class stackEmptyException : public exception
{
public:
    const char* what() const throw ()
    {
        return "Stack is empty";
    }
};

template < typename T, int N >
Stack<T, N>::Stack()
{
    top = -1;
}

template < typename T, int N >
Stack<T, N>::~Stack () {};

template < typename T, int N >
bool Stack<T, N>::isEmpty()
{
    return top == -1;
}

template < typename T, int N >
bool Stack<T, N>::isFull()
{
    return top == 99;
}

template < typename T, int N >
void Stack<T, N>::push(int x)
{
    if (isFull())
    {
        throw stackFullException();
    }

    top++;
    stack[top] = x;
}

template < typename T, int N >
T Stack<T, N>::pop()
{
    if (isEmpty())
    {
        throw stackEmptyException();
    }

    int temp = stack[top];
    top--;
    return temp;
}
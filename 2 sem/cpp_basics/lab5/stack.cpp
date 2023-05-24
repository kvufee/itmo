#include "stack.h"

#include <iostream>

using namespace std;

template <typename T, int N>
Stack<T, N>::Stack()
{
    T head = -1;
    T stack[100];
}

template <typename T, int N>
bool Stack<T, N>::isEmpty()
{
    return head == -1;
}

template <typename T, int N>
bool Stack<T, N>::isFull()
{
    return head == 99;
}

template <typename T, int N>
void Stack<T, N>::add(T x)
{
    if (isFull())
    {
        cout << "Stack is full";
        return;
    }

    ++head;
    stack[head] = x;
}

template <typename T, int N>
T Stack<T, N>::del()
{
    if (isEmpty())
    {
        cout << "Stack is empty";
        return -1;
    }

    int temp = stack[head];

    --head;

    return temp;
}

template <typename T, int N>
T Stack<T, N>::checkHead()
{
    return stack[head];
}

template <typename T, int N>
Stack<T, N>& Stack<T, N>::operator<<(T x)
{
    add(x);
    return *this;
}

template <typename T, int N>
Stack<T, N>& Stack<T, N>::operator>>(T &x)
{
    x = del();
    return *this;
}

template <typename T, int N>
void Stack<T, N>::print(Stack<T, N> s)
{
    if (s.isEmpty())
    {
        cout << "Stack is empty!";
        return;
    }

    while (!s.isEmpty())
    {
        cout << s.del() << " ";
    }

    cout << '\n';
}

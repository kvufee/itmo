#include "stack.h"

#include <iostream>

using namespace std;


Stack::Stack()
{
    int head = -1;
    int stack[100];
}

bool Stack::isEmpty()
{
    return head == -1;
}

bool Stack::isFull()
{
    return head == 99;
}

void Stack::add(int x)
{
    if (isFull())
    {
        cout << "Stack is full";
        return;
    }

    ++head;
    stack[head] = x;
}

int Stack::del()
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

int Stack::checkHead()
{
    return stack[head];
}

Stack& Stack::operator<<(int x)
{
    add(x);
    return *this;
}

Stack& Stack::operator>>(int &x)
{
    x = del();
    return *this;
}

void Stack::print(Stack s)
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

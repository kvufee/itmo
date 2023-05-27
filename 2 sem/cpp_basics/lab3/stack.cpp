#include "stack.h"

#include <iostream>

using namespace std;


Stack::Stack()
{
    top = -1;
}

Stack::~Stack () {};

bool Stack::isEmpty()
{
    return top == -1;
}

bool Stack::isFull()
{
    return top == 99;
}

void Stack::push(int x)
{
    if (isFull())
    {
        cout << "Stack is full";
        return;
    }

    top++;
    stack[top] = x;
}

int Stack::pop()
{
    if (isEmpty())
    {
        cout << "Stack is empty";
        return -1;
    }

    int temp = stack[top];
    top--;
    return temp;
}

int Stack::peek()
{
    return stack[top];
}

Stack& Stack::operator<<(int x)
{
    push(x);
    return *this;
}

Stack& Stack::operator>>(int &x)
{
    x = pop();
    return *this;
}

void Stack::show_stack(Stack s) {
    if (s.isEmpty()) {
        cout << "Stack is empty!";
        return;
    }

    while (!s.isEmpty()) {
        cout << s.pop() << " ";
    }
    cout << '\n';
}
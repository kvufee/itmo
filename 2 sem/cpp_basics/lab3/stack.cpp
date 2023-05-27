#include "stack.h"

#include <iostream>

using namespace std;


Stack::Stack()
{
    top = -1;
}

Stack::~Stack () {};

bool Stack::is_empty()
{
    return top == -1;
}

bool Stack::is_full()
{
    return top == 99;
}

void Stack::push(int x)
{
    if (is_full())
    {
        std::cout << "Stack is full";
        return;
    }

    top++;
    stack[top] = x;
}

int Stack::pop()
{
    if (is_empty())
    {
        std::cout << "Stack is empty";
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
    if (s.is_empty()) {
        std::cout << "Stack is empty!";
        return;
    }

    while (!s.is_empty()) {
        std::cout << s.pop() << " ";
    }
    std::cout << '\n';
}
#pragma once

#include <iostream>

using namespace std;


class Stack
        {
private:
    int stack[100];
    int head;

public:
    Stack() {
        head = -1;
    }

    ~Stack () {};

    bool is_empty()
    {
        return head == -1;
    }

    bool is_full()
    {
        return head == 99;
    }

    void push(int x)
    {
        if (is_full())
        {
            cout << "Stack is full";
            return;
        }

        ++head;
        stack[head] = x;
    }

    int pop()
    {
        if (is_empty())
        {
            cout << "Stack is empty";
            return -1;
        }

        int temp = stack[head];

        --head;

        return temp;
    }

    int look_at_top()
    {
        return stack[head];
    }

    Stack& operator<<(int x)
    {
        push(x);
        return *this;
    }

    Stack& operator>>(int &x)
    {
        x = pop();
        return *this;
    }

    void show_stack(Stack stack)
    {
        if (stack.is_empty())
        {
            cout << "Stack is empty!";
            return;
        }

        while (!stack.is_empty())
        {
            cout << stack.pop() << " ";
        }
        cout << '\n';
    }
};
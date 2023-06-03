#include "stack.h"
#include <vector>
#include <iostream>
#include <exception>

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


template<int N,typename T>
Stack<N,T>::Stack() : head(nullptr),next(nullptr) {};

template<int N,typename T>
Stack<N,T>::~Stack()
{
    while(head != nullptr)
    {
        auto * temp = head;
        head = head->next;
        delete temp;
    }
}

template<int N,typename T>
void Stack<N, T>::push(T value)
{
    if(size() >= N)
    {
        throw stackFullException();
    }
    auto* node = new Stack;
    node->data = value;
    node->next = head;
    head = node;
}


template<int N,typename T>
void Stack<N, T>::pop()
{
    if(head == nullptr)
    {
        throw stackEmptyException();
    }
    auto* temp = head;
    head = head->next;
    delete temp;
}


template<int N,typename T>
void Stack<N, T>::print()
{
    auto* temp = head;
    vector<T> result;
    while (temp != nullptr)
    {
        result.push_back(temp->data);
        temp = temp->next;
    }
    for(auto& x : result)
    {
        cout << x << " " << "\n";
    }
}


template<int N,typename T>
int Stack<N, T>::size()
{
    auto* temp = head;
    int count = 0;
    while(temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
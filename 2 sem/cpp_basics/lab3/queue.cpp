#include "queue.h"
#include <iostream>

using namespace std;


qq::qq()
{
    head = nullptr;
    tail = nullptr;
    next = nullptr;
    data = 0;
}

qq::~qq()
{
    qq* temp = head;
    while(temp != nullptr)
    {   next = temp->next;
        delete temp;
        temp = next;
    }
}

void qq::push(int value)
{
    auto* node = new qq;
    node->data = value;
    node->next = nullptr;
    if(head == nullptr)
    {
        head = tail = node;
    }
    else
    {
        tail->next = node;
        tail = node;
    }
}

void qq::del() {
    if(head == nullptr)
    {
        return;
    }
    qq* temp = head;
    head = head->next;
    delete temp;
}

qq& qq::operator<<(int value)
{
    qq::push(value);
    return *this;
}

qq& qq::operator>>(int& value)
{
    if (head != nullptr) {
        value = head->data;
        del();
    }
    return *this;
}
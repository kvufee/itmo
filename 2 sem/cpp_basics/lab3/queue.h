#pragma once


class qq
{
public:
    qq();
    ~qq();
    void push(int value);
    void del();
    qq& operator<<(int value);
    qq& operator>>(int& value);
private:
    int data;
    qq* head;
    qq* tail;
    qq* next;
};
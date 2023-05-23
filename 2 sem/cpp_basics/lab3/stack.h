class Stack
{
    int stack[100];
    int head;
public:
    Stack();
    bool isEmpty();
    bool isFull();
    void add(int x);
    int del();
    int checkHead();
    Stack& operator<<(int x);
    Stack& operator>>(int &x);
    void print(Stack s);
};
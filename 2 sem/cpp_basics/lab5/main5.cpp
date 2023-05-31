#include <bits/stdc++.h>

using namespace std;


class stackException
{
public:
    stackException(string message) : message{move(message)} {}

    string getMassage() const
    {
        return message;
    }
private:
    string message;
};


class Stack
{
    int head;
    int MAX;
    int *a;
public:
    Stack(int size)
    {
        MAX = size;
        a = new int[MAX];
        head = -1;
    }
    void push(int x);
    int pop();
    int peek();
    bool isEmpty() const;
};

void Stack::push(int x)
{
    if (head >= (MAX - 1)) {
        throw stackException{"Stack is full"};
    }
    a[++head] = x;
    cout << x;
}

int Stack::pop()
{
    if (head < 0)
    {
        throw stackException{"Stack is empty"};
    }
    int x = a[head--];
    return x;
}

int Stack::peek()
{
    if (head < 0)
    {
        cout << "Stack is Empty";
        return 0;
    } else
    {
        int x = a[head];
        return x;
    }
}

bool Stack::isEmpty() const
{
    return (head < 0);
}


template <typename T>
T findMin(T a, T b)
{
    if (a < b)
    {
        return a;
    } else return b;
}


int main()
{
    int a, b;
    cin >> a >> b;
    findMin(a, b);
ё
    try {
        class Stack s(3);
        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);
        s.pop();
        s.pop();
        s.pop();

        //print top element of stack after popping
        cout << "Head: " << s.peek() << "\n";

        while (!s.isEmpty()) {
            cout << s.peek() << " ";
            s.pop();
        }

    }
    catch (const stackException ex){
        cout << ex.getMassage() << "\n";
    }

    return 0;
}
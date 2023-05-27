class Stack
{
private:
    int stack[100];
    int top;

public:
    Stack();

    ~Stack ();

    bool isEmpty();
    bool isFull();
    void push(int x);
    int pop();
    int peek();

    Stack& operator<<(int x);
    Stack& operator>>(int &x);

    void show_stack(Stack s);
};

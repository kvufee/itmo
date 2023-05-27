class Stack
{
private:
    int stack[100];
    int top;

public:
    Stack();

    ~Stack ();

    bool is_empty();
    bool is_full();
    void push(int x);
    int pop();
    int peek();

    Stack& operator<<(int x);
    Stack& operator>>(int &x);

    void show_stack(Stack s);
};

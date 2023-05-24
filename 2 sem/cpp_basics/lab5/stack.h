template <typename T, int N>
class Stack
{
    T stack[100];
    T head;
public:
    Stack();
    bool isEmpty();
    bool isFull();
    void add(int x);
    T del();
    T checkHead();
    Stack& operator<<(T x);
    Stack& operator>>(T &x);
    void print(Stack s);
};
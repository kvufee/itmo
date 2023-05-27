template < typename T, int N >
class Stack
{
private:
    T stack[100];
    T top;

public:
    Stack();
    ~Stack ();

    bool isEmpty();
    bool isFull();
    void push(int x);
    T pop();
};

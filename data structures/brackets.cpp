#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data = 0;
    Node* prev = nullptr;
};

struct Stack {

    Node* head = new Node;
    Node* tail = head;

    void push(char data)
    {
        Node* tmp = new Node;
        tmp->prev = tail;
        tail = tmp;
        tmp->data = data;
    }
  
    char pop()
    {
        if (head == tail)
            return '1';

        Node* tmp = tail;
        char ans = tmp->data;
        tail = tail->prev;

        delete tmp;
        return ans;
    }
};
int main()
{
    string s;

    while ((cin >> s) && !(s[0] == EOF && s.size() == 1))
    {
        bool correct = true;
        Stack stk;

        for (auto str: s)
        {
            if (str == '(' || str == '[' || str == '{')
                stk.push(str);
            else if (str == ')' && stk.pop() == '(')
                continue;
            else if (str == ']' && stk.pop() == '[')
                continue;
            else
            {
            correct = false;
            break;
            }
        }
        if (correct &= (stk.head == stk.tail))
            cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    return 0;
}
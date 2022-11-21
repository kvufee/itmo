#include <iostream>
using namespace std;

struct Node
{
    long long data = 0;
    Node* next = nullptr;
};

struct List
{
    Node* head = new Node;
    Node* tail = new Node;
    List()
    {
        head = tail;
    }
};

void push(List* list, long long data)
{
    Node* tmp = new Node;
    tmp->data = data;
    list->tail->next = tmp;
    list->tail = tmp;
}

void pop(List* list)
{
    Node* tmp = list->head;
    list->head = list->head->next;

    cout << list->head->data << "\n";

    tmp->next = nullptr;
    delete tmp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    List list;
    long long n;
    cin >> n;
  
    while (n--)
    {
        char str;
        cin >> str;

        if (str == '+') {
            long long tmp;
            cin >> tmp;
            push(&list, tmp);
        }
        else
            pop(&list);
    }
    return 0;
}
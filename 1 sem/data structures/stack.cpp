#include <iostream>
using namespace std;

struct Node
{
    long long data = 0;
    Node* next;
};

struct List
{
    Node* head = new Node;
    List() {
        head->data = 0;
        head->next = 0;
    }
};

void push(List* list, long long data)
{
    Node* tmp = new Node;
    tmp->data = data;
    tmp->next = list->head->next;
    list->head->next = tmp;
}

void pop(List* list)
{
    Node* tmp = list->head;
    list->head = list->head->next;
    tmp->next = nullptr;

    cout << list->head->data << "\n";

    delete tmp;
}

int main()
{
    List list;
    long long n;
    
    cin >> n;

    while(n--)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        char str;
        cin >> str;
        if (str == '+')
        {
            long long tmp;
            cin >> tmp;
            push(&list, tmp);
            
        } 
        else
            pop(&list);
    }
    return 0;
}
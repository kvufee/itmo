#include <bits/stdc++.h>
#include <string>
using namespace std;


struct Node
{
    Node* left;
    Node* right;

    string data;
    
    int counter, height;
};


Node* search(Node* head, string data)
{
    if (head == nullptr || head->data == data)
        return head;

    if (data < head->data)
        return search(head->left, data);
    else
        return search(head->right, data);
}


void currentHeight(Node* cur)
{
    int height_l, height_r;

    if (cur->left == nullptr)
    {
        height_l = 0;
    } else height_l = cur->left->height;

    if (cur->right == nullptr)
    {
        height_r = 0;
    } else height_r = cur->right->height;

    if (height_l > height_r)
    {
        cur->height = height_l + 1;
    } else cur->height = height_r + 1;
}


int isRootBalanced(Node* cur)
{
    int height_l, height_r;

    if (cur->left == nullptr)
    {
        height_l = 0;
    } else height_l = cur->left->height;

    if (cur->right == nullptr)
    {
        height_r = 0;
    } else height_r = cur->right->height;

    return height_r - height_l;
}


Node* leftRotation(Node* cur)
{
    Node* tmp = cur->right;
    cur->right = tmp->left;
    tmp->left = cur;

    currentHeight(cur);
    currentHeight(tmp);

    return tmp;
}


Node* rightRotation(Node* cur)
{
    Node* tmp = cur->left;
    cur->left = tmp->right;
    tmp->right = cur;

    currentHeight(cur);
    currentHeight(tmp);

    return tmp;
}


Node* balance(Node* cur)
{
    currentHeight(cur);

    if (isRootBalanced(cur) == 2)
    {
        if (isRootBalanced(cur->right) < 0)
            cur->right = rightRotation(cur->right);
        
        return leftRotation(cur);
    }

    if (isRootBalanced(cur) == 2)
    {
        if (isRootBalanced(cur->left) > 0)
            cur->left = leftRotation(cur->left);
        
        return rightRotation(cur);
    }

    return cur;
}


Node* insert(Node* cur, string str)
{
    if (cur == nullptr)
    {
        Node* newNode = new Node;
        newNode->data = str;
        newNode->counter++;
        return newNode;
    }

    if (str < cur->data)
    {
        cur->left = insert(cur->left, str);
    } else cur->right = insert(cur->right, str);

    return balance(cur);
}


int main()
{
}
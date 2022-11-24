#include <bits/stdc++.h>
using namespace std;

class BST {
    struct Node
    {
        int key;
        Node *left = nullptr, *right = nullptr;
        Node(int key): key(key) {}
    } *root = nullptr;


    bool contains(Node *current, int key) const
    {
        if (current == nullptr)
            return false;

        if (key == current->key)
            return true;

        if (key < current->key)
            return contains(current->left, key);
        else 
            return contains(current->right, key);
    }


    void insert(Node *current, int key)
    {
        if (root == nullptr)
        {
            root = new Node(key);
            return;
        }

        if (key == current->key)
            return;
        
        if (key < current->key)
        {
            if (current->left)
                insert(current->left, key);
            else
                current->left = new Node(key);
        } else {
            if (current->right)
                insert(current->right, key);
            else
                current->right = new Node(key);
        }
    }

    void print(Node *current) const {
        if (current == nullptr)
            return;
        print(current->left);
        cout << current->key << "\n";
        print(current->right);
    }


public:
    bool contains(int key) const
    {
        return contains(root, key);
    }

    void insert(int key)
    {
        return insert(root, key);
    }


    void print() const 
    {
        print(root);
    }
};


int main()
{
    BST bst;
    
    int n, i, j;
    int arr[n][3];

    cin >> n;

    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < 3; ++j)
        {
            cin >> arr[i][j];
            bst.insert(arr[i][0]);
        }
    }

    bst.print()
}
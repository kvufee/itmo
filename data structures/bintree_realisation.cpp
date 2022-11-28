#include <bits/stdc++.h>
using namespace std;

class BST {
    struct Node
    {
        int key;
        Node *left = nullptr, *right = nullptr;
        Node(int key): key(key) {}
    } *root = nullptr;


    bool exists(Node *current, int key) const
    {
        if (current == nullptr)
            return false;

        if (key == current->key)
            return true;

        if (key < current->key)
            return exists(current->left, key);
        else 
            return exists(current->right, key);
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


    void del(Node *current, int key)
    {
        if (root == nullptr) return;

        if 
    }


    void print(Node *current) const {
        if (current == nullptr)
            return;
        print(current->left);
        cout << current->key << "\n";
        print(current->right);
    }


public:
    bool exists(int key) const
    {
        return exists(root, key);
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
    
    string command;

    while (cin >> command)
    {
        if (command == "exists")
            {
                long long key;
                cin >> key;
                cout << (bst.exists(key) ? "true\n" : "false\n");
            } else {
                if (command == "insert")
                {
                    long long key;
                    cin >> key;
                    bst.insert(key);
                }
            }
    }

    return 0;
}
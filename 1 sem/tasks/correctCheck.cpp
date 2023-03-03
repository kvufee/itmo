#include <bits/stdc++.h>
using namespace std;
 

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
 

struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));

    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return (node);
}
 

char maxValue(struct Node* node)
{
    if (node == NULL) {
        return 0;
    }

    int key = node->data;
    int lmax = maxValue(node->left);
    int rmax = maxValue(node->right);
 
    return max(key, max(lmax, rmax));
}
 

char minValue(struct Node* node)
{
    if (node == NULL) {
        return 0;
    }
    int key = node->data;
    int leftMax = minValue(node->left);
    int rightMax = minValue(node->right);
 
    return min(key, min(leftMax, rightMax));
}


int correctivity(struct Node* node)
{
    if (node == NULL)
        return 1;
 
    if (node->left != NULL && maxValue(node->left) > node->data)
        return 0;
 
    if (node->right != NULL && minValue(node->right) < node->data)
        return 0;

    return 1;
}
 

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        long long key, left, right;
        cin >> key >> left >> right;

        struct Node* root = newNode(key);
        

    }

    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
 
    if (correctivity(root))
        printf("Is BST");
    else
        printf("Not a BST");
 
    return 0;
}
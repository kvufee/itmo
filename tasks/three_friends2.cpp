#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Node {

  Node* left;
  Node* right;

  string data;

  int counter;
  int hgt;

  Node() : left {nullptr},
           right {nullptr},
           data {""},
           counter {0},
           hgt {0}
           {}
};

Node* head = nullptr;

Node* search(Node* head, string data) {
    if (head == nullptr) return head;
    if (head->data == data) return head;
    if (head->data > data)
        return search(head->left, data);
    else
        return search(head->right, data);
}

int height(Node* cur) {
    if (cur == nullptr) return 0;
	return cur->hgt;
}

int getBalance(Node* cur)
{
    if (cur == nullptr) return 0;
    return height(cur->left) - height(cur->right);
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
	Node* subtree = y->left;
	y->left = x;
	x->right = subtree;
	x->hgt = max(height(x->left), height(x->right)) + 1;
	y->hgt = max(height(y->left), height(y->right)) + 1;
	return y;
}

Node* rightRotate(Node* y)
{
    Node* x = y->left;
	Node* subtree = x->right;
	x->right = y;
	y->left = subtree;
	y->hgt = max(height(y->left), height(y->right)) + 1;
	x->hgt = max(height(x->left), height(x->right)) + 1;
	return x;
}

Node* newNode(string data)
    {
	Node* node = new Node();
	node->data = data;
	node->left = nullptr;
	node->right = nullptr;
	node->hgt = 1;
	return (node);
}

Node* insert(Node* node, string str) {
    if (node == nullptr)
		return (newNode(str));

	if (str < node->data)
		node->left = insert(node->left, str);
	else if (str > node->data)
		node->right = insert(node->right, str);
	else
		return node;

	node->hgt = 1 + max(height(node->left), height(node->right));

	int balance = getBalance(node);

	if (balance > 1) 
    {
		if (str < node->left->data)
        {
			return rightRotate(node);
		}
		else if (str > node->left->data)
        {
			node->left = leftRotate(node->left);
			return rightRotate(node);
		}
	}

	if (balance < -1)
    {
		if (str > node->right->data)
        {
			return leftRotate(node);
		} 
        else if (str < node->right->data) {
			node->right = rightRotate(node->right);
			return leftRotate(node);
		}
	}

	return node;
}

int main()
{
    int n; cin >> n;
    vector <string> vectr(3 * n);

    for (int i = 0; i < 3 * n; i++)
    {
        string key;
        cin >> key;
        vectr[i] = key;

        Node* searching = search(head, key);

        if (searching == nullptr) 
            head = insert(head, key);
        else 
            searching->counter++;
    }

    for (int i = 0; i < 3; i++)
    {
        int result = 0;
        for (int j = 0; j < n; j++)
        {
            Node* key = search(head, vectr[i * n + j]);
            if (key->counter == 1) result += 3;
            if (key->counter == 2) result += 1;
        }
        cout << result << " ";
    }
    
    return 0;
}
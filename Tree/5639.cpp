#include<iostream>
#include<vector>
using namespace std;

struct Node
{
    int value;
    Node *left, *right;
};

Node *root = NULL;

Node *addNode(Node *node, int n)
{
    if(node==NULL)
    {
        node = new Node();
        node->value = n;
        node->left = NULL;
        node->right = NULL;
    }
    else if(n > node->value)
        node->right = addNode(node->right, n);
    else
        node->left = addNode(node->left, n);

    return node;
}

void post(Node *node)
{
    if(node == NULL)
        return;

    post(node->left);
    post(node->right);
    cout << node->value << endl;
}

int main()
{
    int n;
    
    while(cin >> n)
    {
        root = addNode(root, n);
    }
    post(root);
}
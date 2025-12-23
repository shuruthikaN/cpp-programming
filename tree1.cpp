#include <iostream>
#include <stack>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

// Insert into BST
Node* insert(Node* root, int val)
{
    if (!root)
        return new Node{val, nullptr, nullptr};

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Iterative Preorder
void preorder(Node* root)
{
    if (!root) return;
    stack<Node*> s;
    s.push(root);
    while (!s.empty())
    {
        Node* node = s.top(); s.pop();
        cout << node->data << " ";
        if (node->right) s.push(node->right);
        if (node->left) s.push(node->left);
    }
}

// Iterative Inorder
void inorder(Node* root)
{
    stack<Node*> s;
    Node* curr = root;
    while (curr || !s.empty())
    {
        while (curr)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top(); s.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}

// Iterative Postorder
void postorder(Node* root)
{
    if (!root) return;
    stack<Node*> s1, s2;
    s1.push(root);
    while (!s1.empty())
    {
        Node* node = s1.top(); s1.pop();
        s2.push(node);
        if (node->left) s1.push(node->left);
        if (node->right) s1.push(node->right);
    }
    while (!s2.empty())
    {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

// Free memory
void freeTree(Node* root)
{
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main()
{
    int arr[] = {9, 4, 15, 6, 12, 17, 2};
    Node* root = nullptr;

    for (int x : arr)
        root = insert(root, x);

    cout << "Preorder: "; preorder(root); cout << endl;
    cout << "Inorder: "; inorder(root); cout << endl;
    cout << "Postorder: "; postorder(root); cout << endl;

    freeTree(root); // Clean up memory
    return 0;
}


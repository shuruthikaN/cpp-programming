#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

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

void preorder(Node* root)
{
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root)
{
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root)
{
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    int arr[] = {9, 4, 15, 6, 12, 17, 2};
    Node *root = nullptr;

    for (int x : arr)
        root = insert(root, x);

    cout << "Preorder: "; preorder(root); cout << endl;
    cout << "Inorder: "; inorder(root); cout << endl;
    cout << "Postorder: "; postorder(root); cout << endl;
    return 0;
}


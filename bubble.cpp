#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void insert(Node* &head, int val)
{
    Node *n = new Node{val, nullptr};
    if (!head)
        head = n;
    else
    {
        Node *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = n;
    }
}

void bubbleSort(Node* head)
{
    bool swapped;
    do
    {
        swapped = false;
        Node *ptr = head;
        while (ptr->next)
        {
            if (ptr->data > ptr->next->data)
            {
                swap(ptr->data, ptr->next->data);
                swapped = true;
            }
            ptr = ptr->next;
        }
    } while (swapped);
}

void display(Node* head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    int arr[] = {50, 34, 67, 2, 81, 46};
    Node *head = nullptr;

    for (int x : arr)
        insert(head, x);

    bubbleSort(head);
    display(head);
    return 0;
}


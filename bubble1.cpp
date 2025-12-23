#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void insert(Node*& head, int val)
{
    Node* n = new Node{val, nullptr};

    if (!head)
    {
        head = n;
        return;
    }

    Node* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = n;
}

// Optimized Bubble Sort
void bubbleSortOptimized(Node* head)
{
    if (!head) return;

    bool swapped;
    Node* end = nullptr;

    do
    {
        swapped = false;
        Node* curr = head;

        while (curr->next != end)
        {
            if (curr->data > curr->next->data)
            {
                swap(curr->data, curr->next->data);
                swapped = true;
            }
            curr = curr->next;
        }

        end = curr;
    } while (swapped);
}

void display(Node* head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    int arr[] = {50, 34, 67, 2, 81, 46};
    Node* head = nullptr;

    for (int x : arr)
        insert(head, x);

    bubbleSortOptimized(head);
    display(head);

    return 0;
}


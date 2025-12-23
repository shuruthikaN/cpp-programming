#include <iostream>
using namespace std;

/* =========================
   Linked List Node
   ========================= */
struct Node
{
    int data;
    Node* next;
};

/* =========================
   Insert at End
   ========================= */
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

/* =========================
   Merge Two Sorted Lists
   ========================= */
Node* merge(Node* a, Node* b)
{
    if (!a) return b;
    if (!b) return a;

    if (a->data < b->data)
    {
        a->next = merge(a->next, b);
        return a;
    }
    else
    {
        b->next = merge(a, b->next);
        return b;
    }
}

/* =========================
   Split List into Two Halves
   ========================= */
Node* split(Node* head)
{
    Node* slow = head;
    Node* fast = head->next;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* mid = slow->next;
    slow->next = nullptr;

    return mid;
}

/* =========================
   Merge Sort on Linked List
   ========================= */
Node* mergeSort(Node* head)
{
    if (!head || !head->next)
        return head;

    Node* mid = split(head);

    Node* left = mergeSort(head);
    Node* right = mergeSort(mid);

    return merge(left, right);
}

/* =========================
   Display List
   ========================= */
void display(Node* head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

/* =========================
   Free Memory
   ========================= */
void freeList(Node* head)
{
    while (head)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

/* =========================
   Main
   ========================= */
int main()
{
    int arr[] = {50, 34, 67, 2, 81, 46};
    Node* head = nullptr;

    for (int x : arr)
        insert(head, x);

    cout << "Before sorting: ";
    display(head);

    head = mergeSort(head);

    cout << "After sorting:  ";
    display(head);

    freeList(head);
    return 0;
}


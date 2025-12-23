#include <iostream>
using namespace std;

#define MAX 5

class Stack
{
    int top;
    int arr[MAX];

public:
    Stack() { top = -1; }

    void push(int x)
    {
        if (top == MAX - 1)
            cout << "Overflow\n";
        else
            arr[++top] = x;
    }

    void pop()
    {
        if (top == -1)
            cout << "Underflow\n";
        else
            cout << "Popped: " << arr[top--] << endl;
    }

    void display()
    {
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    s.pop();
    s.display();
    return 0;
}


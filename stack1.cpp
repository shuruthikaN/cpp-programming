#include <iostream>
using namespace std;

class Stack
{
    static const int MAX = 5;
    int arr[MAX];
    int top;

public:
    Stack() : top(-1) {}

    bool push(int x)
    {
        if (isFull())
            return false;

        arr[++top] = x;
        return true;
    }

    bool pop(int &poppedValue)
    {
        if (isEmpty())
            return false;

        poppedValue = arr[top--];
        return true;
    }

    bool isEmpty() const
    {
        return top == -1;
    }

    bool isFull() const
    {
        return top == MAX - 1;
    }

    void display() const
    {
        for (int i = top; i >= 0; --i)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main()
{
    Stack s;
    int value;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    if (s.pop(value))
        cout << "Popped: " << value << endl;

    s.display();

    return 0;
}


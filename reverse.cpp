#include <iostream>
using namespace std;

int main()
{
    char str[] = "Hello world";
    int len = 0;

    while (str[len] != '\0') len++;

    for (int i = len - 1; i >= 0; )
    {
        int start = i;
        while (start >= 0 && str[start] != ' ')
            start--;

        for (int j = start + 1; j <= i; j++)
            cout << str[j];
        cout << " ";

        i = start - 1;
    }
    return 0;
}


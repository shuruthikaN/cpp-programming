#include <iostream>
using namespace std;

int* sortArray(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);

    return arr;
}

int main()
{
    int arr[10] = {9, 5, 3, 1, 7, 2, 8, 6, 4, 0};
    int *sorted = sortArray(arr, 10);

    for (int i = 0; i < 10; i++)
        cout << sorted[i] << " ";

    return 0;
}


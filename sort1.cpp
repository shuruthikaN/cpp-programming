#include <iostream>
using namespace std;

void sortArray(int *arr, int size)
{
    if (!arr || size <= 1)
        return;

    for (int i = 0; i < size - 1; i++)
    {
        bool swapped = false;

        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }

        // If no swap occurred, array is already sorted
        if (!swapped)
            break;
    }
}

int main()
{
    int arr[10] = {9, 5, 3, 1, 7, 2, 8, 6, 4, 0};

    sortArray(arr, 10);

    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";

    return 0;
}


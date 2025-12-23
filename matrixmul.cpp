#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    int r1 = 2, c1 = 2, r2 = 2, c2 = 2;

    int A[2][2] = {{10, 15}, {20, 5}};
    int B[2][2] = {{6, 14}, {12, 20}};
    int C[2][2] = {0};

    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            for (int k = 0; k < c1; k++)
                C[i][j] += A[i][k] * B[k][j];

    cout << "Result Matrix:\n";
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            cout << C[i][j] << " ";

    return 0;
}

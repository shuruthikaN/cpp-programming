#include <iostream>
using namespace std;

int main()
{
    const int r1 = 2, c1 = 2, r2 = 2, c2 = 2;

    int A[r1][c1] = {{10, 15}, {20, 5}};
    int B[r2][c2] = {{6, 14}, {12, 20}};
    int C[r1][c2] = {0};

    // Cache-optimized multiplication
    for (int i = 0; i < r1; i++) {
        for (int k = 0; k < c1; k++) {
            int aik = A[i][k];               // loop invariant
            for (int j = 0; j < c2; j++) {
                C[i][j] += aik * B[k][j];
            }
        }
    }

    cout << "Result Matrix:\n";
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            cout << C[i][j] << " ";

    return 0;
}


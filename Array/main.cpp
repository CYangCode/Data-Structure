#include <iostream>

using namespace std;

int main()
{
    const int M = 10;
    const int N = 5;
    const int O = 4;
    const int P = 20;
    int array[M][N][O][P];
    int array2[M * N * O * P];
    int num = 0;
    for (int i = 0; i < M; ++i)
    for (int j = 0; j < N; ++j)
    for (int k = 0; k < O; ++k)
    for (int l = 0; l < P; ++l) {
        array[i][j][k][l] = num++;
        array2[i * N * O * P + j * O * P + k * P + l] = num - 1;
    }
    for (int * i = array2; *i < M * N * P; ++i) {
        cout << *i << " ";
    }
    return 0;
}

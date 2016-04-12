#include <iostream>

using namespace std;

int abs(int a)
{
    return a > 0? a: -a;
}

bool check(int * queens, int row, int pos)
{
    for (int i = 0; i < row; ++i)
    {
        if (pos == queens[i] || abs(pos - queens[i]) == abs(i - row))
            return false;
    }
    return true;
}

void print(int * queens, int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << queens[i] << " ";
    }
    cout << endl;
}

int Queens(int * queens,  int n, int row)
{
    int count = 0;
    for (int pos = 0; pos < n; ++pos)
    {
        if (check(queens, row, pos))
        {
            queens[row] = pos;
            if (row == n - 1) ++count;
            else count += Queens(queens, n, row + 1);
        }
    }
    return count;
}

int main()
{
    int n = 8;
    int * queens = new int[n];
    cout << Queens(queens, n, 0) << endl;
    return 0;
}

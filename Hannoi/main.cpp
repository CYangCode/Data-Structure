#include <iostream>

using namespace std;

void move(int n, char x, char y)
{
    cout << n << ": " << x << "->" << y << endl;
}
//��n����Ƭ��x��ͨ��y�ƶ���z��
void hanoi(int n, char x, char y, char z)
{
    if (n == 0) return;
    hanoi(n - 1, x, z, y);
    move(n, x, z);
    hanoi(n - 1, y, x, z);
}

int main()
{
    hanoi(6, 'x', 'y', 'z');
    return 0;
}

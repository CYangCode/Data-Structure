#include <iostream>

using namespace std;

void move(int n, char x, char y)
{
    cout << n << ": " << x << "->" << y << endl;
}
//将n个盘片从x上通过y移动到z上
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

#include <iostream>
using namespace std;

int f(int & a)
{
    cout << "��ֵ���ã�" << a << endl;
    return a;
}

int f(int && a)
{
    cout << "��ֵ���ã�" << ++a << endl;
    return a;
}

int main()
{
    int a = 1;
    f(a);
    cout << a;
    return 0;
}

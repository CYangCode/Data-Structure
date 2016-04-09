#include <iostream>
using namespace std;

int f(int & a)
{
    cout << "左值引用：" << a << endl;
    return a;
}

int f(int && a)
{
    cout << "右值引用：" << ++a << endl;
    return a;
}

int main()
{
    int a = 1;
    f(a);
    cout << a;
    return 0;
}

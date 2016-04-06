#include <iostream>
using namespace std;

class A
{
public:
    int a;
    A()
    {
        a = 20;
        cout << "a" << endl;
    }
};

class B
{
public:
    static A a;
};
A B::a;
int main()
{
}

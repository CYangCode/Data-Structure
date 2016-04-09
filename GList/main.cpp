#include <iostream>
using namespace std;

struct B
{
    int a;
    short aa;
    double b;
    float c;
};

struct A
{
    int a;
    double b;
    short c;
    B d;
    char e[2];
};

struct C
{
    short s;
    int a;
    short ss;
    double b;
    short c;
    int aa;
    double bb;
    float cc;
    char e[2];
};

int main()
{
    cout << sizeof(A) << " " << sizeof(C) << endl;
}

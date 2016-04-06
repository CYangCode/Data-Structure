#include <iostream>
#include "String.h"
using namespace std;

int test()
{
    return 1;
}
int main()
{
    String str("12345");
    const String & str2 = str.copy();
    (const_cast<String*>(&str2))->append("1234");
    cout << str;
    return 0;
}

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    //test
    String str("asdf");
    str += "ABN";
    str + "jjjj";
    str.append("1234");
    str.append("fjjf");
    str += 12354.123;
    cout << str;
    return 0;
}

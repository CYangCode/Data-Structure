#include <iostream>
#include "String.h"
using namespace std;

int main()
{
    String str("acabaaaabaaaabcacaabc");
    cout << str.index("aaaabc", 9) << endl;
    return 0;
}

#include <iostream>
#include "GList.h"
#include <string.h>
using namespace std;

int main()
{
    char * str = "(a,((b,c),d),(e,f))";
  //  char * str = "(a,b,c,d,e,f)";
    GList list(str);
    GList list2 = list.copy();
    list2.travel();
    cout << list2.depth();
}

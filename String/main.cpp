#include <iostream>
#include "String.h"
using namespace std;
int strlen(char * str)
{
    int i;
    for (i = 0; str[i]; ++i);
    return i;
}
int * GetNext(char * str, int size)
{
    int * next = new int[size];
    int i = 0;//i始终指向next数组的操作位置
    int j = -1;//j指向模式串的当前匹配位置
    next[0] = -1;//如果j为0任然与str[i]不匹配，则i变为-1，-1的意义就在于此
    while (i < size) {
        if (j == -1 || str[i] == str[j]) {
            //i指向的当前字符与j指向的模式串字符匹配，或者在之前的操作中没有找到
            ++i;++j;//i指向下一个需要赋值的地方
            next[i] = j;
        }
        else j = next[j];//如果不匹配，就类似于KMP中模式串不匹配的操作相同
    }
    return next;
}

int * GetNextValue(char * str, int size)
{
    int * next_val = new int[size];
    next_val[0] = -1;
    int i = 0;
    int j = -1;
    while (i < size) {
        if (j == -1 || str[i] == str[j]) {
            ++i; ++j;
            if (str[i] != str[j]) next_val[i] = j;
            else next_val[i] = next_val[j];//如果该字符和i指向的模式串的字符相同，则从该处仍然无法匹配
        }
        else j = next_val[j];
    }
    return next_val;
}

int KMP(char * src, char * t)
{
    int * next = GetNextValue(t, strlen(t));
    int i = 0;
    int j = 0;
    while (i < strlen(src) && j < strlen(t)){
        if (j == -1 || src[i] == t[j]) {
            ++i; ++j;
        }
        else {
            j = next[j];
        }
    }
    return (i == strlen(src))? -1: i - strlen(t);
}

int main()
{
    char * src = "fdjkbchabaabcacacbabcafsbdafbascba";
    char * t = "abaabcac";
//    for (int i = 0; i < strlen(str); ++i) cout << next[i] << "\t";
    cout << KMP(src, t) << endl;
    return 0;
}

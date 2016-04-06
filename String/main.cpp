#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int strlen(char * str)
{
    int i;
    for (i = 0; str[i]; ++i);
    return i;
}

int * getNext(char * t)
{
    int len = strlen(t);
    int * next = new int[len];
    next[0] = -1;
    int i = 0, j = -1;
    while (i < len)
    {
        if (j == -1 || t[i] == t[j]) {
            ++i; ++j;
            if (t[i] != t[j]) next[i] = j;
            else next[i] = next[j];
        } else {
            j = next[j];
        }
    }
    return next;
}

int kmp(char * s, char * t, int pos)
{
    int i = pos, j = 0;
    int * next = getNext(t);
    for (int k = 0; k < strlen(t); ++k) {
        cout << next[k] << endl;
    }
    cout << endl;
    int sLen = strlen(s), tLen = strlen(t);
    while (i < sLen && j < tLen) {
        if (j == -1 || s[i] == t[j]) { ++i; ++j;}
        else j = next[j];
    }
    if (j >= tLen) return i - tLen;
    delete[] next;
    return 0;
}

int main()
{
    //test
    int result = kmp("acabaaaabaaaabcacaabc", "aaaabc", 0);
    cout << result << endl;
    return 0;
}

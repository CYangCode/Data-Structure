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
//abaabc
int * getNextArray(char * t)
{
    int len = strlen(t);
    int i = 1, j = 0;
    int * next = new int[len];
    next[0] = -1;
    while (i < len) {
        if (j == 0 || t[i - 1] == t[j - 1]) {
            ++i;
            ++j;
            next[i - 1] = j - 1;
        } else {
            j = next[j - 1] + 1;
        }
    }
    return next;
}

int kmp(char * s, char * t, int pos)
{
    int i = pos, j = 0;
    int * next = getNextArray(t);
    cout << endl;
    int sLen = strlen(s), tLen = strlen(t);
    while (i < sLen && j < tLen) {
        if (j == -1 || s[i] == t[j]) { ++i; ++j;}
        else j = next[j];
    }
    if (j >= tLen) return i - tLen;
    return 0;
}

int main()
{
    //test
    int result = kmp("acabaabaabcacaabc", "abaabc", 0);
    cout << result << endl;
    return 0;
}

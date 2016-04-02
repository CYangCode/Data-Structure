#include <string.h>
#include <stdio.h>

int positionInSymbols(char ch)
{
    int i;
    char * symbols = "()[]{}";
    char length = strlen(symbols);
    for (i = 0; i < length; ++i) {
        if (symbols[i] == ch) {
            return i;
        }
    }
    return -1;
}

void match(char * str, int length)
{
    int i, j;
    int pos;
    int top = -1;
#define STACK_SIZE 20
    char stack[STACK_SIZE];
    for (i = 0; i < length; ++i) {
       pos = positionInSymbols(str[i]);
       //说明是左括号
       if (pos != -1 && pos % 2 == 0) {
            stack[++top] = str[i];
       } else if (top > -1 && positionInSymbols(stack[top]) == pos - 1){
           //说明右括号匹配
           top--;
       } else if (pos == -1) {
           //忽略字符
            continue;
       } else {
           //匹配到了不是对应的字符
           printf("failed!");
           return;
       }
    }
    //栈空
    if (top == -1) {
        printf("success!");
    } else {
        printf("failed!");
    }
}

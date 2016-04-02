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
       //˵����������
       if (pos != -1 && pos % 2 == 0) {
            stack[++top] = str[i];
       } else if (top > -1 && positionInSymbols(stack[top]) == pos - 1){
           //˵��������ƥ��
           top--;
       } else if (pos == -1) {
           //�����ַ�
            continue;
       } else {
           //ƥ�䵽�˲��Ƕ�Ӧ���ַ�
           printf("failed!");
           return;
       }
    }
    //ջ��
    if (top == -1) {
        printf("success!");
    } else {
        printf("failed!");
    }
}

#include <iostream>
#include <string.h>

using namespace std;
const int STACK_SIZE = 20;

int readNum(char * e, int& start);

int readSym(char * e, int& start);

int calculate(int ope1, int ope2, int sym);

int main()
{
    int optr[STACK_SIZE];//运算符栈
    int opnd[STACK_SIZE];//运算数栈
    int top1 = -1, top2 = -1;
    char * e = "(1+2-4)*3/3";
    int start = 0;

    while (start < strlen(e)) {
        int num = readNum(e, start);
        int sym = readSym(e, start);
        if (num != -1) {opnd[++top2] = num;}
        //符号不是括号
        if (sym >= 0) {
            //把+ -当成同一优先级，* /当做同一优先级，如果栈中的符号优先级低于当前符号
            while (top1 > -1 && optr[top1] / 2 >= sym / 2) {
                int result = calculate(opnd[top2--], opnd[top2--], optr[top1--]);
                opnd[++top2] = result;
            }
            optr[++top1] = sym;

        }
    }
    while (top1 > -1) {
        int result = calculate(opnd[top2--], opnd[top2--], optr[top1--]);
        opnd[++top2] = result;
    }
    cout << opnd[top2];
}

int readNum(char * e, int & start)
{
    int i = start;
    int result = 0;
    if (e[i] < '0' || e[i] > '9') return -1;
    while (e[i] >= '0' && e[i] <= '9') {
        result = result * 10 + (e[i] - '0');
        ++i;
    }
    start = i;
    return result;
}
//当出现括号时，使用提高优先级的方法，而不将括号放入栈中
int prefix = 0;

int readSym(char * e, int & start)
{
    switch (e[start++]) {
        case '+': return prefix + 0;
        case '-': return prefix + 1;
        case '*': return prefix + 2;
        case '/': return prefix + 3;
        case '(': prefix += 4; return -1; break;
        case ')': prefix -= 4; return -2; break;
        default: return -3;
    }
}

int calculate(int ope1, int ope2, int sym)
{
    sym %= 4;
    switch(sym) {
    case 0: return ope1 + ope2;
    case 1: return ope1 - ope2;
    case 2: return ope1 * ope2;
    case 3: return ope1 / ope2;
    }
}

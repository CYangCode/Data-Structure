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
    int i = 0;//iʼ��ָ��next����Ĳ���λ��
    int j = -1;//jָ��ģʽ���ĵ�ǰƥ��λ��
    next[0] = -1;//���jΪ0��Ȼ��str[i]��ƥ�䣬��i��Ϊ-1��-1����������ڴ�
    while (i < size) {
        if (j == -1 || str[i] == str[j]) {
            //iָ��ĵ�ǰ�ַ���jָ���ģʽ���ַ�ƥ�䣬������֮ǰ�Ĳ�����û���ҵ�
            ++i;++j;//iָ����һ����Ҫ��ֵ�ĵط�
            next[i] = j;
        }
        else j = next[j];//�����ƥ�䣬��������KMP��ģʽ����ƥ��Ĳ�����ͬ
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
            else next_val[i] = next_val[j];//������ַ���iָ���ģʽ�����ַ���ͬ����Ӹô���Ȼ�޷�ƥ��
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

#ifndef STRING_H
#define STRING_H

#include <iostream>
using namespace std;

class String
{
    public:
        //当使用该构造函数baseStr默认为空字符串
        String();
        //实现自动类型转换
        String(char * str);
        //深拷贝
        String(const String& str);
        //析构函数
        virtual ~String();
        //返回
        String copy();
        //判断是否为空
        int isEmpty()const;
        //和给定的字符串进行比较
        int equal(String str)const;
        //长度
        int length()const;
        //追加字符
        void append(String str);
        //清空原有字符
        void clear();
        //子串默认位置是开始位置 s 为0，结束位置为length - 1，即整个字符串
        String subString(int s, int e);
        //得到指定位置的字符
        char charAt(int index) const;
        //返回一个新的字符数组
        char * toCharArray();
        //转换成大写
        String toUpperCase();
        //转换成小写
        String toLowerCase();
        //重载+号
        String operator+(String other);
        //重载+=号
        String operator+=(String other);
        //重载+号
        String operator+(int other);
        //重载+=号
        String operator+=(int other);
        //重载+号
        String operator+(double other);
        //重载+=号
        String operator+=(double other);
        //重载+号
        String operator+(char other);
        //重载+=号
        String operator+=(char other);
        //重载等号
        String operator=(String other);
        //重载[]
        char operator[](int n);
        //重载输出流
        friend ostream& operator<< (ostream & stream,String other);
        //重载输入流
        friend istream& operator>>(istream & stream, String other);
        int strlen(char * str)const;
    protected:
        //初始化
        void init();
        //拷贝字符串
        void copyStr(char * str);
    private:
        //使用动态数组
        char * baseStr;
        int size;
};

#endif // STRING_H

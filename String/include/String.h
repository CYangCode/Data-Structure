#ifndef STRING_H
#define STRING_H

#include <iostream>
using namespace std;

class String
{
    public:
        //��ʹ�øù��캯��baseStrĬ��Ϊ���ַ���
        String();
        //ʵ���Զ�����ת��
        String(char * str);
        //���
        String(const String& str);
        //��������
        virtual ~String();
        //����
        String copy();
        //�ж��Ƿ�Ϊ��
        int isEmpty()const;
        //�͸������ַ������бȽ�
        int equal(String str)const;
        //����
        int length()const;
        //׷���ַ�
        void append(String str);
        //���ԭ���ַ�
        void clear();
        //�Ӵ�Ĭ��λ���ǿ�ʼλ�� s Ϊ0������λ��Ϊlength - 1���������ַ���
        String subString(int s, int e);
        //�õ�ָ��λ�õ��ַ�
        char charAt(int index) const;
        //����һ���µ��ַ�����
        char * toCharArray();
        //ת���ɴ�д
        String toUpperCase();
        //ת����Сд
        String toLowerCase();
        //����+��
        String operator+(String other);
        //����+=��
        String operator+=(String other);
        //����+��
        String operator+(int other);
        //����+=��
        String operator+=(int other);
        //����+��
        String operator+(double other);
        //����+=��
        String operator+=(double other);
        //����+��
        String operator+(char other);
        //����+=��
        String operator+=(char other);
        //���صȺ�
        String operator=(String other);
        //����[]
        char operator[](int n);
        //���������
        friend ostream& operator<< (ostream & stream,String other);
        //����������
        friend istream& operator>>(istream & stream, String other);
        int strlen(char * str)const;
    protected:
        //��ʼ��
        void init();
        //�����ַ���
        void copyStr(char * str);
    private:
        //ʹ�ö�̬����
        char * baseStr;
        int size;
};

#endif // STRING_H

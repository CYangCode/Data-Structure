#include "String.h"
#include <sstream>
String::String()
{
    init();
}

String::~String()
{
    clear();
}

String::String(char* str)
{
    init();
    size = strlen(str);
    copyStr(str);
}

String::String(const String & str)
{
    init();
    size = str.size;
    copyStr(str.baseStr);
}

String String::copy()
{
    String str(*this);
    return str;
}

void String::copyStr(char* str)
{
    baseStr = new char[size + 1];
    for (int i = 0; i < size; ++i) {
        baseStr[i] = str[i];
    }
    baseStr[size] = 0;
}

int String::isEmpty() const
{
    return size == 0;
}

int String::equal(String str) const
{
    if (size != str.size) return false;
    for (int i = 0; i < size; ++i) {
        if (baseStr[i] != str.baseStr[i]) {
            return false;
        }
    }
    return true;
}

int String::length() const
{
    return this->size;
}

void String::append(String str)
{
    int newStrLen = this->size + str.size;
    char * temp = new char[newStrLen];
    int i;
    for (i = 0; i < this->size; ++i) {
        temp[i] = baseStr[i];
    }
    for (;i < newStrLen; ++i) {
        temp[i] = str.baseStr[i - this->size];
    }
    temp[i] = 0;
    clear();
    this->size = i;
    this->baseStr = temp;
}

void String::clear()
{
    delete[] baseStr;
    size = 0;
}

String String::subString(int s, int e)
{
    if (s > e) return "";
    int length = e - s + 1;
    char * str = new char[length + 1];
    for (int i = 0; i < length; ++i) {
        str[i] = baseStr[i + s];
    }
    str[length] = 0;
    return str;
}

char String::charAt(int index) const
{
    if (index >= size) return '\0';
    return baseStr[index];
}

char * String::toCharArray()
{
    return baseStr;
}

String String::toUpperCase()
{
     String des(*this);
     for (int i = 0; i < size; ++i) {
        if (des.baseStr[i] >= 'a' && des.baseStr[i] <= 'z') {
            des.baseStr[i] -= 32;
        }
    }
    return des;
}

String String::toLowerCase()
{
     String des(*this);
     for (int i = 0; i < size; ++i) {
        if (des.baseStr[i] >= 'A' && des.baseStr[i] <= 'Z') {
            des.baseStr[i] += 32;
        }
    }
    return des;
}

int String::strlen(char * str) const
{
    int len;
    for (len = 0; str[len]; ++len);
    return len;
}

void String::init()
{
    baseStr = NULL;
    size = 0;
}

String String::operator+(String other)
{
    String str(*this);
    str.append(other);
    return str;
}

String String::operator+=(String other)
{
    append(other);
    return *this;
}


String String::operator=(String other)
{
    clear();
    size = other.size;
    copyStr(other.baseStr);
    return *this;
}

String String::operator+(int other)
{
    String returnedStr(*this);
    stringstream ss;
    ss.clear();
    ss <<  other;
    char * str = new char[ss.width()];
    ss >> str;
    returnedStr.append(str);
    return returnedStr;
}

String String::operator+=(int other)
{
    return (*this) = (*this) + other;
}

String String::operator+(double other)
{
    String returnedStr(*this);
    stringstream ss;
    ss.clear();
    ss <<  other;
    char * str = new char[ss.width()];
    ss >> str;
    returnedStr.append(str);
    return returnedStr;
}

String String::operator+=(double other)
{
    return (*this) = (*this) + other;
}

String String::operator+(char other)
{
    String returnedStr(*this);
    stringstream ss;
    ss.clear();
    ss <<  other;
    char * str = new char[ss.width()];
    ss >> str;
    returnedStr.append(str);
    return returnedStr;
}

String String::operator+=(char other)
{
    return (*this) = (*this) + other;
}

char String::operator[](int n)
{
    return charAt(n);
}

ostream& operator<<(ostream & stream,String other)
{
    stream << other.baseStr;
    return stream;
}

istream& operator>>(istream & stream, String other)
{
    other.size = stream.width();
    other.baseStr = new char[other.size];
    stream >> other.baseStr;
    return stream;
}

// to_string example
#include <iostream>   // std::cout
#include <map>
#include <functional>
#include <algorithm>
using namespace std;

struct A
{
    int a;
    double b;
    A(int a, double b) {this->a = a; this->b = b;}
};
int main ()
{
    int a[5];
    //lambda���ʽ
    generate_n(a, 5, [](){
               static int i;
               return i++;
               });
    for_each(a, a + 5, [](int & x){cout << x << endl;});
    //����ĳ�ʼ����ʽ
    map<int, string> m{{1, "abc"}, {2, "bcd"}, {3, "cde"}, {4, "def"}};
    //auto���ͺ��ر�ı�����ʽ��������begin��end��
    for (auto elem: m) {
        cout << elem.first << " " << elem.second << endl;
    }
    //decltype ת������
    int intA = 10;
    decltype(intA) intB = intA;
    cout << "intB: " << intB << endl;

    //�䳤����
    auto p = make_pair(1, "C++ 11");
    cout << p.first <<" " << p.second << endl;
    auto t1 = make_tuple(1, 2.0, "c++11", A(1, 2.0));
    cout << get<0>(t1) << " " << get<1>(t1) << " " << get<2>(t1) << endl;


}

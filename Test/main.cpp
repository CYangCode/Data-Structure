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
    //lambda表达式
    generate_n(a, 5, [](){
               static int i;
               return i++;
               });
    for_each(a, a + 5, [](int & x){cout << x << endl;});
    //特殊的初始化方式
    map<int, string> m{{1, "abc"}, {2, "bcd"}, {3, "cde"}, {4, "def"}};
    //auto类型和特别的遍历方式（必须有begin和end）
    for (auto elem: m) {
        cout << elem.first << " " << elem.second << endl;
    }
    //decltype 转换类型
    int intA = 10;
    decltype(intA) intB = intA;
    cout << "intB: " << intB << endl;

    //变长参数
    auto p = make_pair(1, "C++ 11");
    cout << p.first <<" " << p.second << endl;
    auto t1 = make_tuple(1, 2.0, "c++11", A(1, 2.0));
    cout << get<0>(t1) << " " << get<1>(t1) << " " << get<2>(t1) << endl;


}

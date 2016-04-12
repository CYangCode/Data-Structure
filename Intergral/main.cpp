#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;

float mod(float la, float l)
{
    if (la - l < 0) return la;
    return mod(la - l, l);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        float l, va, vb, times;
        cin >> l >> va >> vb >> times;
        float time = (times * 2 - 1) * l / (va + vb);
        float la = time * va, lb = time * vb;
        float dist = (la = mod(la, l)) < (lb = mod(lb, l))? la: lb;
        printf("Time=%.3f Dist=%.3f\n", time, dist);
    }
}

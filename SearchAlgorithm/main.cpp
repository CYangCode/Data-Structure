#include <iostream>
#include <time.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <functional>

using namespace std;

/** \brief 使用插值查找找到有序序列的某个值
 */
int search(int * ord_seq, int l, int h, int key)
{
    if (l > h) return -1;
    int i = (key - ord_seq[l]) * (h - l + 1)/(ord_seq[h] - ord_seq[l]);
    if (ord_seq[i] == key) return i;
    int index = search(ord_seq, l, i, key);
    if (index != -1) return index;
    else return search(ord_seq, i + 1, h, key);
}

int main()
{
    const int ARRAY_SIZE = 100;
    int order_seq[ARRAY_SIZE];
    srand((int)time(0));
    for (int i = 0; i < ARRAY_SIZE; ++i) order_seq[i] = rand() % 1000;
    auto cmp = [](const void * a, const void * b)->int
    {
        return (*(int *)a) - (*(int *)b);
    };
    qsort(order_seq, ARRAY_SIZE, sizeof(int), cmp);
    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        cout << order_seq[i] << endl;
    }
    int searched_num;
    while (cin >> searched_num)
    {
        cout << search(order_seq, 0, ARRAY_SIZE - 1, searched_num);
    }
}

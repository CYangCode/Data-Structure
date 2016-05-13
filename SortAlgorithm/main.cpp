#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

void PrintArray(int *array, int size);

void QSort(int * array, int left, int right)
{
    if (left >= right) return;
    int l = left, r = right;
    int cur_val = array[l];
    while (l < r) {
        //从右向左找到比当前值小的第一个值
        while (array[r] > cur_val && l < r) {
            --r;
        }
        if (l < r) array[l++] = array[r];
        //从左向右找到比当前值大的第一个值
        while (array[l] < cur_val && l < r) {
            ++l;
        }
        if (l < r) array[r--] = array[l];
    }
    array[l] = cur_val;
    QSort(array, left, l);
    QSort(array, l + 1, right);
}

void Merge(int * array, int left, int mid, int right)
{
    int * temp_array = new int[right - left + 1];
    int cur = 0;//指向临时数组的当前操作位置
    int i = left;//指向左数组的当前操作位置
    int j = mid + 1;//指向右数组的当前操作位置
    while (i < mid + 1 && j < right + 1) {
        if (array[i] < array[j]) {
            temp_array[cur++] = array[i++];
        } else {
            temp_array[cur++] = array[j++];
        }
    }
    while (i < mid + 1) {
        temp_array[cur++] = array[i++];
    }
    while (j < right + 1) {
        temp_array[cur++] = array[j++];
    }
    for (i = 0; i < cur; ++i) {
        array[left++] = temp_array[i];
    }
}

void MergeSort(int * array, int left, int right)
{
    if (left >= right) return;
    int mid = (left + right) / 2;
    MergeSort(array, left, mid);
    MergeSort(array, mid + 1, right);
    Merge(array, left, mid, right);
}

void PrintArray(int * array, int size)
{
    for (int i = 0; i < size; ++i) {
        cout << array[i] << "\t";
    }
    cout << endl;
}

int * GenerateRandomArray(int size, int range)
{
    int * array = new int[size];
    srand((unsigned int)time(0));
    for (int i = 0; i < size; ++i) {
        array[i] = rand() % range;
    }
    return array;
}

int main()
{
    int * array = GenerateRandomArray(10, 100);
    PrintArray(array, 10);
  //  QSort(array, 0, 9);
    MergeSort(array, 0, 9);
    PrintArray(array, 10);
    return 0;
}

#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    //数组的末尾位置是确定，但首位的位置会随着数组的长度而改变
   int a[6]={1,2,3,4,5,6};
   int * ptr = (int *)(a + 1);
   //ptr1指向数组的末尾 + 1
   int *ptr1=(int *)(&a+1);
   //ptr2为指针a的地址加1的位置
   int *ptr2=(int *)((int)a + 1);
   //虽然a和&a的值是相同的，但是加1的结果是不同的，a + 1指向的是数组的第二个元素，&a + 1指向的是数组的末尾 + 1的位置
   printf("%x %x\n", (a + 1), (int)a + 1);
   //一个指针指向一个字节，指针加1，则指针指向下一字节，又因为int为4字节即32比特
   //数组的第二个数的一部分包括在32位中，所以*ptr2是2 00 00 00
   printf("%x,%x",ptr1[-1],*ptr2);
   return 0;
}

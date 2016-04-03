#include <iostream>
using namespace std;

int check(int * array, int n)
{
  for (int i = 0; i < n * n; ++i){
  	if (array[i] == 0) return 1;
  }
  return 0;
}
int main()
{
  //四个方向
  int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  int n;
  cin >> n;
  int * array = new int[n * n];
  //初始化
  for (int i = 0; i < n * n; ++i) {
  	array[i] = 0;
  }
  //初始位置
  int x = 0;
  int y = 0;
  //计数
  int count = 2;
  array[0] = 1;
  while (check(array, n)) {
    //走一圈
     for (int i = 0; i < 4; ++i) {
       //不越界，不覆盖
       while (x + dir[i][0] < n && y + dir[i][1] < n && array[(x + dir[i][0]) * n + (y + dir[i][1])] == 0) {
         array[(x + dir[i][0]) * n + (y + dir[i][1])]  = (count++);
         x += dir[i][0];
         y += dir[i][1];
       }

     }

  }
  for (int i = 0; i < n * n; ++i) {
  	cout << array[i] << " ";
  }
  delete[] array;
}

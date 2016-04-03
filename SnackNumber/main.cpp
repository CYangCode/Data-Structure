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
  //�ĸ�����
  int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  int n;
  cin >> n;
  int * array = new int[n * n];
  //��ʼ��
  for (int i = 0; i < n * n; ++i) {
  	array[i] = 0;
  }
  //��ʼλ��
  int x = 0;
  int y = 0;
  //����
  int count = 2;
  array[0] = 1;
  while (check(array, n)) {
    //��һȦ
     for (int i = 0; i < 4; ++i) {
       //��Խ�磬������
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

#include <iostream>

using namespace std;

 int maze[6][8] = {
    {0, 1, 1, 1, 0, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 1, 0},
    {0, 1, 0, 0, 1, 1, 1, 1},
    {0, 1, 1, 0, 0, 0, 0, 0},
    {1, 0, 0, 1, 1, 0, 1, 0},
    {0, 1, 1, 0, 0, 1, 1, 0}
    };

struct Point
{
    int x;
    int y;
    Point * prev;
    Point(){prev = NULL;};
    Point(int x, int y) {this->x = x; this->y = y;}
    Point operator=(Point p) {this->x = p.x; this->y = p.y; return p;}
};

void BFS(int maze[][8], int m, int n);

int check(int x, int y);

void printMaze();

void printPath(Point * tail);

int main()
{
    BFS(maze, 6, 8);
    return 0;
}

void BFS(int maze[][8], int m, int n)
{
    int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    Point * stack[50];
    for (int i = 0; i < 50; ++i) {
        stack[i] = NULL;
    }
    int top = -1;
    Point * p = new Point(0, 0);
    stack[++top] = p;

    //Õ»²»¿Õ
    while (top > -1) {
        //³öÕ»
        Point * cur = stack[top--];
        if (cur->x == m - 1 && cur->y == n - 1) {
            cout << "Find it!" << endl;
         //   printMaze();
            printPath(cur);
            return;
        }
        for (int i = 0; i < 4; ++i) {
            maze[cur->x][cur->y] = 2;
            if (check(cur->x + dir[i][0], cur->y + dir[i][1])) {
                Point * temp = new Point(cur->x + dir[i][0], cur->y + dir[i][1]);
                temp->prev = cur;
                stack[++top] = temp;
            }
        }
    }
    cout << "Failed!" << endl;
}

int check(int x, int y)
{
    return maze[x][y] == 0 && x >= 0 && x <= 6 && y >= 0 && y <= 8;
}

void printMaze()
{
    for (int i = 0; i < 6; ++i) {
         for (int j = 0; j < 8; ++j)
            cout << maze[i][j] << " ";
        cout << endl;
    }
}

void printPath(Point * tail)
{
    if (tail == NULL) return;
    printPath(tail->prev);
    cout << tail->x << " " << tail->y << endl;
}

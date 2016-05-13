#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

typedef struct BSTNode
{
    int data;
    int bf;//平衡因子
    BSTNode * lchild, * rchild;
}* BSTree;

int init(BSTree & root, int data)
{
    root = new BSTNode;
    root->data = data;
    root->lchild = NULL;
    root->rchild = NULL;
    root->bf = 0;
}

void RR(BSTree A)
{
    BSTree B = A->lchild;
    A->lchild = B->rchild;
    B->rchild = A;
}

void LR(BSTree A)
{
    BSTree B = A->rchild;
    A->rchild = B->lchild;
    B->lchild = A;
}

void insert(BSTree root, int data)
{
    if (!root) {
        root = new BSTNode;
        root->data = data;
        root->lchild = NULL;
        root->rchild = NULL;
        root->bf = 0;
        return;
    }
    if (data > root->data) {
        root->bf--;
        insert(root->rchild, data);
    } else if (data < root->data) {
        root->bf++;
        insert(root->lchild, data);
    }
}

void PreTravel(BSTree root)
{
    if (!root) return;
    cout << root->data << "\t";
    PreTravel(root->lchild);
    PreTravel(root->rchild);
}

void Travel(BSTree root)
{
    if (!root) return;
    Travel(root->lchild);
    cout << root->data << "\t";
    Travel(root->rchild);
}

int main()
{
    srand((int)time(0));
    BSTree tree = NULL;
    for (int i = 0; i < 10; ++i) {
        insert(tree, rand() % 100);
    }
    Travel(tree);
    cout << endl;
    PreTravel(tree);
    return 0;
}

#include <iostream>
#include <string.h>
using namespace std;

enum NodeTag {Link, Thread};

struct BNode
{
    char data;
    BNode * lchild, * rchild;
    NodeTag ltag, rtag;
    BNode():lchild(nullptr), rchild(nullptr)
    {
        ltag = Link;
        rtag = Link;
    }
    BNode(char data):BNode()
    {
        this->data = data;
    }
};

/** \brief 根据输入的字符串生成一棵二叉树
 *
 * \param str 先根遍历顺序的元素，空节点有#键表示
 * \param i 从位置i开始
 * \return 二叉树的根节点
 *
 */
BNode * createBiTree(char * str, int && i)
{
    if (str[i] == '#') return nullptr;
    BNode * root = new BNode(str[i]);
    root->lchild = createBiTree(str, move(++i));
    root->rchild = createBiTree(str, move(++i));
    return root;
}

/** \brief 清空以root为根的二叉树
 *
 * \param root 树根
 * \return void
 *
 */
void destroy(BNode * root)
{
    if (root == nullptr) return;
    if (root->rtag == Link) destroy(root->lchild);
    if (root->ltag == Link) destroy(root->rchild);
    delete root;
}

/** \brief 中根遍历以root为树根的二叉树
 *
 * \param root树根
 * \return void
 *
 */
void travel(BNode * root)
{
    if (root == nullptr) return;
    if (root->ltag == Link) travel(root->lchild);
    if (root->rtag == Link) travel(root->rchild);
    cout << root->data;
}

BNode * pre = nullptr;
void inThreading(BNode * root)
{
    if (root)
    {
        inThreading(root->lchild);
        if (!root->lchild)
        {
            root->ltag = Thread;
            root->lchild = pre;
        }
        if (!pre->rchild)
        {
            pre->rtag = Thread;
            pre->rchild = root;
        }
        inThreading(root->rchild);
    }
}
/** \brief 中序遍历二叉树root，并将其终须线索化
 *
 * \param root 二叉树的根节点root
 * \return 线索二叉树的根节点
 *
 */
void inOrderTheading(BNode * root)
{
    BNode * thrt = new BNode;//线索二叉树树根
    thrt->ltag = Link;
    thrt->rtag = Thread;
    thrt->rchild = thrt;
    if (!root) thrt->lchild = thrt;
    else
    {
        thrt->lchild = root;
        pre = thrt;
        inThreading(root);
        pre->rchild = thrt;
        pre->rtag = Thread;
        thrt->rchild = pre;
    }
}

BNode * search(BNode * root, char ch)
{
    if (root == nullptr) return nullptr;
    if (root->data == ch) return root;
    BNode * result = nullptr;
    if (root->ltag == Link && (result = search(root->lchild, ch))) return result;
    else if (root->rtag == Link && (result = search(root->rchild, ch))) return result;
}

void myInOrderTheading(BNode * root)
{
    if (root == nullptr) return;
    if (!root->lchild) root->ltag = Thread;
    if (!root->rchild) root->rtag = Thread;
    myInOrderTheading(root->lchild);
    myInOrderTheading(root->rchild);
    BNode * p = nullptr;
    //找到左子树的最右下节点
    for (p = root->lchild; p && p->rchild; p = p->rchild);
    if (p) p->rchild = root;
    //找到右子树最左下角的节点
    for (p = root->rchild; p && p->lchild; p = p->lchild);
    if (p) p->lchild = root;
}

int main()
{
    BNode * root = createBiTree("-+a##*b##-c##d##/e##f##", 0);
    myInOrderTheading(root);
    travel(root);
    cout << endl;
    char ch;
    while (cin >> ch && ch != '#')
    {
        BNode * result = search(root, ch);
        if (result)
        {
            if (result->lchild)
                cout << "左孩子" << result->lchild->data << endl;
            else
                cout << "nil" << endl;
            if (result->rchild)
                cout << "右孩子" << result->rchild->data << endl;
            else
                cout << "nil" << endl;
        }

    }
    destroy(root);
}

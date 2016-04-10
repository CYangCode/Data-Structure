#include <iostream>
#include <string.h>
using namespace std;

enum NodeTag {Link, Thread};

struct BNode
{
    char data;
    BNode * lchild, * rchild;
    NodeTag ltag, rtag;
    BNode():lchild(nullptr), rchild(nullptr) {}
    BNode(char data):lchild(nullptr),rchild(nullptr) {this->data = data;}
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
    destroy(root->lchild);
    destroy(root->rchild);
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
    travel(root->lchild);
    cout << root->data;
    travel(root->rchild);
}

/** \brief 中序遍历二叉树root，并将其终须线索化
 *
 * \param root 二叉树的根节点root
 * \return 线索二叉树的根节点
 *
 */
BNode * inOrderTheading(BNode * root)
{
    BNode * thrt = new BNode;//线索二叉树树根
    thrt->ltag = Link;
}

int main()
{
    BNode * root = createBiTree("-+a##*b##-c##d##/e##f##", 0);
    travel(root);
    destroy(root);
}

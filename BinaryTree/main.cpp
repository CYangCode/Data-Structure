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

/** \brief ����������ַ�������һ�ö�����
 *
 * \param str �ȸ�����˳���Ԫ�أ��սڵ���#����ʾ
 * \param i ��λ��i��ʼ
 * \return �������ĸ��ڵ�
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

/** \brief �����rootΪ���Ķ�����
 *
 * \param root ����
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

/** \brief �и�������rootΪ�����Ķ�����
 *
 * \param root����
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
/** \brief �������������root������������������
 *
 * \param root �������ĸ��ڵ�root
 * \return �����������ĸ��ڵ�
 *
 */
void inOrderTheading(BNode * root)
{
    BNode * thrt = new BNode;//��������������
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
    //�ҵ��������������½ڵ�
    for (p = root->lchild; p && p->rchild; p = p->rchild);
    if (p) p->rchild = root;
    //�ҵ������������½ǵĽڵ�
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
                cout << "����" << result->lchild->data << endl;
            else
                cout << "nil" << endl;
            if (result->rchild)
                cout << "�Һ���" << result->rchild->data << endl;
            else
                cout << "nil" << endl;
        }

    }
    destroy(root);
}

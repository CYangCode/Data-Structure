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
    destroy(root->lchild);
    destroy(root->rchild);
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
    travel(root->lchild);
    cout << root->data;
    travel(root->rchild);
}

/** \brief �������������root������������������
 *
 * \param root �������ĸ��ڵ�root
 * \return �����������ĸ��ڵ�
 *
 */
BNode * inOrderTheading(BNode * root)
{
    BNode * thrt = new BNode;//��������������
    thrt->ltag = Link;
}

int main()
{
    BNode * root = createBiTree("-+a##*b##-c##d##/e##f##", 0);
    travel(root);
    destroy(root);
}

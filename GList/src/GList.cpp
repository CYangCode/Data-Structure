#include "GList.h"
#include <string.h>


GList::GList(char * str)
{
    head = createGList(str);
}

GList::GList()
{
    head = nullptr;
}

GList::~GList()
{
    destroy();
}
/** \brief 根据字符串获得广义表
 *
 * \param str 字符串，元素之间由','隔开，LIST类型的加括号
 * \return 广义表的头结点
 *
 */
GNode* GList::createGList(char* str)const
{
    if (strcmp(str, "()") == 0) return nullptr;
    GNode * head = nullptr;
    if (strlen(str) == 1) {
        head = new GNode(str[0]);
    }
    else {
        head = new GNode;
        GNode * p = head;
        //sub为去掉最外层括号的子串
        char * sub = substr(str, 1, strlen(str) - 2);
        //当sub不为空
        while (strcmp(sub, "") != 0) {
            char * hsub = new char[strlen(sub) + 1];
            //hsub为sub表头元素，此函数之后sub为表尾元素
            sever(sub, hsub);
            p->setHead(createGList(hsub));
            GNode * q = p;
            if (strcmp(sub, "") != 0) {
                p = new GNode;
                q->setTail(p);
            }
        }
    }
    return head;
}

/** \brief 将非空串str分割成两部分
 *
 * \param hstr为第一个','之前的子串
 * \param str为之后的子串
 * \return void
 *
 */
void GList::sever(char*& str, char*& hstr)const
{
    int n = strlen(str);
    int i = -1, k = 0;
    char ch;
    do{
        ++i;
        ch = substr(str, i, i)[0];
        if (ch == '(') ++k;
        else if (ch == ')') --k;
    }while (i < n && (ch != ',' || k != 0));
    if (i < n) {
        hstr = substr(str, 0, i - 1);
        str = substr(str, i + 1, n - 1);
    }
    else {
        strcpy(hstr, str);
        str = "";
    }
}

/** \brief 得到str的子串
 *
 * \param str 母串
 * \param s 开始位置
 * \param e 结束位置
 * \return 子串
 *
 */
char* GList::substr(char* str, int s, int e)const
{
    char * sub = new char[e - s + 2];
    memcpy(sub, str + s, e - s + 1);
    sub[e - s + 1] = 0;
    return sub;
}

/** \brief 以深度优先的方式遍历广义表
 *
 * \param 广义表的头结点
 * \return void
 *
 */
void GList::travel(GNode* head)const
{
    if (head == nullptr) return;
    if (head->tag == ATOM) {
        cout << head->elem.atom << endl;
        return;
    }
    travel(head->getHead());
    travel(head->getTail());
}

/** \brief 以深度优先的方式清空所有节点
 *
 * \param head 广义表的头结点
 * \return void
 *
 */
void GList::destroy(GNode* head)const
{
    if (head == nullptr) return;
    if (head->tag == ATOM) {
        delete head;
        return;
    }
    destroy(head->getHead());
    destroy(head->getTail());
    delete head;
}

/** \brief 得到广义表的深度
 *
 * \param head 广义表的头结点
 * \return 广义表的深度
 *
 */
int GList::depth(GNode* head)const
{
    if (head == nullptr) return 0;
    if (head->tag == ATOM) return 1;
    int max = 0;
    for (GNode * ptr = head; ptr; ptr = ptr->getTail()) {
        int dep = depth(ptr->getHead());
        if (dep > max) {
            max = dep;
        }
    }
    return max + 1;
}

/** \brief 拷贝一个广义表
 *
 * \param head 广义表的头结点
 * \return 拷贝之后的广义表头结点
 *
 */
GNode* GList::copy(GNode* head) const
{
    GNode * T;
    if (head == nullptr) return nullptr;
    T = new GNode;
    T->tag = head->tag;
    if (head->tag == ATOM) T->elem.atom = head->elem.atom;
    else {
        T->setHead(copy(head->getHead()));
        T->setTail(copy(head->getTail()));
    }
    return T;
}
//方法2，看起来没有上边的简洁
//GNode* GList::copy(GNode* head) const
//{
//    if (head == nullptr) return nullptr;
//    if (head->tag == ATOM) return new GNode(head->elem.atom);
//    GNode * returnedHead = new GNode;
//    GNode * newCurPtr = returnedHead;
//    GNode * srcCurPtr = head;
//    while (srcCurPtr) {
//        newCurPtr->setHead(copy(srcCurPtr->getHead()));
//        srcCurPtr = srcCurPtr->getTail();
//        if (srcCurPtr != nullptr) {
//            GNode * q = new GNode;
//            newCurPtr->setTail(q);
//            newCurPtr = q;
//        }
//    }
//    return returnedHead;
//}


/** \brief 清空广义表的所有节点
 *
 * \return void
 *
 */
void GList::destroy()
{
    destroy(head);
}

GList GList::copy()
{
    GList list;
    list.head = copy(head);
    return list;
}

/** \brief 获得广义表的长度即元素个数
 *
 * \return 广义表的长度
 *
 */
int GList::length() const
{
    int len;
    for (GNode * p = head; p; p = p->getTail())
        ++len;
    return len;
}

int GList::depth() const
{
    return depth(head);
}

bool GList::isEmpty() const
{
    return head == nullptr;
}

void GList::travel()
{
    travel(head);
}

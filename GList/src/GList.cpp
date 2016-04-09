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
/** \brief �����ַ�����ù����
 *
 * \param str �ַ�����Ԫ��֮����','������LIST���͵ļ�����
 * \return ������ͷ���
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
        //subΪȥ����������ŵ��Ӵ�
        char * sub = substr(str, 1, strlen(str) - 2);
        //��sub��Ϊ��
        while (strcmp(sub, "") != 0) {
            char * hsub = new char[strlen(sub) + 1];
            //hsubΪsub��ͷԪ�أ��˺���֮��subΪ��βԪ��
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

/** \brief ���ǿմ�str�ָ��������
 *
 * \param hstrΪ��һ��','֮ǰ���Ӵ�
 * \param strΪ֮����Ӵ�
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

/** \brief �õ�str���Ӵ�
 *
 * \param str ĸ��
 * \param s ��ʼλ��
 * \param e ����λ��
 * \return �Ӵ�
 *
 */
char* GList::substr(char* str, int s, int e)const
{
    char * sub = new char[e - s + 2];
    memcpy(sub, str + s, e - s + 1);
    sub[e - s + 1] = 0;
    return sub;
}

/** \brief ��������ȵķ�ʽ���������
 *
 * \param ������ͷ���
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

/** \brief ��������ȵķ�ʽ������нڵ�
 *
 * \param head ������ͷ���
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

/** \brief �õ����������
 *
 * \param head ������ͷ���
 * \return ���������
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

/** \brief ����һ�������
 *
 * \param head ������ͷ���
 * \return ����֮��Ĺ����ͷ���
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
//����2��������û���ϱߵļ��
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


/** \brief ��չ��������нڵ�
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

/** \brief ��ù����ĳ��ȼ�Ԫ�ظ���
 *
 * \return �����ĳ���
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

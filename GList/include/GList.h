#ifndef GLIST_H
#define GLIST_H
#include <iostream>
using namespace std;
enum ElemTag {ATOM = 1, LIST} ;

struct GPtr;

struct GNode
{
    ElemTag tag;

    struct GPtr
    {
        GNode * hp, * tp;
    };

    union
    {
        char atom;
        GPtr ptr;
        //ptr是表节点的指针域，ptr.hp和ptr.tp分别指向表头和表尾
    } elem;

    GNode()
    {
        tag = LIST;
        setHead();
        setTail();
    }

    GNode(char atom)
    {
        tag = ATOM;
        elem.atom = atom;
    }

    GNode(GPtr ptr)
    {
        tag = LIST;
        elem.ptr.hp = ptr.hp;
        elem.ptr.tp = ptr.tp;
    }

    GNode(GNode * ptr)
    {
        tag = LIST;
        setHead();
        setTail();
        if (ptr != nullptr) setHead(ptr);
    }

    GNode *& getHead()
    {
        return elem.ptr.hp;
    }

    GNode *& getTail()
    {
        return elem.ptr.tp;
    }

    void setHead(GNode * p = nullptr)
    {
        elem.ptr.hp = p;
    }

    void setTail(GNode * p = nullptr)
    {
        elem.ptr.tp = p;
    }

};


class GList
{
public:
    GList(char * str);
    GList();
    virtual ~GList();

    void destroy();
    GList copy();
    int length()const;
    int depth()const;
    bool isEmpty()const;
    void travel();
protected:
    GNode * createGList(char * str)const;
    void sever(char *& str, char *& hstr)const;
    char * substr(char * str, int s, int e)const;
    void travel(GNode * head)const;
    int depth(GNode * head)const;
    void destroy(GNode * head)const;
    GNode * copy(GNode * head)const;
private:
    GNode * head;
};

#endif // GLIST_H

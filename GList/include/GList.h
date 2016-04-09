#ifndef GLIST_H
#define GLIST_H
#include <iostream>
using namespace std;
enum ElemTag {ATOM, LIST} ;

struct GNode
{
    ElemTag tag;
    union
    {
        string atom;
    };
};
class GList
{
    public:
        GList();
        virtual ~GList();

    protected:

    private:
};

#endif // GLIST_H

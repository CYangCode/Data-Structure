#ifndef GLIST_H
#define GLIST_H

enum ElemTag {ATOM, LIST} ;

struct GNode
{
    ElemTag tag;
    union
    {
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

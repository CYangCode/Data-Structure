#ifndef _H_INCLUDED
#define _H_INCLUDED

#define LIST_SIZE 5

typedef struct ArrayList
{
    int * elem;
    int length;
    int listSize;
} ArrayList, * PArrayList;

PArrayList impl();

void init(PArrayList list);

int insertToPos(PArrayList list, int pos, int e);

void insertOrdered(PArrayList list, int e);

void printArrayList(PArrayList list);

void printListInfo(PArrayList list);
#endif // _H_INCLUDED

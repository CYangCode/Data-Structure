#ifndef _H_INCLUDED
#define _H_INCLUDED

#define LIST_SIZE 100

typedef struct ArrayList
{
    int elem[LIST_SIZE];
    int length;
    int listSize;
} ArrayList, * PArrayList;

PArrayList impl();

void init(PArrayList list);

void insertToPos(PArrayList list, int pos, int e);

void insertOrdered(PArrayList list, int e);

void printArrayList(PArrayList list);
#endif // _H_INCLUDED

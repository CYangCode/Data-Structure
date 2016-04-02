#include "ArrayList.h"
#include <stdlib.h>
#include <stdio.h>


PArrayList impl()
{
    PArrayList list = (PArrayList)malloc(sizeof(ArrayList));
    init(list);
    return list;
}

void init(PArrayList list)
{
    list->elem = (int *)malloc(sizeof(int) * LIST_SIZE);
    list->length = 0;
    list->listSize = LIST_SIZE;
}

int insertToPos(PArrayList list, int pos, int e)
{
    int i;
    int * newBase;
    if (list->length < pos || pos < 0) {
        return -1;
    }

    if (list->length + 1 > list->listSize) {
        newBase = (int *)realloc(list->elem, (list->listSize + LIST_SIZE) * sizeof(int) );
        if (!newBase) {
            return -2;
        }
        list->elem = newBase;
        list->listSize += LIST_SIZE;
    }

    for (i = list->length; i > pos; --i) {
        list->elem[i] = list->elem[i - 1];
    }
    list->elem[pos] = e;
    list->length++;
    return 1;
}

void insertOrdered(PArrayList list, int e)
{
    //如果插入的元素数量超过了数组的尺寸
    if (list->length + 1 < list->listSize) {
        list->elem = (int *)realloc(list->elem, (list->listSize + LIST_SIZE) * sizeof(int));
        if (!list->elem) {
            return -2;
        }
        list->listSize += LIST_SIZE;
    }
    list->elem[list->length++] = e;
}

void printArrayList(PArrayList list)
{
    int i;
    for (i = 0; i < list->length; ++i) {
        printf("%d\t", list->elem[i]);
    }
    printf("\n");
}

void printListInfo(PArrayList list)
{
    printf("List Size: %d\n", list->listSize);
    printf("List length: %d\n", list->length);
}

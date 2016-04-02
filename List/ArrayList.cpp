#include "ArrayList.h"
#include <stdlib.h>
#include <stdio.h>


void impl(PArrayList list)
{
    list = (PArrayList)malloc(sizeof(ArrayList));
    init(list);
}

void init(PSqlList list)
{
    list->length = 0;
    list->listSize = LIST_SIZE;
}

void insertToPos(PSqlList list, int pos, int e)
{
    if (list->length == LIST_SIZE) {
        return;
    }
    int i, j;
    for (i = list->length; i > pos; --i) {
        list->elem[i] = list->elem[i - 1];
    }
    list->elem[pos] = e;
    list->length++;
}

void insertOrdered(PSqlList list, int e)
{
    list->elem[length++] = e;
}

void printArrayList(PSqlList list)
{
    int i;
    for (i = 0; i < list->length; ++i) {
        printf("%d\t", list->elem[i]);
    }
    printf("\n");
}
void

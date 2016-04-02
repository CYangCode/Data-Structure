#include "include/List.h"
#include "ArrayList.h"
#include <string.h>


int main()
{
    char * seq = "qre[qrqew(qfaqdsf{faq}rq[ew]fd)reqw]";
    match(seq, strlen(seq));
}

int testArrayList()
{
    PArrayList list = impl();
    int i;
    for (i = 0; i < 20; ++i) {
        insertOrdered(list, i);
    }
    insertToPos(list, 10, 2342);
    printListInfo(list);
    printArrayList(list);
    free(list);
    return 0;
}
int testList()
{
    int i;
	Node * head1 = (Node *)malloc(sizeof(Node));
	Node * head2 = (Node *)malloc(sizeof(Node));
	head1->next = NULL;
	head2->next = NULL;
	for (i = 0; i < 20; i += 2) {
		insert2(head1, i);
	}
	for (i = 1; i < 20; i += 2) {
		insert2(head2, i);
	}
	Node * head = merge(head1, head2);
	removeByData(head, 15);
	print(head);
	release(head1);
	release(head2);
	release(head);
	return 0;
}

#include "List.h"


void insert(Node * head, Node * node) {
	Node * p = head->next;
	head->next = node;
	node->next = p;
}

void insert2(Node * head, int num) {
	Node * p = (Node *)malloc(sizeof(Node));
	p->data = num;
	p->next = NULL;
	insert(head, p);
}

void removeByData(Node * head, int data) {
	Node * p = preSearch(head, data);
	Node * temp = p->next;
	p->next = p->next->next;
	free(temp);
}

void modify(Node * head, int originData, int newData) {
	Node * p = search(head, originData);
	p->data = newData;
}

Node * search(Node * head, int num) {
	Node * p = preSearch(head, num);
	return p->next;
}

Node * preSearch(Node * head, int num) {
	Node * p = NULL;
	Node * pre = NULL;
	for (pre = head, p = head->next; p; pre = pre->next, p = p->next) {
		if (p->data == num) {
			return pre;
		}
	}

	return pre;
}

void release(Node * head) {
	Node * p = head->next;
	Node * pre = head;
	while (p) {
		free(pre);
		pre = p;
		p = p->next;
	}
}

void print(Node * head) {
	Node * p = NULL;
	for (p = head->next; p; p = p->next) {
		printf("%d\t", p->data);
	}
	printf("\n");
}

Node * merge(Node * head1, Node * head2) {
	Node * head = (Node *)malloc(sizeof(Node));
	head->next = NULL;
	Node * p, * q;
	Node * temp = NULL;
	for (p = head1->next, q = head2->next; p && q;) {
		if (p->data > q->data) {
            temp = (Node *)malloc(sizeof(Node));
            temp->data = p->data;
			insert(head, temp);
			p = p->next;
		}
		else {
			temp = (Node *)malloc(sizeof(Node));
            temp->data = q->data;
			insert(head, temp);
			q = q->next;
		}
	}

	while (p){
        temp = (Node *)malloc(sizeof(Node));
        temp->data = p->data;
		insert(head, temp);
        p = p->next;
	}
	while (q){
		temp = (Node *)malloc(sizeof(Node));
        temp->data = q->data;
        insert(head, temp);
		q = q->next;
	}
	return head;
}

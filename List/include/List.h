#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node * next;
} Node;

void insert(Node * head, Node * node);
void insert2(Node * head, int num);
void removeByData(Node * head, int data);
void modify(Node * head, int originData, int newData);
Node * search(Node * head, int num);
Node * preSearch(Node * head, int num);
void release(Node * head);
void print(Node * head);
Node * merge(Node * head1, Node * head2);

#endif // LIST_H

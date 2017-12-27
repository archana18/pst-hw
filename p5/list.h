
#ifndef LIST_H
#define LIST_H

#include "data.h"
#include "list.h"
typedef struct Data Data;
typedef struct Node Node;
struct List
{
	Node *head;
	Node *tail; int ind;
	void (*insert)(struct List *, int, struct Data);
	Data * (*read)(struct List *, int);
	void (*remove)(struct List *, int);
	void (*delete)(struct List *);
	int length;

}l1;

typedef struct List List;


List * newList();
void insertList(List * list, int index, Data value);
void removeData(List * list, int index);
Data * readData(List * list, int index);


#endif

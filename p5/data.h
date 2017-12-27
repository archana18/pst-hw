#ifndef DATA_H
#define DATA_H
struct Data {

	int value;
}d;
typedef struct Data Data;
struct Node
{
	struct Node *prev;
	struct Node *next;
	int id;
	Data data;
}n;
#endif

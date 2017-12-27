#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#include <sys/time.h>
#include <assert.h>
#include "list.h"
#include "data.h"



typedef struct Node Node;
typedef struct Data Data;
typedef struct List List;



//INSERTING ------------------------------------------------------------------------------------------------------------------------------
void insertList(List * list, int index, Data value)
{

	int i=0;
	Node * cNode;
	Node * node = (Node*) malloc(sizeof(Node));
	node->next=NULL;
	node->prev=NULL;
	node->data = value;
	if(list->head == NULL)
	{
		list->head = node;
		list->tail = node;
	}
	else
	{	list->length++;
		cNode=list->head;
		while(i < index)
		{
			if(cNode->next != NULL)
			{
				cNode = cNode->next;
			}
			i++;
		}
		if(cNode->next != NULL)
		{
			node->next = cNode->next;
			node->prev = cNode;
			cNode->next->prev = node;
			cNode->next = node;
		}
		else
		{

			cNode->next = node;
			node->prev = cNode;
			list->tail = node;
		}
	}


}


//SEARCHING---------------------------------------------------------------------------------------------------------------------------------------------------

Data * readData(List * list, int index)
{  
	int i=0;
	int position = 0;
	if(list->head == NULL && list->tail == NULL)
	return NULL;
	else
	{
		Node * cNode=list->head;
		while(i < index)
		{
			if(cNode->next != NULL)
				{
				cNode = cNode->next;
				position++;
				}
			i++;
		}
		if(position < index)
		{
		return NULL;
		}
	
		return &(cNode->data);
	}
}


//REMOVING---------------------------------------------------------------------------------------------------------------------------------------------------
void removeData(List *list , int index)
{
	
	int i=0;
	Node * cNode=(Node*)malloc(sizeof(Node));
	cNode=list->head;
	while(i <=index)
	{
		if(cNode->next != NULL)
		{
			cNode = cNode->next;
		}
		i++;
	}
	if (cNode->prev) {
        cNode->prev->next = cNode->next;
    } else {
        assert(list->head == cNode);
        list->head = cNode->next;
    }

    if (cNode->next) {
        cNode->next->prev = cNode->prev;
    } else {
        assert(list->tail == cNode);
        list->tail = cNode->prev;
    }
    list->length--;
    free(cNode);
}

		
//DELETE---------------------------------------------------------------------------------------------------------------------------------------------------
void deleteList(List * list)
{
  if(list->head == NULL)
  {
    free(list);
    list = NULL;
  }
}



//CREATING---------------------------------------------------------------------------------------------------------------------------------------------------
List * newList()
{
	List *l=(List *)malloc(sizeof(List));
	if(l==NULL) 
	{
	
		fprintf(stderr,"Not enough space in Memory for list\n");
		exit(-1);
	}
	l->head=NULL;
	l->tail=NULL;
	l->insert=insertList;
	l->remove=removeData; 
	l->delete=deleteList;
	l->read=readData;
	l->length=0;
	return l;
	
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#include <sys/time.h>
#include "vector.h"
#include "data.h"

//INSERTING----------------------------------------------------------------------------------------------------------------------------------------

void insertVector(struct Vector * array, int index, Data value)
 {

	if (array->max_size <= index){
		array->max_size = index*2 + 1;
		Data *new_Data = malloc(sizeof(Data) * array->max_size);

		for (int i = 0; i != array->max_size; i++){
			*(new_Data + i) = (Data){-1};
		}
		for (int i = 0; i != array->current_size; i++){
			*(new_Data + i) = *(array->data + i);
		}
		free(array->data);
		array->data = new_Data;
	}
	array->data[index] = value;
	if(index >= array->current_size)
		array->current_size = index+1;
}

//READING---------------------------------------------------------------------------------------------------------------------------------------
Data * vectorRead(struct Vector * array, int index) 
{

	if(index >= array->max_size)
		return NULL;	
	else 
	{
		
		if(array->data[index].value!=0)
			return &array->data[index];
		else
			return NULL;
	}
}


//REMOVING---------------------------------------------------------------------------------------------------------------------------------------
void removeVector(struct Vector * array, int index)
 {

	if(index <array->max_size && array->current_size>=0 ) 
	{
		
		fprintf(stdout,"Deleted value at index %d is : %d\n",index,array->data[index].value);
		array->data[index].value = 0;
		array->current_size--;
	} else
		fprintf(stdout,"Value not present in the Vector\n");	

}

//DELETING----------------------------------------------------------------------------------------------------------------------------------------
void * deleteVector(Vector *v)
{
	
	free(v->data);
	return v;

}
//CREATING----------------------------------------------------------------------------------------------------------------------------------------

Vector * newVector() {

	Vector *vector=malloc(sizeof(Vector));
	
	if(vector==NULL) 
	{
	
		fprintf(stderr,"Not enough space in Memory\n");
		exit(-1);
	}
	
	vector->data=NULL;
	vector->max_size=0;
	vector->current_size=0;
	vector->insert=insertVector;
	vector->remove=removeVector;
	vector->delete=deleteVector;
	vector->read=vectorRead;
	return vector;
}








#ifndef VECTOR_H
#define VECTOR_H


#include "data.h"
typedef struct Data Data;
typedef struct Node Node;
typedef struct Vector Vector;

typedef struct List List;
struct Vector {

	Data *data;
	unsigned int current_size;
	unsigned int max_size;
	void (*insert)(struct Vector * array, int index, Data value);
	Data * (*read)(struct Vector * array, int index);
	void (*remove)(struct Vector * array, int index);
	void (*delete)(struct Vector * array);

}x;

typedef struct Vector Vector;

Vector *newVector();
void insertVector(Vector *array, int index, Data value);
void removeVector(Vector *array, int index);
Data *readVector(Vector *array, int index);
void *deleteVector(Vector *array);

#endif

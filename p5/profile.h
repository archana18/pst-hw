#ifndef PROFILE_H
#define PROFILE_H

#include "data.h"
#include "vector.h"
#include "list.h"

typedef struct Data Data;
typedef struct Node Node;
typedef struct Vector Vector;

typedef struct List List;

struct timeval start1,start2,start3, start4,start5,start6, stop1,stop2, stop3,stop4,stop5,stop6;


void profileInsert(Vector *v, List *l);
void profileRead(Vector *v, List *l);
void profileRemove(Vector *v, List *l);

#endif

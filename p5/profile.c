#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#include <sys/time.h>
#include "list.h"
#include "data.h"
#include "profile.h"
typedef struct Data Data;
typedef struct Node Node;
typedef struct Vector Vector;
typedef struct List List;


struct timeval start1,start2,start3, start4,start5,start6, stop1,stop2, stop3,stop4,stop5,stop6;




//INSERTING------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void profileInsert(Vector *v, List *l)
{
	int i=1;
	gettimeofday(&start1, NULL);
	for(i=1;i<=1000;i++)
	{
		Data data1;
		data1.value=i;
		insertVector(v,i,data1);
		
	}
	gettimeofday(&stop1, NULL);
	time_t start_time1 = (start1.tv_sec* 1000000) + start1.tv_usec;
	time_t stop_time1 = (stop1.tv_sec* 1000000) + stop1.tv_usec;
	float profile_time1 = stop_time1 - start_time1;
	fprintf(stdout,"insert vector:%f\t", profile_time1);


	gettimeofday(&start2, NULL);
	for(i=1;i<=1000;i++)
	{
		Data data2;
		
		data2.value=i;
		insertList(l,i,data2);
		
		
	}
	gettimeofday(&stop1, NULL);
	time_t start_time2 = (start2.tv_sec* 1000000) + start2.tv_usec;
	time_t stop_time2 = (stop2.tv_sec* 1000000) + stop2.tv_usec;
	float profile_time2 = stop_time2 - start_time2;
	fprintf(stdout,"insert list:%f\n", profile_time2);
}


//READING---------------------------------------------------------------------------------------------------------------------------------------------------
void profileRead(Vector *v, List *l)
{
	int i=1,m;
	gettimeofday(&start3, NULL);
	for(i=1;i<=100;i++)
	{	
		m=rand()%1000;
		Data *vdata=malloc(sizeof(Data));
		vdata=vectorRead(v,m);

	}
	gettimeofday(&stop3, NULL);
	time_t start_time3 = (start3.tv_sec* 1000000) + start3.tv_usec;
	time_t stop_time3 = (stop3.tv_sec* 1000000) + stop3.tv_usec;
	float profile_time3 = stop_time3 - start_time3;
	fprintf(stdout,"read vector:%f\t", profile_time3);
	gettimeofday(&start3, NULL);
	for(i=1;i<=100;i++)
	{	
		m=rand()%1000;
		Data *ldata=malloc(sizeof(Data));
		ldata=readData(l,m);

	}
	gettimeofday(&stop4, NULL);
	time_t start_time4 = (start4.tv_sec* 1000000) + start4.tv_usec;
	time_t stop_time4 = (stop4.tv_sec* 1000000) + stop4.tv_usec;
	float profile_time4 = stop_time4 - start_time4;
	fprintf(stdout,"read list:%f\t", profile_time4);

}


//REMOVING---------------------------------------------------------------------------------------------------------------------------------------------------
void profileRemove(Vector *v, List *l)
{
	int i=1,m;
	gettimeofday(&start5, NULL);
	for(i=1;i<=100;i++)
	{	
		m=rand()%1000;
		removeVector(v,m);

	}
	gettimeofday(&stop4, NULL);
	time_t start_time5 = (start5.tv_sec* 1000000) + start5.tv_usec;
	time_t stop_time5 = (stop5.tv_sec* 1000000) + stop5.tv_usec;
	float profile_time5 = stop_time5 - start_time5;
	fprintf(stdout,"remove vector:%f\t", profile_time5);
	gettimeofday(&start6, NULL);
	for(i=1;i<=100;i++)
	{	
		m=rand()%1000;
		removeData(l,m);
	}
	gettimeofday(&stop5, NULL);
	time_t start_time6 = (start6.tv_sec* 1000000) + start6.tv_usec;
	time_t stop_time6 = (stop6.tv_sec* 1000000) + stop6.tv_usec;
	float profile_time6 = stop_time6 - start_time6;
	fprintf(stdout,"remove list:%f\t", profile_time6);
}



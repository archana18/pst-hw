#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#pragma GCC diagnostic ignored "-Wreturn-local-addr"
#pragma GCC diagnostic ignored "-Wfree-nonheap-object"

void f1(){
	int s[3];
	int *a;
	a =(int *) malloc(sizeof(s));
	for (int i = 0; i <3; i++){
		a[i] = i; 
	} free(a);
}

int * f2(){
	int a[10]; int i=0;
	for (i = 0; i <=9; i++){
		a[i] = i;
	}
	for (i = 0; i < 10; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
	return a;
}

int f3(){
	char l[11];
	char *cptr;
	cptr = (char *) malloc(sizeof(l)); 
	cptr[10] = 'a';
	char *junk =0;
	if(junk == 0){
		printf("Junk is zero.");
	}
	free(junk); 
	free(cptr);
	return 0;
}

/** DO NOT ALTER THE MAIN FUNCTION **/

int main(){
f1();
f2();
f3();
}

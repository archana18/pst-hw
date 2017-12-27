
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 32
int myStrStr(char haystack[], char needle[], char buffer[]);
void binaryArray(int n, int array[], int size);
void binaryPrinter(int array[], int size);
unsigned int countOnes(int num);
char *haystack_ptr, *needle_ptr; int bin[255];
void convert(int num);






  

//part1


int myStrStr(char haystack[],char needle[],char buffer[])
{
    memset(buffer,'\0', 255);  int flag;
    char *temp_mem=(char *)  malloc(sizeof(char));
    haystack_ptr=haystack; 
    needle_ptr=needle;
    while(*haystack_ptr!='\0',*needle_ptr!='\0')
    {   
        
        if(*haystack_ptr != *needle_ptr && *haystack_ptr!='\0'  &&  *needle_ptr!='\0' ) 
        {   flag=0;
            haystack_ptr++;    
                        
        }
        else if (*needle_ptr == *haystack_ptr  && *haystack_ptr!='\0'  &&  *needle_ptr!='\0')
        {   flag++;
            *temp_mem=*haystack_ptr;
            strcat(buffer,temp_mem);
            haystack_ptr++;
            needle_ptr++;   

        }          
        else return 0;
    
    }
    //puts(buffer);
  
    if(*needle_ptr=='\0' ) 
        return 1;
    return 0;
}




//part 2

/*   
void convert(int num)
{
   
    while (num > 0)
    {
        int i=0; 
        //unsigned int mask=32768;   //mask = [1000 0000 0000 0000]

        while (num > 0) 
        {
    
    
    		bin[i] = num % 2;
    		num = num / 2;
    		i++;
        }
        
     }
}    
 */

void binaryArray(int n, int array[], int size)
{
    int i=0,j;
	while(size)
	{
		j= n >> size-1;
		if(j & 1)
		array[i]=1;
		else
		array[i]=0;
		i++;
		size--;
	}

}


unsigned int countOnes(int num)
{
    int i=0,j;
    unsigned int count=0;
    
    
    for (j = SIZE-1; j >= 0; j--)
    {
        bin[j] = num >> j;
        if (bin [j] & 1)
            bin[j] = 1;
        else
            bin[j] = 0;
    }
    for(i=SIZE-1;i>=0;i--)
    {
        if(bin[i]==1)
            count++;
        
    }
    
    return (count);


}


void binaryPrinter(int array[], int size)
{
    int i;
	for(i = 0; i <= size; i++)
    {
        if(i%4 == 0)
            printf(" ");
        printf("%d", array[i]);
    }
    printf("\n");

}           

    
    





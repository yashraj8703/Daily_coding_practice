#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 10
typedef struct
{
    int num;
    int status;
} myList;

myList arr1[TABLE_SIZE];
void init()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        arr1[i].status = 0;
    }
}

int hashFunction(int num)
{
    return num % TABLE_SIZE;
}

void inser(int num)
{
    int index=hashFunction(num);
    int currIdx=index;
    while (arr1[currIdx].status != 0)
    {
        currIdx = (currIdx + 1) % TABLE_SIZE;
        if (currIdx == index)
        {
            printf("Hash table is full!\n");
            return;
        }
    }
    arr1[currIdx].num = num;
    arr1[currIdx].status = 1;
}

int compare(int a)
{
    int index=hashFunction(a);
    int currIdx=index;
    while (arr1[currIdx].status!=0)
    {
        if(arr1[currIdx].status==1 && arr1[currIdx].num==a)
        {
            // printf("Element %d found in hash table\n", a);
            return 1;
        }
        if(currIdx==index)
        {
            break;
        }
    }
    return 0;
       
}
int areArraysSame(int a1[], int a2[], int size)
{
    for (int i = 0; i < size; i++)
    {
        inser(a1[i]);
    }

    for (int i = 0; i < size; i++)
    {
        if (!compare(a2[i])) 
        {
            return 0;
        }
    }
    return 1; 
}
int main()
{
    init();
    int a1[5]={1,2,3,4,5};
    int a2[5]={4,2,1,5,0};
    for(int i=0;i<5;i++)
    {
        inser(a1[i]);
    }
    if(areArraysSame(a1,a2,5))
    {
        printf("same\n");
    }
    else{
        printf("not same\n");
    }
    
}
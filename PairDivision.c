#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 10
typedef struct
{
    int num;
    int status;
} Numbers;

Numbers hashtable[TABLE_SIZE];

void init()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashtable[i].status = 0;
    }
}

int hashFunction(int num)
{
    return num % TABLE_SIZE;
}

void insert(int num)
{
    int index = hashFunction(num);
    int currIdx = index;
    while (hashtable[currIdx].status != 0)
    {
        currIdx = (currIdx + 1) % TABLE_SIZE;
        if (currIdx == index)
        {
            return;
        }
    }
    hashtable[currIdx].num = num;
    hashtable[currIdx].status = 1;
}
int search(int num)
{
    int index = hashFunction(num);
    int currIdx = index;
    while (hashtable[currIdx].status != 0)
    {
        if (hashtable[currIdx].status == 1 && hashtable[currIdx].num==num)
        {
            return hashtable[currIdx].num;
        }
        currIdx = (currIdx + 1) % TABLE_SIZE;
        if (currIdx == index)
        {
            break;
        }
    }
   return -1;
}

void pairDivision(int k)
{
    for(int i=0;i<TABLE_SIZE;i++)
    {
        if(hashtable[i].status==1)
        {
            int num1=hashtable[i].num;
            int num2=(k - num1 % k) % k;
            if (num1 != num2 && search(num2) != -1) {
                printf("Pair found: %d and %d\n", num1, num2);
            }
        }
    }
}
int main()
{
    init();
    int arr[4]={9,7,5,3};
    int k=6;
    for(int i=0;i<4;i++)
    {
        insert(arr[i]);
    }
    pairDivision(k);
}
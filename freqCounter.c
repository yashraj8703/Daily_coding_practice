#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TABLE_SIZE 100

typedef struct
{
    char ch;
    int frequency;
    int status;
} StringHash;

StringHash hashTable[TABLE_SIZE];

void init()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashTable[i].status = 0;
        hashTable[i].frequency = 0;
    }
}

int hashFunction(char ch)
{
    return ch % TABLE_SIZE;
}

void add(char ch)
{
    int index=hashFunction(ch);
    int currIdx=index;
    if(hashTable[currIdx].status==1 && hashTable[currIdx].ch==ch)
    {
        hashTable[currIdx].frequency++;
        return;
    }
    while(hashTable[currIdx].status!=0)
    {
        currIdx=(currIdx+1)%TABLE_SIZE;
        if(currIdx==index)
        {
            return;
        }
    }
    hashTable[currIdx].frequency++;
    hashTable[currIdx].status=1;
    hashTable[currIdx].ch=ch;
}

void printTable()
{
    for(int i=0;i<TABLE_SIZE;i++)
    {
        if(hashTable[i].status==1)
        {
            printf("{%c:%d}, ",hashTable[i].ch,hashTable[i].frequency);
        }
    }
}

void printHashfreq()
{
    int l=0;
    for(int i=0;i<TABLE_SIZE;i++)
    {
        if(hashTable[i].status==1)
        {
            l++;
        }
    }
    printf("%d\n",l);
}

int main()
{
    init();
    char s[100]="aabbc";
    for(int i=0;s[i]!='\0';i++)
    {
        add(s[i]);
    }
    printTable();
    printHashfreq();
}


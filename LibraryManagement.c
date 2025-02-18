#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TABLE_SIZE 100

typedef struct
{
    char book[50];
    int availability;
    int status; // 0 - Available 1- Borrowed
} Library;

Library hashTable[TABLE_SIZE];

void init()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashTable[i].status = 0;
        hashTable[i].availability = 0;
    }
}

int hashFunction(char book[])
{
    int hashval = 0;
    for (int i = 0; book[i] != '\0'; i++)
    {
        hashval += book[i];
    }
    return hashval % TABLE_SIZE;
}

void addBook(char book[])
{
    int index=hashFunction(book);
    int currIdx=index;
    while(hashTable[currIdx].status!=0)
    {
        currIdx=(currIdx+1)%TABLE_SIZE;
        if(currIdx==index)
        {
            return;
        }
    }
    strcpy(hashTable[currIdx].book,book);
    hashTable[currIdx].status = 1;
    hashTable[currIdx].availability = 0;
}

void BorrowBook(char book[])
{
    int index=hashFunction(book);
    int currIdx=index;
    while(hashTable[currIdx].status!=0)
    {
        if(hashTable[currIdx].status==1 && strcmp(hashTable[currIdx].book,book)==0)
        {
            if(hashTable[currIdx].availability==0)
            {
                hashTable[currIdx].availability=1;
                return;
            }
            
        }
        currIdx=(currIdx+1)%TABLE_SIZE;
        if(currIdx==index)
        {
            return;
        }
    }
}
void ReturnBook(char book[])
{
    int index=hashFunction(book);
    int currIdx=index;
    while(hashTable[currIdx].status!=0)
    {
        if(hashTable[currIdx].status==1 && strcmp(hashTable[currIdx].book,book)==0)
        {
            if(hashTable[currIdx].availability==1)
            {
                hashTable[currIdx].availability=0;
                return;
            }
            
        }
        currIdx=(currIdx+1)%TABLE_SIZE;
        if(currIdx==index)
        {
            return;
        }
    }
}
void Query(char book[])
{
    int index=hashFunction(book);
    if(hashTable[index].status==1 && strcmp(hashTable[index].book,book)==0)
    {
        if(hashTable[index].availability==0)
        {
            printf("Book is Available\n");
        }
        else{
            printf("Book is Not Available\n");
        }
    }
    else{
        printf("Book Not found\n");
    }
}
int main()
{
    init();
    addBook("Gulliver's travel");
    addBook("pride and Prejudice");
    addBook("harry potter");
    Query("pride and Prejudice");
    BorrowBook("pride and Prejudice");
    Query("pride and Prejudice");
    ReturnBook("pride and Prejudice");
    Query("pride and Prejudice");
    Query("Gulliver's travel");
}
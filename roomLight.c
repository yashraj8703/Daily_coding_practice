#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct Node
{
    char room[50];
    int status;
    struct Node *next;
} Node;

typedef struct HashMap
{
    Node *head;
} HashMap;

Node *createNode(char room[])
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->room,room);
    newNode->status = 0;
    newNode->next = NULL;
    return newNode;
}

void init(HashMap *hashTable)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashTable[i].head = NULL;
    }
}

int hashFunction(char room[])
{
    int hashval=0;
    for(int i=0;room[i]!='\0';i++)
    {
        hashval+=room[i];
    }
    return hashval % TABLE_SIZE;
}

void add(HashMap *hashTable, char room[])
{
    int index = hashFunction(room);
    Node *newNode = createNode(room);
    if (hashTable[index].head == NULL)
    {
        hashTable[index].head = newNode;
    }
    else
    {
        newNode->next = hashTable[index].head;
        hashTable[index].head = newNode;
    }
}
void TurnOffOn(HashMap *hashTable, char room[])
{
    int index = hashFunction(room);
    if (hashTable[index].head == NULL)
    {
        printf("No room found\n");
        return;
    }
    Node* temp=hashTable[index].head;
    while(temp)
    {
        if(strcmp(temp->room,room)==0)
        {
            if(temp->status==0)
            {
                temp->status=1;
            }
            else
            {
                temp->status=0;
            }
            return;
        }
        temp=temp->next;
    }
    printf("no room found\n");
}
void roomstatus(HashMap *hashTable, char room[])
{
    int index = hashFunction(room);
    if (hashTable[index].head == NULL)
    {
        printf("No room found\n");
        return;
    }
    Node* temp=hashTable[index].head;
    while(temp)
    {
        if(strcmp(temp->room,room)==0)
        {
            if(temp->status==0)
            {
                printf("light is off\n");
            }
            else
            {
                printf("light is on\n");
            }
        return;
        }
        temp=temp->next;
    }
    printf("no room found\n");
}

int main()
{
    HashMap *table = (HashMap *)malloc(TABLE_SIZE * sizeof(HashMap));
    init(table);
    add(table,"bedroom");
    add(table,"kitchen");
    add(table,"hall");
    add(table,"bathrooom");
    TurnOffOn(table,"bedroom");
    roomstatus(table,"bedroom");
}
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define TABLE_SIZE 10

typedef struct Node
{
    char name[50];
    int Quantity;
    struct Node* next;
}Node;

typedef struct HashMap{
    Node* head;
}HashMap;

Node* createNode(char name[50],int Quantity)
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    strcpy(newNode->name,name);
    newNode->Quantity=Quantity;
    newNode->next=NULL;
    return newNode;
}

void init(HashMap* hashTable)
{
    for(int i=0;i<TABLE_SIZE;i++)
    {
        hashTable[i].head=NULL;
    }
}

int hashFunction(char name[])
{
    int hashVal=0;
    for (int i = 0; name[i]!='\0'; i++)
    {
        hashVal+=name[i];
    }
    return hashVal%TABLE_SIZE;    
}

void add(HashMap* hashTable, char name[],int Quantity)
{
    int index=hashFunction(name);
    Node* newNode=createNode(name,Quantity);
    if(hashTable[index].head==NULL)
    {
        hashTable[index].head=newNode;
    }
    else
    {
        Node* curr=hashTable[index].head;
        while (curr)
        {
            if(strcmp(curr->name,name)==0)
            {
                curr->Quantity+=Quantity;
                return;
            }
            curr=curr->next;
        }
        newNode->next=hashTable[index].head;
        hashTable[index].head=newNode;
    }
}

void update(HashMap* hashTable,char name[],int Quantity)
{
    int index=hashFunction(name);
    if(hashTable[index].head==NULL)
    {
        printf("No item Found\n");
        return;
    }
    Node* curr=hashTable[index].head;
    while(curr)
    {
        if(strcmp(curr->name,name)==0)
        {
            curr->Quantity=Quantity;
            return;
        }
        curr=curr->next;
    }
}

void Query(HashMap* hashTable,char name[])
{
    int index=hashFunction(name);
    if(hashTable[index].head==NULL)
    {
        printf("No item Found\n");
        return;
    }
    Node* curr=hashTable[index].head;
    while(curr)
    {
        if(strcmp(curr->name,name)==0)
        {
            printf("%d\n",curr->Quantity);
            return;
        }
        curr=curr->next;
    }
    printf("item Not found\n");
}

void printTable(HashMap *table)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (table[i].head != NULL)
        {
            printf("%d : ",i);
            Node *temp = table[i].head;
            while (temp)
            {
                printf("{%s %d}->", temp->name,temp->Quantity);
                temp = temp->next;
            }
            printf("NULL\n");
        }
    }
    
}
int main()
{
    HashMap* table1=(HashMap*)malloc(TABLE_SIZE*sizeof(HashMap));
    init(table1);
    add(table1,"pen",10);
    add(table1,"book",13);
    add(table1,"pencil",23);
    add(table1,"eraser",56);
    add(table1,"pen",30);
    update(table1,"pen",100);
    Query(table1,"eraser");
    Query(table1,"efwd");
    printTable(table1);

}
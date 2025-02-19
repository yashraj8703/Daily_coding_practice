#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define TABLE_SIZE 100

typedef struct Node{
    char name[100];
    int phoneNum;
    struct Node* next;
}Node;

typedef struct HashMap{
    Node* head;
}HashMap;

int hashFunction(char name[])
{
    int hashVal=0;
    for (int i = 0; name[i]!='\0'; i++)
    {
        hashVal+=name[i];
    }
    return hashVal%TABLE_SIZE;    
}

void init(HashMap* table)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        table[i].head=NULL;
    }
}

Node* createNode(char name[],int phoneNum)
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    strcpy(newNode->name,name);
    newNode->phoneNum=phoneNum;
    newNode->next=NULL;
    return newNode;
}

void add(HashMap* table, char name[],int phoneNum)
{
    int index = hashFunction(name);
    Node* newNode = createNode(name, phoneNum);
    if (table[index].head == NULL) {
        table[index].head = newNode;
    } else {
        Node* curr = table[index].head;
        while (curr) {
            if (strcmp(curr->name, name) == 0) {
                curr->phoneNum=phoneNum;
                return;
            }
            curr = curr->next;
        }
        newNode->next = table[index].head;
        table[index].head = newNode;
    }
}

void search(HashMap* table, char name[])
{
    int index=hashFunction(name);
    if(table[index].head==NULL)
    {
        printf("Not available\n");
        return;
    }
    else{
        Node* curr=table[index].head;
        while (curr)
        {
            if(strcmp(curr->name,name)==0)
            {
                printf("found\n");
                return;
            }
            curr=curr->next;
        }
        printf("Not available\n");
    }
}

void delete(HashMap* table, char name[])
{
    int index=hashFunction(name);
    if(table[index].head==NULL)
    {
        printf("Not available\n");
        return;
    }
    else{
        Node* curr=table[index].head;
        Node* prev=NULL;
        while (curr)
        {
            if(strcmp(curr->name,name)==0)
            {
                if(prev==NULL)
                {
                    table[index].head=table[index].head->next;
                    return;
                }
                else{
                    prev->next=curr->next;
                    free(curr);
                    return;
                }
            }
            curr=curr->next;
        }
        printf("Not available\n");
    }
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
                printf("{%s %d}->", temp->name,temp->phoneNum);
                temp = temp->next;
            }
            printf("NULL\n");
        }
    }
    
}

int main()
{
    HashMap* table=malloc(TABLE_SIZE*sizeof(HashMap));
    init(table);
    add(table,"yash",123);
    add(table,"yash",345);
    add(table,"sourabh",987);
    add(table,"shubh",121);
    add(table,"vivek",3432);
    // delete(table,"yash");
    // search(table,"yash");
    printTable(table);
}
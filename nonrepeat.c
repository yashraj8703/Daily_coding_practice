#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define TABLE_SIZE 100

typedef struct Node{
    char name[100];
    int freq;
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

Node* createNode(char name[])
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    strcpy(newNode->name,name);
    newNode->freq=1;
    newNode->next=NULL;
    return newNode;
}

void add(HashMap* table, char name[])
{
    int index = hashFunction(name);
    Node* newNode = createNode(name);
    if (table[index].head == NULL) {
        table[index].head = newNode;
    } else {
        Node* curr = table[index].head;
        while (curr) {
            if (strcmp(curr->name, name) == 0) {
                curr->freq+=1;
                return;
            }
            curr = curr->next;
        }
        newNode->next = table[index].head;
        table[index].head = newNode;
    }
}

int searchTable(HashMap* table, char name[])
{
    int index=hashFunction(name);
    if(table[index].head==NULL)
    {
        printf("Not available\n");
        return 0;
    }
    else{
        Node* curr=table[index].head;
        while (curr)
        {
            if(strcmp(curr->name,name)==0)
            {
                if(curr->freq==1)
                {
                    return 1;
                }
            }
            curr=curr->next;
        }
    }
    return 0;
}
void freqRepeat(HashMap* hashTable,char s[100][100])
{
    for(int i=0;i<9;i++)
    {
        if(searchTable(hashTable,s[i]))
        {
            printf("%s",s[i]);
            break;
        }
    }
}
// void printTable(HashMap *table)
// {
//     for (int i = 0; i < TABLE_SIZE; i++)
//     {
//         if (table[i].head != NULL)
//         {
//             printf("%d : ",i);
//             Node *temp = table[i].head;
//             while (temp)
//             {
//                 printf("{%s %d}->", temp->name,temp->phoneNum);
//                 temp = temp->next;
//             }
//             printf("NULL\n");
//         }
//     }
    
// }t

int main()
{
    HashMap* table=malloc(TABLE_SIZE*sizeof(HashMap));
    init(table);
    char s[9][100]={"this","is","a","test","this","is","only","a","test"};
    add(table,"this");
    add(table,"is");
    add(table,"a");
    add(table,"test");
    add(table,"this");
    add(table,"is");
    add(table,"only");
    add(table,"a");
    add(table,"test");
    freqRepeat(table,s);

}
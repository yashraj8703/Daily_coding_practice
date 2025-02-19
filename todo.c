#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct Node
{
    char name[50];
    int status;
    struct Node *next;
} Node;

typedef struct HashMap
{
    Node *head;
} HashMap;

Node *createNode(char name[50], int Quantity)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->status = Quantity;
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

int hashFunction(int randomVal)
{
    return randomVal % TABLE_SIZE;
}

void add(HashMap *hashTable, char name[], int val)
{
    int index = hashFunction(val);
    Node *newNode = createNode(name, 0);
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

void complete(HashMap *hashTable, char name[], int val)
{
    int index = hashFunction(val);
    if (hashTable[index].head == NULL)
    {
        printf("No task found\n");
        return;
    }
    Node *curr = hashTable[index].head;
    while (curr)
    {
        if (strcmp(curr->name, name) == 0)
        {
            curr->status = 1;
            return;
        }
        curr = curr->next;
    }
    printf("No task Found\n");
}

void PendingTask(HashMap *hashTable)
{
    int found = 0;
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        Node *temp = hashTable[i].head;
        while (temp)
        {
            if (temp->status == 0) // Check for pending task
            {
                printf("Pending Task: %s\n", temp->name);
                found = 1;
            }
            temp = temp->next;
        }
    }
    if (!found) // If no pending tasks are found
    {
        printf("No pending tasks.\n");
    }
}


int main()
{
    HashMap *hashTable = (HashMap *)malloc(TABLE_SIZE * sizeof(HashMap));
    init(hashTable);
    add(hashTable, "stacks", 1);
    add(hashTable, "Linked List", 2);
    add(hashTable, "HashMap", 3);
    add(hashTable, "Queue", 4);
    add(hashTable, "Matrix", 5);
    // PendingTask(hashTable);
    complete(hashTable, "stacks", 1);
    complete(hashTable, "Linked List", 2);
    PendingTask(hashTable);
}
#include <stdio.h>
#include <stdlib.h>
#define n 10
typedef struct Node
{
    int key;   // unique key to search the value
    int value; //
    struct Node *next;
} Node;

typedef struct hashMap
{
    Node *head;
} hashMap;

int hashFunction(int key)
{
    return key % n;
}

void add(hashMap *table, int key, int value)
{
    int index = hashFunction(key);
    Node *newNode = malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    if (table[index].head == NULL)
    {
        table[index].head = newNode;
    }
    else
    {
        newNode->next = table[index].head;
        table[index].head = newNode;
    }
}
void search(hashMap *table, int key)
{
    int index = hashFunction(key);
    if (table[index].head == NULL)
    {
        printf("no value\n");
    }
    else
    {
        Node *temp = table[index].head;
        while (temp)
        {
            if (temp->key == key)
            {
                printf("Value is %d\n", temp->value);
                return;
            }
            temp = temp->next;
        }
        printf("Not available\n");
    }
}
void delete(hashMap *table, int key)
{
    int index = hashFunction(key);
    if (table[index].head == NULL)
    {
        printf("no value\n");
    }
    else
    {
        Node *temp = table[index].head;
        Node *prev = NULL;
        while (temp)
        {
            if (temp->key == key)
            {
                if (prev == NULL)
                {
                    table[index].head = table[index].head->next;
                    return;
                }
                else
                {
                    prev->next = prev->next->next;
                    return;
                }
            }
            temp = temp->next;
        }
        printf("Not available\n");
    }
}

void printTable(hashMap *table)
{
    for (int i = 0; i < n; i++)
    {
        // if (table[i].head != NULL)
        // {
            printf("%d : ",i);
            Node *temp = table[i].head;
            while (temp)
            {
                printf("{%d %d}->", temp->key,temp->value);
                temp = temp->next;
            }
            printf("NULL\n");
        // }
    }
    
}
int main()
{
    hashMap *table = malloc(n * sizeof(hashMap));
    for (int i = 0; i < n; i++)
    {
        table[i].head = NULL;
    }
    add(table, 1, 2);
    add(table, 4, 8);
    add(table, 5, 87);
    add(table, 445, 86);
    printTable(table);
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct Node
{
    char data;
    int frequency;
    struct Node *next;
} Node;

typedef struct HashMap
{
    Node *head;
} HashMap;

Node *createNode(char data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->frequency = 1;
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

int hashFunction(char data)
{
    return data % TABLE_SIZE;
}

void add(HashMap *hashTable, char data)
{
    int index = hashFunction(data);
    Node *newNode = createNode(data);
    if (hashTable[index].head == NULL)
    {
        hashTable[index].head = newNode;
    }
    else
    {
        Node *curr = hashTable[index].head;
        while (curr)
        {
            if (curr->data == data)
            {
                curr->frequency += 1;
                return;
            }
            curr = curr->next;
        }
        newNode->next = hashTable[index].head;
        hashTable[index].head = newNode;
    }
}
void delete(HashMap *hashTable, char data)
{
    int index = hashFunction(data);
    if (hashTable[index].head == NULL)
    {
        return;
    }
    Node *curr = hashTable[index].head;
    Node *prev = NULL;
    while (curr)
    {
        if (curr->data == data)
        {
            if (prev == NULL)
            {
                hashTable[index].head = hashTable[index].head->next;
            }
            else
            {
                prev->next = curr->next;
            }
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}
void removedata(HashMap *hashTable, char data)
{
    int index = hashFunction(data);
    Node *curr = hashTable[index].head;
    while (curr)
    {
        if (curr->data == data)
        {
            curr->frequency -= 1;
            if (curr->frequency == 0)
            {
                delete (hashTable, data);
            }
            return;
        }
        curr = curr->next;
    }
}

void printTable(HashMap *table)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (table[i].head != NULL)
        {
            printf("%d : ", i);
            Node *temp = table[i].head;
            while (temp)
            {
                printf("{%c %d}->", temp->data, temp->frequency);
                temp = temp->next;
            }
            printf("NULL\n");
        }
    }
}

int hashCount(HashMap *hashTable)
{
    int c = 0;
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hashTable[i].head != NULL)
        {
            c++;
        }
    }
    return c;
}
int maxi(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
void slidingWindow(HashMap *hashTable, char s[], int k)
{
    int l = 0;
    int r = 0;
    int max_count = 0;
    while (r < strlen(s))
    {
        add(hashTable, s[r]);
        while (hashCount(hashTable) > k)
        {
            removedata(hashTable, s[l]);
            l++;
        }
            max_count = maxi(max_count, r - l + 1);
        r++;
    }
    printf("%d", max_count);
}
int main()
{
    HashMap *table = (HashMap *)malloc(TABLE_SIZE * sizeof(HashMap));
    init(table);
    char s[100] = "gtgtggaabbbbbbbbfc";
    slidingWindow(table, s, 2);
}
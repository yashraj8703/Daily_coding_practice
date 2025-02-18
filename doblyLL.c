#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LEN 1024

typedef struct Node
{
    char data[MAX_URL_LEN];
    struct Node *next;
    struct Node *previous;
} Node;

Node *createList(char data[])
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;
    newNode->previous = NULL;
    return newNode;
}

void insertathead(Node **head, Node **tail, char data[])
{
    Node *newNode = createList(data);
    if (*head != NULL)
    {
        newNode->next = *head;
        (*head)->previous = newNode;
    }
    else
    {
        *head = *tail = newNode;
    }
    *head = newNode;
}

void insertattail(Node **head, Node **tail, char data[])
{
    Node *newNode = createList(data);
    if (*tail != NULL)
    {
        (*tail)->next = newNode;
        newNode->previous = *tail;
        *tail = newNode;
    }
    else
    {
        *head = *tail = newNode;
    }
}

int len(Node *head, Node *tail)
{
    int l = 0;
    Node *temp = head;
    while (temp)
    {
        l++;
        temp = temp->next;
    }
    return l;
}

void insertK(Node **head, Node **tail, char data[], int k)
{
    Node *newNode = createList(data);
    if (k < 1)
    {
        printf("Invalid position.\n");
        return;
    }

    int l = len(*head, *tail);
    if (k > l + 1)
    {
        printf("Invalid position.\n");
        return;
    }

    if (k == 1)
    {
        insertathead(head, tail, data);
        return;
    }

    if (k == l + 1)
    {
        insertattail(head, tail, data);
        return;
    }

    Node *temp = *head;
    for (int i = 1; i < k - 1; i++)
    {
        temp = temp->next;
    }
    Node *prevNode = temp;
    Node *nextNode = temp->next;

    prevNode->next = newNode;
    newNode->previous = prevNode;
    newNode->next = nextNode;
    if (nextNode != NULL)
        nextNode->previous = newNode;
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        printf("%s->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void navigateForward(Node** head,Node** tail,Node** current)
{
    if(*current==NULL || (*current)->next==NULL)
    {
        return;
    }
    *current=(*current)->next;
    printf("Navigated to: %s\n", (*current)->data);
}
void navigateBackward(Node** head,Node** tail,Node** current)
{
    if(*current==NULL || (*current)->previous==NULL)
    {
        return;
    }
    *current=(*current)->previous;
    printf("Navigated to: %s\n", (*current)->data);
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    Node *current = NULL;

    insertathead(&head, &tail, "https://google.com");
    insertathead(&head, &tail, "https://yahoo.com");
    insertathead(&head, &tail, "https://example.com");

    current = head;

    printf("Current History: ");
    printList(head);
    navigateForward(&head,&tail,&current);
    navigateBackward(&head,&tail,&current);

    return 0;
}

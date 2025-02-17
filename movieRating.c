#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char movieName[50];
    int rating;
    int ratedAt;
    struct Node* next;
} Node;

Node* createNode(char name[], int rating, int time)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->rating = rating;
    strcpy(newNode->movieName, name);
    newNode->ratedAt = time;
    newNode->next = NULL;
    return newNode;
}

void insert(Node** head, char name[], int rating, int time)
{
    // Node* newNode = createNode(name, rating, time);
    // if (*head == NULL)
    // {
    //     *head = newNode;
    //     return;
    // }

    // Node* temp = *head;
    // while (temp->next != NULL)
    // {
    //     temp = temp->next;
    // }
    // temp->next = newNode;
    ////////////////////////////////////
    if (*head == NULL)
    {
        *head = createNode(name, rating, time);
        return;
    }

    Node* temp = *head;
    
    while (temp != NULL)
    {
        if (strcmp(temp->movieName, name) == 0)
        {
            temp->rating = rating;
            temp->ratedAt = time;
            return;
        }
        temp = temp->next;
    }
    
    Node* newNode = createNode(name, rating, time);
    temp = *head;
    
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(Node* head)
{
    if (head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL)
    {
        printf("{Movie: %s, Rating: %d, Rated At: %d}\n", temp->movieName, temp->rating, temp->ratedAt);
        temp = temp->next;
    }
    printf("NULL\n");
}
void RemoveRating(Node** head,char name[])
{
    if(*head==NULL)
    {
        return;
    }
    Node* dummy=createNode("NULL",-1,-1);
    dummy->next=*head;
    Node* temp=dummy;
    while(temp->next)
    {
        if(strcmp(temp->next->movieName,name)==0)
        {
            temp->next=temp->next->next;
        }
        temp=temp->next;
    }
    *head=dummy->next;
}
void Top(Node* head)
{
    if (head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }
    Node* curr = head;
    Node* topMovie = curr;
    
    while (curr != NULL)
    {
        if (curr->rating > topMovie->rating || 
            (curr->rating == topMovie->rating && curr->ratedAt < topMovie->ratedAt))
        {
            topMovie = curr;
        }
        curr = curr->next; 
    }
    printf("Top Movie: {Movie: %s, Rating: %d, Rated At: %d}\n", 
           topMovie->movieName, topMovie->rating, topMovie->ratedAt);
}

int main()
{
    Node* head = NULL;
    insert(&head, "Tiger3", 7, 1);
    insert(&head, "Pathan", 8, 2);
    insert(&head, "Airlift", 9, 5);
    printf("Movie List:\n");
    printList(head);
    RemoveRating(&head,"Tiger3");
    printList(head);
    Top(head);
    return 0;
}

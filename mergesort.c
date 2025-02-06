#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node
{
    char name[100];
    int marks;
    int roll;
    struct Node* next;
};

struct Node* createNode(char name[], int marks, int roll) 
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name,name);
    newNode->roll=roll;
    newNode->marks=marks;
    newNode->next=NULL;
    return newNode;
}
void insertNode(struct Node** head,char name[],int marks, int roll)
{
    struct Node* newnode=createNode(name,marks,roll);
    if(*head==NULL)
    {
        *head=newnode;
        return;
    }
    struct Node* temp=*head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
}
void printList(struct Node* head)
{
    struct Node* temp=head;
    while(temp)
    {
        printf("(%s|%d|%d)->",temp->name,temp->marks,temp->roll);
        temp=temp->next;
    }
    printf("NULL\n");
}
struct Node* merge(struct Node* left,struct Node* right)
{
    if(left==NULL) return right;
    if(right==NULL) return left;
    if((strcmp(left->name,right->name)<=0))
    {
        left->next=merge(left->next,right);
        return left;
    }
    else{
        right->next=merge(left,right->next);
        return right;
    }
}
void middle(struct Node* head,struct Node** left,struct Node** right)
{
    struct Node* slow=head;
    struct Node* fast=head->next;
    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next;
    }
    *left=head;
    *right=slow->next;
    slow->next=NULL;
}
void mergesort(struct Node** head)
{
    if(*head==NULL || (*head)->next==NULL)
    {
        return;
    }
    struct Node* left;
    struct Node* right;
    middle(*head,&left,&right);
    mergesort(&left);
    mergesort(&right);
    *head=merge(left,right);
}
int main()
{
    struct Node* head=NULL;
    insertNode(&head,"Alice",85,23);
    insertNode(&head,"Bob",85,34);
    insertNode(&head,"kendal",98,24);
    insertNode(&head,"rack",87,12);
    printList(head);
    mergesort(&head);
    printList(head);
}
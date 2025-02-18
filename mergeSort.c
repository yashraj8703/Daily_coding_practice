#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* createList(int data)
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

void insert(Node** head,int data)
{
    Node* newNode=createList(data);
    newNode->next=*head;
    *head=newNode;
}

void printList(Node* head)
{
    Node* temp=head;
    while(temp)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
Node* merge( Node* left,  Node* right)
{
    if (left == NULL) return right;
    if (right == NULL) return left;

    if (left->data <= right->data) {
        left->next = merge(left->next, right);
        return left;
    } else {
        right->next = merge(left, right->next);
        return right;
    }
}
void middle(Node* head, Node** left, Node** right)
{
    Node* fast;
    Node* slow;
    slow = head;
    fast = head->next;
    
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    *left = head;           
    *right = slow->next;    
    slow->next = NULL;      
}

void MergeSort(Node** head)
{
    if(*head==NULL || (*head)->next==NULL)
    {
        return;
    }
    Node* left;
    Node* right;
    middle(*head,&left,&right);
    MergeSort(&left);
    MergeSort(&right);
    *head=merge(left,right);
}
int main()
{
    Node* head=NULL;
    insert(&head,1);
    insert(&head,6);
    insert(&head,38);
    insert(&head,42);
    MergeSort(&head);
    printList(head);

}
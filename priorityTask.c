#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct Node{
    char task_name[100];
    int priority;
    char time_stamp[20];
    struct Node* next;
};
struct Node* createNode(char task_name[],int priority,char time_stamp[])
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->task_name,task_name);
    newNode->priority=priority;
    strcpy(newNode->time_stamp,time_stamp);
    return newNode;
}
void insertatEnd(struct Node** head,char task_name[],int priority,char time_stamp[])
{
    struct Node* newNode=createNode(task_name,priority,time_stamp);
    if(*head==NULL)
    {
        *head=newNode;
        return;
    }
    struct Node* temp=*head;
    while(temp->next)
    {
        temp=temp->next;
    }
    temp->next=newNode;
}
void printList(struct Node* head)
{
    struct Node* temp=head;
    while(temp)
    {
        printf("{%s|%d|%s}->",temp->task_name,temp->priority,temp->time_stamp);
        temp=temp->next;
    }
    printf("NULL\n");
}
void sortLinkedList(struct Node** head)
{
    struct Node* current=*head;
    for(struct Node* i=current;i!=NULL;i=i->next)
    {
        for (struct Node* j = i->next; j != NULL; j = j->next)
        {
            if(i->priority<j->priority)
            {
                char tempTask[50];
                strcpy(tempTask,i->task_name);
                strcpy(i->task_name,j->task_name);
                strcpy(j->task_name,tempTask);
                int tempPriority=i->priority;
                i->priority=j->priority;
                j->priority=tempPriority;
                char temptime[50];
                strcpy(temptime,i->time_stamp);
                strcpy(i->time_stamp,j->time_stamp);
                strcpy(j->time_stamp,temptime);
            }
        }
    }
}
int main()
{
    struct Node* head=NULL;
    char input_str[100]="{Task1, 3, 10:30},{Task2, 1, 14:45},{Task3, 4, 08:00},{Task8, 7, 08:00}";
    char *token=strtok(input_str,"{}");
    while(token!=NULL)
    {
        while(*token==' ')
        {
            token++;
        }
        char task_name[30];
        int priority;
        char timeStamp[20];
         if (sscanf(token, " %99[^,], %d, %19s", task_name, &priority, timeStamp) == 3) {
            insertatEnd(&head, task_name, priority, timeStamp);
        }
        token=strtok(NULL,"{}");
    }
    printList(head);
    printf("\n");
    sortLinkedList(&head);
    printList(head);
}
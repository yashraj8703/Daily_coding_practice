#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct Queue{
    int size;
    int front;
    int rear;
    char *arr;
};
struct Queue* createQueue(int size){
    struct Queue * Queue=(struct Queue*)malloc(sizeof(struct Queue));
    Queue->front=-1;
    Queue->size=size;
    Queue->rear=-1;
    Queue->arr=(char*)malloc(Queue->size*sizeof(char));
    return Queue;
}
int isFull(struct Queue* Queue)
{
    return Queue->rear==Queue->size-1;
}
int isEmpty(struct Queue * Queue)
{
    return Queue->front==-1;
}

void enqueue(struct Queue * Queue,char ch)
{
    if(isFull(Queue))
    {
        return;
    }
    if(Queue->front==-1)
    {
        Queue->front=0;
    }
    Queue->rear++;
    
    Queue->arr[Queue->rear]=ch;
}
char dequeue(struct Queue * Queue)
{
    if(isEmpty(Queue))
    {
        return '0';
    }
    char value=Queue->arr[Queue->front];
    Queue->front++;
    if(Queue->front>Queue->rear)
    {
        Queue->front=Queue->rear=-1;
    }
    return value;
}
char peek(struct Queue * Queue)
{
    if(isEmpty(Queue))
    {
        return '0';
    }
    char value=Queue->arr[Queue->front];
    return value;
}
void displayQueue(struct Queue* Queue)
{
    if(isEmpty(Queue))
    {
        return;
    }
    for(int i=Queue->front;i<=Queue->rear;i++)
    {
        printf("%c ",Queue->arr[i]);
    }
}
int main()
{
    // struct Queue* Queue=createQueue(5);
    // enqueue(Queue,"hello");
    // enqueue(Queue,"world");
    // displayQueue(Queue);
    // char* str=dequeue(Queue);
    // printf("\n");
    // displayQueue(Queue);
    int choice;
    char ch;
    struct Queue* Queue=createQueue(100);
    do {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        switch(choice) {
            case 1:
                printf("Enter character to enqueue: ");
                scanf("%c",&ch);
                enqueue(Queue, ch);
                break;
            case 2:
                printf("Dequeued: %c\n", dequeue(Queue));
                break;
            case 3:
                printf("Front element: %c\n", peek(Queue));
                break;
            case 4:
                displayQueue(Queue);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
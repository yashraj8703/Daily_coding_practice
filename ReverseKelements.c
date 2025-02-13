#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int front;
    int size;
    int rear;
    char** arr;
}Queue;

Queue * CreateQueue(int size)
{
    Queue *newQueue=(Queue*)malloc(sizeof(Queue));
    newQueue->size=size;
    newQueue->front=-1;
    newQueue->rear=-1;
    newQueue->arr=(char**)malloc(size*sizeof(char*));
    return newQueue;
}

int isFull(Queue * Queue)
{
    return Queue->rear==Queue->size-1;
}
int isEmpty(Queue * Queue)
{
    return Queue->front==-1;
}

void enqueue(Queue* Queue,char s[])
{
    if(isFull(Queue))
    {
        return;
    }
    Queue->rear++;
    if(Queue->front==-1)
    {
        Queue->front=0;
    }
    Queue->arr[Queue->rear]=(char*)malloc(100*sizeof(char));
    strcpy(Queue->arr[Queue->rear],s);
}

void dequeue(Queue*Queue)
{
    if(isEmpty(Queue))
    {
        return;
    }
    Queue->front++;
    if(Queue->front>Queue->rear)
    {
        Queue->front=Queue->rear=-1;
    }
}
char* peek(Queue * Queue)
{
    if(isEmpty(Queue))
    {
        return NULL;
    }
    return Queue->arr[Queue->front];
}
void printQueue(Queue* Queue)
{
    for(int i=Queue->front;i<=Queue->rear;i++)
    {
        printf("%s ",Queue->arr[i]);
    }
}
void reverseArrayOfStrings(char *arr[], int n) {
    int start = 0;
    int end = n - 1;
    while (start < end) {
        char *temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        
        start++;
        end--;
    }
}
int QueueSize(Queue* Queue)
{
    int l=0;
    for(int i=Queue->front;i<=Queue->rear;i++)
    {
        l++;
    }
    return l;
}
void ReverseElements(Queue* Queue,int k)
{
    int NonRevElement=QueueSize(Queue)-k;
    char *elementArray[k];

    for(int i=0;i<k;i++)
    {
        elementArray[i] = (char*)malloc(100 * sizeof(char));
        strcpy(elementArray[i],peek(Queue));
        dequeue(Queue);
    }
    reverseArrayOfStrings(elementArray,k);
    for (int i = 0; i < k; i++) {
        enqueue(Queue, elementArray[i]);
    }
    for(int i=0;i<NonRevElement;i++)
    {
        enqueue(Queue,peek(Queue));
        dequeue(Queue);
    }
}
int main()
{
    Queue * Queue=CreateQueue(100);
    enqueue(Queue,"yash");
    enqueue(Queue,"sourabh");
    enqueue(Queue,"shubh");
    enqueue(Queue,"vivek");
    enqueue(Queue,"sahil");
    enqueue(Queue,"dhruv");
    printQueue(Queue);
    printf("\n");
    ReverseElements(Queue,4);
    printQueue(Queue);
    
}
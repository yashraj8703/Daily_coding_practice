#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int front;
    int size;
    int rear;
    int *arr;
} Queue;

Queue *CreateQueue(int size)
{
    Queue *newQueue = (Queue *)malloc(sizeof(Queue));
    newQueue->size = size;
    newQueue->front = -1;
    newQueue->rear = -1;
    newQueue->arr = (int *)malloc(size * sizeof(int));
    return newQueue;
}

int isFull(Queue *Queue)
{
    return Queue->rear == Queue->size - 1;
}
int isEmpty(Queue *Queue)
{
    return Queue->front == -1;
}

void enqueue(Queue *Queue, int data)
{
    if (isFull(Queue))
    {
        return;
    }
    Queue->rear++;
    if (Queue->front == -1)
    {
        Queue->front = 0;
    }
    Queue->arr[Queue->rear] = data;
}

void dequeue(Queue *Queue)
{
    if (isEmpty(Queue))
    {
        return;
    }
    Queue->front++;
    if (Queue->front > Queue->rear)
    {
        Queue->front = Queue->rear = -1;
    }
}
int peek(Queue *Queue)
{
    if (isEmpty(Queue))
    {
        return -1;
    }
    return Queue->arr[Queue->front];
}
void printQueue(Queue *Queue)
{
    for (int i = Queue->front; i <= Queue->rear; i++)
    {
        printf("%d ", Queue->arr[i]);
    }
}

int QueueSize(Queue *Queue)
{
    int l = 0;
    for (int i = Queue->front; i <= Queue->rear; i++)
    {
        l++;
    }
    return l;
}
void minEnqueue(Queue *inputQueue, Queue *minQueue, int data)
{
    enqueue(inputQueue, data);
    while (!isEmpty(minQueue) && peek(minQueue) > data)
    {
        dequeue(minQueue);
    }
    enqueue(minQueue, data);
}
void popMinQueue(Queue *inputQueue, Queue *minQueue)
{
    int val = peek(inputQueue);
    dequeue(inputQueue);
    if (val == peek(minQueue))
    {
        dequeue(minQueue);
    }
}
int getMin(Queue *minQueue)
{
    if (isEmpty(minQueue))
    {
        return -1;
    }
    return peek(minQueue);
}

int main()
{
    Queue *inputQueue = CreateQueue(100);
    Queue *minQueue = CreateQueue(100);
    minEnqueue(inputQueue, minQueue, 1);
    minEnqueue(inputQueue, minQueue, 2);
    minEnqueue(inputQueue, minQueue, 3);
    minEnqueue(inputQueue, minQueue, 4);
    printf("%d\n", getMin(minQueue));
    popMinQueue(inputQueue, minQueue);
    popMinQueue(inputQueue, minQueue);
    printf("%d\n", getMin(minQueue));
    printQueue(inputQueue);
}
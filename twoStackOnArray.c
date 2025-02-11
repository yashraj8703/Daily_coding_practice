#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
    int size;
    int top1;
    int top2;
    int *arr;
}stack;

stack* createStack(int size)
{
    stack* newStack=(stack*)malloc(sizeof(stack));
    newStack->size=size;
    newStack->top1=-1;
    newStack->top2=size;
    newStack->arr=(int*)malloc(size*sizeof(int));
    return newStack;
}

int isFull(stack* stack)
{
    return stack->top1+1==stack->top2;
}
int isEmpty1(stack* stack)
{
    return stack->top1==-1;
}
int isEmpty2(stack* stack)
{
    return stack->top2==stack->size;
}

void push1(stack* stack,int data)
{
    if(isFull(stack))
    {
        return;
    }
    stack->top1++;
    stack->arr[stack->top1]=data;
}
void push2(stack* stack,int data)
{
    if(isFull(stack))
    {
        return;
    }
    stack->top2--;
    stack->arr[stack->top2]=data;
}

void pop1(stack* stack)
{
    if(isEmpty1(stack))
    {
        return;
    }
    stack->top1--;
}
void pop2(stack* stack)
{
    if(isEmpty2(stack))
    {
        return;
    }
    stack->top2++;
}
int top2(stack* stack)
{
    if(isEmpty2(stack))
    {
        return -1;
    }
    int data=stack->arr[stack->top2];
    return data;
}
int top1(stack* stack)
{
    if(isEmpty1(stack))
    {
        return -1;
    }
    int data=stack->arr[stack->top1];
    return data;
}
void printStack(stack* stack1)
{
    for(int i=0;i<=stack1->top1;i++)
    {
        printf("%d ",stack1->arr[i]);
    }
    printf("\n");
    for (int i = stack1->size - 1; i >= stack1->top2; i--) {
        printf("%d ", stack1->arr[i]);
    }
    printf("\n");
    
}
int main()
{
    stack* stack=createStack(100);
    push1(stack,1);
    push1(stack,2);
    push1(stack,3);
    push2(stack,4);
    push2(stack,5);
    printStack(stack);
    pop1(stack);
    pop2(stack);
    printStack(stack);
}
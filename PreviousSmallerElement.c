#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{
    int size;
    int top;
    int *arr;
};
struct stack* createStack(int size)
{
    struct stack* stack=(struct stack*)malloc(sizeof(struct stack));
    stack->top=-1;
    stack->size=size;
    stack->arr=(int*)malloc(stack->size*sizeof(int));
    return stack;
}
int isFull(struct stack* stack)
{
    return stack->top==stack->size-1;
}
int isEmpty(struct stack* stack)
{
    return stack->top==-1;
}
void push(struct stack* stack,int data)
{
    if(isFull(stack))
    {
        return;
    }
    stack->top++;
    stack->arr[stack->top]=data;
}
int pop(struct stack* stack)
{
    if(isEmpty(stack))
    {
        return '0';
    }
    int value=stack->arr[stack->top];
    stack->top--;
    return value;
}
int top(struct stack* stack)
{
    if(isEmpty(stack))
    {
        return '0';
    }
    int value=stack->arr[stack->top];
    return value;
}
void PreviousSamllerElement(struct stack* stack,int arr[],int n)
{
    int res[5];
    for(int i=0;i<5;i++)
    {
        res[i]=-1;
    }
    for(int i=0;i<5;i++)
    {
        while(!isEmpty(stack) && top(stack)>arr[i])
        {
            pop(stack);
        }
        if(!isEmpty(stack))
        {
            res[i]=top(stack);
        }
        push(stack,arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",res[i]);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int *arr=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    struct stack* stack=createStack(n);
    PreviousSamllerElement(stack,arr,n);
    free(arr);
    return 0;
}
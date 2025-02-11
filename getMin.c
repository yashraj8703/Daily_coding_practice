#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
    int size;
    int top;
    int *arr;
}stack;

stack* createStack(int size)
{
    stack* newStack=(stack*)malloc(sizeof(stack));
    newStack->size=size;
    newStack->top=-1;
    newStack->arr=(int*)malloc(size*sizeof(int));
    return newStack;
}

int isFull(stack* stack)
{
    return stack->top==stack->size-1;
}
int isEmpty(stack* stack)
{
    return stack->top==-1;
}

void push(stack *stack,int data)
{
    if(isFull(stack))
    {
        printf("stack is full\n");
        return;
    }
    stack->top++;
    stack->arr[stack->top]=data;
}

void pop(stack *stack)
{
    if(isEmpty(stack))
    {
        printf("Stack is empty\n");
        return;
    }
    stack->top--;
}

int top(stack *stack)
{
    if(isEmpty(stack))
    {
        printf("stack is full\n");
        return -1;
    }
    int data=stack->arr[stack->top];
    return data;
}
void printStack(stack *stack)
{
    if(isEmpty(stack))
    {
        printf("stack is full\n");
        return;
    }
    for(int i=0;i<=stack->top;i++)
    {
        printf("%d ",stack->arr[i]);
    }
    printf("\n");
}
void pushWithMin(stack *stack1,stack* minStack,int data)
{
    push(stack1,data);
    if(isEmpty(minStack) || data<=top(minStack))
    {
        push(minStack,data);
    }
}
void popwithMin(stack* stack1,stack* minStack){
    if (isEmpty(stack1))
    {
        printf("Stack is empty\n");
        return;
    }

    int popped = top(stack1);
    pop(stack1);

    if (popped == top(minStack))
    {
        pop(minStack);
    } 
}
int getMin(stack* minStack)
{
    if (isEmpty(minStack))
    {
        printf("Min stack is empty\n");
        return -1;
    }
    return top(minStack);
}
int main()
{
    stack* inputStack=createStack(100);
    stack* minStack=createStack(100);
    pushWithMin(inputStack,minStack,5);
    pushWithMin(inputStack,minStack,3);
    pushWithMin(inputStack,minStack,8);
    pushWithMin(inputStack,minStack,2);
    pushWithMin(inputStack,minStack,4);
    popwithMin(inputStack,minStack);
    popwithMin(inputStack,minStack);
    popwithMin(inputStack,minStack);
    int min=getMin(minStack);
    printf("%d ",min);

}
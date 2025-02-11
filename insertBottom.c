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
void insertAtBottom(stack* inputstack,int data)
{
    stack* tempstack=createStack(100);
    while(!isEmpty(inputstack))
    {
        push(tempstack,top(inputstack));
        pop(inputstack);
    }
    push(inputstack,data);
    while (!isEmpty(tempstack))
    {
        push(inputstack,top(tempstack));
        pop(tempstack);
    }
    
}
int main()
{
   stack* inputStack=createStack(100);
   int n;
   scanf("%d",&n);
   int data;
   while(n--)
   {
        int choice;
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            scanf("%d",&data);
            push(inputStack,data);
            break;
        case 2:
            scanf("%d",&data);
            insertAtBottom(inputStack,data);
            break;
        case 3:
            printStack(inputStack);
            break;
        default:
            printf("Invalid Choice");
            break;
        }

   }
}
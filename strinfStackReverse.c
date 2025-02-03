#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{
    int size;
    int top;
    char *arr;
};
struct stack* createStack(int size)
{
    struct stack* stack=(struct stack*)malloc(sizeof(struct stack));
    stack->top=-1;
    stack->size=size;
    stack->arr=(char*)malloc(stack->size*sizeof(char));
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
void push(struct stack* stack,char data)
{
    if(isFull(stack))
    {
        return;
    }
    stack->top++;
    stack->arr[stack->top]=data;
}
char pop(struct stack* stack)
{
    if(isEmpty(stack))
    {
        return '0';
    }
    char value=stack->arr[stack->top];
    stack->top--;
    return value;
}
char top(struct stack* stack)
{
    if(isEmpty(stack))
    {
        return '0';
    }
    char value=stack->arr[stack->top];
    return value;
}
void reverseString(struct stack* stack,char s[],int n)
{
    for(int i=0;i<n;i++)
    {
        push(stack,s[i]);
    }
    int index=0;
    while(!isEmpty(stack))
    {
        s[index++]=pop(stack);
    }
    s[index]='\0';
    printf("%s",s);
}
int main()
{
    char s[100];
    scanf("%s",s);
    int n=strlen(s);
    struct stack* stack=createStack(n);
    reverseString(stack,s,n);

    return 0;
}
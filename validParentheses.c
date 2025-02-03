#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{
    int top;
    int size;
    char *ch;
};
struct stack* createStack(int size)
{
    struct stack* stack=(struct stack * )malloc(sizeof(struct stack));
    stack->size=size;
    stack->top=-1;
    stack->ch=(char*)malloc(1*sizeof(char));
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
    stack->ch[stack->top]=data;
}
char pop(struct stack* stack)
{
    if(isEmpty(stack))
    {
        return '0';
    }
    char value=stack->ch[stack->top];
    stack->top--;
    return value;
}
char top(struct stack* stack)
{
    if(isEmpty(stack))
    {
        return '0';
    }
    char value=stack->ch[stack->top];
    return value;
}
void printStack(struct stack * stack)
{
    if(isEmpty(stack)){
        return;
    }
    for(int i=0;i<=stack->top;i++)
    {
        printf("%c ",stack->ch[i]);
    }
}
int validParantheses(struct stack* stack,char s[])
{
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]=='[' || s[i]=='{' || s[i]=='(')
        {
            push(stack,s[i]);
        }
        else{
            if (isEmpty(stack)) return 0;
            if(s[i]==']' && top(stack)=='[')
            {
                pop(stack);
            }
            else if(s[i]==')' && top(stack)=='(')
            {
                pop(stack);
            }
            else if(s[i]=='}' && top(stack)=='{')
            {
                pop(stack);
            }
            else return 0;
        }
    }
    return isEmpty(stack);
}
int main()
{
    char s[100];
    scanf("%s",s);
    int n=strlen(s);
    struct stack * stack=createStack(n);
    if(validParantheses(stack,s))
    {
        printf("valid Parantheses");
    }
    else{
        printf("not valid Parantheses");
    }
    
}
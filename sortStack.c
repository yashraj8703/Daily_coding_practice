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
        return -1;
    }
    int value=stack->arr[stack->top];
    stack->top--;
    return value;
}
int top(struct stack* stack)
{
    if(isEmpty(stack))
    {
        return -1;
    }
    int value=stack->arr[stack->top];
    return value;
}
void displayStack(struct stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->arr[i]);
    }
}
void sortStack(struct stack* stack)
{
    struct stack* tempStack=createStack(5);
    while(!isEmpty(stack))
    {
        int temp=pop(stack);
        while(!isEmpty(tempStack) && temp<top(tempStack))
        {
            push(stack,pop(tempStack));
        }
        push(tempStack,temp);
        
    }
    while(!isEmpty(tempStack))
    {
        push(stack,pop(tempStack));
    }
    displayStack(stack);
}
int main()
{

    struct stack* myStack = createStack(5);  
    int choice, value;

    do {
        printf("\nStack Operations Menu\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display Stack\n");
        printf("4. Sort Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push onto the stack: ");
                scanf("%d", &value);
                push(myStack, value);
                break;
            case 2:
                value = pop(myStack);
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                displayStack(myStack);
                break;
            case 4:
                sortStack(myStack);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 5);

    free(myStack->arr);
    free(myStack);

    return 0;
}
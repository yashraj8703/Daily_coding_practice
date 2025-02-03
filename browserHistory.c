#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{
    int size;
    int top;
    char **url;
};
struct stack* createStack(int size)
{
    struct stack* stack=(struct stack*)malloc(sizeof(struct stack));
    stack->top=-1;
    stack->size=size;
    stack->url=(char**)malloc(stack->size*(sizeof(char*)));
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
void push(struct stack* stack,char url[])
{
    if(isFull(stack))
    {
        return;
    }
    stack->top++;
    stack->url[stack->top]=(char*)malloc(100*sizeof(char));
    strcpy(stack->url[stack->top],url);
}
char* pop(struct stack* stack)
{
    if(isEmpty(stack))
    {
        return "0";
    }
    char* value=stack->url[stack->top];
    stack->top--;
    return value;
}
char* top(struct stack* stack)
{
    if(isEmpty(stack))
    {
        return "0";
    }
    char* value=stack->url[stack->top];
    return value;
}
void displayStack(struct stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack contents (URLs):\n");
    for (int i = stack->top; i >= 0; i--) {
        printf("%s\n", stack->url[i]);
    }
}
void deleteAllUrl(struct stack* stack)
{
    while(!isEmpty(stack))
    {
        pop(stack);
    }
}
void removeRecentURL(struct stack* stack)
{
    if (!isEmpty(stack)) {
        printf("Removed URL: %s\n", pop(stack));
    } else {
        printf("No URLs to remove.\n");
    }
}
void editUrl(struct stack* stack,int index,char newURL[])
{
    if(isEmpty(stack))
    {
        return;
    }
    strcpy(stack->url[index],newURL);
}
int main()
{
    struct stack* stack = createStack(5);
    int choice;
    char url[100];
    int index;

    do {
        printf("\nMenu:\n");
        printf("1. Push URL\n");
        printf("2. Pop URL\n");
        printf("3. Display Stack\n");
        printf("4. Edit URL\n");
        printf("5. Remove Most Recent URL\n");
        printf("6. Delete All URLs\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch(choice) {
            case 1:
                printf("Enter URL to push: ");
                scanf("%s",url);
                push(stack, url);
                break;
            case 2:
                printf("Popped URL: %s\n", pop(stack));
                break;
            case 3:
                displayStack(stack);
                break;
            case 4:
                printf("Enter index to edit (0 to %d): ", stack->top);
                scanf("%d", &index);
                getchar(); 
                if (index >= 0 && index <= stack->top) {
                    printf("Enter new URL: ");
                    scanf("%s",url);
                    editUrl(stack, index, url);
                } else {
                    printf("Invalid index.\n");
                }
                break;
            case 5:
                removeRecentURL(stack);
                break;
            case 6:
                deleteAllUrl(stack);
                printf("All URLs deleted.\n");
                break;
            case 7:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 7);

    return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
    int size;
    int top;
    int *pageNo;

}stack;

stack* createStack(int size)
{
    stack* newStack=(stack*)malloc(sizeof(stack));
    newStack->size=size;
    newStack->top=-1;
    newStack->pageNo=(int*)malloc(size*sizeof(int));
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

void push(stack* stack,int page)
{
    if(isFull(stack))
    {
        return;
    }
    stack->top++;
    stack->pageNo[stack->top]=page;
}

void delete(stack* stack)
{
    if(isEmpty(stack))
    {
        return;
    }
    stack->top--;
}
void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void printStack(stack* stack)
{
    if(isEmpty(stack))
    {
        printf("No bookmarks\n");
        return;
    }
    int len=stack->top+1;
    int arr[len];
    int index=0;
    for(int i=0;i<len;i++)
    {
        arr[index++]=stack->pageNo[i];
    }
    sort(arr,index);
    for(int i=0;i<index;i++)
    {
        printf("%d ",arr[i]);
    }
}

int main()
{
    stack* inputStack=createStack(100);
    char str[100];
    int n;
    scanf("%d", &n);
    while (n--) {
        scanf("%s", str); 
        char func[50];
        int page;
        if (sscanf(str, "%[^<]<%d>", func, &page) == 2) {
            if (strcmp(func, "BOOKMARK") == 0) {
                push(inputStack,page); 
            }
        }
        else if (strcmp(str, "DELETE") == 0) {
            delete(inputStack);
        }
        else if (strcmp(str, "LIST") == 0) {
            printStack(inputStack);
        }
        else {
            printf("Invalid input\n");  
        }
    }

    return 0;
}
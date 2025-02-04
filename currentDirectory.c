#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack {
    int size;
    int top;
    char** arr;
};

struct stack* createStack(int size) {
    struct stack* stack = (struct stack*)malloc(sizeof(struct stack));
    stack->size = size;
    stack->top = -1;
    stack->arr = (char**)malloc(size * sizeof(char*));
    return stack;
}
int isFull(struct stack* stack) {
    return stack->top == stack->size - 1;
}

int isEmpty(struct stack* stack) {
    return stack->top == -1;
}

void push(struct stack* stack, char* str) {
    if (isFull(stack)) {
        return;
    }
    stack->top++;
    stack->arr[stack->top] = (char*)malloc(100 * sizeof(char));
    strcpy(stack->arr[stack->top], str);
}

void pop(struct stack* stack) {
    if (isEmpty(stack)) {
        return;
    }
    stack->top--;
}

void printStack(struct stack* stack) {
    for (int i = 0; i <= stack->top; i++) {
        printf("%s", stack->arr[i]);
    }
    printf("\n");
}

void processCommands(struct stack* stack, char s[100][100], int n) {
    for (int i = 0; i < n; i++)
    {
        char extracted_str[200];
        if(strcmp(s[i],"cd ../")==0)
        {
            pop(stack);
        }
        else
        {
            sscanf(s[i]," %*s%s",extracted_str);
            push(stack,extracted_str);
        }
    }
    printStack(stack);
}

int main() {
    int n;
    scanf("%d",&n);
    getchar();
    char input_str[100][100];
    for (int i = 0; i < n; i++) {
        fgets(input_str[i], 100, stdin);  
        input_str[i][strcspn(input_str[i], "\n")] = '\0';  
    }
    struct stack* stack = createStack(n);
    processCommands(stack, input_str, n);

    return 0;
}

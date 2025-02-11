#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int size;
    int top;
    char **arr;
} stack;

stack* createStack(int size) {
    stack* newStack = (stack*)malloc(sizeof(stack));
    newStack->size = size;
    newStack->top = -1;
    newStack->arr = (char**)malloc(size * sizeof(char*));
    return newStack;
}

int isFull(stack* stack) {
    return stack->top == stack->size - 1;
}

int isEmpty(stack* stack) {
    return stack->top == -1;
}

void push(stack *stack, char data[]) {
    if (isFull(stack)) {
        printf("Stack is full\n");
        return;
    }
    stack->top++;
    stack->arr[stack->top] = (char*)malloc(100 * sizeof(char));
    strcpy(stack->arr[stack->top], data);
}

void pop(stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    stack->top--;
}

char* top(stack *stack) {
    if (isEmpty(stack)) {
        return "empty";
    }
    return stack->arr[stack->top];
}

void printStack(stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = 0; i <= stack->top; i++) {
        printf("%s ", stack->arr[i]);
    }
    printf("\n");
}

void PostfixtoInfix(stack* inputStack, char s[]) {
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] >= 'a' && s[i] <= 'z') {
            char input[2];
            input[0] = s[i];
            input[1] = '\0';
            push(inputStack, input);
        }
        else {
            char t1[30];
            char t2[30];
            strcpy(t1, top(inputStack));
            pop(inputStack);
            strcpy(t2, top(inputStack));
            pop(inputStack);
            char res[100];
            sprintf(res, "(%s%c%s)", t2, s[i], t1);
            push(inputStack, res);
        }
        i++;
    }
}

int main() {
    stack* inputStack = createStack(100);
    char input_str[100];
    scanf("%s",input_str);
    PostfixtoInfix(inputStack, input_str);
    printf("%s", top(inputStack));
    return 0;
}

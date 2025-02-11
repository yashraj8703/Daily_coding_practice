#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int capacity;
    int index;
    int *elements;
} Stack;

Stack* createIntStack(int capacity) {
    Stack* newStack = (Stack*)malloc(sizeof(Stack));
    newStack->capacity = capacity;
    newStack->index = -1;
    newStack->elements = (int*)malloc(capacity * sizeof(int));
    return newStack;
}

int intIsFull(Stack* stack) {
    return stack->index == stack->capacity - 1;
}

int intIsEmpty(Stack* stack) {
    return stack->index == -1;
}

void intPush(Stack* stack, int value) {
    if (intIsFull(stack)) {
        printf("Stack is full\n");
        return;
    }
    stack->index++;
    stack->elements[stack->index] = value;
}

void intPop(Stack* stack) {
    if (intIsEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    stack->index--;
}

int intTop(Stack* stack) {
    if (intIsEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->elements[stack->index];
}

typedef struct {
    int size;
    int top;
    char **arr;
} CharStack;

CharStack* createCharStack(int size) {
    CharStack* newStack = (CharStack*)malloc(sizeof(CharStack));
    newStack->size = size;
    newStack->top = -1;
    newStack->arr = (char**)malloc(size * sizeof(char*));
    return newStack;
}

int isFull(CharStack* stack) {
    return stack->top == stack->size - 1;
}

int isEmpty(CharStack* stack) {
    return stack->top == -1;
}

void push(CharStack *stack, char data[]) {
    if (isFull(stack)) {
        printf("Stack is full\n");
        return;
    }
    stack->top++;
    stack->arr[stack->top] = (char*)malloc(100 * sizeof(char));
    strcpy(stack->arr[stack->top], data);
}

void pop(CharStack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    stack->top--;
}

char* top(CharStack *stack) {
    if (isEmpty(stack)) {
        return "empty";
    }
    return stack->arr[stack->top];
}

void printStack(CharStack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = 0; i <= stack->top; i++) {
        printf("%s ", stack->arr[i]);
    }
    printf("\n");
}

void decodeString(Stack* intStack, CharStack* charStack, char s[]) {
    for(int i = 0; i < strlen(s); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            int num = 0;
            while (i < strlen(s) && s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            i--;
            intPush(intStack, num);
        }
        else if(s[i] >= 'a' && s[i] <= 'z' || s[i] == '[') {
            char temp[2];
            temp[0] = s[i];
            temp[1] = '\0';
            push(charStack, temp);
        }
        else if(s[i] == ']') {
            char str[100] = "";
            while(!isEmpty(charStack) && strcmp(top(charStack), "[") != 0) {
                strcat(str, top(charStack));
                pop(charStack);
            }
            pop(charStack);
            char res[100] = "";
            int stopVal = intTop(intStack);
            intPop(intStack);
            for(int i = 0; i < stopVal; i++) {
                strcat(res, str);
            }
            push(charStack, res);
        }
    }
}
void reverseString(char s[])
{
    int l=0;
    int e=strlen(s)-1;
    while(l<e)
    {
        char temp=s[l];
        s[l]=s[e];
        s[e]=temp;
        l++;
        e--;
    }
}
int main() {
    char s[100];
    scanf("%s",s);
    Stack* intStack = createIntStack(100);
    CharStack* charStack = createCharStack(100);

    decodeString(intStack, charStack, s);
    char res[100];
    strcpy(res,top(charStack));
    reverseString(res);
    printf("%s",res);

    return 0;
}

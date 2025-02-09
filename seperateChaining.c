#include <stdio.h>

#define TABLE_SIZE 10
#define MAX_ENTRY_PER_INDEX 5  

typedef struct Node {
    int key;
} Node;

Node hashTable[TABLE_SIZE][MAX_ENTRY_PER_INDEX];

void init_hashTable()
{
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        for(int j = 0; j < MAX_ENTRY_PER_INDEX; j++)
        {
            hashTable[i][j].key = -1;
        }
    }
}

unsigned int hashFunction(int key)
{
    return (2 * key + 3) % TABLE_SIZE;
}

void insertElement(int key)
{
    unsigned int index = hashFunction(key);
    for (int i = 0; i < MAX_ENTRY_PER_INDEX; i++)
    {
        if (hashTable[index][i].key == -1)
        {
            hashTable[index][i].key = key;
            return;
        }
    }
    printf("Error: Chain is full at index %d\n", index);
}

void PrintHashTable()
{
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        for (int j = 0; j < MAX_ENTRY_PER_INDEX; j++) {
            if (hashTable[i][j].key != -1) {
                printf("%d", hashTable[i][j].key);
                if (j < MAX_ENTRY_PER_INDEX - 1 && hashTable[i][j + 1].key != -1) {
                    printf(" -> ");
                }
            }
        }
        printf("\n");
    }
}

int main()
{
    int keys[] = {3, 2, 9, 6, 11, 13, 7, 12};
    int n = sizeof(keys) / sizeof(keys[0]);
    
    init_hashTable();  

    for (int i = 0; i < n; i++)
    {
        insertElement(keys[i]);
    }
    
    PrintHashTable();
    return 0;
}

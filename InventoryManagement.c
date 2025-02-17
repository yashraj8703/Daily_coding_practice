#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 10
typedef struct
{
    char itemName[50];
    int item;
    int status;
} Inventory;

Inventory hashtable[TABLE_SIZE];

void init()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashtable[i].status = 0;
    }
}

int hashFunction(char name[])
{
    int hashval = 0;
    for (int i = 0; name[i] != 0; i++)
    {
        hashval += name[i];
    }
    return hashval % TABLE_SIZE;
}

void add(char name[], int Quantity)
{
    int index = hashFunction(name);
    int currIdx = index;
    while (hashtable[currIdx].status != 0)
    {
        currIdx = (currIdx + 1) % TABLE_SIZE;
        if (currIdx == index)
        {
            return;
        }
    }
    hashtable[currIdx].item = Quantity;
    hashtable[currIdx].status = 1;
    strcpy(hashtable[currIdx].itemName, name);
}

void update(char name[], int Quantity)
{
    int index = hashFunction(name);
    int currIdx = index;
    while (hashtable[currIdx].status != 0)
    {
        if (hashtable[currIdx].status == 1 && strcmp(hashtable[currIdx].itemName, name) == 0)
        {
            hashtable[currIdx].item = Quantity;
            return;
        }
        currIdx = (currIdx + 1) % TABLE_SIZE;
        if (currIdx == index)
        {
            break;
        }
    }
    printf("item not found\n");
}
void Query(char name[])
{
    int index = hashFunction(name);
    int currIdx = index;
    while (hashtable[currIdx].status != 0)
    {
        if (hashtable[currIdx].status == 1 && strcmp(hashtable[currIdx].itemName, name) == 0)
        {
            printf("item %s Quantity %d\n", hashtable[currIdx].itemName, hashtable[currIdx].item);
            return;
        }
        currIdx = (currIdx + 1) % TABLE_SIZE;
        if (currIdx == index)
        {
            break;
        }
    }
    printf("item not found\n");
}

int main()
{
    init();
    char str[100];
    int n;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%s", str);
        char func[50];
        char name[50];
        int qty;
        if (sscanf(str, "%[^<]<%[^>]><%d>", func, name, &qty) == 3)
        {
            if (strcmp(func, "ADD") == 0)
            {
                add(name, qty);
            }
            else if (strcmp(func, "UPDATE") == 0)
            {
                update(name, qty);
            }
        }
        else if (sscanf(str, "%[^<]<%[^>]>", func, name) == 2)
        {
            if (strcmp(func, "QUERY") == 0)
            {
                Query(name);
            }
        }
        else
        {
            printf("Invalid input\n");
        }
    }
}
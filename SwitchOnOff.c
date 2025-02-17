#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 10
typedef struct
{
    char room[50];
    int light;//0 for off 1 for on
    int status;
} Inventory;

Inventory hashtable[TABLE_SIZE];

void init()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashtable[i].status = 0;
        hashtable[i].light = 0;
    }
}

int hashFunction(char room[])
{
    int hashval = 0;
    for (int i = 0; room[i] != 0; i++)
    {
        hashval += room[i];
    }
    return hashval % TABLE_SIZE;
}

void add(char room[])
{
    int index = hashFunction(room);
    int currIdx = index;
    while (hashtable[currIdx].status != 0)
    {
        currIdx = (currIdx + 1) % TABLE_SIZE;
        if (currIdx == index)
        {
            return;
        }
    }
    hashtable[currIdx].status = 1;
    strcpy(hashtable[currIdx].room, room);
}

void update(char room[])
{
    int index = hashFunction(room);
    int currIdx = index;
    while (hashtable[currIdx].status != 0)
    {
        if (hashtable[currIdx].status == 1 && strcmp(hashtable[currIdx].room, room) == 0)
        {
            if(hashtable[currIdx].light== 0)
            {
                hashtable[currIdx].light= 1;

            }
            else{
                hashtable[currIdx].light= 0;
            }
            return;
        }
        currIdx = (currIdx + 1) % TABLE_SIZE;
        if (currIdx == index)
        {
            break;
        }
    }
    printf("Room not found\n");
}
void status(char room[])
{
    int index = hashFunction(room);
    int currIdx = index;
    while (hashtable[currIdx].status != 0)
    {
        if (hashtable[currIdx].status == 1 && strcmp(hashtable[currIdx].room, room) == 0)
        {
            char s[50];
            if(hashtable[currIdx].light==0)
            {
                strcpy(s,"OFF");
            }
            else{
                strcpy(s,"ON");
            }
            printf("Light of room %s is %s\n",hashtable[currIdx].room,s);
            return;
        }
        currIdx = (currIdx + 1) % TABLE_SIZE;
        if (currIdx == index)
        {
            break;
        }
    }
    printf("Room not found\n");
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
        if (sscanf(str, "%[^<]<%[^>]>", func, name) == 2)
        {
            if (strcmp(func, "TURN_ON") == 0 || strcmp(func, "TURN_OFF") == 0)
            {
                update(name);
            }
            else if(strcmp(func, "ADD")==0)
            {
                add(name);
            }
            else if (strcmp(func, "STATUS") == 0)
            {
                status(name);
            }
        }
        else
        {
            printf("Invalid input\n");
        }
    }
}
// 5
// ADD<room1>
// TURN_ON<room1>
// STATUS<room1>
// TURN_OFF<room1>
// STATUS<room1> 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TABLE_SIZE 100

typedef struct
{
    char action[50];
    int frequency;
    int status; // 0 - Available 1- not
} Entries;

Entries hashTable[TABLE_SIZE];

void init()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashTable[i].status = 0;
        hashTable[i].frequency = 0;
    }
}

int hashFunction(char action[])
{
    int hashval = 0;
    for (int i = 0; action[i] != '\0'; i++)
    {
        hashval += action[i];
    }
    return hashval % TABLE_SIZE;
}

void add(char action[])
{
    int index=hashFunction(action);
    int currIdx=index;
    if(hashTable[currIdx].status==1 && strcmp(hashTable[currIdx].action,action)==0)
    {
        hashTable[currIdx].frequency++;
    }
    while(hashTable[currIdx].status!=0)
    {
        currIdx=(currIdx+1)%TABLE_SIZE;
        if(currIdx==index)
        {
            return;
        }
    }
    hashTable[currIdx].status=1;
    hashTable[currIdx].frequency++;
    strcpy(hashTable[currIdx].action,action);
}


// void compare(int k)
// {
//     for(int i=0;i<TABLE_SIZE;i++)
//     {
//         if (hashTable[i].status == 1)
//             {
//                 if (hashTable[i].frequency < k)
//                 {
//                     printf("%s\n", hashTable[i].action);
//                         hashTable[i].frequency=k+1;
//                     // break;
//                 }
//                 // break; 
//             }
//     }
// }
void compare(int n,char strArray[n][100],int k)
{
    for(int i=0;i<n;i++)
    {
        // int index=hashFunction(strArray[i]);
        // if(hashTable[index].status==1 && strcmp(hashTable[index].action,strArray[i])==0)
        // {
        //     if(hashTable[index].frequency<k)
        //     {
        //         printf("%s\n",strArray[i]);
        //             break;

        //     }
        // }
        int index = hashFunction(strArray[i]);
        int currIdx = index;

        // Linear probing to find the action in the table
        while (hashTable[currIdx].status != 0)
        {
            if (hashTable[currIdx].status == 1 && strcmp(hashTable[currIdx].action, strArray[i]) == 0)
            {
                if (hashTable[currIdx].frequency < k)
                {
                    printf("%s\n", strArray[i]);
                    hashTable[currIdx].frequency=k+1;
                    // break;
                }
                break; 
            }
            currIdx = (currIdx + 1) % TABLE_SIZE;

            if (currIdx == index)
            {
                break;
            }
        }
    }
}


int main()
{
    init();
    int n=6;
    char s[6][100]={"login", "logout", "upload", "login", "upload", "download"};
    for(int i=0;i<n;i++)
    {
        add(s[i]);
    }
    compare(n,s,2);

}   

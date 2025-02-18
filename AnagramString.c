#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TABLE_SIZE 100

typedef struct
{
    char ch;
    int frequency;
    int status;
} StringHash;

StringHash hashTable[TABLE_SIZE];

void init()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashTable[i].status = 0;
        hashTable[i].frequency = 0;
    }
}

int hashFunction(char ch)
{
    return ch % TABLE_SIZE;
}

void add(char ch)
{
    int index=hashFunction(ch);
    int currIdx=index;
    if(hashTable[currIdx].status==1 && hashTable[currIdx].ch==ch)
    {
        hashTable[currIdx].frequency++;
        return;
    }
    while(hashTable[currIdx].status!=0)
    {
        currIdx=(currIdx+1)%TABLE_SIZE;
        if(currIdx==index)
        {
            return;
        }
    }
    hashTable[currIdx].frequency++;
    hashTable[currIdx].status=1;
    hashTable[currIdx].ch=ch;
}

void anagramComputation(char str[])
{
    for (int i = 0; str[i] != '\0'; i++) {
        int index = hashFunction(str[i]);
        int currIdx = index;
        while (hashTable[currIdx].status != 0) {
            if (hashTable[currIdx].status == 1 && hashTable[currIdx].ch == str[i]) {
                hashTable[currIdx].frequency--;
                break;
            }
            currIdx = (currIdx + 1) % TABLE_SIZE;
            if (currIdx == index) {
                break;
            }
        }
    }
}

int AreAnagram()
{
    for(int i=0;i<TABLE_SIZE;i++)
    {
        if(hashTable[i].status==1)
        {
            if(hashTable[i].frequency!=0)
            {
                return 0;
            }
        }
    }
    return 1;
}

// int main()
// {
//     init();
//     char s1[100]="listen";
//     char s2[100]="silaent";
//     for(int i=0;s1[i]!='\0';i++)
//     {
//         add(s1[i]);
//     }
//     anagramComputation(s2);
//     if(AreAnagram(s2))
//     {
//         printf("anagram string\n");
//     }
//     else{
//         printf("Not anagram string\n");
//     }
// }
int main()
{
    init();
    char s1[100] = "listen";
    char s2[100] = "silaent"; // Incorrect example, should be anagram-free strings

    if (strlen(s1) != strlen(s2)) {
        printf("Not an anagram string\n");
        return 0; // Return immediately if lengths are different
    }

    for (int i = 0; s1[i] != '\0'; i++) {
        add(s1[i]); // Add characters of s1 to the hash table
    }

    anagramComputation(s2); // Remove characters of s2 from the hash table

    if (AreAnagram()) { // Check the hash table for any non-zero frequency
        printf("Anagram strings\n");
    } else {
        printf("Not an anagram string\n");
    }

    return 0;
}

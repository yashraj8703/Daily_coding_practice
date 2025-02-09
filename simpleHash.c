
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_NAME 256
#define TABLE_SIZE 10
typedef struct{
    char name[50];
    int age;
    
}person;

person hash_table[TABLE_SIZE]; //array of person
unsigned int hash(char *name) //lookup by name (hashfunction)
{
    unsigned int hashValue = 0;
    for (int i = 0; name[i] != '\0'; i++) {
        hashValue += name[i];  
        hashValue *= name[i];  
    }
    return hashValue % TABLE_SIZE; 
}

void insert(person p)
{
    unsigned int index=hash(p.name);
    hash_table[index]=p;
}
void printHashTable()
{
    for(int i=0;i<TABLE_SIZE;i++)
    {
        printf("at index %d person is %s\n",i,hash_table[i].name);
    }
}
void search(char *name)
{
    for(int i=0;i<TABLE_SIZE;i++)
    {
        if(strcmp(hash_table[i].name,name)==0)
        {
            printf("at index %d person is %s\n",i,hash_table[i].name);
            return;
        }
    }
    printf("not found");
}
void delete(char *name)
{
    for(int i=0;i<TABLE_SIZE;i++)
    {
        if(strcmp(hash_table[i].name,name)==0)
        {
            hash_table[i].name[0]='\0';
            return;
        }
    }
    printf("not found");
}

int main()
{
    person p1 = {"shreedhi", 22};
    person p2 = {"roshni", 21};
    person p3 = {"suhash", 24};
    person p4 = {"yash", 20};

    insert(p1);
    insert(p2);
    insert(p3);
    insert(p4);
    printHashTable();
    search("yash");
    delete("roshni");
    printf("-----------");
    printHashTable();
    search("roshni");
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TABLE_SIZE 100

typedef struct
{
    char name[50];
    int phone;
    int status; //0-empty 1-filled -1-deleted(can be reused)
} phoneBook;

phoneBook hashTable[TABLE_SIZE];

void init()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashTable[i].status = 0;
    }
}

int hashFunction(char name[])
{
    int hashval = 0;
    for (int i = 0; name[i] != '\0'; i++)
    {
        hashval += name[i];
    }
    return hashval % TABLE_SIZE;
}

void add(char name[],int num)
{
    int index= hashFunction(name);
    int currIdx=index;
    if(hashTable[currIdx].status==1 && strcmp(hashTable[currIdx].name,name)==0)
    {
        hashTable[currIdx].phone=num;
        return;
    }
    while (hashTable[currIdx].status!=0)
    {
        currIdx=(currIdx+1)%TABLE_SIZE;
        if(currIdx==index)
        {
            return;
        }
    }
    hashTable[currIdx].phone=num;
    strcpy(hashTable[currIdx].name,name);
    hashTable[currIdx].status=1;
    printf("Success\n");
}

void search(char name[])
{
    int index= hashFunction(name);
    int currIdx=index;
    while (hashTable[currIdx].status!=0 )
    {
        if(hashTable[currIdx].status==1 && strcmp(hashTable[currIdx].name,name)==0)
        {
            printf("Found %d\n",hashTable[currIdx].phone);
            return;
        }
        currIdx=(currIdx+1)%TABLE_SIZE;
        if(currIdx==index)
        {
            return;
        }
    }
    printf("Not Found\n");
}

void Delete(char name[])
{
    int index= hashFunction(name);
    int currIdx=index;
    while (hashTable[currIdx].status!=0)
    {
        if(hashTable[currIdx].status==1 && strcmp(hashTable[currIdx].name,name)==0)
        {
            hashTable[currIdx].status=-1;
            printf("Deleted\n");
            return;
        }
        currIdx=(currIdx+1)%TABLE_SIZE;
        if(currIdx==index)
        {
            return;
        }
    }
    printf("Not Found\n");
}

int main()
{
    init();
    int n;
    char str[1000];
    char name[101];
    int no;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf(" %[^\n]",str);
        if(strncmp(str,"add",3) == 0){
            sscanf(str," add(\"%[^\"]\", %d)",name,&no);
            add(name,no);
        }else if(strncmp(str,"search",6)==0){
            sscanf(str," search(\"%[^\"]\")",name);
            search(name);
        }else{
            sscanf(str," delete(\"%[^\"]\")",name);
            Delete(name);
        }
    }
    return 0;
    // add("yash",123);
    // add("sahil",234);
    // search("yash");
    // add("yash",456);
    // search("yash");

    // add("dhruv",45);
    // add("sourabh",12);
    // search("sahil");
    // search("fweesc");
    // Delete("sourabh");
    // search("sourabh");

}
// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 
// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
 
// Constraints:
 
// 2 <= nums.length <= 10^4
// -10^9 <= nums[i] <= 10^9
// -10^9 <= target <= 10^9
 
// Time constraint : O(n) using hash map

#include<stdio.h>
#include<stdlib.h>
#define TABLE_SIZE 100004
typedef struct
{
    int index;
    int num;
    int status;
}Element;


Element hashTable[TABLE_SIZE];

void init()
{
    for(int i=0;i<TABLE_SIZE;i++)
    {
        hashTable[i].status=0;
    }
}
int hashFunction(int data)
{
    return data%TABLE_SIZE;
}
void insert(int dataindex,int data)
{
    int index=hashFunction(data);
    int currIdx=index;
    while(hashTable[currIdx].status!=0)
    {
        currIdx=(currIdx+1)%TABLE_SIZE;
        if(currIdx==index)
        {
            return;
        }
    }
    hashTable[currIdx].num=data;
    hashTable[currIdx].index=dataindex;
    hashTable[currIdx].status=1;
}

int search(int data)
{
    int index=hashFunction(data);
    int currIdx=index;
    while(hashTable[currIdx].status!=0)
    {
        if(hashTable[currIdx].num==data && hashTable[currIdx].status==1)
        {
            return hashTable[currIdx].index;
        }
        if(currIdx==index)
        {
            return -1;
        }
    }
    return -1;
}
void printHashTable()
{
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        if(hashTable[i].status == 1)
        {
            printf("Hash Index %d: %d, actual index %d\n", i, hashTable[i].num,hashTable[i].index);
        }
    }
}

void twoSum(int target)
{
    for(int i=0;i<TABLE_SIZE;i++)
    {
        if(hashTable[i].status==1)
        {
            int num1=hashTable[i].num;
            int num2=target-num1;
            int i1=hashTable[i].index;
            int i2 = search(num2);
            if (i2 != -1) {
                printf("%d, %d\n", i1, i2);
                return;
            }
        }
    }
    printf("not found");
}
int main()
{
    init();
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        insert(i,arr[i]);
    }
    int target;
    scanf("%d",&target);
    twoSum(target);
}
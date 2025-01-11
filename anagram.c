#include<stdio.h>
#include<stdlib.h>
#define total_alphabets 26
#define MAX_LEN 100
int len(char *s)
{
    int l=0;
    while(s[l]!='\0')
    {
        l++;
    }
    return l;
}
void check_anagram(char *string1,char *string2)
{
    if(len(string1)!=len(string2))
    {
       printf("Strings are not anagrams");
        return; 
    }
    int frequency[total_alphabets]={0};
    for(int i=0;i<len(string1);i++)
    {
        frequency[string1[i]-'a']++;
    }
    for(int i=0;i<len(string2);i++)
    {
        frequency[string2[i]-'a']--;
    }
    for(int i=0;i<total_alphabets;i++)
    {
        if(frequency[i]!=0)
        {
        printf("Strings are not anagrams");
        return;
        }
    }
    printf("strings are anagrams");
}
int main() {
    char *string1=(char*)malloc(MAX_LEN*sizeof(char));
    if(string1==NULL)
    {
        printf("dynamic memory allocation failed");
        return 1;
    }
    printf("Enter first string : ");
    scanf("%s",string1);
    char *string2=(char*)malloc(MAX_LEN*sizeof(char));
    if(string2==NULL)
    {
        printf("dynamic memory allocation failed");
        return 1;
    }
    printf("Enter second string : ");
    scanf("%s",string2);
    check_anagram(string1,string2);
    free(string1);
    free(string2);
    return 0;
}
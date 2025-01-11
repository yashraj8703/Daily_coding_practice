#include <stdio.h>
#include<stdlib.h>

#define Input_str_len 100
#define string_len 100

int length_string(char *input_string)
{
    int l=0;
    while(input_string[l]!='\0')
    {
        l++;
    }
    return l;
}
void string_to_words(char **word_array,char *input_string,int n)
{
    int word_count=0;
    int i=0;
    int j=0;
    while(i<n)
    {
        while(i<n && input_string[i]==' ')
        {
            i++;
        }
        if(i>=n)
        {
            break;
        }
        word_array[word_count]=(char*)malloc(string_len*sizeof(char));
        if(word_array[word_count]==NULL)
        {
            printf("Dynamic memory allocation failed for individual string\n");
            return;
        }
        j=0;
        while(i<n && input_string[i]!=' ')
        {
                word_array[word_count][j]=input_string[i];
                j++;
                i++;
        }
        word_array[word_count][j]='\0';
        word_count++;
        
    }
    for(int i=word_count-1;i>=0;i--)
    {
        printf("%s ",word_array[i]);
    }
    for(int i=0;i<word_count;i++)
    {
        free(word_array[i]);
    }
}
int main()
{
    char *input_string=(char*)malloc(Input_str_len*sizeof(char));
    if(input_string==NULL)
    {
        printf("Dynamic memory allocation failed\n");
        return 1;
    }
    printf("Enter the input string : ");
    scanf("%[^\n]",input_string);
    int n=length_string(input_string);
    char **word_array=(char**)malloc(100*sizeof(char*));
    if(word_array==NULL)
    {
        printf("Dynamic memory allocation failed for word array\n");
        return 1;
    }
    string_to_words(word_array,input_string,n);
    free(word_array);
    free(input_string);
    return 0;

}


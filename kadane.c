#include <stdio.h>
#include<stdlib.h>
int str_len(char* input_string)
{
    int l=0;
    while(input_string[l]!='\0')
    {
        l++;
    }
    return l;
}
int is_digit(char c)
{
    return (c>='0' && c<='9');
}
int find_maximum(int a,int b)
{
    if(a>b) return a;
    else return b;
}
void kadane_sum(int *elements_array,int word_count)
{
    int array_sum = 0;
    int maximum_sum = elements_array[0];
    for (int i = 0; i < word_count; i++)
    {
        array_sum += elements_array[i];
        maximum_sum = find_maximum(array_sum, maximum_sum);
        if (array_sum < 0)
        {
            array_sum = 0;
        }
    }
    printf("%d\n", maximum_sum);
}
void find_elements(char* input_string,int n)
{
    //finding no of elements
    int i=0;
    int word_count=0;
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
        if(is_digit(input_string[i]))
        {
            while(is_digit(input_string[i]))
            {
               i++; 
            }
            word_count++;
        }
        else if(input_string[i]=='-' && i<n && is_digit(input_string[i+1]))
        {
            i++;
            while(is_digit(input_string[i]))
            {
               i++; 
            }
            word_count++;
        }
        else {
            i++;
        }
    }
    //allocating memory
    int *elements_array=(int*)malloc(word_count*sizeof(int));
    if (!elements_array) {
        printf("Memory allocation failed\n");
        return;
    }
    i=0;
    word_count=0;
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
        if(is_digit(input_string[i]))
        {
            int number=0;
            while(is_digit(input_string[i]))
            {
               number = number * 10 + (input_string[i] - '0');
               i++; 
            }
            elements_array[word_count]=number;
            word_count++;
        }
        else if(input_string[i]=='-' && i<n && is_digit(input_string[i+1]))
        {
            i++;
            int number=0;
            while(is_digit(input_string[i]))
            {
               number = number * 10 + (input_string[i] - '0');
               i++; 
            }
            elements_array[word_count]=-number;
            word_count++;
        }
        else {
            i++;
        }
    }
    kadane_sum(elements_array,word_count);
    free(elements_array);
}
int main()
{
    char *input_string = (char*)malloc(100*sizeof(char));
    if (!input_string) {
        printf("Memory allocation failed\n");
        return 1;
    }
    scanf("%[^\n]",input_string);
    int n=str_len(input_string);
    find_elements(input_string,n);
    free(input_string);
    return 0;
}
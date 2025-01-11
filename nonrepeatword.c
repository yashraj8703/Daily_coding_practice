#include<stdio.h>
#include<stdlib.h>
#define input_str_len 100
int len_str(char* input_string)
{
    int l=0;
    while(input_string[l]!='\0')
    {
        l++;
    }
    return l;
}
int compare_str(char* str1,char* str2) {
    if (len_str(str1) != len_str(str2)) return 1;
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2) {
            return 1;
        }
        str1++;
        str2++;
    }
    return 0;
}

void find_word(char **word_array,int word_count)
{
    for (int i = 0; i < word_count; i++) {
        int isrepeat = 0;
        for (int j = 0; j < word_count; j++) {
            if (i != j && compare_str(word_array[i],word_array[j]) == 0) {
                isrepeat = 1;
                break;
            }
        }
        if (!isrepeat) {
            printf("%s\n", word_array[i]);
        }
    }
}
void words_in_array(char *input_string,int n)
{
    char **word_array=(char**)malloc(100*sizeof(char*));
    if(word_array==NULL)
    {
        printf("Dynamic Memory Allocation Failed for word array\n");
        return;
    }
    int word_count=0;
    int i=0,j=0;
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
        word_array[word_count]=(char*)malloc(100*sizeof(char));
        if(word_array[word_count]==NULL)
        {
            printf("Dynamic Memory Allocation Failed for word\n");
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
    find_word(word_array,word_count);
    for(int i=0;i<word_count;i++)
    {
        free(word_array[i]);
    }
    free(word_array);
}
int main()
{
    char *input_string=(char*)malloc(input_str_len*sizeof(char));
    if(input_string==NULL)
    {
        printf("Dynamic Memory Allocation Failed \n");
        return 1;
    }
    scanf("%[^\n]",input_string);
    int n=len_str(input_string);
    words_in_array(input_string,n);
    free(input_string);
}
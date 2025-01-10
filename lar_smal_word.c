#include <stdio.h>
void String_copy(char *destination_string, const char *source_string)
{
    while (*source_string != '\0')
    {
        *destination_string = *source_string;
        destination_string++;
        source_string++;
    }
    *destination_string = '\0';
}
int string_len(const char *str)
{
    int len = 0;
    while (*str != '\0')
    {
        len++;
        str++;
    }
    return len;
}
int if_space(char ch)
{
    return (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\v' || ch == '\f' || ch == '\r');
}

void largest_smallest_word(char word_array[100][100], int word_count)
{
    if (word_count == 0)
    {
        printf("No words found.\n");
        return;
    }
    char lar_str[100];
    char small_str[100];
    String_copy(lar_str, word_array[0]);
    String_copy(small_str, word_array[0]);
    for (int i = 1; i < word_count; i++)
    {
        if (string_len(word_array[i]) > string_len(lar_str))
        {
            String_copy(lar_str, word_array[i]);
        }
        if (string_len(word_array[i]) < string_len(small_str))
        {
            String_copy(small_str, word_array[i]);
        }
    }
    printf("largest word is '%s'\n", lar_str);
    printf("smallest word is '%s'\n", small_str);
}
void seperate_word_array(char *input_str, char word_array[100][100], int n)
{
    int i = 0, j = 0, word_count = 0;
    while (i < n && if_space(input_str[i]))
    {
        i++;
    }

    while (i < n)
    {
        if (!if_space(input_str[i]))
        {
            word_array[word_count][j] = input_str[i];
            j++;
        }
        else if (j > 0)
        {
            word_array[word_count][j] = '\0';
            word_count++;
            j = 0;
        }
        i++;
    }
    if (j > 0)
    {
        word_array[word_count][j] = '\0';
        word_count++;
    }
    largest_smallest_word(word_array,word_count);
}
int main()
{
    char input_str[100];
    scanf("%[^\n]", input_str);
    int n = string_len(input_str);
    char word_array[100][100];
    seperate_word_array(input_str, word_array, n);
    return 0;
}
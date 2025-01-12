#include <stdio.h>
#include <stdlib.h>

int is_alpha(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    {
        return 1;
    }
    return 0;
}

char to_lower(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
    {
        return ch + ('a' - 'A');
    }
    return ch;
}

int isogram_check(char *array)
{
    char frequency[26] = {0};
    int index;

    for (int i = 0; array[i] != '\0'; i++)
    {
        if (is_alpha(array[i]))
        {
            index = to_lower(array[i]) - 'a';
            frequency[index] += 1;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if (frequency[i] > 1)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n;
    printf("Enter the maximum string length: ");
    scanf("%d", &n);
    getchar();

    char *array = (char *)malloc(n * sizeof(char));
    if (array == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the string: ");
    scanf("%s", array);

    if (isogram_check(array))
    {
        printf("The string is an isogram.\n");
    }
    else
    {
        printf("The string is not an isogram.\n");
    }

    free(array);
    return 0;
}

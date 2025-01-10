#include <stdio.h>

int string_len(char *string)
{
    int len = 0;
    while (string[len] != '\0')
    {
        len++;
    }
    return len;
}

void binary_addition(char *string1, char *string2, char *result)
{
    int i = string_len(string1) - 1;
    int j = string_len(string2) - 1;
    int carry = 0;
    int index = 0;

    while (i >= 0 || j >= 0 || carry)
    {
        if (i >= 0)
        {
            carry += string1[i] - '0';
            i--;
        }
        if (j >= 0)
        {
            carry += string2[j] - '0';
            j--;
        }
        result[index] = (carry % 2) + '0';
        index++;
        carry = carry / 2;
    }

    result[index] = '\0';
    int start = 0;
    int end = string_len(result) - 1;
    while (start < end)
    {
        char temp = result[start];
        result[start] = result[end];
        result[end] = temp;
        start++;
        end--;
    }
}

int main()
{
    char string1[100];
    char string2[100];
    printf("Enter first binary number: ");
    scanf("%s", string1);
    printf("Enter second binary number: ");
    scanf("%s", string2);

    char result[250];
    binary_addition(string1, string2, result);
    printf("Binary addition is: %s\n", result);
    return 0;
}

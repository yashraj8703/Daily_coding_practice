#include <stdio.h>
#include <string.h>

void reverse_array(char arr[], int start, int end)
{
    while (start <= end)
    {
        char temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main()
{
    int k;
    char str[100];
    printf("Enter the string: ");
    scanf("%s", str);

    int size = strlen(str);
    printf("Enter how many times to rotate the string: ");
    scanf("%d", &k);
    
    k = k % size;
    
    reverse_array(str, 0, k - 1);
    reverse_array(str, k, size - 1);
    reverse_array(str, 0, size - 1);

    printf("String after rotation: %s\n", str);

    return 0;
}

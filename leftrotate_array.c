#include <stdio.h>
void reverse_array(int arr[], int start, int end)
{
    while (start <= end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
int main()
{
    int size;
    int k;
    printf("Enter the number of elements : ");
    scanf("%d", &size);
    printf("Enter how many times to rotate array : ");
    scanf("%d", &k);
    int array[size];
    printf("Enter the array elements : ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }
    k = k % size;
    reverse_array(array, 0, k - 1);
    reverse_array(array, k, size - 1);
    reverse_array(array, 0, size - 1);
    printf("Array after rotation is :");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }

    return 0;
}
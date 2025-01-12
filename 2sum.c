#include <stdio.h>
#include <stdlib.h>
void bubble_Sort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
}
void find_target(int *array, int n,int target)
{
    int i=0,j=n-1;
    while(i<j)
    {
        if(array[i]+array[j]==target)
        {
            printf("%d %d",array[i],array[j]);
            return;
        }
        if(array[i]+array[j]<target)
        {
            i++;
        }
        else{
            j--;
        }
    }
    printf("No pair found\n");
}
int main()
{
    int n;
    printf("Enter the nof of elements : ");
    scanf("%d", &n);
    int *array = (int *)malloc(n * sizeof(int));
    if (array == NULL)
    {
        printf("Memory allocation failed");
        return 1;
    }
    printf("Enter the elements : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    int target;
    printf("Enter the target element : ");
    scanf("%d", &target);
    bubble_Sort(array,n);
    find_target(array,n,target);
    free(array);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

void moveZeros(int n, int a[]) {
    int j = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            j = i;
            break;
        }
    }

    if (j == -1) return;

    for (int i = j + 1; i < n; i++) {
        if (a[i] != 0) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            j++;
        }
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int *arr = (int*)malloc(n * sizeof(int));
    if(arr==NULL)
    {
        printf("Memory allocation failed");
        return 1;
    }
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    moveZeros(n, arr);

    printf("Array after moving zeros: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}

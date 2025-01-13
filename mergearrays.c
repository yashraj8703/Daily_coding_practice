#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int* merge_arrays(int *arr1, int *arr2, int n, int m) {
    int left = n - 1;
    int right = 0;

    while (left >= 0 && right < m) {
        if (arr1[left] > arr2[right]) {
            int temp = arr1[left];
            arr1[left] = arr2[right];
            arr2[right] = temp;
        }
        left--;
        right++;
    }

    bubble_sort(arr1, n);
    bubble_sort(arr2, m);

    arr1 = (int*) realloc(arr1, (n + m) * sizeof(int));

    for (int i = n, k = 0; k < m; i++, k++) {
        arr1[i] = arr2[k];
    }

    return arr1;
}

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    int *arr1 = (int *)malloc(n * sizeof(int));
    int *arr2 = (int *)malloc(m * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }

    for (int i = 0; i < m; i++) {
        scanf("%d", &arr2[i]);
    }

    arr1 = merge_arrays(arr1, arr2, n, m);

    for (int i = 0; i < (n + m); i++) {
        printf("%d ", arr1[i]);
    }

    free(arr2);
    free(arr1);

    return 0;
}

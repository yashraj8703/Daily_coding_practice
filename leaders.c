#include <stdio.h>
#include <stdlib.h>

void leaders(int *arr, int n) {
    int *res = (int *)malloc(n * sizeof(int));
    int index = 0;
    int maxRight = arr[n - 1];
    
    res[index++] = maxRight;
    
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] >= maxRight) {
            maxRight = arr[i];
            res[index++] = maxRight;
        }
    }
    
    for (int i = index - 1; i >= 0; i--) {
        printf("%d ", res[i]);
    }
    printf("\n");
    
    free(res);
}

int main() {
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    leaders(arr, n);
    free(arr);
    return 0;
}

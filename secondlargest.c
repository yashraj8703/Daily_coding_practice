#include <stdio.h>

int find_second_largest(int *arr, int n) {
    int lar = arr[0], slar = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] > lar) {
            slar = lar;
            lar = arr[i];
        } else if (arr[i] > slar && arr[i] < lar) {
            slar = arr[i];
        }
    }
    return slar;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Second Largest is: %d\n", find_second_largest(arr, n));
    return 0;
}

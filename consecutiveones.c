#include <stdio.h>

int max_fun(int a, int b) {
    if(a>b) return a;
    else return b;
}

int find_max_consecutive_ones(int *arr, int n) {
    int count = 0, maxcount = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            count++;
            maxcount = max_fun(count, maxcount);
        } else {
            count = 0;
        }
    }
    return maxcount;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("%d\n", find_max_consecutive_ones(arr, n));
    return 0;
}

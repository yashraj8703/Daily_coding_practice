#include <stdio.h>
void AdjacentRowSwap(int n, int a[n][n])
{
    for(int i=0;i<n-1;i+=2)
    {
        for(int j=0;j<n;j++)
        {
            int temp=a[i][j];
            a[i][j]=a[i+1][j];
            a[i+1][j]=temp;
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int matrix[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    AdjacentRowSwap(n, matrix);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
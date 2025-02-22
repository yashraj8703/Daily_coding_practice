#include <stdio.h>
void DiagonalSum(int n, int matrix[n][n])
{
    int sum1=0;
    int sum2=0;
    for(int i=0;i<n;i++)
    {
            sum1+=matrix[i][i];
            sum2+=matrix[i][n-i-1];
    }
    printf("%d %d",sum1,sum2);
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
    DiagonalSum(n, matrix);
}
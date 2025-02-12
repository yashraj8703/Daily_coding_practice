#include <stdio.h>
void BoundaryTraversal(int n,int matrix[n][n])
{
    int i=0;
    for(int i=0;i<n;i++)
    {
        printf("%d ",matrix[0][i]);
    }
    for(int i=1;i<n;i++)
    {
        printf("%d ",matrix[i][n-1]);
    }
    for(int i=n-2;i>=0;i--)
    {
        printf("%d ",matrix[n-1][i]);
    }
    for(int i=n-2;i>=1;i--)
    {
        printf("%d ",matrix[i][0]);
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
    BoundaryTraversal(n, matrix);
    
}
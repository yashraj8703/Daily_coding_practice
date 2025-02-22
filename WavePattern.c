#include <stdio.h>
void WavePattern(int n, int matrix[n][n])
{
    //column wise
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%d ", matrix[j][i]);
            }
        }
        else
        {
            for (int j = n-1; j >=0; j--)
            {
                printf("%d ", matrix[j][i]);
            }
        }
    }
    // row wise
    // for (int i = 0; i < n; i++)
    // {
    //     if (i % 2 == 0)
    //     {
    //         for (int j = 0; j < n; j++)
    //         {
    //             printf("%d ", matrix[i][j]);
    //         }
    //     }
    //     else
    //     {
    //         for (int j = n-1; j >=0; j--)
    //         {
    //             printf("%d ", matrix[i][j]);
    //         }
    //     }
    // }
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
    WavePattern(n, matrix);
}
#include <stdio.h>

void diagonal_matrix(int n, int m, int matrix[n][m])
{
    for (int i = 0; i < n && i < m; i++)
    {
        int temp = matrix[i][i];
        matrix[i][i] = matrix[i][m - 1 - i];
        matrix[i][m - 1 - i] = temp;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int n, m;
    printf("Enter the value of n and m : ");
    scanf("%d", &n);
    scanf("%d", &m);
    int matrix[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    diagonal_matrix(n, m, matrix);
    return 0;
}
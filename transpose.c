#include <stdio.h>
void rotateMatrix(int n, int matrix[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int s = 0;
            int e = n - 1;
            while (s < e)
            {
                int temp = matrix[i][s];
                matrix[i][s]=matrix[i][e];
                matrix[i][e]=temp;
                s++;
                e--;
            }
        }
    }
}
void transpose(int n, int matrix[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    rotateMatrix(n,matrix);
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
    transpose(n, matrix);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
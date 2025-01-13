#include <stdio.h>
#include <stdlib.h>

void matrix_multiplication(int **matrix1, int **matrix2, int **finalMatrix, int row1, int col1, int row2, int col2)
{
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            int sum = 0;
            for (int k = 0; k < col1; k++)
            {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            finalMatrix[i][j] = sum;
        }
    }
}

int main()
{
    int row1, col1, row2, col2;

    printf("Enter rows and columns for matrix1: ");
    scanf("%d %d", &row1, &col1);

    printf("Enter rows and columns for matrix2: ");
    scanf("%d %d", &row2, &col2);

    if (col1 != row2)
    {
        printf("Matrix multiplication is not possible\n");
        return 1;
    }

    int **matrix1 = (int **)malloc(row1 * sizeof(int *));
    for (int i = 0; i < row1; i++)
    {
        matrix1[i] = (int *)malloc(col1 * sizeof(int));
    }

    int **matrix2 = (int **)malloc(row2 * sizeof(int *));
    for (int i = 0; i < row2; i++)
    {
        matrix2[i] = (int *)malloc(col2 * sizeof(int));
    }

    int **finalMatrix = (int **)malloc(row1 * sizeof(int *));
    for (int i = 0; i < row1; i++)
    {
        finalMatrix[i] = (int *)malloc(col2 * sizeof(int));
    }

    printf("Enter elements of matrix1:\n");
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter elements of matrix2:\n");
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            scanf("%d", &matrix2[i][j]);
        }
    }

    matrix_multiplication(matrix1, matrix2, finalMatrix, row1, col1, row2, col2);

    printf("Resultant matrix after multiplication:\n");
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            printf("%d ", finalMatrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < row1; i++)
    {
        free(matrix1[i]);
    }
    free(matrix1);

    for (int i = 0; i < row2; i++)
    {
        free(matrix2[i]);
    }
    free(matrix2);

    for (int i = 0; i < row1; i++)
    {
        free(finalMatrix[i]);
    }
    free(finalMatrix);

    return 0;
}

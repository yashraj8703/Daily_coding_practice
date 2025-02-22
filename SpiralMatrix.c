#include <stdio.h>
void SpiralMatrix(int n,int matrix[n][n])
{
    int rowStart=0;
    int rowEnd=n-1;
    int colStart=0;
    int colEnd=n-1;
    while(rowStart<=rowEnd && colStart<=colEnd)
    {
        for(int i=colStart;i<=colEnd;i++)
        {
            printf("%d ",matrix[rowStart][i]);
        }
        rowStart++;
        for(int i=rowStart;i<=rowEnd;i++)
        {
            printf("%d ",matrix[i][colEnd]);
        }
        colEnd--;
        if(rowStart<=rowEnd)
        {
            for(int i=colEnd;i>=colStart;i--)
            {
                printf("%d ",matrix[rowEnd][i]);
            }
            rowEnd--;
        }     
        if(colStart<=colEnd)
        {   
            for(int i=rowEnd;i>=rowStart;i--)
            {
                printf("%d ",matrix[i][colStart]);
            }
            colStart++;
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
    SpiralMatrix(n, matrix);
    
}
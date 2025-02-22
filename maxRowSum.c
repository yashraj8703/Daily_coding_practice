#include <stdio.h>
int maxi(int a ,int b)
{
    if(a>b) return a;
    else return b;
}
void maxRowSum(int n,int matrix[n][n])
{
    int sum=0;
    int max_sum=sum;
    for(int i=0;i<n;i++)
    {
        sum=0;
        for(int j=0;j<n;j++)
        {
            sum+=matrix[i][j];
        }
        max_sum=maxi(max_sum,sum);
        
    }
    printf("%d",max_sum);
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
    maxRowSum(n, matrix);
    
}
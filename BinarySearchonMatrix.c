#include <stdio.h>
int binary(int arr[],int target,int m)
{
    int l=0;
    int e=m-1;
    while(l<=e)
    {
        int m=(l+e)/2;
        if(arr[m]==target)
        {
            return 1;
        }
        if(arr[m]>target)
        {
            e=m-1;
        }
        else{
            l=m+1;
        }
    }
    return 0;
}
int BinarySearch(int n, int m,int matrix[n][m],int target)
{
    for(int i=0;i<n;i++)
    {
        if(matrix[i][0]<=target && target<=matrix[i][m-1])
        {
            return binary(matrix[i],target,m);
        }
    }
    return 0;
    
}
int main()
{
    int n,m;
    scanf("%d %d", &n,&m);
    int matrix[n][m];
    int target;
    scanf("%d",&target);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    if(BinarySearch(n, m,matrix,target))
    {
        printf("present");
    }
    else{
        printf("not present");
    }
}
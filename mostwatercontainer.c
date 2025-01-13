#include <stdio.h>
#include <stdlib.h>
int find_max(int a, int b)
{
    if(a>b) return a;
    else return b;
}
int find_min(int a, int b)
{
    if(a<b) return a;
    else return b;
}
void find_max_area(int *height_array,int n){
    int area=0;
    int start=0;
    int end=n-1;
    while(start<end)
    {
        int base=end-start;
        int height=find_min(height_array[start],height_array[end]);
        area=find_max(area,height*base);
        if(height_array[start]<height_array[end])
        {
            start++;
        }
        else{
            end--;
        }
    }
    printf("heighest area : %d",area);
}
int main()
{
    int n;
    scanf("%d",&n);
    int *height_array=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        scanf("%d",&height_array[i]);
    }
    find_max_area(height_array,n);
    free(height_array);
    return 0;
}
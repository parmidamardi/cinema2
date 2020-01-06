#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *arr,int y,int x)
{
    int temp;
    temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}
int func(int *arr, int start, int end)
{
    srand(time(NULL));
    int point = start + (rand()%(end - start));
    swap(arr,start,point);
    point = start + 1;
    for(int i = start + 1; i <= end; i++)
    {
        if(arr[i] < arr[start])
        {
            swap(arr, i, point);
            point++;
        }
    }
    swap(arr, start, (point-1));
    return (point - 1);
   
}
void quicksort(int *arr, int start, int end)
{
    int point;
    if(start < end)
    {
        point = func(arr,start,end);
        quicksort(arr, start, point-1);
        quicksort(arr, point + 1, end);
    }
}
int main()
{
   int arr[15] = {1,1,1,1,2,4,5,7,3,2,1,0,-3,5,6};
   quicksort(arr,0,14);
   for(int i =0;i<15;i++)
   printf("%d ",arr[i]);
}
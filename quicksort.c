#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct time
{
    int hour;
    int min;
    int sec;
};
void swap(struct time t[],int y,int x)
{
    struct time temp;
    temp.hour = t[x].hour;
    temp.min = t[x].min;
    temp.sec = t[x].sec;
    t[x].hour = t[y].hour;
    t[x].min = t[y].min;
    t[x].sec = t[y].sec;
    t[y].hour = temp.hour;
    t[y].min = temp.min;
    t[y].sec = temp.sec;
}
int func(struct time t[], int start, int end)
{
    srand(time(NULL));
    int point = start + (rand()%(end - start));
    swap(t,start,point);
    point = start + 1;
    for(int i = start + 1; i <= end; i++)
    {
        if(t[i].hour < t[start].hour)
        {
            swap(t, i, point);
            point++;
        }
    }
    swap(t, start, (point-1));
    return (point - 1);
   
}
void quicksort(struct time t[], int start, int end)
{
    int point;
    if(start < end)
    {
        point = func(t,start,end);
        quicksort(t, start, point-1);
        quicksort(t, point + 1, end);
    }
}
int main()
{
    struct time t[4];
    t[0].hour = 3;
    t[0].min = 3;
    t[0].sec = 3;
    t[1].hour = 5;
    t[1].min = 5;
    t[1].sec = 5;
    t[2].hour = 1;
    t[2].min = 1;
    t[2].sec = 1;
    t[3].hour = 8;
    t[3].min = 8;
    t[3].sec = 8;
   //int arr[15] = {1,1,1,1,2,4,5,7,3,2,1,0,-3,5,6};
   quicksort(t,0,3);
   for(int i =0;i<4;i++)
   {
        printf("%d:%d:%d\n",t[i].hour,t[i].min,t[i].sec);
   }
}
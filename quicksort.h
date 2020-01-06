#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//structs
struct Movie
{
    char movieName[200];
    char summary[10000];
    char movieJenre[100];
};
struct Starting
{
    int startHour;
    int startMin;
    int startSec;
};
struct Ending
{
    int endHour;
    int endMin;
    int endSec;
};
struct Sons
{
    char todayDate[100];
    struct Movie Film;
    struct Starting StartTime;
    struct Ending EndTime;
    int emptySeats;
};
void swap(struct Sons Sonses[],int y,int x)
{
    struct Sons Temp;
    strcpy(Temp.todayDate,Sonses[x].todayDate);
    strcpy(Temp.Film.movieName,Sonses[x].Film.movieName);
    strcpy(Temp.Film.summary,Sonses[x].Film.summary);
    strcpy(Temp.Film.movieJenre,Sonses[x].Film.movieJenre);
    Temp.StartTime.startHour = Sonses[x].StartTime.startHour;
    Temp.StartTime.startMin = Sonses[x].StartTime.startMin;
    Temp.StartTime.startSec = Sonses[x].StartTime.startSec;
    Temp.EndTime.endHour = Sonses[x].EndTime.endHour;
    Temp.EndTime.endMin = Sonses[x].EndTime.endMin;
    Temp.EndTime.endSec = Sonses[x].EndTime.endSec;
    Temp.emptySeats = Sonses[x].emptySeats;

    strcpy(Sonses[x].todayDate,Sonses[y].todayDate);
    strcpy(Sonses[x].Film.movieName,Sonses[y].Film.movieName);
    strcpy(Sonses[x].Film.summary,Sonses[y].Film.summary);
    strcpy(Sonses[x].Film.movieJenre,Sonses[y].Film.movieJenre);
    Sonses[x].StartTime.startHour = Sonses[y].StartTime.startHour;
    Sonses[x].StartTime.startMin = Sonses[y].StartTime.startMin;
    Sonses[x].StartTime.startSec = Sonses[y].StartTime.startSec;
    Sonses[x].EndTime.endHour = Sonses[y].EndTime.endHour;
    Sonses[x].EndTime.endMin = Sonses[y].EndTime.endMin;
    Sonses[x].EndTime.endSec = Sonses[y].EndTime.endSec;
    Sonses[x].emptySeats = Sonses[y].emptySeats;

    strcpy(Sonses[y].todayDate,Temp.todayDate);
    strcpy(Sonses[y].Film.movieName,Temp.Film.movieName);
    strcpy(Sonses[y].Film.summary,Temp.Film.summary);
    strcpy(Sonses[y].Film.movieJenre,Temp.Film.movieJenre);
    Sonses[y].StartTime.startHour = Temp.StartTime.startHour;
    Sonses[y].StartTime.startMin = Temp.StartTime.startMin;
    Sonses[y].StartTime.startSec = Temp.StartTime.startSec;
    Sonses[y].EndTime.endHour = Temp.EndTime.endHour;
    Sonses[y].EndTime.endMin = Temp.EndTime.endMin;
    Sonses[y].EndTime.endSec = Temp.EndTime.endSec;
    Sonses[y].emptySeats = Temp.emptySeats;
}
int func(struct Sons Sonses[], int start, int end)
{
    srand(time(NULL));
    int point = start + (rand()%(end - start));
    swap(Sonses,start,point);
    point = start + 1;
    for(int i = start + 1; i <= end; i++)
    {
        if(Sonses[i].StartTime.startHour < Sonses[start].StartTime.startHour)
        {
            swap(Sonses, i, point);
            point++;
        }
        else if(Sonses[i].StartTime.startHour == Sonses[start].StartTime.startHour)
        {
            if(Sonses[i].StartTime.startMin < Sonses[start].StartTime.startMin)
            {
                swap(Sonses, i, point);
                point++;
            }
            else if(Sonses[i].StartTime.startMin == Sonses[start].StartTime.startMin)
            {
                if(Sonses[i].StartTime.startSec < Sonses[start].StartTime.startSec)
                {
                    swap(Sonses, i, point);
                    point++;
                }
            }   
        }
    }
    swap(Sonses, start, (point-1));
    return (point - 1);
   
}
void quicksort(struct Sons Sonses[], int start, int end)
{
    int point;
    if(start < end)
    {
        point = func(Sonses,start,end);
        quicksort(Sonses, start, point-1);
        quicksort(Sonses, point + 1, end);
    }
}
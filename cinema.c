#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "quicksort.h"
//time
void date(char time2[])
{
    time_t current_time;
    char* c_time_string;

    /* Obtain current time. */
    current_time = time(NULL);

    if (current_time == ((time_t)-1))
    {
        (void) fprintf(stderr, "Failure to obtain the current time.\n");
        exit(EXIT_FAILURE);
    }

    /* Convert to local time format. */
    c_time_string = ctime(&current_time);

    if (c_time_string == NULL)
    {
        (void) fprintf(stderr, "Failure to convert the current time.\n");
        exit(EXIT_FAILURE);
    }

    /* Print to stdout. ctime() has already added a terminating newline character. */
    strcpy(time2,c_time_string);
    // exit(EXIT_SUCCESS);
    
}
void todayDate(char time[],char today[])
{
    int cnt = 0;
    int i;
    for(i = 0;cnt < 3;i++)
    {
        today[i] = time[i];
        if(time[i] == ' ')
        {
            cnt++;
            if(cnt != 3)
            today[i] = '-';
        }
    }
    today[i] = '\0';
}
void clockTime(char time[],int *hour, int *min, int *sec)
{
   int cnt = 0;
   for(int i = 0;cnt < 4;i++)
   {
      if(time[i] == ' ')
      {
          cnt++;
      }
      if(cnt == 3)
      {
          *hour = (time[i+1]-'0')*10 + (time[i+2]-'0');
          *min = (time[i+4]-'0')*10 + (time[i+5]-'0');
          *sec = (time[i+7]-'0')*10 + (time[i+8]-'0');
          break;
      }
   }
}
int sonsCheck(struct Sons TodaySons,struct Sons Allsons[])
{
    for(int i = 0;i < 10; i++)
    {
        if(i == 0)
        {
            if(TodaySons.EndTime.endHour < Allsons[i].StartTime.startHour)
                return 1;
            else if(TodaySons.EndTime.endHour == Allsons[i].StartTime.startHour)
            {
               if(TodaySons.EndTime.endMin < Allsons[i].StartTime.startMin)
                   return 1;
                else if(TodaySons.EndTime.endMin == Allsons[i].StartTime.startMin)
                {
                    if(TodaySons.EndTime.endSec <= Allsons[i].StartTime.startSec)
                        return 1;
                }                
            }
        }
        if(TodaySons.StartTime.startHour > Allsons[i].EndTime.endHour)
        {
            if(TodaySons.EndTime.endHour < Allsons[i+1].StartTime.startHour || Allsons[i+1].StartTime.startHour == 100)
            {
                return 1;
            }
            else if (TodaySons.EndTime.endHour == Allsons[i+1].StartTime.startHour)
            {
                if(TodaySons.EndTime.endMin < Allsons[i+1].StartTime.startMin)
                {
                    return 1;
                }
                else if (TodaySons.EndTime.endMin == Allsons[i+1].StartTime.startMin)
                {
                    if(TodaySons.EndTime.endSec <= Allsons[i+1].StartTime.startSec)
                    {
                        return 1;
                    }
        
                }
                    
            }
        }
        else if(TodaySons.StartTime.startHour == Allsons[i].EndTime.endHour)
        {
            if(TodaySons.StartTime.startMin > Allsons[i].EndTime.endMin)
            {
                if(TodaySons.EndTime.endHour < Allsons[i+1].StartTime.startHour || Allsons[i+1].StartTime.startHour == 100)
                {
                    return 1;
                }
                else if (TodaySons.EndTime.endHour == Allsons[i+1].StartTime.startHour)
                {
                    if(TodaySons.EndTime.endMin < Allsons[i+1].StartTime.startMin)
                    {
                        return 1;
                    }
                    else if (TodaySons.EndTime.endMin == Allsons[i+1].StartTime.startMin)
                    {
                        if(TodaySons.EndTime.endSec <= Allsons[i+1].StartTime.startSec)
                        {
                            return 1;
                        }
            
                    }
                        
                }
            }
            else if(TodaySons.StartTime.startMin == Allsons[i].EndTime.endMin)
            {
                if(TodaySons.StartTime.startSec > Allsons[i].EndTime.endSec)
                {
                    if(TodaySons.EndTime.endHour < Allsons[i+1].StartTime.startHour || Allsons[i+1].StartTime.startHour == 100) 
                    {
                        return 1;
                    }
                    else if (TodaySons.EndTime.endHour == Allsons[i+1].StartTime.startHour)
                    {
                        if(TodaySons.EndTime.endMin < Allsons[i+1].StartTime.startMin)
                        {
                            return 1;
                        }
                        else if (TodaySons.EndTime.endMin == Allsons[i+1].StartTime.startMin)
                        {
                            if(TodaySons.EndTime.endSec <= Allsons[i+1].StartTime.startSec)
                            {
                                return 1;
                            }
                
                        }
                            
                    }

                }
            }
        }
        
        
    }
    return 0;
}
int main()
{
    char time[50];
    char today[100];
    int hour,min,sec;
    int state;
    int sonsCounter = 0;
    date(time);
    todayDate(time,today);
    clockTime(time,&hour,&min,&sec);
    FILE *sons;
    sons = fopen("sonss.txt","r+");
    struct Sons TodaySons;
    struct Sons Allsons[10];
    for(int i = 0;i < 10;i++)
    {
        Allsons[i].StartTime.startHour = 100;
        Allsons[i].StartTime.startMin = 100;
        Allsons[i].StartTime.startSec = 100;
        Allsons[i].EndTime.endHour = 100;
        Allsons[i].EndTime.endMin = 100;
        Allsons[i].EndTime.endSec = 100;
    }
    while(!feof(sons))
    {
        printf("injaaaaaaaaaaa\n\n");
        fscanf(sons,"%s %s %s %s %d:%d:%d %d:%d:%d %d\n",&Allsons[sonsCounter].todayDate,&Allsons[sonsCounter].Film.movieName,&Allsons[sonsCounter].Film.summary,&Allsons[sonsCounter].Film.movieJenre,&Allsons[sonsCounter].StartTime.startHour,&Allsons[sonsCounter].StartTime.startMin,&Allsons[sonsCounter].StartTime.startSec,&Allsons[sonsCounter].EndTime.endHour,&Allsons[sonsCounter].EndTime.endMin,&Allsons[sonsCounter].EndTime.endSec,&Allsons[sonsCounter].emptySeats);
        printf("%s %s %s %s %d:%d:%d %d:%d:%d %d\n",Allsons[sonsCounter].todayDate,Allsons[sonsCounter].Film.movieName,Allsons[sonsCounter].Film.summary,Allsons[sonsCounter].Film.movieJenre,Allsons[sonsCounter].StartTime.startHour,Allsons[sonsCounter].StartTime.startMin,Allsons[sonsCounter].StartTime.startSec,Allsons[sonsCounter].EndTime.endHour,Allsons[sonsCounter].EndTime.endMin,Allsons[sonsCounter].EndTime.endSec,Allsons[sonsCounter].emptySeats);
        sonsCounter++;
    }
    quicksort(Allsons,0,9);
    for(int i = 0;i<10;i++)
    {
            printf("\n%s %s %s %s %d:%d:%d %d:%d:%d %d\n\n",Allsons[i].todayDate,Allsons[i].Film.movieName,Allsons[i].Film.summary,Allsons[i].Film.movieJenre,Allsons[i].StartTime.startHour,Allsons[i].StartTime.startMin,Allsons[i].StartTime.startSec,Allsons[i].EndTime.endHour,Allsons[i].EndTime.endMin,Allsons[i].EndTime.endSec,Allsons[i].emptySeats);
    }
    strcpy(TodaySons.todayDate,today);
    printf("1.Ezafe kardan sons\n2.kharide bilit\nshomare mored nazar: ");
    scanf("%d",&state);
    while(state != 1 && state != 2)
    {
        printf("shomare vared shode eshtebah ast\nshomare mored nazar:");
        scanf("%d",&state);
    } 
    if(state == 1)
    {
        int trueOrFalse;
        printf("be jaye space '-' begozarid!!!\n");
        strcpy(TodaySons.todayDate,today);
        printf("adding sons\nmovie name:");
        scanf("%s",TodaySons.Film.movieName);
        printf("movie summary:\t");
        scanf("%s",TodaySons.Film.summary);
        printf("movie jenre:\t");
        scanf("%s",TodaySons.Film.movieJenre);
        printf("movie start time(hour:min:sec):\t");
        scanf("%d:%d:%d",&TodaySons.StartTime.startHour,&TodaySons.StartTime.startMin,&TodaySons.StartTime.startSec);
        printf("movie end time(hour:min:sec):\t");
        scanf("%d:%d:%d",&TodaySons.EndTime.endHour,&TodaySons.EndTime.endMin,&TodaySons.EndTime.endSec);
        printf("empty seats number:\t");
        scanf("%d",&TodaySons.emptySeats);
        trueOrFalse = sonsCheck(TodaySons,Allsons);
        while(trueOrFalse == 0)
        {
            printf("sonsha tadakhol dashtand dobare talash konid:\n");
            printf("be jaye space '-' begozarid!!!\n");
            strcpy(TodaySons.todayDate,today);
            printf("adding sons\nmovie name:");
            scanf("%s",TodaySons.Film.movieName);
            printf("movie summary:\t");
            scanf("%s",TodaySons.Film.summary);
            printf("movie jenre:\t");
            scanf("%s",TodaySons.Film.movieJenre);
            printf("movie start time(hour:min:sec):\t");
            scanf("%d:%d:%d",&TodaySons.StartTime.startHour,&TodaySons.StartTime.startMin,&TodaySons.StartTime.startSec);
            printf("movie end time(hour:min:sec):\t");
            scanf("%d:%d:%d",&TodaySons.EndTime.endHour,&TodaySons.EndTime.endMin,&TodaySons.EndTime.endSec);
            printf("empty seats number:\t");
            scanf("%d",&TodaySons.emptySeats); 
            trueOrFalse = sonsCheck(TodaySons,Allsons);
        }
        fprintf(sons,"%s %s %s %s %d:%d:%d %d:%d:%d %d\n",TodaySons.todayDate,TodaySons.Film.movieName,TodaySons.Film.summary,TodaySons.Film.movieJenre,TodaySons.StartTime.startHour,TodaySons.StartTime.startMin,TodaySons.StartTime.startSec,TodaySons.EndTime.endHour,TodaySons.EndTime.endMin,TodaySons.EndTime.endSec,TodaySons.emptySeats);
        fclose(sons);
        
    }

}
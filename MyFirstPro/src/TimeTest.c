#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

void initGui();                   //process head;
void selectFunc();                //select functions;
char * PrintfTodayData();         //puts today data;
void PrintfThisMonthData();       //puts this month calendar;
void PrintfTodaySche();           //puts today class;
void SearchSche();                //look for class schedue;
void Compre();                    //compare weekday;

int main(void)
{

    initGui();
    selectFunc();

    return 0;
}


void initGui()
{
    system("clear");
    puts("-------------------------------------");
    puts("1:looking for today data");
    puts("2:looking for this month calender");
    puts("3:looking for today class schedule");
    puts("4:looking for class schedule");
    puts("5:exit the system");
    puts("-------------------------------------");
    puts("please input your select");
}

void selectFunc()
{
    int flag;
       
    while(1)
    {
        scanf("%d",&flag);
        if(5 == flag)
            exit(0);
        else
         {
             switch(flag)
             {
                 case 1:
                    PrintfTodayData();
                    break;
                 case 2:
                    PrintfThisMonthData();
                    break;
                 case 3:
                    PrintfTodaySche();
                    break;
                 case 4:
                    Compre();
                    break;
                 case 5:
                    exit(0);
                 default:
                    printf("intput error\n");
                    break;
             }
        }
        puts("please select continue");
    }
}

char * PrintfTodayData()
{
   char *array;
   time_t timep;

   time(&timep);
   array = ctime(&timep);

   printf("%s",array);
}

void PrintfThisMonthData()
{
    int i;
    pid_t pid;

    pid = fork();
    wait();//prime(parent) process wait child deaded,then parent continue run;

    if(pid == 0)
    {
       i =  execl("/usr/bin/cal","cal",NULL);
       printf("%d\n",i);
       exit(1);
    }
}
void PrintfTodaySche()
{
    
/****************************to be continued*************************************/
        char *array;
        char arr[3];
        //arr = NULL;

        time_t timep;

        time(&timep);
        array = ctime(&timep);

        strncpy(arr,array,3);
        fflush(stdin); 
       
        strcat(arr,"\n"); 
        SearchSche(arr);
}
void SearchSche(char *arr)
{
    
    FILE *fp;
    char array[100];
    int i;

    if((fp = fopen("../etc/course.txt","r")) == NULL )
    {
        perror("open file error");
        exit(1);
    }
    else
    {
        while(fgets(array,100,fp) !=NULL)
             if(strcmp(arr,array) == 0)
              {
                  for( i = 0;i < 4; i++)
                  {
                     fgets(array,100,fp);
                     puts(array);
            
                  }
             }
          
    }
    fclose(fp);
}

void Compre()
{
    void  (* p)(char *) = SearchSche;
    char arr[20];
    int i;

    puts("Please input you wang search day,such as 1,2,3,4,5,6,7");
    scanf("%d",&i);
  
    switch(i)
    {
        case 1:
            printf("out?\n");
            (* p)("Mon\n");
            break;
        case 2:
            (* p)("Tes\n");
            break;
        case 3:
            (* p)("Wes\n");
            break;
        case 4:
            (* p)("Thr\n");
            break;
        case 5:
            (* p)("Fri\n");
            break;
        case 6:
            (* p)("Sat\n");
            break;
        case 7:
            (* p)("Sun\n");
            break;
        default:
             printf("intput error\n");
             break;
    }
    
}

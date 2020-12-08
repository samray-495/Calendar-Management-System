#include <stdio.h>
#include <stdlib.h>


void calendar22(int hi){
int firstweekday(int year){

  int d;
  d = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7;
  return d;
}

int calendarsetup(void)
{
   int year,month,day,daysinmonth,weekday=0,startday;
   printf("\nEnter your desired year:");
   scanf("%d",&year);

   char *months[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
   int monthday[]={31,28,31,30,31,30,31,31,30,31,30,31};

   if((year%4==0&&year%100!=0)||year%400==0)
       monthday[1]=29;

   startday=firstweekday(year);

   for(month=0;month<12;month++){

      daysinmonth=monthday[month];
      printf("\n\n---------------%s---------------\n",months[month]);
      printf("\n  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

      for(weekday=0;weekday<startday;weekday++)
        printf("     ");

      for(day=1;day<=daysinmonth;day++){
        printf("%5d",day);

        if(++weekday>6){
            printf("\n");
            weekday=0;
        }
        startday=weekday;
      }
   }
   }
   int page;
printf("\n1) View Calendar\n");
printf("2) Back To Main Menu\n");
printf("3) EXIT PROGRAM\n");
printf("Select an option: ");
scanf("%d", &page);
switch(page){
case 1:
calendarsetup();
case 2:
//cal();
printf("hello");

case 3:
system("cls");
printf("Exiting the view calendar . . .\n");
system("pause");
break;
}
}
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

void read_note(int month)
{
    FILE *f;
    char note[60],loc[100];
    switch(month)
    {
        case 1:strcpy(loc,"Jan");break;
        case 2:strcpy(loc,"Feb");break;
        case 3:strcpy(loc,"Mar");break;
        case 4:strcpy(loc,"Apr");break;
        case 5:strcpy(loc,"May");break;
        case 6:strcpy(loc,"Jun");break;
        case 7:strcpy(loc,"Jul");break;
        case 8:strcpy(loc,"Aug");break;
        case 9:strcpy(loc,"Sep");break;
        case 10:strcpy(loc,"Oct");break;
        case 11:strcpy(loc,"Nov");break;
        case 12:strcpy(loc,"Dec");break;

    }
    f=fopen(loc,"r");
    while(fgets(note,59,f)!=NULL)
    {
        printf("                                                 ");
        puts(note);
    }
    fclose(f);
}

void write_note(int month)
{
    FILE *f;
    char loc[100],note[60];
    switch(month)
    {
        case 1:strcpy(loc,"Jan");break;
        case 2:strcpy(loc,"Feb");break;
        case 3:strcpy(loc,"Mar");break;
        case 4:strcpy(loc,"Apr");break;
        case 5:strcpy(loc,"May");break;
        case 6:strcpy(loc,"Jun");break;
        case 7:strcpy(loc,"Jul");break;
        case 8:strcpy(loc,"Aug");break;
        case 9:strcpy(loc,"Sep");break;
        case 10:strcpy(loc,"Oct");break;
        case 11:strcpy(loc,"Nov");break;
        case 12:strcpy(loc,"Dec");break;

    }
    fflush(stdin);
    printf("\n\tEnter the Note : ");
    gets(note);
    f=(fopen(loc,"a"));
        if(f==NULL)
        printf("\n\tERROR");
        else
        printf("\n\tSUCESSFULL");
    fputs(note,f);
    fclose(f);
}


void main()
{
   int year,days=0,gap=0,month,leap=0,jan_start,non_leap=0,feb=28;
   system("COLOR E0");
   system("title Bibhas\\Calender");
   printf("\tEnter the Year : ");
   scanf("%d",&year);




   for(int i=1;i<year;i++)
   {
       if(i%4==0 && i%100!=0 || i%400==0)
        leap++;

        else
        non_leap++;
   }

   days=((leap*366)+(non_leap*365));
   jan_start=(days%7);

   printf("\n");

   switch(jan_start)
   {
       case 5: gap=6;break;//saturday
       case 6: gap=0;break;
       case 0: gap=1;break;
       case 1: gap=2;break;
       case 2: gap=3;break;
       case 3: gap=4;break;
       case 4: gap=5;break;//friday
   }


    if(year%4==0 && year%100!=0 || year%400==0)
        feb=29;

  printf("\n************************************************************************************************************************");
  printf("\t\t\t\t%d\t\t\t<<<<** CALENDER **>>>> \t  \t \t  %d",year,year);
  printf("\n************************************************************************************************************************\n");

   for(month=1;month<=12;month++)
   {
      switch(month)
      {
      case 1: printf("\n\t\tJanuary\n");read_note(1);break;
      case 2: printf("\t\t\tFebruary\n");read_note(2);break;
      case 3: printf("\t\t\t  March\n");read_note(3);break;
      case 4: printf("\t\t\t  April\n");read_note(4);break;
      case 5: printf("\t\t\t  May\n");read_note(5);break;
      case 6: printf("\t\t\t  June\n");read_note(6);break;
      case 7: printf("\t\t\t July\n");read_note(7);break;
      case 8: printf("\t\t\t  August\n");read_note(8);break;
      case 9: printf("\t\t\tSepetember\n");read_note(9);break;
      case 10: printf("\t\t\tOctober\n");read_note(10);break;
      case 11: printf("\t\t\tNovember\n");read_note(11);break;
      case 12: printf("\t\t\tDecember\n");read_note(12);break;
      }


     if(month%2!=0 && month<8)
     {     int j,count=0;

           printf("\tSu  Mo  Tu  We  Th  Fr  Sa\n");
             printf("\t");
           for(j=0;j<gap;j++)
             {printf("    ");}

           for(int i=1;i<=31;i++)
            {


            if(i<10)
            printf(" ");

            printf("%d  ",i);
            count++;
            if((count+j)==7)
            {
                j=0;
                count=0;
                printf("\n\t");
            }

            gap=count;
            }

            printf("\n\n************************************************************************************************************************");
     }





     else if(month==2)
     {
           int j,count=0;
            printf("\tSu  Mo  Tu  We  Th  Fr  Sa\n");
           printf("\t");
           for(j=0;j<gap;j++)
           {printf("    ");}

            for(int i=1;i<=feb;i++)
            {
            if(i<10)
            printf(" ");
            printf("%d  ",i);
            count++;
            if((count+j)==7)
            {
                j=0;
                count=0;
                printf("\n\t");
            }
            gap=count;
            }
             printf("\n\n************************************************************************************************************************");
     }




     else if(month%2==0 && month>7)
     {
         int j,count=0;

          printf("\tSu  Mo  Tu  We  Th  Fr  Sa\n");
         printf("\t");
         for(j=0;j<gap;j++)
         {printf("    ");}

         for(int i=1;i<=31;i++)
            {
            if(i<10)
            printf(" ");
            printf("%d  ",i);
            count++;
            if((count+j)==7)
            {
                j=0;
                count=0;
                printf("\n\t");
            }
            gap=count;
             }
               printf("\n\n************************************************************************************************************************");
     }


     else
        {
        int j,count=0;
         printf("\tSu  Mo  Tu  We  Th  Fr  Sa\n");
        printf("\t");
        for(j=0;j<gap;j++)
        {printf("    ");}

        for(int i=1;i<=30;i++)
        {
        if(i<10)
        printf(" ");
        printf("%d  ",i);
        count++;

        if((count+j)==7)
        {
            j=0;
            count=0;
            printf("\n\t");
        }
        gap=count;
        }
          printf("\n\n************************************************************************************************************************");
        }

   }


     int ch,sv;
     printf("\n\n\tTo creat a note enter 1 & exit type any key.");
     printf("\n\tJarvis : ");
     scanf("%d",&ch);

     if(ch==1)
     {
         printf("\n\tTo save a note please enter the mounth's number (Ex. 1,2,3...,12) : ");
         scanf("%d",&sv);
         switch(sv)
         {
             case 1:write_note(1);break;
             case 2:write_note(2);break;
             case 3:write_note(3);break;
             case 4:write_note(4);break;
             case 5:write_note(5);break;
             case 6:write_note(6);break;
             case 7:write_note(7);break;
             case 8:write_note(8);break;
             case 9:write_note(9);break;
             case 10:write_note(10);break;
             case 11:write_note(11);break;
             case 12:write_note(12);break;
         }
     }




   getch();

}

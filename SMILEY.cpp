#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
#include <process.h>

int point=0,s=0,i,x=0,n,z=0;  // variable declarations
struct people
{
 char name[256];
 int score;
}p[5];                //structure for storing names and scores of players

void main()
{
 clrscr();
 void up();
 void leaderboard();                    //declaring functions
 int gd=DETECT, gm;
 initgraph(&gd,&gm,"c:\\tc\\bgi");
 setbkcolor(3);
 cout<<"\t"<<"GO SMILEY!"<<"\n";

 cout<<"Enter No. Of Players(Max 5, Min 2):";
 cin>>n;
 if(n>5)
 exit(0);
 while(1)
 {start:
   if(z>=n)               //display leaderboard after all players have played
    { leaderboard();
     }
  window(20,4,80,5);
  cout<<"Player "<<z+1<<" Enter Name";
  gets(p[z].name);
  while(1)
  {
   cleardevice();
   circle(50,290,20);                //structure ofsmiley face
   ellipse(55,280,0,360,2,3) ;
   ellipse(45,280,0,360,2,3) ;
   arc (50, 290, 180, 0, 8) ;
   bar(400-x,300,410-x,350);
   delay(6-s);                       //to manipulate speed

   if(400-x==60)                 // if player does not enter key
    {                            // and coordinates of bar and smiley meet
     p[z].score=point;
      if(z>=n)                    //to check if all the players have played
      {leaderboard(); }           // display leaderboard

      else
    {                          //control shifts to next player
    z++;
    x=0;
    point=0;                  //resetting speed and score
    s=0;
    sound(69);
    delay(100);
    nosound();
    goto start;
    }
   }

   if(kbhit()!=0)                //if any key is pressed
   {
    if(400-x>60 && 400-x<150)    //if the coordinates of bar and smiley meet
    {
     sound(169);
     delay(100);
     nosound();
     up();                       //calling the function to move smiley up
     getch();
     point++;                    //incrementing score
     if(point%3==0 && s<6)       //to increase the speed after 3 points
     {
      s++;
     }
     x = 0;
    }
    else
    {
     p[z].score=point;

     if(z>=n)                     //to display leaderboard in the end
     leaderboard();
     else
     {
      z++;
      x=0;
      point=0;
      sound(69);
      delay(100);
      nosound();
      goto start;
     }
    }
   }
   x++;
   window(62,2,80,3)   ;
   cout<<"SCORE: "<<point;
  }
 }

}

 void leaderboard()
 {
clrscr();
cleardevice();
 cout<<endl;

 for(int i=0;i<n; i++)
{ cout<<"Player "<<i+1<<"\t"<<p[i].name<<"\t"<<p[i].score<<endl;
 }
int win=0;
int winner[5],j=0;
for(i=0;i<n;i++)
{ if(p[i].score>win)
   { win=p[i].score;
   winner[j]=i;
   }

   else if(p[i].score==win)
   {
   j++;
   winner[j]=i;
   }
 }
 for(i=0;i<=j;i++)
 {
cout<<"Winner is: "<<p[winner[i]].name<<"\t"<<"Score: "<<p[winner[i]].score<<endl;
}
char a;
cout<<endl<<"Press any key followed by enter to exit";
cin>>a;
exit(0);
}





void up()
{
 int gd=DETECT, gm;
 initgraph(&gd,&gm,"c:\\tc\\bgi");
 setbkcolor(3) ;
 for (i=290; i>150; i--)
 {
  cleardevice();
  circle(50,i,20);
   ellipse(55,i+10,0,360,2,3) ;
   ellipse(45,i+10,0,360,2,3) ;
   arc (50,i,180, 0,8) ;
  delay(2);
 }
 for ( i=150; i<291; i++)
 {
  cleardevice();
  circle(50,i,20);
  ellipse(55,i+10,0,360,2,3) ;
   ellipse(45,i+10,0,360,2,3) ;
   arc (50,i,180, 0,8) ;
  delay(2);
 }
}



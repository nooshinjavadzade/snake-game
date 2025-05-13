#include <iostream>
#include <conio.h>
#include <random>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
using namespace std;
enum state {stop,down , up , rightt , leftt};
state now;
struct p{
   int x,y;
};
p gamer , food;
int score = 0;
bool gameover=false;
int tool = 30 , arz = 30;
void setap(){
   gamer.x = tool/2;
   gamer.y = arz/2;
   food.x = rand()%tool;
   food.y = rand()%arz;
   now = stop;
}
void draw(){
   system("cls");

   for (int i = 0; i < tool; i++)
      cout << "#" ;
   cout << endl;
   for (int i = 0; i < arz-1; i++)
   {
      for (int j = 0; j < tool; j++)
      {
         if (j==0||j==tool-1)
         {
            cout << "#";
         }
         else if(j == gamer.y && i == gamer.x){
            cout << "@";
         }
         else if (j == food.y && i == food.x)
         {
            cout << "$";
         }
         
         else
         {
            cout << " ";
         }
         
         
      }
      cout << endl;
      
   }
   for (int i = 0; i < tool; i++)
   {
      cout << "#";
   }
   cout << endl;

}
void input(){
   if (kbhit())
   {
      switch(getche()){
         case 'w':
         case 'W':
            now = up;
            break;
         case 's':
         case 'S':
            now = down;
            break;
         case 'a':
         case 'A':
            now = leftt;
            break;
         case 'd':
         case 'D':
            now = rightt;
            break;
         default:
            break;
      }
   }
   

}
void logic(){
   switch (now)
   {
   case leftt:
      gamer.y--; 
      break;
   case rightt:
      gamer.y++;
      break;
   case up:
      gamer.x--;
      break;
   case down:
      gamer.x++;
      break;
   
   default:
      break;
   }

}
int main(){
   srand(time(NULL));
   setap();
   while (!gameover)
   {
      draw();
      input();
      logic();
      Sleep(500);
   }
   
   getch();
   return 0;
}
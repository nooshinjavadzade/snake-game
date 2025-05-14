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
   food.x = rand()%(tool-2)+1;
   food.y = rand()%(arz-2)+1;
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
   cout <<"your score:" << score << endl;
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
      if (gamer.y<1 || gamer.y>28)
      {
         gameover = true;
      }
      
      break;
   case rightt:
      gamer.y++;
      if (gamer.y<1 || gamer.y>28)
      {
         gameover = true;
      }
      break;
   case up:
      gamer.x--;
      if (gamer.x<1 || gamer.x>28)
      {
         gameover = true;
      }
      break;
   case down:
      gamer.x++;
      if (gamer.x<1 || gamer.x>28)
      {
         gameover = true;
      }
      break;
   
   default:
      break;
   }

   if (gamer.x == food.x && gamer.y == food.y){
      score++;
      food.x = rand()%(tool-2)+1;
      food.y = rand()%(arz-2)+1;
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
      Sleep(200);
   }
   cout << "game over!!!!";
   getch();
   return 0;
}
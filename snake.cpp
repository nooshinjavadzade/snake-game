#include <iostream>
#include <conio.h>
#include <random>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
using namespace std;
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

}
void logic(){

}
int main(){
   srand(time(NULL));
   setap();
   while (!gameover)
   {
      draw();
      input();
      logic();
      Sleep(2000);
   }
   
   getch();
   return 0;
}
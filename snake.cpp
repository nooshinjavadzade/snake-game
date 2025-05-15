#include <iostream>
#include <conio.h>
#include <random>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
using namespace std;

enum state { stop, down, up, rightt, leftt };
state now;

struct p {
    int x, y;
};

p gamer, food;
p snake[900]; 
int score = 0;
int speed = 500; 
bool gameover = false;
int tool = 30, arz = 30;

void colorfull_print(int color, char in) {
    HANDLE mewo = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(mewo, color);
    cout << in;
    SetConsoleTextAttribute(mewo, 7);
}
void gotoXY(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = { y, x };
    SetConsoleCursorPosition(hConsole, position);
}
void setup() {
    gamer.x = tool / 2;
    gamer.y = arz / 2;
    food.x = rand() % (tool - 2) + 1;
    food.y = rand() % (arz - 2) + 1;
    now = stop;
}

void draw() {
    gotoXY(0, 0);

    for (int i = 0; i < tool; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < arz - 1; i++) {
        for (int j = 0; j < tool; j++) {
            if (j == 0 || j == tool - 1) {
                cout << "#";
            }
            else if (j == gamer.y && i == gamer.x) {
                colorfull_print(5, '@'); 
            }
            else if (j == food.y && i == food.x) {
                colorfull_print(10, '$'); 
            }
            else {
                bool flag = false;
                for (int k = 0; k < score; k++) {
                    if (j == snake[k].y && i == snake[k].x) {
                        colorfull_print(5, '@'); 
                        flag = true;
                        break;
                    }
                }
                if (!flag) {
                    cout << " ";
                }
            }
        }
        cout << endl;
    }

    for (int i = 0; i < tool; i++) {
        cout << "#";
    }
    cout << endl;
    cout << "Your score: " << score << endl;
}

void input() {
    if (kbhit()) {
        switch (getche()) {
            case 'w':
            case 'W':
                if (now != down) 
                    now = up;
                break;
            case 's':
            case 'S':
                if (now != up) 
                    now = down;
                break;
            case 'a':
            case 'A':
                if (now != rightt) 
                    now = leftt;
                break;
            case 'd':
            case 'D':
                if (now != leftt) 
                    now = rightt;
                break;
            default:
                break;
        }
    }
}

void logic() {
    for (int i = score - 1; i > 0; i--) {
        snake[i].x = snake[i - 1].x;
        snake[i].y = snake[i - 1].y;
    }
    if (score > 0) {
        snake[0].x = gamer.x;
        snake[0].y = gamer.y;
    }

    switch (now) {
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

    if (gamer.x < 0 || gamer.x >= arz-1 || gamer.y < 0 || gamer.y >= tool-1 ) {
        gameover = true;
    }

    if (gamer.x == food.x && gamer.y == food.y) {
        score++;
        food.x = rand() % (tool - 2) + 1;
        food.y = rand() % (arz - 2) + 1;
        snake[score - 1].x = snake[score - 2].x;
        snake[score - 1].y = snake[score - 2].y;
        if (speed > 50) {
            speed -= 50;
        }
    }
}

int main() {
    srand(time(NULL));
    setup();
    while (!gameover) {
        draw();
        input();
        logic();
        Sleep(speed);
    }
    cout << "Game Over!!!!";
    getch();
    return 0;
}
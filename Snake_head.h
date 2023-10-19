#ifndef SNAKE_HEAD_H_INCLUDED
#define SNAKE_HEAD_H_INCLUDED

#include <iostream>
#include <windows.h>
#include <vector>
#include <conio.h>

using namespace std;

struct snakeBlock{
    int x,y;
};

//long int score = 0;

void gotoxy(int x, int y);
void drawMap(vector<snakeBlock> snake);
bool checkLose(int x, int y,vector<snakeBlock> &snake);
void snakeInit(int x,int y ,vector<snakeBlock> &snake);
bool snakeMove(vector<snakeBlock> &snake,short dire[2]);


#endif // SNAKE_HEAD_H_INCLUDED

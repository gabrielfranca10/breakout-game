#ifndef GAME_H
#define GAME_H

#include "raylib.h"
#include "paddle.h" 
#include "ball.h"
#include "brick.h" 

typedef struct Game {
    Paddle paddle;
    Ball ball;
    BrickList brickList;
    int score;
    int lives; 
    int screenWidth;
    int screenHeight;
}Game;

void InitGame(Game *game, int screenWidth, int screenHeight);
void UpdateGame(Game *game);
void DrawGame(Game game);
void UnloadGame(Game *game);

#endif
#ifndef GAME_H
#define GAME_H

#include "raylib.h"
#include "paddle.h" 

typedef struct Game {
    Paddle paddle;
    int screenWidth;
    int screenHeight;
} Game;

void InitGame(Game *game, int screenWidth, int screenHeight);
void UpdateGame(Game *game);
void DrawGame(Game game);
void UnloadGame(Game *game);

#endif
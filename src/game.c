#include "game.h"
#include "paddle.h"

void InitGame(Game *game, int screenWidth, int screenHeight)
{
    game->screenWidth = screenWidth;
    game->screenHeight = screenHeight;
    
    Vector2 paddlePos = { 
        (game->screenWidth / 2.0f) - 50.0f, 
        game->screenHeight - 40.0f 
    };
    Vector2 paddleSize = { 100.0f, 20.0f };
    
    InitPaddle(&game->paddle, paddlePos, paddleSize, WHITE);
}

void UpdateGame(Game *game)
{
    UpdatePaddle(&game->paddle, game->screenWidth);
}

void DrawGame(Game game)
{
    ClearBackground(BLACK);
    DrawPaddle(game.paddle);
}

void UnloadGame(Game *game)
{
}
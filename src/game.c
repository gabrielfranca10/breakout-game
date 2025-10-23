#include "game.h"
#include "raylib.h"

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

    Vector2 ballPos = { screenWidth / 2.0f, screenHeight / 2.0f };
    Vector2 ballSpeed = { 250.0f, -250.0f };
    InitBall(&game->ball, ballPos, ballSpeed, 8, YELLOW);
}

void UpdateGame(Game *game)
{
    UpdatePaddle(&game->paddle, game->screenWidth);
    UpdateBall(&game->ball, game->screenWidth, game->screenHeight);

    // Colisão bola ↔ paddle
    Rectangle paddleRect = game->paddle.rect;
    if (CheckCollisionCircleRec(game->ball.position, game->ball.radius, paddleRect))
    {
        game->ball.speed.y *= -1;
        game->ball.position.y = paddleRect.y - game->ball.radius;
    }

    // Se a bola cair da tela (abaixo do paddle)
    if (game->ball.position.y > game->screenHeight)
    {
        Vector2 resetPos = { game->screenWidth / 2.0f, game->screenHeight / 2.0f };
        InitBall(&game->ball, resetPos, (Vector2){ 250.0f, -250.0f }, 8, YELLOW);
    }
}

void DrawGame(Game game)
{
    ClearBackground(BLACK);
    DrawPaddle(game.paddle);
    DrawBall(game.ball);
}

void UnloadGame(Game *game)
{
    // Nenhum recurso dinâmico ainda
}

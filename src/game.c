#include "game.h"
#include "paddle.h"
#include "ball.h"
#include "brick.h"

void InitGame(Game *game, int screenWidth, int screenHeight)
{
    game->screenWidth = screenWidth;
    game->screenHeight = screenHeight;
    game->score = 0;
    game->lives = 3;

    Vector2 paddlePos = { (game->screenWidth / 2.0f) - 50.0f, game->screenHeight - 40.0f };
    Vector2 paddleSize = { 100.0f, 20.0f };
    InitPaddle(&game->paddle, paddlePos, paddleSize, WHITE);

    Vector2 ballPos = { screenWidth / 2.0f, screenHeight / 2.0f };
    Vector2 ballSpeed;
    ballSpeed.y = -250.0f;
    ballSpeed.x = GetRandomValue(-200, 200);

    InitBall(&game->ball, ballPos, ballSpeed, 8, YELLOW);

    InitBrickList(&game->brickList);

    int brickRows = 5;
    int brickCols = 10;
    float brickWidth = (float)(game->screenWidth - (brickCols + 1) * 5) / brickCols;
    float brickHeight = 25.0f;
    float initialOffsetX = (game->screenWidth - (brickWidth * brickCols + (brickCols - 1) * 5)) / 2;
    float initialOffsetY = 50.0f;

    for (int i = 0; i < brickRows; i++)
    {
        for (int j = 0; j < brickCols; j++)
        {
            Vector2 brickPos;
            brickPos.x = initialOffsetX + j * (brickWidth + 5);
            brickPos.y = initialOffsetY + i * (brickHeight + 5);
            Color color;
            if (i == 0) color = RED;
            else if (i == 1) color = ORANGE;
            else if (i == 2) color = YELLOW;
            else if (i == 3) color = GREEN;
            else if (i == 4) color = BLUE;
            AddBrick(&game->brickList, brickPos, (Vector2){brickWidth, brickHeight}, color);
        }
    }
}

void UpdateGame(Game *game)
{
    if (game->lives <= 0) return;

    UpdatePaddle(&game->paddle, game->screenWidth);
    UpdateBall(&game->ball, game->screenWidth, game->screenHeight);
    UpdateBrickList(&game->brickList, &game->ball, &game->score);

    Rectangle paddleRect = game->paddle.rect;

    if (CheckCollisionCircleRec(game->ball.position, game->ball.radius, paddleRect))
    {
        if (game->ball.speed.y > 0)
        {
            game->ball.speed.y *= -1;
            float hitPos = (game->ball.position.x - paddleRect.x) - paddleRect.width / 2;
            float normalized = hitPos / (paddleRect.width / 2);
            game->ball.speed.x = normalized * 300.0f;
            game->ball.position.y = paddleRect.y - game->ball.radius;
        }
    }

    if (game->ball.position.y - game->ball.radius > game->screenHeight)
    {
        game->lives--;

        if (game->lives > 0)
        {
            Vector2 resetPos = { game->screenWidth / 2.0f, game->screenHeight / 2.0f };
            Vector2 resetSpeed;
            resetSpeed.y = -250.0f;
            resetSpeed.x = GetRandomValue(-200, 200);
            InitBall(&game->ball, resetPos, resetSpeed, game->ball.radius, game->ball.color);
        }
        else
        {
            game->lives = 0;
        }
    }
}

void DrawGame(Game game)
{
    ClearBackground(BLACK);
    DrawPaddle(game.paddle);
    DrawBall(game.ball);
    DrawBrickList(&game.brickList);

    DrawText(TextFormat("Pontos: %04i", game.score), 20, game.screenHeight - 25, 20, WHITE);
    DrawText(TextFormat("Vidas: %i", game.lives), game.screenWidth - 100, game.screenHeight - 25, 20, WHITE);

    if (game.lives <= 0)
    {
        const char* text = "GAME OVER";
        int fontSize = 40;
        int textWidth = MeasureText(text, fontSize);
        DrawText(text, (game.screenWidth - textWidth) / 2, game.screenHeight / 2 - fontSize, fontSize, RED);
        
        const char* subtext = "Pressione ENTER para reiniciar";
        int subFontSize = 20;
        int subTextWidth = MeasureText(subtext, subFontSize);
        DrawText(subtext, (game.screenWidth - subTextWidth) / 2, game.screenHeight / 2 + 10, subFontSize, GRAY);
    }
}

void UnloadGame(Game *game)
{
    FreeBrickList(&game->brickList);
}
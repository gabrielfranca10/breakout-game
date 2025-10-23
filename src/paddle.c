#include "paddle.h"

void InitPaddle(Paddle *paddle, Vector2 position, Vector2 size, Color color)
{
    paddle->rect.x = position.x;
    paddle->rect.y = position.y;
    paddle->rect.width = size.x;
    paddle->rect.height = size.y;
    paddle->color = color;
}

void UpdatePaddle(Paddle *paddle, int screenWidth)
{
    if (IsKeyDown(KEY_LEFT))
    {
        paddle->rect.x -= 7.0f;
    }
    if (IsKeyDown(KEY_RIGHT))
    {
        paddle->rect.x += 7.0f;
    }

    if (paddle->rect.x <= 0)
    {
        paddle->rect.x = 0;
    }
    if (paddle->rect.x + paddle->rect.width >= screenWidth)
    {
        paddle->rect.x = screenWidth - paddle->rect.width;
    }
}

void DrawPaddle(Paddle paddle)
{
    DrawRectangleRec(paddle.rect, paddle.color);
}
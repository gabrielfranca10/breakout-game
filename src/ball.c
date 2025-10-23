#include "ball.h"

void InitBall(Ball *ball, Vector2 position, Vector2 speed, float radius, Color color)
{
    ball->position = position;
    ball->speed = speed;
    ball->radius = radius;
    ball->color = color;
    ball->active = true;
}

void UpdateBall(Ball *ball, int screenWidth, int screenHeight)
{
    if (!ball->active) return;

    ball->position.x += ball->speed.x * GetFrameTime();
    ball->position.y += ball->speed.y * GetFrameTime();

    if ((ball->position.x - ball->radius) <= 0 || (ball->position.x + ball->radius) >= screenWidth)
        ball->speed.x *= -1;

    if ((ball->position.y - ball->radius) <= 0)
        ball->speed.y *= -1;
}

void DrawBall(Ball ball)
{
    DrawCircleV(ball.position, ball.radius, ball.color);
}

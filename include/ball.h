#ifndef BALL_H
#define BALL_H

#include "raylib.h"

typedef struct Ball {
    Vector2 position;
    Vector2 speed;
    float radius;
    Color color;
    bool active;
} Ball;

void InitBall(Ball *ball, Vector2 position, Vector2 speed, float radius, Color color);
void UpdateBall(Ball *ball, int screenWidth, int screenHeight);
void DrawBall(Ball ball);

#endif

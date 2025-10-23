
#ifndef PADDLE_H
#define PADDLE_H

#include "raylib.h"


typedef struct Paddle {
    Rectangle rect;
    Color color;
} Paddle;




void InitPaddle(Paddle *paddle, Vector2 position, Vector2 size, Color color);


void UpdatePaddle(Paddle *paddle, int screenWidth);


void DrawPaddle(Paddle paddle);

#endif 
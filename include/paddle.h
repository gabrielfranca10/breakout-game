#ifndef PADDLE_H
#define PADDLE_H

#include "raylib.h"

typedef struct Paddle {
    Rectangle retangulo;
    Color cor;
} Paddle;

void IniciarPaddle(Paddle *paddle, Vector2 posicao, Vector2 tamanho, Color cor);
void AtualizarPaddle(Paddle *paddle, int larguraTela);
void DesenharPaddle(Paddle paddle);

#endif

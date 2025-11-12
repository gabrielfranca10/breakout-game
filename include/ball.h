#ifndef BALL_H
#define BALL_H

#include "raylib.h"

typedef struct Bola {
    Vector2 posicao;
    Vector2 velocidade;
    float raio;
    Color cor;
    bool ativa;
} Bola;

void IniciarBola(Bola *bola, Vector2 posicao, Vector2 velocidade, float raio, Color cor);
void AtualizarBola(Bola *bola, int larguraTela, int alturaTela);
void DesenharBola(Bola bola);

#endif

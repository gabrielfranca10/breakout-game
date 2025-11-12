#ifndef GAME_H
#define GAME_H

#include "raylib.h"
#include "paddle.h"
#include "ball.h"
#include "brick.h"

typedef struct Jogo {
    Paddle paddle;
    Bola bola;
    ListaTijolos listaTijolos;
    int pontuacao;
    int vidas;
    int larguraTela;
    int alturaTela;
    bool jogoGanho;
} Jogo;

void IniciarJogo(Jogo *jogo, int larguraTela, int alturaTela);
void AtualizarJogo(Jogo *jogo);
void DesenharJogo(Jogo jogo);
void DescarregarJogo(Jogo *jogo);

#endif

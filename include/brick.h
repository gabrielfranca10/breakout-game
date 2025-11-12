#ifndef BRICK_H
#define BRICK_H

#include "raylib.h"

struct Bola;

typedef struct Tijolo {
    Rectangle retangulo;
    Color cor;
    int resistencia;
    Color corOriginal;
    struct Tijolo *proximo;
} Tijolo;

typedef struct ListaTijolos {
    Tijolo *cabeca;
    int quantidade;
} ListaTijolos;

void IniciarListaTijolos(ListaTijolos *lista);

void AdicionarTijolo(ListaTijolos *lista, Vector2 posicao, Vector2 tamanho, Color cor, int resistencia);

void AtualizarListaTijolos(ListaTijolos *lista, struct Bola *bola, int *pontuacao);
void DesenharListaTijolos(ListaTijolos *lista);
void LiberarListaTijolos(ListaTijolos *lista);

#endif
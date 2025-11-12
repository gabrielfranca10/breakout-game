#include "brick.h"
#include "ball.h"
#include <stdlib.h>

void IniciarListaTijolos(ListaTijolos *lista)
{
    lista->cabeca = NULL;
    lista->quantidade = 0;
}

void AdicionarTijolo(ListaTijolos *lista, Vector2 posicao, Vector2 tamanho, Color cor)
{
    Tijolo *novoTijolo = (Tijolo *)malloc(sizeof(Tijolo));
    if (novoTijolo == NULL) return;

    novoTijolo->retangulo.x = posicao.x;
    novoTijolo->retangulo.y = posicao.y;
    novoTijolo->retangulo.width = tamanho.x;
    novoTijolo->retangulo.height = tamanho.y;
    novoTijolo->cor = cor;
    
    novoTijolo->proximo = lista->cabeca;
    lista->cabeca = novoTijolo;
    lista->quantidade++;
}

void AtualizarListaTijolos(ListaTijolos *lista, Bola *bola, int *pontuacao)
{
    Tijolo *atual = lista->cabeca;
    Tijolo *anterior = NULL;

    while (atual != NULL)
    {
        if (CheckCollisionCircleRec(bola->posicao, bola->raio, atual->retangulo))
        {
            bola->velocidade.y *= -1;
            (*pontuacao) += 10;
            
            if (anterior == NULL)
            {
                lista->cabeca = atual->proximo;
            } 
            else 
            {
                anterior->proximo = atual->proximo;
            }
            
            Tijolo *paraLiberar = atual;
            atual = atual->proximo;
            free(paraLiberar);
            lista->quantidade--;
            
            return;
        }
        
        anterior = atual;
        atual = atual->proximo;
    }
}

void DesenharListaTijolos(ListaTijolos *lista)
{
    Tijolo *atual = lista->cabeca;
    while (atual != NULL)
    {
        DrawRectangleRec(atual->retangulo, atual->cor);
        atual = atual->proximo;
    }
}

void LiberarListaTijolos(ListaTijolos *lista)
{
    Tijolo *atual = lista->cabeca;
    while (atual != NULL)
    {
        Tijolo *paraLiberar = atual;
        atual = atual->proximo;
        free(paraLiberar);
    }
    lista->cabeca = NULL;
    lista->quantidade = 0;
}

#include "ball.h"

void IniciarBola(Bola *bola, Vector2 posicao, Vector2 velocidade, float raio, Color cor)
{
    bola->posicao = posicao;
    bola->velocidade = velocidade;
    bola->raio = raio;
    bola->cor = cor;
    bola->ativa = true;
}

void AtualizarBola(Bola *bola, int larguraTela, int alturaTela)
{
    if (!bola->ativa) return;

    bola->posicao.x += bola->velocidade.x * GetFrameTime();
    bola->posicao.y += bola->velocidade.y * GetFrameTime();

    if ((bola->posicao.x - bola->raio) <= 0)
    {
        bola->velocidade.x *= -1;
        bola->posicao.x = bola->raio;
    }
    
    if ((bola->posicao.x + bola->raio) >= larguraTela)
    {
        bola->velocidade.x *= -1;
        bola->posicao.x = larguraTela - bola->raio;
    }

    if ((bola->posicao.y - bola->raio) <= 0)
    {
        bola->velocidade.y *= -1;
        bola->posicao.y = bola->raio;
    }
}

void DesenharBola(Bola bola)
{
    DrawCircleV(bola.posicao, bola.raio, bola.cor);
}

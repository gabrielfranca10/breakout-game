#include "paddle.h"

void IniciarPaddle(Paddle *paddle, Vector2 posicao, Vector2 tamanho, Color cor)
{
    paddle->retangulo.x = posicao.x;
    paddle->retangulo.y = posicao.y;
    paddle->retangulo.width = tamanho.x;
    paddle->retangulo.height = tamanho.y;
    paddle->cor = cor;
}

void AtualizarPaddle(Paddle *paddle, int larguraTela)
{
    if (IsKeyDown(KEY_LEFT))
    {
        paddle->retangulo.x -= 7.0f;
    }
    if (IsKeyDown(KEY_RIGHT))
    {
        paddle->retangulo.x += 7.0f;
    }

    if (paddle->retangulo.x <= 0)
    {
        paddle->retangulo.x = 0;
    }
    if (paddle->retangulo.x + paddle->retangulo.width >= larguraTela)
    {
        paddle->retangulo.x = larguraTela - paddle->retangulo.width;
    }
}

void DesenharPaddle(Paddle paddle)
{
    DrawRectangleRec(paddle.retangulo, paddle.cor);
}

#include "game.h"
#include "paddle.h"
#include "ball.h"
#include "brick.h"
#include <stdlib.h>
#include <stdbool.h>

void IniciarJogo(Jogo *jogo, int larguraTela, int alturaTela)
{
    jogo->larguraTela = larguraTela;
    jogo->alturaTela = alturaTela;
    jogo->pontuacao = 0;
    jogo->vidas = 3;

    Vector2 posPaddle = { (jogo->larguraTela / 2.0f) - 50.0f, jogo->alturaTela - 40.0f };
    Vector2 tamPaddle = { 100.0f, 20.0f };
    IniciarPaddle(&jogo->paddle, posPaddle, tamPaddle, WHITE);

    Vector2 posBola = { larguraTela / 2.0f, alturaTela / 2.0f };
    Vector2 velBola;
    velBola.y = -250.0f;
    velBola.x = GetRandomValue(-200, 200);
    IniciarBola(&jogo->bola, posBola, velBola, 8, YELLOW);

    IniciarListaTijolos(&jogo->listaTijolos);

    int linhas = 5;
    int colunas = 10;
    float larguraTijolo = (float)(jogo->larguraTela - (colunas + 1) * 5) / colunas;
    float alturaTijolo = 25.0f;
    float deslocamentoX = (jogo->larguraTela - (larguraTijolo * colunas + (colunas - 1) * 5)) / 2;
    float deslocamentoY = 50.0f;

    int resistentesContados = 0;

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            Vector2 posTijolo;
            posTijolo.x = deslocamentoX + j * (larguraTijolo + 5);
            posTijolo.y = deslocamentoY + i * (alturaTijolo + 5);
            
            Color cor;
            int resistencia;

            if (resistentesContados < 4 && GetRandomValue(0, 12) == 0)
            {
                resistencia = 2;
                cor = GOLD;
                resistentesContados++;
            }
            else
            {
                resistencia = 1;
                cor = GRAY;
            }

            AdicionarTijolo(&jogo->listaTijolos, posTijolo, (Vector2){larguraTijolo, alturaTijolo}, cor, resistencia);
        }
    }
}

void AtualizarJogo(Jogo *jogo)
{
    if (jogo->vidas <= 0) return;

    AtualizarPaddle(&jogo->paddle, jogo->larguraTela);
    AtualizarBola(&jogo->bola, jogo->larguraTela, jogo->alturaTela);
    AtualizarListaTijolos(&jogo->listaTijolos, &jogo->bola, &jogo->pontuacao);

    Rectangle retPaddle = jogo->paddle.retangulo;

    if (CheckCollisionCircleRec(jogo->bola.posicao, jogo->bola.raio, retPaddle))
    {
        if (jogo->bola.velocidade.y > 0)
        {
            float posColisao = (jogo->bola.posicao.x - retPaddle.x) - retPaddle.width / 2;
            float normalizado = posColisao / (retPaddle.width / 2);

            // Mantém velocidade constante
            float velocidade = 350.0f;

            // Direção linear simples
            jogo->bola.velocidade.x = normalizado * velocidade;
            jogo->bola.velocidade.y = -velocidade + (normalizado * 50.0f);

            jogo->bola.posicao.y = retPaddle.y - jogo->bola.raio;
        }
    }

    if (jogo->bola.posicao.y - jogo->bola.raio > jogo->alturaTela)
    {
        jogo->vidas--;

        if (jogo->vidas > 0)
        {
            Vector2 posReset = { jogo->larguraTela / 2.0f, jogo->alturaTela / 2.0f };
            Vector2 velReset;
            velReset.y = -250.0f;
            velReset.x = GetRandomValue(-200, 200);
            IniciarBola(&jogo->bola, posReset, velReset, jogo->bola.raio, jogo->bola.cor);
        }
        else
        {
            jogo->vidas = 0;
        }
    }
}

void DesenharJogo(Jogo jogo)
{
    ClearBackground(BLACK);
    DesenharPaddle(jogo.paddle);
    DesenharBola(jogo.bola);
    DesenharListaTijolos(&jogo.listaTijolos);

    DrawText(TextFormat("Pontos: %04i", jogo.pontuacao), 20, jogo.alturaTela - 25, 20, WHITE);
    DrawText(TextFormat("Vidas: %i", jogo.vidas), jogo.larguraTela - 100, jogo.alturaTela - 25, 20, WHITE);

    if (jogo.vidas <= 0)
    {
        const char* texto = "FIM DE JOGO";
        int tamanhoFonte = 40;
        int larguraTexto = MeasureText(texto, tamanhoFonte);
        DrawText(texto, (jogo.larguraTela - larguraTexto) / 2, jogo.alturaTela / 2 - tamanhoFonte, tamanhoFonte, RED);

        const char* subtitulo = "Pressione ENTER para voltar ao Menu";
        int tamFonteSub = 20;
        int larguraSub = MeasureText(subtitulo, tamFonteSub);
        DrawText(subtitulo, (jogo.larguraTela - larguraSub) / 2, jogo.alturaTela / 2 + 10, tamFonteSub, GRAY);
    }
}

void DescarregarJogo(Jogo *jogo)
{
    LiberarListaTijolos(&jogo->listaTijolos);
}

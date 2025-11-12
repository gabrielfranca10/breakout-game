#include "raylib.h"
#include "screens.h"
#include "game.h"
#include <stdio.h>

const int larguraTela = 800;
const int alturaTela = 450;

void SalvarPontuacao(int pontuacao)
{
    FILE *arquivo = fopen("scores.txt", "a");
    if (arquivo != NULL)
    {
        fprintf(arquivo, "%d\n", pontuacao);
        fclose(arquivo);
    }
}

int DesenharHistoricoPontuacoes(int larguraTela, int alturaTela)
{
    ClearBackground(BLACK);
    DrawText("HISTÓRICO DE PONTUAÇÕES", larguraTela / 2 - 220, 80, 30, YELLOW);

    FILE *arquivo = fopen("scores.txt", "r");
    if (arquivo == NULL)
    {
        DrawText("Nenhum histórico encontrado!", larguraTela / 2 - 170, 220, 20, WHITE);
    }
    else
    {
        int y = 160;
        int pontuacao;
        int partida = 1;

        while (fscanf(arquivo, "%d", &pontuacao) != EOF && partida <= 10)
        {
            DrawText(TextFormat("Partida %d: %d pontos", partida, pontuacao),
                     larguraTela / 2 - 130, y, 20, LIGHTGRAY);
            y += 35;
            partida++;
        }

        fclose(arquivo);
    }

    DrawText("Pressione ESC para voltar", larguraTela / 2 - 150, 400, 20, GRAY);
    if(IsKeyPressed(KEY_ESCAPE))
    {
        return 1;
    }
    return 0;
}

int main(void)
{
    InitWindow(larguraTela, alturaTela, "Projeto Breakout");
    SetExitKey(0);
    SetTargetFPS(60);

    Jogo jogo = {0};
    IniciarJogo(&jogo, larguraTela, alturaTela);

    int telaAtual = TELA_MENU;

    while (!WindowShouldClose())
    {
        switch (telaAtual)
        {
            case TELA_MENU:
            {
            }
            break;

            case TELA_JOGO:
            {
                if (jogo.vidas > 0)
                {
                    AtualizarJogo(&jogo);
                }
                else
                {
                    if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_ESCAPE))
                    {
                        SalvarPontuacao(jogo.pontuacao);
                        telaAtual = TELA_MENU;
                    }
                }
            }
            break;

            case TELA_FIM_DE_JOGO:
            {
                if (IsKeyPressed(KEY_ESCAPE)) telaAtual = TELA_MENU;
            }
            break;
        }

        BeginDrawing();

        switch (telaAtual)
        {
            case TELA_MENU:
            {
                ClearBackground(BLACK);

                const char *titulo = "BREAKOUT";
                int tamanhoFonte = 60;
                int larguraTitulo = MeasureText(titulo, tamanhoFonte);
                DrawText(titulo, (larguraTela - larguraTitulo) / 2, 100, tamanhoFonte, YELLOW);

                const char *opcoes[] = {"Começar", "Histórico de Pontuação", "Sair"};
                for (int i = 0; i < 3; i++)
                {
                    Rectangle botao = {larguraTela / 2 - 160, 220 + i * 80.0f, 320, 50};
                    bool hover = CheckCollisionPointRec(GetMousePosition(), botao);
                    if (hover)
                        DrawRectangleRec(botao, DARKGRAY);
                    else
                        DrawRectangleLinesEx(botao, 3, GRAY);
                    DrawText(opcoes[i], botao.x + 30, botao.y + 15, 20, WHITE);

                    if (hover && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                    {
                        if (i == 0)
                        {
                            DescarregarJogo(&jogo);
                            IniciarJogo(&jogo, larguraTela, alturaTela);
                            telaAtual = TELA_JOGO;
                        }
                        else if (i == 1)
                        {
                            telaAtual = TELA_FIM_DE_JOGO;
                        }
                        else if (i == 2)
                        {
                            DescarregarJogo(&jogo);
                            CloseWindow();
                            return 0;
                        }
                    }
                }
            }
            break;

            case TELA_JOGO:
            {
                DesenharJogo(jogo);
            }
            break;

            case TELA_FIM_DE_JOGO:
            {
                if(DesenharHistoricoPontuacoes(larguraTela, alturaTela)){
                    telaAtual = TELA_MENU;
                }
            }
            break;
        }

        EndDrawing();
    }

    DescarregarJogo(&jogo);
    CloseWindow();
    return 0;
}

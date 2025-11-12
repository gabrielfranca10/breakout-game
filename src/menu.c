#include "menu.h"

OpcaoMenu DesenharMenu(int larguraTela, int alturaTela)
{
    ClearBackground(BLACK);

    const char *titulo = "BREAKOUT";
    int tamanhoFonte = 60;
    int larguraTitulo = MeasureText(titulo, tamanhoFonte);
    DrawText(titulo, (larguraTela - larguraTitulo) / 2, 100, tamanhoFonte, YELLOW);

    const char *opcoes[] = {"Começar", "Histórico de Pontuação", "Sair"};
    int totalOpcoes = 3;

    for (int i = 0; i < totalOpcoes; i++)
    {
        float y = 220 + i * 80;
        Rectangle botao = {larguraTela / 2 - 160, y, 320, 50};
        bool hover = CheckCollisionPointRec(GetMousePosition(), botao);

        if (hover)
            DrawRectangleRec(botao, DARKGRAY);
        else
            DrawRectangleLinesEx(botao, 3, GRAY);

        DrawText(opcoes[i], botao.x + 30, botao.y + 15, 20, WHITE);

        if (hover && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            if (i == 0) return MENU_INICIAR;
            if (i == 1) return MENU_HISTORICO;
            if (i == 2) return MENU_SAIR;
        }
    }

    return MENU_NENHUM;
}

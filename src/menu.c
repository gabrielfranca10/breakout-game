#include "menu.h"

MenuOption DrawMenu(int screenWidth, int screenHeight)
{
    ClearBackground(BLACK);

    const char *title = "BREAKOUT";
    int titleFontSize = 60;
    int titleWidth = MeasureText(title, titleFontSize);
    DrawText(title, (screenWidth - titleWidth) / 2, 100, titleFontSize, YELLOW);

    const char *options[] = {"Começar", "Histórico de Pontuação", "Sair"};
    int totalOptions = 3;

    for (int i = 0; i < totalOptions; i++)
    {
        float y = 220 + i * 80;
        Rectangle btn = {screenWidth / 2 - 160, y, 320, 50};
        bool hover = CheckCollisionPointRec(GetMousePosition(), btn);

        if (hover)
            DrawRectangleRec(btn, DARKGRAY);
        else
            DrawRectangleLinesEx(btn, 3, GRAY);

        DrawText(options[i], btn.x + 30, btn.y + 15, 20, WHITE);

        if (hover && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            if (i == 0) return MENU_START;
            if (i == 1) return MENU_HISTORY;
            if (i == 2) return MENU_EXIT;
        }
    }

    return MENU_NONE;
}

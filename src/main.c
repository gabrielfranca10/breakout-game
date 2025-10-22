

#include "raylib.h"
#include "screens.h" 

const int screenWidth = 800;
const int screenHeight = 450;

int main(void)
{
    InitWindow(screenWidth, screenHeight, "Projeto Breakout ");
    SetTargetFPS(60); 

    GameScreen currentScreen = SCREEN_MENU;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE); 

        switch (currentScreen)
        {
            case SCREEN_MENU:
            {
                ClearBackground(BLACK); 

                const char* title = "BREAKOUT";
                int titleFontSize = 40;
                int titleWidth = MeasureText(title, titleFontSize); 
                DrawText(title, (screenWidth - titleWidth) / 2, 150, titleFontSize, YELLOW);

                const char* startOption = "Começar";
                int startFontSize = 20;
                int startWidth = MeasureText(startOption, startFontSize);
                DrawText(startOption, (screenWidth - startWidth) / 2, 250, startFontSize, WHITE);

            } break;

            case SCREEN_GAME:
            {
                ClearBackground(DARKBLUE);
                DrawText("TELA DE JOGO (Em construção por Gabriel)", 20, 20, 20, WHITE);

            } break;

            case SCREEN_GAME_OVER:
            {
                ClearBackground(GRAY);
                DrawText("GAME OVER", 20, 20, 20, RED);

            } break;

            default: break;
        }

        EndDrawing();
    }

    CloseWindow(); 

    return 0;
}
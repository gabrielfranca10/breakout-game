#include "raylib.h"
#include "screens.h"
#include "menu.h"
#include <stdio.h>

const int screenWidth = 800;
const int screenHeight = 450;

void SaveScore(int score) {
    FILE *file = fopen("scores.txt", "a");
    if (file != NULL) {
        fprintf(file, "%d\n", score);
        fclose(file);
    }
}

void DrawScoreHistory(int screenWidth, int screenHeight) {
    ClearBackground(BLACK);
    DrawText("HISTÓRICO DE PONTUAÇÕES", screenWidth / 2 - 220, 80, 30, YELLOW);

    FILE *file = fopen("scores.txt", "r");
    if (file == NULL) {
        DrawText("Nenhum histórico encontrado!", screenWidth / 2 - 170, 220, 20, WHITE);
    } else {
        int y = 160;
        int score;
        int partida = 1;

        while (fscanf(file, "%d", &score) != EOF && partida <= 10) {
            DrawText(TextFormat("Partida %d: %d pontos", partida, score),
                     screenWidth / 2 - 130, y, 20, LIGHTGRAY);
            y += 35;
            partida++;
        }

        fclose(file);
    }

    DrawText("Pressione ESC para voltar", screenWidth / 2 - 150, 400, 20, GRAY);
}

int main(void)
{
    InitWindow(screenWidth, screenHeight, "Projeto Breakout");
    SetTargetFPS(60);

    GameScreen currentScreen = SCREEN_MENU;
    int playerScore = 0; 

    while (!WindowShouldClose())
    {
        BeginDrawing();

        switch (currentScreen)
        {
            case SCREEN_MENU:
            {
                ClearBackground(BLACK);

                const char *title = "BREAKOUT";
                int titleFontSize = 60;
                int titleWidth = MeasureText(title, titleFontSize);
                DrawText(title, (screenWidth - titleWidth) / 2, 100, titleFontSize, YELLOW);

                const char *options[] = {"Começar", "Histórico de Pontuação", "Sair"};
                int totalOptions = 3;

                for (int i = 0; i < totalOptions; i++) {
                    float y = 220 + i * 80;
                    Rectangle btn = {screenWidth / 2 - 160, y, 320, 50};
                    bool hover = CheckCollisionPointRec(GetMousePosition(), btn);

                    if (hover)
                        DrawRectangleRec(btn, DARKGRAY);
                    else
                        DrawRectangleLinesEx(btn, 3, GRAY);

                    DrawText(options[i], btn.x + 30, btn.y + 15, 20, WHITE);

                    if (hover && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                        if (i == 0) {
                            playerScore = 0;
                            currentScreen = SCREEN_GAME;
                        } else if (i == 1) {
                            currentScreen = SCREEN_GAME_OVER;
                        } else if (i == 2) {
                            CloseWindow();
                            return 0;
                        }
                    }
                }
            } break;

            case SCREEN_GAME:
            {
                ClearBackground(DARKBLUE);

                DrawText("TELA DE JOGO", screenWidth / 2 - 100, 180, 40, WHITE);
                DrawText("EM CONSTRUÇÃO", screenWidth / 2 - 150, 230, 30, YELLOW);
                DrawText("Pressione ESC para voltar ao menu", screenWidth / 2 - 200, 380, 20, LIGHTGRAY);

                if (IsKeyPressed(KEY_ESCAPE)) {
                    SaveScore(playerScore);
                    currentScreen = SCREEN_MENU;
                }
            } break;

            case SCREEN_GAME_OVER:
            {
                DrawScoreHistory(screenWidth, screenHeight);

                if (IsKeyPressed(KEY_ESCAPE))
                    currentScreen = SCREEN_MENU;
            } break;
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

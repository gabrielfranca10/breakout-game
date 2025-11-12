#ifndef MENU_H
#define MENU_H

#include "raylib.h"

typedef enum {
    MENU_NENHUM,
    MENU_INICIAR,
    MENU_HISTORICO,
    MENU_SAIR
} OpcaoMenu;

OpcaoMenu DesenharMenu(int larguraTela, int alturaTela);

#endif

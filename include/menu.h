#ifndef MENU_H
#define MENU_H

#include "raylib.h"

typedef enum {
    MENU_NONE,
    MENU_START,
    MENU_HISTORY,
    MENU_EXIT
} MenuOption;

MenuOption DrawMenu(int screenWidth, int screenHeight);

#endif

#ifndef BRICK_H
#define BRICK_H

#include "raylib.h"

struct Ball; 

typedef struct Brick {
    Rectangle rect;
    Color color;
    struct Brick *next;
} Brick;

typedef struct BrickList {
    Brick *head;
    int count;
} BrickList;

void InitBrickList(BrickList *list);
void AddBrick(BrickList *list, Vector2 position, Vector2 size, Color color);
void UpdateBrickList(BrickList *list, struct Ball *ball, int *score);
void DrawBrickList(BrickList *list);
void FreeBrickList(BrickList *list);

#endif
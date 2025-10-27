#include "brick.h"
#include "ball.h"
#include <stdlib.h>

void InitBrickList(BrickList *list)
{
    list->head = NULL;
    list->count = 0;
}

void AddBrick(BrickList *list, Vector2 position, Vector2 size, Color color)
{
    Brick *newBrick = (Brick *)malloc(sizeof(Brick));
    if (newBrick == NULL) {
        return;
    }

    newBrick->rect.x = position.x;
    newBrick->rect.y = position.y;
    newBrick->rect.width = size.x;
    newBrick->rect.height = size.y;
    newBrick->color = color;
    
    newBrick->next = list->head;
    list->head = newBrick;
    list->count++;
}

void UpdateBrickList(BrickList *list, Ball *ball, int *score)
{
    Brick *current = list->head;
    Brick *prev = NULL;

    while (current != NULL)
    {
        if (CheckCollisionCircleRec(ball->position, ball->radius, current->rect))
        {
            ball->speed.y *= -1;
            (*score) += 10;
            
            if (prev == NULL)
            {
                list->head = current->next;
            } 
            else 
            {
                prev->next = current->next;
            }
            
            Brick *toFree = current;
            current = current->next;
            free(toFree); 
            list->count--;
            
            return;
        }
        
        prev = current;
        current = current->next;
    }
}

void DrawBrickList(BrickList *list)
{
    Brick *current = list->head;
    while (current != NULL)
    {
        DrawRectangleRec(current->rect, current->color);
        current = current->next;
    }
}

void FreeBrickList(BrickList *list)
{
    Brick *current = list->head;
    while (current != NULL)
    {
        Brick *toFree = current;
        current = current->next;
        free(toFree);
    }
    list->head = NULL;
    list->count = 0;
}
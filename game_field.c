#include <stdio.h>
#include "game_field.h"

void clearGameField(char matrix[][MAX_Y])
{
    for (int i = 0; i < MAX_X; ++i)
    {
        for (int j = 0; j < MAX_Y; ++j)
        {
            if (matrix[i][j] != ' ')
            {
                matrix[i][j] = ' ';
            }
        }
    }
}

void printGameField(char matrix[][MAX_Y])
{
    // рисуем все поле
    for (int j = 0; j < MAX_Y; ++j)
    {
        for (int i = 0; i < MAX_X; ++i)
        {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }
}
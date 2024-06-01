#include "apple.h"
#include "time.h"

apple_t initApple(int x, int y, int weigt)
{
    apple_t apple;

    apple.x = x;
    apple.y = y;
    apple.weigt = weigt;

    return apple;
}

void printApple(apple_t *apple, char matrix[][MAX_Y])
{
    char ch_apple;

    switch (apple->weigt)
    {
    case 2:
        ch_apple = '&';
        break;
    case 3:
        ch_apple = '$';
        break;
    default:
        ch_apple = '#';
        break;
    }

    matrix[apple->x][apple->y] = ch_apple;
}

void generateNewApple(snake_t *snake, apple_t *apple)
{
    int new_x;
    int new_y;
    int deltaX;
    int deltaY;
    srand(time(NULL));

    do
    {
        new_x = rand() % MAX_X;
        new_y = rand() % MAX_Y;

        deltaX = abs(snake->x - new_x);
        deltaY = abs(snake->y - new_y);
    } while (deltaX < MIN_DELTA_NEW_RAND_APPLE_X && deltaY < MIN_DELTA_NEW_RAND_APPLE_Y);

    apple->x = new_x;
    apple->y = new_y;
    apple->weigt = 1 + rand() % MAX_APPLE_WEIGHT;
}
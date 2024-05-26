#include "snake.h"
#include "settings.h"

snake_t initSnake(int x, int y, size_t tsize, control_buttons *butCtrl)
{
    snake_t snake;

    snake.x = x;
    snake.y = y;
    snake.tsize = tsize;
    snake.tail = (tail_t *)malloc(sizeof(tail_t) * 100);
    snake.dir = LEFT;
    snake.butCtrl = butCtrl;

    for (int i = 0; i < tsize; ++i)
    {
        snake.tail[i].x = x + i + 1;
        snake.tail[i].y = y;
    }

    return snake;
}

// @**
void printSnake(snake_t *snake, char matrix[][MAX_Y])
{
    // заполняем змейку
    matrix[snake->x][snake->y] = '@';
    for (int i = 0; i < snake->tsize; ++i)
    {
        matrix[snake->tail[i].x][snake->tail[i].y] = '*';
    }
}

void update_tail(snake_t *snake)
{
    for (int i = snake->tsize - 1; i > 0; i--)
    {
        snake->tail[i] = snake->tail[i - 1];
    }
    snake->tail[0].x = snake->x;
    snake->tail[0].y = snake->y;
}

void moveLeft(snake_t *snake)
{
    update_tail(snake);

    snake->x = snake->x - 1;
    if (snake->x < 0)
    {
        snake->x = MAX_X - 1;
    }
}

void moveRight(snake_t *snake)
{
    update_tail(snake);

    snake->x = snake->x + 1;
    if (snake->x >= MAX_X)
    {
        snake->x = 0;
    }
}

void moveDown(snake_t *snake)
{
    update_tail(snake);

    snake->y = snake->y + 1;
    if (snake->y >= MAX_Y)
    {
        snake->y = 0;
    }
}

void moveUp(snake_t *snake)
{
    update_tail(snake);

    snake->y = snake->y - 1;
    if (snake->y < 0)
    {
        snake->y = MAX_Y - 1;
    }
}

void moveSnake(snake_t *snake)
{
    switch (snake->dir)
    {
    case LEFT:
        moveLeft(snake);
        break;
    case RIGHT:
        moveRight(snake);
        break;
    case UP:
        moveUp(snake);
        break;
    case DOWN:
        moveDown(snake);
        break;
    }
}

void setDirDown(snake_t *snake)
{
    if (snake->dir != UP)
    {
        snake->dir = DOWN;
    }
}

void setDirUp(snake_t *snake)
{
    if (snake->dir != DOWN)
    {
        snake->dir = UP;
    }
}

void setDirLeft(snake_t *snake)
{
    if (snake->dir != RIGHT)
    {
        snake->dir = LEFT;
    }
}

void setDirRight(snake_t *snake)
{
    if (snake->dir != LEFT)
    {
        snake->dir = RIGHT;
    }
}

void eatHandler(snake_t *snake, apple_t *apple)
{
    if (snake->x == apple->x && snake->y == apple->y)
    {
        int posLastTail = snake->tsize - 1;
        int posSecLastTail = posLastTail - 1;

        int deltaX = snake->tail[posSecLastTail].x - snake->tail[posLastTail].x;
        int deltaY = snake->tail[posSecLastTail].y - snake->tail[posLastTail].y;

        snake->tsize = snake->tsize + apple->weigt;

        for (int i = posLastTail; i < snake->tsize; i++)
        {
            snake->tail[i].x = snake->tail[i - 1].x + deltaX;
            snake->tail[i].y = snake->tail[i - 1].y + deltaY;
        }

        generateNewApple(snake, apple);
    }
}
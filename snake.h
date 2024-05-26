#ifndef __SNAKE_H__
#define __SNAKE_H__

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>
#include "typedefs.h"
#include "settings.h"
#include "apple.h"

snake_t initSnake(int x, int y, size_t tsize, control_buttons *butCtrl);

// @**
void printSnake(snake_t *snake, char matrix[][MAX_Y]);

// void update_tail(snake_t *snake);

// void moveLeft(snake_t *snake);

// void moveRight(snake_t *snake);
// void moveDown(snake_t *snake);

// void moveUp(snake_t *snake);

void moveSnake(snake_t *snake);

void setDirDown(snake_t *snake);

void setDirUp(snake_t *snake);

void setDirLeft(snake_t *snake);

void setDirRight(snake_t *snake);

void eatHandler(snake_t *snake, apple_t *apple);

#endif /* __SNAKE_H__ */
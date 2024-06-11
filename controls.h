#ifndef __CONTROLS_H__
#define __CONTROLS_H__

#include "snake.h"

#define BUF_ARR_KEY 0
#define SIZE_BUF_KEY 5
#define STOP_KEY_VAL 1
#define PAUSE_KEY_VAL 2

extern control_buttons button_controls_S1[SIZE_BUF_KEY];
extern control_buttons button_controls_S2[SIZE_BUF_KEY];

// Здесь храним коды управления змейкой
int snakeControlHandler(snake_t *snake_1, snake_t *snake_2);

#endif /* __CONTROLS_H__ */
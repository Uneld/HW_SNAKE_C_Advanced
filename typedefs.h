#ifndef __TIPEDEFS_H__
#define __TIPEDEFS_H__

#include <stdlib.h>

typedef struct
{
    int down;
    int up;
    int left;
    int right;
} control_buttons;

enum Direction
{
    UP = 0,
    RIGHT = 1,
    LEFT = 2,
    DOWN = 3
};

typedef struct
{
    int x;
    int y;
} tail_t;

typedef struct
{
    int x;
    int y;
    enum Direction dir;
    tail_t *tail;
    size_t tsize;
    control_buttons *butCtrl;
    const char *headChar;
    const char *tailChar;
    int lockControl;
} snake_t;

typedef struct
{
    int x;
    int y;
    int weigt;
} apple_t;

#endif /* __TIPEDEFS_H__ */
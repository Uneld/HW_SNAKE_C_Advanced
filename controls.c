#include "controls.h"

#define COMMON_ARR 224
#define KEY_ARR_DOWN 80
#define KEY_ARR_UP 72
#define KEY_ARR_LEFT 75
#define KEY_ARR_RIGHT 77

#define KEY_s 115
#define KEY_w 119
#define KEY_a 97
#define KEY_d 100
#define KEY_S 83
#define KEY_W 87
#define KEY_A 65
#define KEY_D 68
#define KEY_RUS_s 235
#define KEY_RUS_w 230
#define KEY_RUS_a 228
#define KEY_RUS_d 162
#define KEY_RUS_S 155
#define KEY_RUS_W 150
#define KEY_RUS_A 148
#define KEY_RUS_D 130

#define KEY_p 112
#define KEY_P 80
#define KEY_RUS_p 167
#define KEY_RUS_P 135

#define COMMON_FKEY 0
#define KEY_F10 68

control_buttons button_controls[SIZE_BUF_KEY] =
    {
        {KEY_ARR_DOWN, KEY_ARR_UP, KEY_ARR_LEFT, KEY_ARR_RIGHT},
        {KEY_s, KEY_w, KEY_a, KEY_d},
        {KEY_S, KEY_W, KEY_A, KEY_D},
        {KEY_RUS_s, KEY_RUS_w, KEY_RUS_a, KEY_RUS_d},
        {KEY_RUS_S, KEY_RUS_W, KEY_RUS_A, KEY_RUS_D}};

int snakeControlHandler(snake_t *snake)
{
    if (kbhit())
    {
        int key = getch();
        // printf("%d \n", key);
        switch (key)
        {
        case COMMON_ARR:
            key = getch();
            if (key == snake->butCtrl[BUF_ARR_KEY].down)
                setDirDown(snake);
            else if (key == snake->butCtrl[BUF_ARR_KEY].up)
                setDirUp(snake);
            else if (key == snake->butCtrl[BUF_ARR_KEY].left)
                setDirLeft(snake);
            else if (key == snake->butCtrl[BUF_ARR_KEY].right)
                setDirRight(snake);

            break;
        case COMMON_FKEY:
            key = getch();

            if (key == KEY_F10)
            {
                return STOP_KEY_VAL;
            }
            break;
        default:
            for (size_t i = BUF_ARR_KEY + 1; i < SIZE_BUF_KEY; i++)
            {
                if (key == snake->butCtrl[i].down)
                    setDirDown(snake);
                else if (key == snake->butCtrl[i].up)
                    setDirUp(snake);
                else if (key == snake->butCtrl[i].left)
                    setDirLeft(snake);
                else if (key == snake->butCtrl[i].right)
                    setDirRight(snake);
            }

            if (key == KEY_p || key == KEY_P || key == KEY_RUS_p || key == KEY_RUS_P)
            {
                return PAUSE_KEY_VAL;
            }

            break;
        }
    }

    return 0;
}
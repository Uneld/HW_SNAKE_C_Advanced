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

#define KEY_k 107
#define KEY_i 105
#define KEY_j 106
#define KEY_l 108
#define KEY_K 75
#define KEY_I 73
#define KEY_J 74
#define KEY_L 76

#define KEY_p 112
#define KEY_P 80
#define KEY_RUS_p 167
#define KEY_RUS_P 135

#define COMMON_FKEY 0
#define KEY_F10 68

control_buttons button_controls_S1[SIZE_BUF_KEY] =
    {
        {KEY_ARR_DOWN, KEY_ARR_UP, KEY_ARR_LEFT, KEY_ARR_RIGHT},
        {KEY_s, KEY_w, KEY_a, KEY_d},
        {KEY_S, KEY_W, KEY_A, KEY_D},
        {KEY_RUS_s, KEY_RUS_w, KEY_RUS_a, KEY_RUS_d},
        {KEY_RUS_S, KEY_RUS_W, KEY_RUS_A, KEY_RUS_D}};

control_buttons button_controls_S2[SIZE_BUF_KEY] =
    {{KEY_k, KEY_i, KEY_j, KEY_l},
     {KEY_K, KEY_I, KEY_J, KEY_L}};

int snakeControlHandler(snake_t *snake_1, snake_t *snake_2)
{
    if (kbhit())
    {
        int key = getch();
        // printf("\n %d \n", key);
        switch (key)
        {
        case COMMON_ARR:
            key = getch();
            if (snake_1->lockControl == 0)
            {
                if (key == snake_1->butCtrl[BUF_ARR_KEY].down)
                    setDir(snake_1, DOWN);
                else if (key == snake_1->butCtrl[BUF_ARR_KEY].up)
                    setDir(snake_1, UP);
                else if (key == snake_1->butCtrl[BUF_ARR_KEY].left)
                    setDir(snake_1, LEFT);
                else if (key == snake_1->butCtrl[BUF_ARR_KEY].right)
                    setDir(snake_1, RIGHT);
            }
            break;
        case COMMON_FKEY:
            key = getch();

            if (key == KEY_F10)
            {
                return STOP_KEY_VAL;
            }
            break;
        default:
            for (size_t i = 0; i < SIZE_BUF_KEY; i++)
            {
                if (snake_1->lockControl == 0)
                {
                    if (key == snake_1->butCtrl[i].down)
                        setDir(snake_1, DOWN);
                    else if (key == snake_1->butCtrl[i].up)
                        setDir(snake_1, UP);
                    else if (key == snake_1->butCtrl[i].left)
                        setDir(snake_1, LEFT);
                    else if (key == snake_1->butCtrl[i].right)
                        setDir(snake_1, RIGHT);
                }

                if (snake_2->lockControl == 0)
                {
                    if (key == snake_2->butCtrl[i].down)
                        setDir(snake_2, DOWN);
                    else if (key == snake_2->butCtrl[i].up)
                        setDir(snake_2, UP);
                    else if (key == snake_2->butCtrl[i].left)
                        setDir(snake_2, LEFT);
                    else if (key == snake_2->butCtrl[i].right)
                        setDir(snake_2, RIGHT);
                }
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
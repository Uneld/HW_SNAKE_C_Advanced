#include "controls.h"
#include "game_field.h"

void printDebugSnake(snake_t *snake)
{
	printf("Dir = %d\n", snake->dir);
	printf("H = %d, %d\n", snake->x, snake->y);
	for (int i = 0; i < snake->tsize; ++i)
	{
		printf("T[%d] = %d, %d\n", i, snake->tail[i].x, snake->tail[i].y);
	}
}

int main()
{
	char matrix[MAX_X][MAX_Y];
	snake_t snake = initSnake(10, 5, 2, button_controls);
	apple_t apple = initApple(5, 5, 1);

	while (1)
	{
		if (snakeControlHandler(&snake) == 1)
		{
			system("cls");
			printf("Exit game");
			return 0;
		}

		moveSnake(&snake);

		clearGameField(matrix);
		printApple(&apple, matrix);
		printSnake(&snake, matrix);
		printGameField(matrix);
		printf("Press F10 for exit game. Control: w,s,a,d or arrows");

		// printDebugSnake(&snake);
		eatHandler(&snake, &apple);
		usleep(DELAY_UPDATE_SCREEN);
		system("cls");
	}

	return 0;
}

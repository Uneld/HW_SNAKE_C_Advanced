#include "controls.h"
#include "game_field.h"
#include "windows.h"

void printDebugSnake(snake_t *snake) { ; }

int currentLevel = 0, collision = 0;
int pauseFlag = 0, eatWeight = 0;
long int delayUpdateScreen = DELAY_UPDATE_SCREEN;
float speed = 3.33; // 1 / DELAY_UPDATE_SCREEN
LARGE_INTEGER counter, oldCounter, freq;

int main()
{
	int buttonGameControl;
	char matrix[MAX_X][MAX_Y];
	snake_t snake = initSnake(10, 5, 2, button_controls);
	apple_t apple = initApple(5, 5, 1);

	QueryPerformanceFrequency(&freq);
	QueryPerformanceCounter(&oldCounter);

	while (1)
	{
		QueryPerformanceCounter(&counter);

		long delta = (counter.QuadPart - oldCounter.QuadPart) * 1000000 / freq.QuadPart;
		if (delta >= delayUpdateScreen)
		{
			oldCounter = counter;

			buttonGameControl = snakeControlHandler(&snake);
			switch (buttonGameControl)
			{
			case STOP_KEY_VAL:
				system("cls");
				printf("Exit game");
				sleep(1);
				return 0;
			case PAUSE_KEY_VAL:
				pauseFlag = !pauseFlag;
				break;
			}

			if (pauseFlag == 1)
			{
				system("cls");
				printf("Game paused");
				usleep(DELAY_UPDATE_SCREEN);
				continue;
			}

			collision = snakeCollision(&snake);
			if (collision)
			{
				system("cls");
				printf("!!GAME OVER!!");
				sleep(2);
				return 0;
			}

			moveSnake(&snake);
			eatWeight = eatHandler(&snake, &apple);
			if (eatWeight)
			{
				currentLevel += eatWeight;
				if (delayUpdateScreen > MIN_DELAY_UPDATE_SCREEN)
				{
					delayUpdateScreen -= eatWeight * INCTEMENT_LEVEL_TIME;
				}
				speed = 1.0 / ((float)delayUpdateScreen / 1000000);
			}

			if (currentLevel >= WON_LEVEL)
			{
				system("cls");
				printf("Congratulations, you won!!");
				return 0;
			}

			system("cls");
			clearGameField(matrix);
			printSnake(&snake, matrix);
			printApple(&apple, matrix);
			printGameField(matrix);
			printf("Current level: %d. Required level to win %d\n", currentLevel, WON_LEVEL);
			printf("Apple weight: %d. Speed: %.2f px/s \n", apple.weigt, speed);
			printf("Press F10 for exit game. Press P for pause. Control: w,s,a,d or arrows");
		}
		usleep(1);
	}

	return 0;
}

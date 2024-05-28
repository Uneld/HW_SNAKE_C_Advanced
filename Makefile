# Это комментарий, который говорит, что переменная CC указывает компилятор, используемый для сборки
CC=gcc
#Это еще один комментарий. Он поясняет, что в переменной CFLAGS лежат флаги, которые передаются компилятору
CFLAGS=-c -Wall -std=c99

all: snake

snake: main.o snake.o controls.o game_field.o apple.o
	$(CC) main.o snake.o controls.o game_field.o apple.o -o snake

main.o: main.c
	$(CC) $(CFLAGS) main.c

snake.o: snake.c
	$(CC) $(CFLAGS) snake.c
	
maincontrolso: controls.c
	$(CC) $(CFLAGS) controls.c
	
game_field: game_field.c
	$(CC) $(CFLAGS) game_field.c
	
apple: apple.c
	$(CC) $(CFLAGS) apple.c

clean:
	del *.o *.exe

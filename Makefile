CC = g++
CFLAGS = -Wall -lSDL2 -I./inc
all:
	$(CC) $(CFLAGS) -o run ./src/*.cpp
clean:
	rm -rf run .vscode
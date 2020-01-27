CC = g++
CFLAGS = -Wall -lSDL2 -lSDL2_ttf -I./inc
all:
	$(CC) $(CFLAGS) -o run ./src/*.cpp
clean:
	rm -rf run .vscode
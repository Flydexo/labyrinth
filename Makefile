all: final

final: build/math.o
	gcc -o ./build/game ./src/main.c
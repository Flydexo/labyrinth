all: final

final: build/math.o
	gcc -o ./build/game ./src/main.c

build/math.o: ./src/utils/math/math.c
	gcc -c ./src/utils/math/math.c -o ./build/math.o

build/associative.o: ./src/structures/associative/associative.c
	gcc -c ./src/structures/associative/associative.c -o ./build/associative.o

build/dynarray.o: ./src/structures/dynarray/dynarray.c
	gcc -c ./src/structures/dynarray/dynarray.c -o ./build/dynarray.o

build/hashtable.o: ./src/structures/hashtable/hashtable.c
	gcc -c ./src/structures/hashtable/hashtable.c -o ./build/hashtable.o

objects: build/math.o build/associative.o build/dynarray.o build/hashtable.o
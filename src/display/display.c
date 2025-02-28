#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

char* stack_to_heap(int len, char stack[]) {
    char* heap = malloc(len * sizeof(char));
    for (int i = 0; i < len; i++) heap[i] = stack[i];
    return heap;
}

char* get_random_object(int random) {

    switch (random % 5) {
        case 0:
            return stack_to_heap(18, "o----o|XXXX|o----o");
        case 1:
            return stack_to_heap(18, "o=  =o|[  ]|o=  =o");
        case 2:
            return stack_to_heap(18, "#()()##(**)##(^^)>");
        case 3: 
            return stack_to_heap(18, "#>@)###( >)###\"\"##");
        case 4:
            return stack_to_heap(18, "3.1415926535897932");
        default:
            return NULL;
    }

}

// o----o
// |XXXX|
// o----o

// o=  =o
// |[  ]|
// o=  =o

// #()()#
// #(**)#
// #(^^)>
  
// #>@)##
// #( >)#
// ##""##

// 3.1415
// 926535
// 897932

// Middle

// ¤~~~~¤
// PORTAL
// ¤~~~~¤


char* generate_room_display(int seed, int width, int height) {

    assert(width >= 40 && height >= 13);

    srand(seed);

    char* display = malloc((width + 1) * height * sizeof(char));

    for (int i = 0; i < width; i++) {
        char c = (abs(width * .5 - i) < 3) ? ' ' : '#';
        display[i] = c;
        display[(height - 1) * (width + 1) + i] = c;
    }

    for (int i = 0; i < height; i++) {
        char c = (abs(height * .5 - i) < 2) ? ' ' : '#';
        display[i * (width + 1)] = c;
        display[i * (width + 1) + width - 1] = c;
        display[i * (width + 1) + width] = '\n';
    }

    for (int i = 1; i < width - 1; i++) {
        for (int j = 1; j < height - 1; j++) {
            display[j * (width + 1) + i] = ' ';
        }
    }

    for (int i = 0; i < 10; i++) {
        int x = rand() % (width - 10) + 5;
        int y = rand() % (height - 6) + 3;
        if (abs(width * .5 - x) < 6 || abs(height * .5 - y) < 4) continue;
        char* object = get_random_object(rand());
        for (int j = 0; j < 18; j++) {
            if (object[j] == '#') continue;
            display[(y - 1 + j / 6) * (width + 1) + x - 2 + j % 6] = object[j];
        }
        free(object);
    }

    return display;

}

int main() {

    for (int i = 0; i < 10; i++) {
        char* display = generate_room_display(i, 80, 20);
        printf("%s\n", display);
        free(display);
    }

    return 0;

}
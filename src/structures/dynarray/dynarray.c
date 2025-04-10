#include <stdlib.h>
#include "../associative/associative.h"
#include <stdio.h>
#include <assert.h>
#define INIT_SIZE 10
#include "./dynarray.h"

DynArray* dyn_create() {
    DynArray* dyn_array = malloc(sizeof(DynArray));
    dyn_array->array = malloc(sizeof(Element)*INIT_SIZE);
    dyn_array->length = 0;
    dyn_array->max_length = INIT_SIZE;
    return dyn_array;
}

void resize(DynArray* dyn_array) {
    Array new_array = malloc(sizeof(Element)*dyn_array->max_length*2);
    dyn_array->max_length = dyn_array->max_length*2;
    for(int i = 0;i<dyn_array->length;i++) {
        new_array[i] = dyn_array->array[i];
    }
    free(dyn_array->array);
    dyn_array->array = new_array;
}

void dyn_append(DynArray* dyn_array, int i, Element elt, void (*reindex)(DynArray*)) {
    if(dyn_array->array[i] == NULL) {
        dyn_array->length = dyn_array->length+1;
        if(dyn_array->length > dyn_array->max_length) {
            printf("RESIZE!!!!!!!!");
            assert(0);
            resize(dyn_array);
            if(reindex != NULL) reindex(dyn_array);
        }
    } 
    
    dyn_array->array[i] = elt;
}

Element dyn_nth(DynArray* dyn_array, int i) {
    if(dyn_array->max_length <= i) {
        fprintf(stderr, "Invalid out of bounds for dynamic array\n");
        assert(0);
    }
    return dyn_array->array[i];
}

void resize_down(DynArray* dyn_array) {
    Array new_array = malloc(sizeof(Element)*dyn_array->max_length/2);
    dyn_array->max_length = dyn_array->max_length/2;
    for(int i = 0;i<dyn_array->length;i++) {
        new_array[i] = dyn_array->array[i];
    }
    free(dyn_array->array);
    dyn_array->array = new_array;
}

Element dyn_pop(DynArray* dyn_array, void (*reindex)(DynArray*)) {
    if(dyn_array->length <= 0) {
        fprintf(stderr, "Invalid out of bounds for dynamic array");
        assert(0);
    }
    dyn_array->length = dyn_array->length-1;
    if(4*dyn_array->length <= dyn_array->max_length) {
        resize_down(dyn_array);
        if(reindex != NULL) {
            reindex(dyn_array);
        }
    }
    return dyn_array->array[dyn_array->length];
}

int dyn_size(DynArray* dyn_array) {
    return dyn_array->max_length;
}
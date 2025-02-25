#include "../chained/chained.h"
#include "../../utils/types/types.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>    

typedef Coords Key;
typedef struct Couple {
    Key key;
    Value value;
} Couple;

List assol_create() {
    return chained_create();
}

void assol_append(List list, Key key, Value value) {
    Couple* couple = malloc(sizeof(Couple));
    couple->key = key;
    couple->value = value;
    chained_append(list, couple);
}

bool assol_has(List list, Key key) {
    if(is_empty(list)) return false;
    Couple* l = *(Couple**)list;
    if(l->key.x == key.x && l->key.y == key.y) return true;
    else return assol_has(chained_tail(list), key);
}

Value assol_get(List list, Key key) {
    if(is_empty(list)) {
        fprintf(stderr, "Key not found associative list");
        assert(0);
    } 
    Couple* l = *(Couple**)list;
    if(l->key.x == key.x && l->key.y == key.y) return l->value;
    return assol_get(chained_tail(list), key);
}

void assol_append_unique(List list, Key key, Value value) {
    if(!assol_has(list, key)) {
       assol_append(list, key, value);
    }
}
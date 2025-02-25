#include "../chained/chained.h"
#include "../../utils/types/types.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>    
#include "associative.h"

CList assol_create() {
    return chained_create();
}

void assol_append(CList list, Key key, Value value) {
    Couple* couple = malloc(sizeof(Couple));
    couple->key = key;
    couple->value = value;
    chained_append(list, couple);
}

bool assol_has(CList list, Key key) {
    if(chained_is_empty(list)) return false;
    Couple* l = *(Couple**)list;
    if(l->key.x == key.x && l->key.y == key.y) return true;
    else return assol_has(chained_tail(list), key);
}

Value assol_get(CList list, Key key) {
    if(chained_is_empty(list)) {
        fprintf(stderr, "Key not found associative list");
        assert(0);
    } 
    Couple* l = *(Couple**)list;
    if(l->key.x == key.x && l->key.y == key.y) return l->value;
    return assol_get(chained_tail(list), key);
}

void assol_append_unique(CList list, Key key, Value value) {
    if(!assol_has(list, key)) {
       assol_append(list, key, value);
    }
}
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

void assol_append(CList list, Key key, AValue value) {
    Couple* couple = malloc(sizeof(Couple));
    couple->key = key;
    couple->value = value;
    chained_append(list, couple);
}

bool assol_has(CList list, Key key) {
    if(chained_is_empty(list)) return false;
    Couple* l = *(Couple**)list;
    printf("assol_has: %d %d\n", l->key->x, l->key->y);
    printf("key: %d %d\n", key->x, key->y);
    if(l->key->x == key->x && l->key->y == key->y) return true;
    else {
        return assol_has(chained_tail(list), key);
    }
}

AValue assol_get(CList list, Key key) {
    if(chained_is_empty(list)) {
        fprintf(stderr, "Key not found associative list");
        assert(0);
    } 
    Couple* l = *(Couple**)list;
    if(l->key->x == key->x && l->key->y == key->y) return l->value;
    return assol_get(chained_tail(list), key);
}

CList assol_delete(CList list, Key key) {
    if(chained_is_empty(list)) {
        fprintf(stderr, "Key not found associative list");
        assert(0);
    } 
    Couple* l = *(Couple**)list;
    if(l->key->x == key->x && l->key->y == key->y) {
        free(l);
        return chained_tail(list);
    } else {
        return assol_delete(chained_tail(list), key);
    }
}

void assol_append_unique(CList list, Key key, AValue value) {
    if(!assol_has(list, key)) {
       assol_append(list, key, value);
    }
}
#include "../chained/chained.h"
#include "../../utils/types/types.h"
#include <stdbool.h>
#include <stdio.h>

typedef Coords Key;
typedef Room* Value;
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
    if(list->value->key == key) return true;
    else return has(tail(list), key);
}

Value assol_get(List list, Key key) {
    if(is_empty(list)) {
        fprintf(stderr, "Key not found associative list");
        assert(0);
    } 
    if(list->value->key == key) return list->value->value;
    return get(tail(list), key);
}

void assol_append_unique(List list, Key key, Value value) {
    if(!has(list, key)) {
        append(list, key, value);
    }
}
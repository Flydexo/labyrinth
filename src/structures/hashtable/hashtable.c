#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "../../utils/types/types.h"
#include "../../utils/math/math.h"
#include "../associative/associative.h"
#include "../dynarray/dynarray.h"

typedef Value* Hashtable;
typedef Coords Key;
typedef Room Value;

Hashtable* create() {
    Hashtable* table = dyn_create();
    return table;
}

int hash(Hashtable* table, Key key) {
    return pow_mod(2, key.x, dyn_size(table))*pow_mod(3,key.y,dyn_size(table)) % size();
}

bool has(Hashtable* table, Key key) {
    int hashed_key = hash(table, key);
    List l = dyn_nth(table, hashed_key);
    if(l == NULL) return false;
    return assol_has(l, key);
}

Value get(Hashtable* table, Key key) {
    if(!has(table, key)) {
        fprintf(stderr, "Key not found in hashtable when trying to get");
        assert(0);
    }
    int hashed_key = hash(table, key);
    return assol_get(dyn_nth(table, hashed_key), key);
}

void set(Hashtable* table, Key key, Value value) {
    assol_append_unique(dyn_nth(table, hash(table, key)), key, value);
}
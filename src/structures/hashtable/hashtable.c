#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "../../utils/types/types.h"
#include "../../utils/math/math.h"
#include "../associative/associative.h"
#include "../dynarray/dynarray.h"

typedef Value* Hashtable;

<<<<<<< Updated upstream
Hashtable* create_hashtable() {
    Hashtable* table = dyn_create();
    return table;
=======
Hashtable* create() {
    Hashtable table = dyn_create();
    return &table;
>>>>>>> Stashed changes
}

int hash(Hashtable* table, Key key) {
    Key k = *(Key*)k;
    return pow_mod(2, k.x, dyn_size(table))*pow_mod(3,k.y,dyn_size(table)) % size();
}

bool has_hashtable(Hashtable* table, Key key) {
    int hashed_key = hash(table, key);
    List l = dyn_nth(table, hashed_key);
    if(l == NULL) return false;
    return assol_has(l, key);
}

Value get_hashtable(Hashtable* table, Key key) {
    if(!has_hashtable(table, key)) {
        fprintf(stderr, "Key not found in hashtable when trying to get");
        assert(0);
    }
    int hashed_key = hash(table, key);
    return assol_get(dyn_nth(table, hashed_key), key);
}

void set_hashtable(Hashtable* table, Key key, Value value) {
    assol_append_unique(dyn_nth(table, hash(table, key)), key, value);
}
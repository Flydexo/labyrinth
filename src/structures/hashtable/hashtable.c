#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include "../../utils/types/types.h"
#include "../../utils/math/math.h"
#include "../associative/associative.h"
#include "../dynarray/dynarray.h"
#include "./hashtable.h"

Hashtable* create_hashtable(int (*hash)(HValue* table, HKey key)) {
    HValue* table = dyn_create();
    Hashtable* htable = malloc(sizeof(Hashtable));
    htable->table = table;
    htable->hash = hash;
    return htable;
}

bool has_hashtable(Hashtable* table, HKey key) {
    int hashed_key = table->hash(table->table, key);
    List l = dyn_nth(table->table, hashed_key);
    if(l == NULL) return false;
    return assol_has(l, key);
}

HValue get_hashtable(Hashtable* table, HKey key) {
    if(!has_hashtable(table, key)) {
        fprintf(stderr, "Key not found in hashtable when trying to get");
        assert(0);
    }
    int hashed_key = table->hash(table->table, key);
    return assol_get(dyn_nth(table->table, hashed_key), key);
}

void set_hashtable(Hashtable* table, HKey key, HValue value) {
    assol_append_unique(dyn_nth(table->table, table->hash(table->table, key)), key, value);
}
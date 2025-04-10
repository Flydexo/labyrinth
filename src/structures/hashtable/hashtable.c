#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include "../../utils/types/types.h"
#include "../../utils/math/math.h"
#include "../associative/associative.h"
#include "../dynarray/dynarray.h"
#include "./hashtable.h"

Hashtable* create_hashtable(int (*hash)(Hashtable* table, HKey key)) {
    DynArray* table = dyn_create();
    Hashtable* htable = malloc(sizeof(Hashtable));
    htable->table = table;
    htable->hash = hash;
    return htable;
}

bool has_hashtable(Hashtable* table, HKey key) {
    int hashed_key = table->hash(table, key);
    CList l = dyn_nth(table->table, hashed_key);
    printf("List is null %d\n", l == NULL);
    if (l == NULL) return false;
    return assol_has(l, key);
}

HValue get_hashtable(Hashtable* table, HKey key) {
    if(!has_hashtable(table, key)) {
        fprintf(stderr, "Key not found in hashtable when trying to get");
        assert(0);
    }
    int hashed_key = table->hash(table, key);
    return assol_get(dyn_nth(table->table, hashed_key), key);
}

void set_hashtable(Hashtable* table, HKey key, HValue value) {
    int i = table->hash(table, key);
    CList list = dyn_nth(table->table, i);
    if(chained_is_empty(list)) {
        CList l = assol_create();
        assol_append(l, key, value);
        dyn_append(table->table, i, l, NULL);
    }else {
        assol_append_unique(list, key, value);
    }
}

void delete_hashtable(Hashtable* table, HKey key) {
    if(!has_hashtable(table, key)) {
        fprintf(stderr, "Key not found in hashtable when trying to delete");
        assert(0);
    }
    int hashed_key = table->hash(table, key);
    CList list = dyn_nth(table->table, hashed_key);
    dyn_set(table->table, hashed_key, assol_delete(list, key));
}

void hashtable_stats(Hashtable* table) {
    printf("hashtable stats:\n");
    printf("length: %d\n", table->table->length);
    printf("max length: %d\n", table->table->max_length);
}
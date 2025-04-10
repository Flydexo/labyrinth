#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <stdbool.h>
#include "../associative/associative.h"
#include "../dynarray/dynarray.h"

typedef void* HKey;
typedef void* HValue;
typedef struct Hashtable {
    DynArray* table;
    int (*hash)(struct Hashtable* table, HKey key);
} Hashtable;

Hashtable* create_hashtable(int (*hash)(Hashtable* table, HKey key));
bool has_hashtable(Hashtable* table, HKey key);
HValue get_hashtable(Hashtable* table, HKey key);
void set_hashtable(Hashtable* table, HKey key, HValue value);
void delete_hashtable(Hashtable* table, HKey key);
void hashtable_stats(Hashtable* table);
#endif
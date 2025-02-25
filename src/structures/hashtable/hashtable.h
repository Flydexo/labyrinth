#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <stdbool.h>

typedef void* HKey;
typedef void* HValue;
typedef struct {
    HValue* table;
    int (*hash)(HValue* table, HKey key);
} Hashtable;

Hashtable* create_hashtable(int (*hash)(HValue* table, HKey key));
bool has_hashtable(Hashtable* table, HKey key);
HValue get_hashtable(Hashtable* table, HKey key);
void set_hashtable(Hashtable* table, HKey key, HValue value);
#endif
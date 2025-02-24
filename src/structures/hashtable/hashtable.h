#include <stdbool.h>

typedef Hashtable;
typedef Key;
typedef Value;

Hashtable* create_hashtable();
bool has_hashtable(Hashtable* table, Key key);
Value get_hashtable(Hashtable* table, Key key);
void set_hashtable(Hashtable* table, Key key, Value value);
typedef Hashtable;
typedef Key;
typedef Value;

Hashtable* create();
bool has(Hashtable* table, Key key);
Value get(Hashtable* table, Key key);
void set(Hashtable* table, Key key, Value value);
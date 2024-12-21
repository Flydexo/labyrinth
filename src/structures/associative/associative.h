#include <stdbool.h>

typedef Key;
typedef Value;
typedef struct Couple {
    Key key;
    Value value;
} Couple;
typedef List;

List assol_create();

void assol_append(List, Key, Value);

void assol_append_unique(List, Key, Value);

bool assol_has(List, Key);

Value assol_get(List, Key);
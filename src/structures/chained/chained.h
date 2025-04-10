#ifndef CHAINED_H
#define CHAINED_H
#include <stdbool.h>
#include "../../utils/types/types.h"

typedef Coords* Key;
typedef struct Couple {
    Key key;
    void* value;
} Couple;
typedef Couple* Value;
typedef struct Cell {
    Value value;
    struct Cell* next;
} Cell;
typedef Cell* CList;

CList chained_create();

Cell* chained_append(CList, Value);

Value chained_head(CList);

CList chained_tail(CList);

bool chained_is_empty(CList);
#endif
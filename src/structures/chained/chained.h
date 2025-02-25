#ifndef CHAINED_H
#define CHAINED_H
#include <stdbool.h>

typedef void* Value;
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
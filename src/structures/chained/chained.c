#include <stdlib.h>
#include "../../utils/types/types.h"
#include <stdbool.h>
#include "chained.h"

CList chained_create() {
    return NULL;
}

Cell* chained_append(CList list, Value value) {
    Cell* cell = malloc(sizeof(Cell));
    cell->value = value;
    cell->next = list;
    return cell;
}

Value chained_head(CList list) {
    return list->value;
}

CList chained_tail(CList list) {
    return list->next;
}

bool chained_is_empty(CList list) {
    return list == NULL;
}
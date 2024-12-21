#include <stdlib.h>
#include "../../utils/types/types.h"

typedef void* Value;
typedef struct Cell {
    Value value;
    Cell* next;
} Cell;
typedef Cell* List;

List create() {
    return NULL;
}

void append(List list, Value value) {
    Cell* cell = malloc(sizeof(Cell));
    cell->value = value;
    cell->next = list;
    return cell;
}

Value head(List list) {
    return list->value;
}

List tail(List list) {
    return list->next;
}
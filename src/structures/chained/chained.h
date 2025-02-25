#include <stdbool.h>

typedef void* Value;
typedef void* Cell;
typedef Cell* List;

List chained_create();

void chained_append(List, Value);

Value chained_head(List);

List chained_tail(List);

bool is_empty(List);
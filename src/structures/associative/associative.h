#ifndef ASSOCIATIVE_H
#define ASSOCIATIVE_H

#include <stdbool.h>
#include "../../utils/types/types.h"
#include "../chained/chained.h"

typedef void* AValue;
CList assol_create();

void assol_append(CList, Key, AValue);

void assol_append_unique(CList, Key, AValue);

bool assol_has(CList, Key);

AValue assol_get(CList, Key);
#endif
#ifndef ASSOCIATIVE_H
#define ASSOCIATIVE_H

#include <stdbool.h>
#include "../../utils/types/types.h"
#include "../chained/chained.h"

typedef void* AValue;
CList assol_create();

CList assol_append(CList, Key, AValue);

CList assol_append_unique(CList, Key, AValue);

bool assol_has(CList, Key);

CList assol_delete(CList, Key);

AValue assol_get(CList, Key);

#endif
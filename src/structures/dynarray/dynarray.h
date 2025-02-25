typedef List Element;
typedef Element* Array;
typedef struct DynArray {
    int length;
    int max_length;
    Array array;
} DynArray;

DynArray* dyn_create();
void dyn_set(DynArray*, int, Element);
Element dyn_nth(DynArray*, int);
Element dyn_pop(DynArray*,void (*reindex)(DynArray*));
int dyn_size(DynArray*);
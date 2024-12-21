typedef DynArray;
typedef Element;

DynArray* dyn_create();
void dyn_set(DynArray*, int, Element);
Element dyn_nth(DynArray*, int);
Element dyn_pop(DynArray*,int);
int dyn_size(DynArray*);
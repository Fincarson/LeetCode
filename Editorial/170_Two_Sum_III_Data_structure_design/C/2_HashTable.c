typedef struct {
    int number;
    int count;
    UT_hash_handle hh;
} NumberCount;

typedef struct {
    NumberCount* num_counts;
} TwoSum;

TwoSum* twoSumCreate() {
    TwoSum* obj = (TwoSum*)malloc(sizeof(TwoSum));
    obj->num_counts = NULL;
    return obj;
}

void twoSumAdd(TwoSum* obj, int number) {
    NumberCount* nc;
    HASH_FIND_INT(obj->num_counts, &number, nc);
    if (nc == NULL) {
        nc = (NumberCount*)malloc(sizeof(NumberCount));
        nc->number = number;
        nc->count = 0;
        HASH_ADD_INT(obj->num_counts, number, nc);
    }
    nc->count++;
}

bool twoSumFind(TwoSum* obj, int value) {
    for (NumberCount* e = obj->num_counts; e != NULL; e = e->hh.next) {
        long complement = (long)value - e->number;
        if (complement != (int)complement) continue;
        NumberCount* comp;
        HASH_FIND_INT(obj->num_counts, &complement, comp);
        if (comp != NULL) {
            if (comp->number == e->number && e->count > 1) {
                return true;
            } else if (comp->number != e->number)
                return true;
        }
    }
    return false;
}

void twoSumFree(TwoSum* obj) {
    NumberCount *cur_elt, *tmp;
    HASH_ITER(hh, obj->num_counts, cur_elt, tmp) {
        HASH_DEL(obj->num_counts, cur_elt);
        free(cur_elt);
    }
    free(obj);
}

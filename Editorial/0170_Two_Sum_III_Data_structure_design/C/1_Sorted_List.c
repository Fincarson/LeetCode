typedef struct {
    int key;
    int count;
    UT_hash_handle hh;
} Count;

typedef struct {
    Count *counts;
} TwoSum;

TwoSum *twoSumCreate() {
    TwoSum *obj = (TwoSum *)malloc(sizeof(TwoSum));
    obj->counts = NULL;
    return obj;
}

void twoSumAdd(TwoSum *obj, int number) {
    Count *count;
    HASH_FIND_INT(obj->counts, &number, count);
    if (count == NULL) {
        count = (Count *)malloc(sizeof(Count));
        count->key = number;
        count->count = 1;
        HASH_ADD_INT(obj->counts, key, count);
    } else {
        count->count++;
    }
}

bool twoSumFind(TwoSum *obj, long value) {
    Count *count, *tmp;
    HASH_ITER(hh, obj->counts, count, tmp) {
        long complement = value - count->key;
        Count *complementCount;
        if (complement < INT_MIN || complement > INT_MAX) {
            continue;
        }
        HASH_FIND_INT(obj->counts, &complement, complementCount);
        if (complementCount) {
            if (complement != count->key || complementCount->count > 1) {
                return true;
            }
        }
    }
    return false;
}

void twoSumFree(TwoSum *obj) {
    Count *currentCount, *tmp;
    HASH_ITER(hh, obj->counts, currentCount, tmp) {
        HASH_DEL(obj->counts, currentCount);
        free(currentCount);
    }
    free(obj);
}

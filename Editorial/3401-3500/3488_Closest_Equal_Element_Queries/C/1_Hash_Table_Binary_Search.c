typedef struct {
    int key;
    int* pos;
    int size;
    int capacity;
    UT_hash_handle hh;
} PosEntry;

PosEntry* findOrCreate(PosEntry** map, int key) {
    PosEntry* entry = NULL;
    HASH_FIND_INT(*map, &key, entry);
    if (entry == NULL) {
        entry = (PosEntry*)malloc(sizeof(PosEntry));
        entry->key = key;
        entry->pos = (int*)malloc(16 * sizeof(int));
        entry->size = 0;
        entry->capacity = 16;
        HASH_ADD_INT(*map, key, entry);
    }
    return entry;
}

void addPos(PosEntry* entry, int val) {
    if (entry->size >= entry->capacity) {
        entry->capacity *= 2;
        entry->pos = (int*)realloc(entry->pos, entry->capacity * sizeof(int));
    }
    entry->pos[entry->size++] = val;
}

void insertFront(PosEntry* entry, int val) {
    if (entry->size >= entry->capacity) {
        entry->capacity *= 2;
        entry->pos = (int*)realloc(entry->pos, entry->capacity * sizeof(int));
    }
    memmove(entry->pos + 1, entry->pos, entry->size * sizeof(int));
    entry->pos[0] = val;
    entry->size++;
}

int lowerBound(int* arr, int size, int target) {
    int lo = 0, hi = size;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] < target) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    return lo;
}

int minInt(int a, int b) { return a < b ? a : b; }

int* solveQueries(int* nums, int numsSize, int* queries, int queriesSize,
                  int* returnSize) {
    int n = numsSize;
    PosEntry* map = NULL;

    for (int i = 0; i < n; i++) {
        PosEntry* entry = findOrCreate(&map, nums[i]);
        addPos(entry, i);
    }

    PosEntry *entry, *tmp;
    HASH_ITER(hh, map, entry, tmp) {
        int x = entry->pos[0];
        int last = entry->pos[entry->size - 1];
        insertFront(entry, last - n);
        addPos(entry, x + n);
    }

    int* result = (int*)malloc(queriesSize * sizeof(int));
    *returnSize = queriesSize;

    for (int i = 0; i < queriesSize; i++) {
        int q = queries[i];
        int x = nums[q];
        PosEntry* entry = findOrCreate(&map, x);

        if (entry->size == 3) {
            result[i] = -1;
            continue;
        }

        int idx = lowerBound(entry->pos, entry->size, q);
        result[i] = minInt(entry->pos[idx + 1] - entry->pos[idx],
                           entry->pos[idx] - entry->pos[idx - 1]);
    }

    HASH_ITER(hh, map, entry, tmp) {
        free(entry->pos);
        HASH_DEL(map, entry);
        free(entry);
    }

    return result;
}

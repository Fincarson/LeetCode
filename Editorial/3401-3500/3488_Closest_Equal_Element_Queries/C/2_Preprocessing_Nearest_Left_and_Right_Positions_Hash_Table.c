typedef struct {
    int key;
    int value;
    UT_hash_handle hh;
} HashItem;

HashItem* hashFindItem(HashItem** table, int key) {
    HashItem* item = NULL;
    HASH_FIND_INT(*table, &key, item);
    return item;
}

void hashAddOrUpdateItem(HashItem** table, int key, int value) {
    HashItem* item = hashFindItem(table, key);
    if (item == NULL) {
        item = (HashItem*)malloc(sizeof(HashItem));
        item->key = key;
        HASH_ADD_INT(*table, key, item);
    }
    item->value = value;
}

int hashGetItem(HashItem** table, int key, int defaultValue) {
    HashItem* item = hashFindItem(table, key);
    return item == NULL ? defaultValue : item->value;
}

int minInt(int a, int b) { return a < b ? a : b; }

int* solveQueries(int* nums, int numsSize, int* queries, int queriesSize,
                  int* returnSize) {
    int n = numsSize;
    int* left = (int*)malloc(sizeof(int) * n);
    int* right = (int*)malloc(sizeof(int) * n);
    HashItem* pos = NULL;

    for (int i = -n; i < n; i++) {
        if (i >= 0) {
            left[i] = hashGetItem(&pos, nums[i], -n);
        }
        hashAddOrUpdateItem(&pos, nums[(i + n) % n], i);
    }

    HashItem *current, *tmp;
    HASH_ITER(hh, pos, current, tmp) {
        HASH_DEL(pos, current);
        free(current);
    }
    for (int i = 2 * n - 1; i >= 0; i--) {
        if (i < n) {
            right[i] = hashGetItem(&pos, nums[i], 2 * n);
        }
        hashAddOrUpdateItem(&pos, nums[i % n], i);
    }

    for (int i = 0; i < queriesSize; i++) {
        int x = queries[i];
        if (x - left[x] == n) {
            queries[i] = -1;
        } else {
            queries[i] = minInt(x - left[x], right[x] - x);
        }
    }

    *returnSize = queriesSize;

    HASH_ITER(hh, pos, current, tmp) {
        HASH_DEL(pos, current);
        free(current);
    }
    free(left);
    free(right);

    return queries;
}

typedef struct {
    int key;
    int val;
    UT_hash_handle hh;
} HashItem;

HashItem* hashFindItem(HashItem** obj, int key) {
    HashItem* pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    return pEntry;
}

bool hashAddItem(HashItem** obj, int key, int val) {
    if (hashFindItem(obj, key)) {
        return false;
    }
    HashItem* pEntry = (HashItem*)malloc(sizeof(HashItem));
    pEntry->key = key;
    pEntry->val = val;
    HASH_ADD_INT(*obj, key, pEntry);
    return true;
}

bool hashSetItem(HashItem** obj, int key, int val) {
    HashItem* pEntry = hashFindItem(obj, key);
    if (!pEntry) {
        hashAddItem(obj, key, val);
    } else {
        pEntry->val = val;
    }
    return true;
}

int hashGetItem(HashItem** obj, int key, int defaultVal) {
    HashItem* pEntry = hashFindItem(obj, key);
    if (!pEntry) {
        return defaultVal;
    }
    return pEntry->val;
}

void hashFree(HashItem** obj) {
    HashItem *curr = NULL, *tmp = NULL;
    HASH_ITER(hh, *obj, curr, tmp) {
        HASH_DEL(*obj, curr);
        free(curr);
    }
}

int compare(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

int lowerBound(int* arr, int size, int target) {
    int left = 0, right = size;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] >= target) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int minMoves(int* nums, int numsSize, int limit) {
    int n = numsSize;
    int half = n / 2;

    HashItem* sumCount = NULL;
    int* minArr = (int*)malloc(half * sizeof(int));
    int* maxArr = (int*)malloc(half * sizeof(int));

    for (int i = 0; i < half; i++) {
        int a = fmin(nums[i], nums[n - 1 - i]);
        int b = fmax(nums[i], nums[n - 1 - i]);

        int sum = a + b;
        int currentCount = hashGetItem(&sumCount, sum, 0);
        hashSetItem(&sumCount, sum, currentCount + 1);

        minArr[i] = a;
        maxArr[i] = b;
    }

    qsort(minArr, half, sizeof(int), compare);
    qsort(maxArr, half, sizeof(int), compare);

    int minOps = n;

    for (int c = 2; c <= 2 * limit; c++) {
        int addLeft = half - lowerBound(minArr, half, c);
        int addRight = lowerBound(maxArr, half, c - limit);

        int currentOps =
            half + addLeft + addRight - hashGetItem(&sumCount, c, 0);
        if (currentOps < minOps) {
            minOps = currentOps;
        }
    }

    free(minArr);
    free(maxArr);
    hashFree(&sumCount);

    return minOps;
}

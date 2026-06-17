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

int minimumDistance(int* nums, int numsSize) {
    int* next = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        next[i] = -1;
    }

    HashItem* occur = NULL;
    int ans = numsSize + 1;

    for (int i = numsSize - 1; i >= 0; i--) {
        int prevPos = hashGetItem(&occur, nums[i], -1);
        if (prevPos != -1) {
            next[i] = prevPos;
        }
        hashSetItem(&occur, nums[i], i);
    }

    for (int i = 0; i < numsSize; i++) {
        int secondPos = next[i];
        if (secondPos != -1) {
            int thirdPos = next[secondPos];
            if (thirdPos != -1) {
                int distance = thirdPos - i;
                if (distance < ans) {
                    ans = distance;
                }
            }
        }
    }

    free(next);
    hashFree(&occur);

    return ans == numsSize + 1 ? -1 : ans * 2;
}

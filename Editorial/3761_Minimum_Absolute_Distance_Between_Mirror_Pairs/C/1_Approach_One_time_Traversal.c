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

void hashEraseItem(HashItem** obj, int key) {
    HashItem* pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    if (pEntry) {
        HASH_DEL(*obj, pEntry);
        free(pEntry);
    }
}

void hashFree(HashItem** obj) {
    HashItem *curr = NULL, *tmp = NULL;
    HASH_ITER(hh, *obj, curr, tmp) {
        HASH_DEL(*obj, curr);
        free(curr);
    }
}

int minMirrorPairDistance(int* nums, int numsSize) {
    int reverseNum(int x) {
        int y = 0;
        while (x > 0) {
            y = y * 10 + x % 10;
            x /= 10;
        }
        return y;
    }

    HashItem* prev = NULL;
    int ans = numsSize + 1;

    for (int i = 0; i < numsSize; i++) {
        int x = nums[i];
        int prevIndex = hashGetItem(&prev, x, -1);
        if (prevIndex != -1) {
            int distance = i - prevIndex;
            if (distance < ans) {
                ans = distance;
            }
        }

        hashSetItem(&prev, reverseNum(x), i);
    }

    hashFree(&prev);

    return ans == numsSize + 1 ? -1 : ans;
}

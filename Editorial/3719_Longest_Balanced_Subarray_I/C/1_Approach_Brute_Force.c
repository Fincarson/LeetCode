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

bool hashEraseItem(HashItem** obj, int key) {
    HashItem* pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    if (pEntry) {
        HASH_DEL(*obj, pEntry);
        free(pEntry);
        return true;
    }
    return false;
}

void hashFree(HashItem** obj) {
    HashItem* curr = NULL;
    HashItem* tmp = NULL;
    HASH_ITER(hh, *obj, curr, tmp) {
        HASH_DEL(*obj, curr);
        free(curr);
    }
    *obj = NULL;
}

int hashSize(HashItem* obj) { return HASH_COUNT(obj); }

int longestBalanced(int* nums, int numsSize) {
    size_t len = 0;
    for (size_t i = 0; i < numsSize; i++) {
        HashItem* odd = NULL;
        HashItem* even = NULL;
        for (size_t j = i; j < numsSize; j++) {
            int count = hashGetItem(&odd, nums[j], 0);
            if ((nums[j] & 1) == 1) {
                hashSetItem(&odd, nums[j], count + 1);
            } else {
                hashSetItem(&even, nums[j], count + 1);
            }
            if (hashSize(odd) == hashSize(even)) {
                len = fmax(len, j - i + 1);
            }
        }
        hashFree(&odd);
        hashFree(&even);
    }

    return (int)len;
}

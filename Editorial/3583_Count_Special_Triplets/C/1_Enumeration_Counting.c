#define MOD 1000000007

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

int specialTriplets(int* nums, int numsSize) {
    HashItem* numCnt = NULL;
    HashItem* numPartialCnt = NULL;

    for (int i = 0; i < numsSize; i++) {
        int v = nums[i];
        hashSetItem(&numCnt, v, hashGetItem(&numCnt, v, 0) + 1);
    }

    long long ans = 0;
    for (int i = 0; i < numsSize; i++) {
        int v = nums[i];
        int target = v * 2;
        int lCnt = hashGetItem(&numPartialCnt, target, 0);
        hashSetItem(&numPartialCnt, v, hashGetItem(&numPartialCnt, v, 0) + 1);
        int rCnt = hashGetItem(&numCnt, target, 0) -
                   hashGetItem(&numPartialCnt, target, 0);
        ans = (ans + (long long)lCnt * rCnt) % MOD;
    }

    hashFree(&numCnt);
    hashFree(&numPartialCnt);
    return (int)ans;
}

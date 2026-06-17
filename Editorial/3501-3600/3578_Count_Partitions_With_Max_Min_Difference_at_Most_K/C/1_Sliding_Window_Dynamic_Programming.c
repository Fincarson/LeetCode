#define MIN_QUEUE_SIZE 64

typedef struct Element {
    int data[1];
} Element;

typedef bool (*compare)(const void*, const void*);

typedef struct PriorityQueue {
    Element* arr;
    int capacity;
    int queueSize;
    compare lessFunc;
} PriorityQueue;

static bool less(const void* a, const void* b) {
    Element* e1 = (Element*)a;
    Element* e2 = (Element*)b;
    return e1->data[0] > e2->data[0];
}

static bool greater(const void* a, const void* b) {
    Element* e1 = (Element*)a;
    Element* e2 = (Element*)b;
    return e1->data[0] < e2->data[0];
}

static void memswap(void* m1, void* m2, size_t size) {
    unsigned char* a = (unsigned char*)m1;
    unsigned char* b = (unsigned char*)m2;
    while (size--) {
        *b ^= *a ^= *b ^= *a;
        a++;
        b++;
    }
}

static void swap(Element* arr, int i, int j) {
    memswap(&arr[i], &arr[j], sizeof(Element));
}

static void down(Element* arr, int size, int i, compare cmpFunc) {
    for (int k = 2 * i + 1; k < size; k = 2 * k + 1) {
        if (k + 1 < size && cmpFunc(&arr[k], &arr[k + 1])) {
            k++;
        }
        if (cmpFunc(&arr[k], &arr[(k - 1) / 2])) {
            break;
        }
        swap(arr, k, (k - 1) / 2);
    }
}

PriorityQueue* createPriorityQueue(compare cmpFunc) {
    PriorityQueue* obj = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    obj->capacity = MIN_QUEUE_SIZE;
    obj->arr = (Element*)malloc(sizeof(Element) * obj->capacity);
    obj->queueSize = 0;
    obj->lessFunc = cmpFunc;
    return obj;
}

void heapfiy(PriorityQueue* obj) {
    for (int i = obj->queueSize / 2 - 1; i >= 0; i--) {
        down(obj->arr, obj->queueSize, i, obj->lessFunc);
    }
}

void enQueue(PriorityQueue* obj, Element* e) {
    // we need to alloc more space, just twice space size
    if (obj->queueSize == obj->capacity) {
        obj->capacity *= 2;
        obj->arr = realloc(obj->arr, sizeof(Element) * obj->capacity);
    }
    memcpy(&obj->arr[obj->queueSize], e, sizeof(Element));
    for (int i = obj->queueSize;
         i > 0 && obj->lessFunc(&obj->arr[(i - 1) / 2], &obj->arr[i]);
         i = (i - 1) / 2) {
        swap(obj->arr, i, (i - 1) / 2);
    }
    obj->queueSize++;
}

Element* deQueue(PriorityQueue* obj) {
    swap(obj->arr, 0, obj->queueSize - 1);
    down(obj->arr, obj->queueSize - 1, 0, obj->lessFunc);
    Element* e = &obj->arr[obj->queueSize - 1];
    obj->queueSize--;
    return e;
}

bool isEmpty(const PriorityQueue* obj) { return obj->queueSize == 0; }

Element* front(const PriorityQueue* obj) {
    if (obj->queueSize == 0) {
        return NULL;
    } else {
        return &obj->arr[0];
    }
}

void clear(PriorityQueue* obj) { obj->queueSize = 0; }

int size(const PriorityQueue* obj) { return obj->queueSize; }

void freeQueue(PriorityQueue* obj) {
    free(obj->arr);
    free(obj);
}

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

int countPartitions(int* nums, int numsSize, int k) {
    if (numsSize == 0) {
        return 0;
    }
    long long* dp = (long long*)malloc((numsSize + 1) * sizeof(long long));
    long long* prefix = (long long*)malloc((numsSize + 1) * sizeof(long long));
    long long mod = 1e9 + 7;
    PriorityQueue* minHeap = createPriorityQueue(less);
    PriorityQueue* maxHeap = createPriorityQueue(greater);
    HashItem* freq = NULL;

    dp[0] = 1;
    prefix[0] = 1;
    Element e;
    for (int i = 0, j = 0; i < numsSize; i++) {
        e.data[0] = nums[i];
        enQueue(minHeap, &e);
        enQueue(maxHeap, &e);
        hashSetItem(&freq, nums[i], hashGetItem(&freq, nums[i], 0) + 1);
        // adjust window
        while (j <= i &&
               (front(maxHeap)->data[0] - front(minHeap)->data[0]) > k) {
            hashSetItem(&freq, nums[j], hashGetItem(&freq, nums[j], 0) - 1);
            while (!isEmpty(minHeap) &&
                   hashGetItem(&freq, front(minHeap)->data[0], 0) == 0) {
                deQueue(minHeap);
            }
            while (!isEmpty(maxHeap) &&
                   hashGetItem(&freq, front(maxHeap)->data[0], 0) == 0) {
                deQueue(maxHeap);
            }
            j++;
        }
        if (j > 0) {
            dp[i + 1] = (prefix[i] - prefix[j - 1] + mod) % mod;
        } else {
            dp[i + 1] = prefix[i] % mod;
        }
        prefix[i + 1] = (prefix[i] + dp[i + 1]) % mod;
    }

    int result = (int)dp[numsSize];
    free(dp);
    free(prefix);
    freeQueue(maxHeap);
    freeQueue(minHeap);
    hashFree(&freq);

    return result;
}

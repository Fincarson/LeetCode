struct hash {
    int key;
    int val;
    UT_hash_handle hh;
};

typedef struct hash hash_t;

int majorityElement(int* nums, int numsSize) {
    hash_t *counts = NULL, *s, *tmp;
    for (int i = 0; i < numsSize; i++) {
        HASH_FIND_INT(counts, &nums[i], s);
        if (s == NULL) {
            s = (hash_t*)malloc(sizeof *s);
            s->key = nums[i];
            s->val = 1;
            HASH_ADD_INT(counts, key, s);
        } else {
            s->val++;
        }
    }

    int majority = numsSize / 2;
    HASH_ITER(hh, counts, s, tmp) {
        if (s->val > majority) return s->key;
    }
    return 0;
}

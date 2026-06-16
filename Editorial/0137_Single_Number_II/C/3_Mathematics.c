struct hash {
    int key;
    UT_hash_handle hh;
};
int singleNumber(int* nums, int numsSize) {
    struct hash *unique = NULL, *s;
    long sum = 0, uniqueSum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        HASH_FIND_INT(unique, &nums[i], s);
        if (s == NULL) {
            s = malloc(sizeof(struct hash));
            s->key = nums[i];
            HASH_ADD_INT(unique, key, s);
            uniqueSum += nums[i];
        }
    }
    return (uniqueSum * 3 - sum) / 2;
}

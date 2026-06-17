int singleNumber(int *nums, int numsSize) {
    int sumOfSet = 0, sumOfNums = 0;
    // uthash set
    struct hash_set {
        int id;
        UT_hash_handle hh;
    };
    struct hash_set *mySet = NULL;
    for (int i = 0; i < numsSize; i++) {
        struct hash_set *s;
        HASH_FIND_INT(mySet, &nums[i], s);
        if (s == NULL) {
            s = (struct hash_set *)malloc(sizeof *s);
            s->id = nums[i];
            HASH_ADD_INT(mySet, id, s);
            sumOfSet += s->id;
        }
        sumOfNums += nums[i];
    }
    return 2 * sumOfSet - sumOfNums;
}

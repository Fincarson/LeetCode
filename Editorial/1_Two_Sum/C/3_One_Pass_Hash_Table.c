int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    struct hashTable {
        int key;
        int value;
        UT_hash_handle hh;
    } *hashTable = NULL, *item, *tmpItem;

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        HASH_FIND_INT(hashTable, &complement, item);

        if (item) {
            int* result = malloc(sizeof(int) * 2);
            result[0] = item->value;
            result[1] = i;
            *returnSize = 2;

            HASH_ITER(hh, hashTable, item, tmpItem) {
                HASH_DEL(hashTable, item);
                free(item);
            }

            return result;
        }

        HASH_FIND_INT(hashTable, &nums[i], item);
        if (item) {
            item->value = i;
        } else {
            item = malloc(sizeof(struct hashTable));
            item->key = nums[i];
            item->value = i;
            HASH_ADD_INT(hashTable, key, item);
        }
    }

    HASH_ITER(hh, hashTable, item, tmpItem) {
        HASH_DEL(hashTable, item);
        free(item);
    }

    *returnSize = 0;
    return malloc(0);
}

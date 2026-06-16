int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    struct hashTable {
        int key;
        int value;
        UT_hash_handle hh;
    } *hashTable = NULL, *item;

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        HASH_FIND_INT(hashTable, &complement, item);
        if (item) {
            int* result = malloc(sizeof(int) * 2);
            result[0] = item->value;
            result[1] = i;
            *returnSize = 2;
            HASH_CLEAR(hh, hashTable);  // Free the hash table
            return result;
        }
        item = malloc(sizeof(struct hashTable));
        item->key = nums[i];
        item->value = i;
        HASH_ADD_INT(hashTable, key, item);
    }
    *returnSize = 0;
    HASH_CLEAR(hh, hashTable);  // Free the hash table
    // Return an empty array if no solution is found
    return malloc(0);  // Allocate 0 bytes
}

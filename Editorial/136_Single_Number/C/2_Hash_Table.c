struct hashTable {
    int num;
    int count;
    UT_hash_handle hh;
};
int singleNumber(int* nums, int numsSize) {
    struct hashTable* hashTable = NULL;
    for (int i = 0; i < numsSize; i++) {
        struct hashTable* tmp;
        HASH_FIND_INT(hashTable, nums + i, tmp);
        if (tmp == NULL) {
            tmp = malloc(sizeof(struct hashTable));
            tmp->num = nums[i];
            tmp->count = 1;
            HASH_ADD_INT(hashTable, num, tmp);
        } else {
            tmp->count++;
        }
    }
    int ans;
    struct hashTable* iter;
    for (iter = hashTable; iter != NULL;
         iter = (struct hashTable*)(iter->hh.next)) {
        if (iter->count == 1) {
            ans = iter->num;
            break;
        }
    }
    struct hashTable *cur, *tmp;
    HASH_ITER(hh, hashTable, cur, tmp) {
        HASH_DEL(hashTable, cur);
        free(cur);
    }
    return ans;
}

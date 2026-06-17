int singleNumber(int* nums, int numsSize) {
    int* no_duplicate_list = (int*)malloc(numsSize * sizeof(int));
    if (no_duplicate_list == NULL) {
        return -1;
    }
    memset(no_duplicate_list, 0, numsSize * sizeof(int));
    int no_duplicate_list_size = 0;
    for (int i = 0; i < numsSize; ++i) {
        int found = 0;
        for (int j = 0; j < no_duplicate_list_size; ++j) {
            if (nums[i] == no_duplicate_list[j]) {
                found = 1;
                memmove(&no_duplicate_list[j], &no_duplicate_list[j + 1],
                        (no_duplicate_list_size - j - 1) * sizeof(int));
                --no_duplicate_list_size;
                break;
            }
        }
        if (!found) {
            no_duplicate_list[no_duplicate_list_size++] = nums[i];
        }
    }
    int result = no_duplicate_list[0];
    free(no_duplicate_list);
    return result;
}

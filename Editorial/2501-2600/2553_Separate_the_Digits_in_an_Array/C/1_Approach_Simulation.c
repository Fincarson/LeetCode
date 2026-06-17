int* separateDigits(int* nums, int numsSize, int* returnSize) {
    int totalDigits = 0;
    for (int i = 0; i < numsSize; i++) {
        int x = nums[i];
        if (x == 0) {
            totalDigits++;
        } else {
            while (x > 0) {
                totalDigits++;
                x /= 10;
            }
        }
    }

    int* res = (int*)malloc(totalDigits * sizeof(int));
    int index = 0;
    for (int i = 0; i < numsSize; i++) {
        int x = nums[i];
        int* tmp = (int*)malloc(10 * sizeof(int));
        int tmpSize = 0;
        if (x == 0) {
            res[index++] = 0;
            continue;
        }
        while (x > 0) {
            tmp[tmpSize++] = x % 10;
            x /= 10;
        }
        for (int j = tmpSize - 1; j >= 0; j--) {
            res[index++] = tmp[j];
        }
        free(tmp);
    }

    *returnSize = totalDigits;
    return res;
}

int* getSneakyNumbers(int* nums, int numsSize, int* returnSize) {
    int n = numsSize - 2;
    double sum = 0, squaredSum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        squaredSum += nums[i] * nums[i];
    }
    double sum2 = sum - n * (n - 1) / 2.0;
    double squaredSum2 = squaredSum - n * (n - 1) * (2 * n - 1) / 6.0;
    int x1 = (int)((sum2 - sqrt(2 * squaredSum2 - sum2 * sum2)) / 2);
    int x2 = (int)((sum2 + sqrt(2 * squaredSum2 - sum2 * sum2)) / 2);
    int* res = (int*)malloc(2 * sizeof(int));
    res[0] = x1;
    res[1] = x2;
    *returnSize = 2;
    return res;
}

void grayCodeHelper(int* result, int* resultSize, int n);
int* grayCode(int n, int* returnSize) {
    int* result = (int*)malloc((1 << n) * sizeof(int));
    *returnSize = 0;
    grayCodeHelper(result, returnSize, n);
    return result;
}
void grayCodeHelper(int* result, int* resultSize, int n) {
    if (n == 0) {
        result[(*resultSize)++] = 0;
        return;
    }
    // derive the n bits sequence from the (n - 1) bits sequence.
    grayCodeHelper(result, resultSize, n - 1);
    int currentSequenceLength = *resultSize;
    // Set the bit at position n - 1 (0 indexed) and assign it to mask.
    int mask = 1 << (n - 1);
    for (int i = currentSequenceLength - 1; i >= 0; i--) {
        // mask is used to set the (n - 1)th bit from the LSB of all the numbers
        // present in the current sequence.
        result[(*resultSize)++] = result[i] | mask;
    }
    return;
}

int nextNum = 0;
void grayCodeHelper(int* result, int* size, int n) {
    if (n == 0) {
        result[*size] = nextNum;
        (*size)++;
        return;
    }
    grayCodeHelper(result, size, n - 1);
    nextNum = nextNum ^ (1 << (n - 1));
    grayCodeHelper(result, size, n - 1);
}
int* grayCode(int n, int* returnSize) {
    int max = 1 << n;
    int* result = (int*)malloc(sizeof(int) * max);
    *returnSize = 0;
    nextNum = 0;
    grayCodeHelper(result, returnSize, n);
    return result;
}

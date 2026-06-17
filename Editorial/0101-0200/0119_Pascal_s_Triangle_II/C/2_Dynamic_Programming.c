struct Cache {
    int key;
    int val;
    UT_hash_handle hh;
};
struct Cache *cache, *tmp;
void add_cache(int key, int val) {
    tmp = malloc(sizeof(struct Cache));
    tmp->key = key;
    tmp->val = val;
    HASH_ADD_INT(cache, key, tmp);
}
struct Cache* find_cache(int key) {
    HASH_FIND_INT(cache, &key, tmp);
    return tmp;
}
int getNum(int row, int col) {
    int key = ((row + 1) << 16) | (col + 1);
    tmp = find_cache(key);
    if (tmp) return tmp->val;
    if (row == 0 || col == 0 || row == col) {
        add_cache(key, 1);
        return 1;
    }
    int val = getNum(row - 1, col - 1) + getNum(row - 1, col);
    add_cache(key, val);
    return val;
}
int* getRow(int rowIndex, int* returnSize) {
    cache = NULL;
    *returnSize = rowIndex + 1;
    int* ans = malloc((*returnSize) * sizeof(int));
    for (int i = 0; i < *returnSize; i++) {
        ans[i] = getNum(rowIndex, i);
    }
    HASH_CLEAR(hh, cache);
    return ans;
}

// Define the struct for uthash
typedef struct {
    int id;
    UT_hash_handle hh;
} Record;
int grayCodeHelper(int *res, int n, int *idx, Record **records);
int *grayCode(int n, int *returnSize) {
    *returnSize = 1 << n;
    int *res = malloc((*returnSize) * sizeof(*res));
    memset(res, 0, (*returnSize) * sizeof(*res));
    Record *records = NULL;
    Record *tmp = malloc(sizeof(*tmp));
    tmp->id = 0;
    HASH_ADD_INT(records, id, tmp);
    int start_idx = 1;
    grayCodeHelper(res, n, &start_idx, &records);
    // Clean up the hash table
    while (records) {
        tmp = records;
        HASH_DEL(records, tmp);
        free(tmp);
    }
    return res;
}
int grayCodeHelper(int *res, int n, int *idx, Record **records) {
    if (*idx == 1 << n) return 1;
    int current = res[*idx - 1];
    for (int i = 0; i < n; i++) {
        int next = current ^ (1 << i);
        Record *tmp;
        HASH_FIND_INT(*records, &next, tmp);
        if (tmp == NULL) {
            tmp = malloc(sizeof(*tmp));
            tmp->id = next;
            HASH_ADD_INT(*records, id, tmp);
            res[*idx] = next;
            (*idx)++;
            if (grayCodeHelper(res, n, idx, records)) return 1;
            HASH_DEL(*records, tmp);
            free(tmp);
            (*idx)--;
        }
    }
    return 0;
}

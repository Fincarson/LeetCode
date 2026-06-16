typedef struct {
    int key;
    int* indices;
    int count;
    int capacity;
    UT_hash_handle hh;
} Group;

long long* distance(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    long long* res = (long long*)calloc(numsSize, sizeof(long long));
    Group* map = NULL;

    for (int i = 0; i < numsSize; i++) {
        Group* g = NULL;
        HASH_FIND_INT(map, &nums[i], g);
        if (!g) {
            g = (Group*)malloc(sizeof(Group));
            g->key = nums[i];
            g->capacity = 16;
            g->indices = (int*)malloc(g->capacity * sizeof(int));
            g->count = 0;
            HASH_ADD_INT(map, key, g);
        }
        if (g->count == g->capacity) {
            g->capacity *= 2;
            g->indices = (int*)realloc(g->indices, g->capacity * sizeof(int));
        }
        g->indices[g->count++] = i;
    }

    Group *g, *tmp;
    HASH_ITER(hh, map, g, tmp) {
        long long total = 0;
        for (int j = 0; j < g->count; j++) {
            total += g->indices[j];
        }
        long long prefixTotal = 0;
        for (int j = 0; j < g->count; j++) {
            int idx = g->indices[j];
            res[idx] =
                total - prefixTotal * 2 + (long long)idx * (2 * j - g->count);
            prefixTotal += idx;
        }
        HASH_DEL(map, g);
        free(g->indices);
        free(g);
    }

    return res;
}

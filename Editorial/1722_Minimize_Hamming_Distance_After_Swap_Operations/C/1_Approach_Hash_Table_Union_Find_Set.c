typedef struct {
    int key;
    int value;
    UT_hash_handle hh;
} HashItem;

typedef struct {
    int* fa;
    int* rank;
    int size;
} UnionFind;

UnionFind* createUnionFind(int n) {
    UnionFind* uf = (UnionFind*)malloc(sizeof(UnionFind));
    uf->fa = (int*)malloc(n * sizeof(int));
    uf->rank = (int*)malloc(n * sizeof(int));
    uf->size = n;
    for (int i = 0; i < n; i++) {
        uf->fa[i] = i;
        uf->rank[i] = 0;
    }
    return uf;
}

int find(UnionFind* uf, int x) {
    if (uf->fa[x] != x) {
        uf->fa[x] = find(uf, uf->fa[x]);
    }
    return uf->fa[x];
}

void unionSet(UnionFind* uf, int x, int y) {
    x = find(uf, x);
    y = find(uf, y);
    if (x == y) return;
    if (uf->rank[x] < uf->rank[y]) {
        int temp = x;
        x = y;
        y = temp;
    }
    uf->fa[y] = x;
    if (uf->rank[x] == uf->rank[y]) {
        uf->rank[x]++;
    }
}

void freeUnionFind(UnionFind* uf) {
    free(uf->fa);
    free(uf->rank);
    free(uf);
}

int minimumHammingDistance(int* source, int sourceSize, int* target,
                           int targetSize, int** allowedSwaps,
                           int allowedSwapsSize, int* allowedSwapsColSize) {
    int n = sourceSize;
    UnionFind* uf = createUnionFind(n);

    for (int i = 0; i < allowedSwapsSize; i++) {
        unionSet(uf, allowedSwaps[i][0], allowedSwaps[i][1]);
    }

    HashItem** sets = (HashItem**)calloc(n, sizeof(HashItem*));
    for (int i = 0; i < n; i++) {
        int f = find(uf, i);
        HashItem* entry = NULL;
        HASH_FIND_INT(sets[f], &source[i], entry);
        if (entry == NULL) {
            entry = (HashItem*)malloc(sizeof(HashItem));
            entry->key = source[i];
            entry->value = 1;
            HASH_ADD_INT(sets[f], key, entry);
        } else {
            entry->value++;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int f = find(uf, i);
        HashItem* entry = NULL;
        HASH_FIND_INT(sets[f], &target[i], entry);
        if (entry != NULL && entry->value > 0) {
            entry->value--;
        } else {
            ans++;
        }
    }

    for (int i = 0; i < n; i++) {
        HashItem *current, *tmp;
        HASH_ITER(hh, sets[i], current, tmp) {
            HASH_DEL(sets[i], current);
            free(current);
        }
    }
    free(sets);
    freeUnionFind(uf);

    return ans;
}

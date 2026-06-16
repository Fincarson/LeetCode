typedef struct {
    long long key;
    UT_hash_handle hh;
} HashItem;

static inline HashItem* hashFindItem(HashItem** obj, long long key) {
    HashItem* pEntry = NULL;
    HASH_FIND(hh, *obj, &key, sizeof(key), pEntry);
    return pEntry;
}

bool hashAddItem(HashItem** obj, long long key) {
    if (hashFindItem(obj, key)) {
        return false;
    }
    HashItem* pEntry = malloc(sizeof(HashItem));
    if (!pEntry) return false;
    pEntry->key = key;
    HASH_ADD(hh, *obj, key, sizeof(key), pEntry);
    return true;
}

void hashFree(HashItem** obj) {
    HashItem *curr, *tmp;
    HASH_ITER(hh, *obj, curr, tmp) {
        HASH_DEL(*obj, curr);
        free(curr);
    }
    *obj = NULL;
}

int** rotation(int** grid, int m, int n, int* newM, int* newN) {
    *newM = n;
    *newN = m;
    int** tmp = malloc(n * sizeof(int*));
    int* data = malloc(n * m * sizeof(int));
    if (!tmp || !data) {
        free(tmp);
        free(data);
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        tmp[i] = data + i * m;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            tmp[j][m - 1 - i] = grid[i][j];
        }
    }
    return tmp;
}

void freeGrid(int** grid, int rows) {
    if (grid && grid[0]) {
        free(grid[0]);
    }
    free(grid);
}

static inline bool checkAndReturnTrue(HashItem** exist, int** currentGrid,
                                      int currentM, int** originalGrid) {
    hashFree(exist);
    if (currentGrid != originalGrid) {
        freeGrid(currentGrid, currentM);
    }
    return true;
}

static inline void rotateAndUpdate(int*** currentGrid, int* currentM,
                                   int* currentN, int** originalGrid) {
    int newM, newN;
    int** newGrid = rotation(*currentGrid, *currentM, *currentN, &newM, &newN);
    if (*currentGrid != originalGrid) {
        freeGrid(*currentGrid, *currentM);
    }
    *currentGrid = newGrid;
    *currentM = newM;
    *currentN = newN;
}

bool canPartitionGrid(int** grid, int gridSize, int* gridColSize) {
    const int m = gridSize;
    const int n = gridColSize[0];
    long long total = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            total += grid[i][j];
        }
    }
    int currentM = m, currentN = n;
    int** currentGrid = grid;

    for (int k = 0; k < 4; k++) {
        HashItem* exist = NULL;
        hashAddItem(&exist, 0LL);
        long long sum = 0;
        if (currentM < 2 || currentN == 1) {
            if (currentN == 1 && currentM >= 2) {
                for (int i = 0; i < currentM - 1; i++) {
                    sum += currentGrid[i][0];
                    long long tag = sum * 2 - total;
                    if (tag == 0 || tag == currentGrid[0][0] ||
                        tag == currentGrid[i][0]) {
                        return checkAndReturnTrue(&exist, currentGrid, currentM,
                                                  grid);
                    }
                }
            }
            rotateAndUpdate(&currentGrid, &currentM, &currentN, grid);
            hashFree(&exist);
            continue;
        }

        for (int i = 0; i < currentM - 1; i++) {
            for (int j = 0; j < currentN; j++) {
                hashAddItem(&exist, (long long)currentGrid[i][j]);
                sum += currentGrid[i][j];
            }
            long long tag = sum * 2 - total;
            if (i == 0) {
                if (tag == 0 || tag == currentGrid[0][0] ||
                    tag == currentGrid[0][currentN - 1]) {
                    return checkAndReturnTrue(&exist, currentGrid, currentM,
                                              grid);
                }
                continue;
            }
            if (hashFindItem(&exist, tag)) {
                return checkAndReturnTrue(&exist, currentGrid, currentM, grid);
            }
        }

        rotateAndUpdate(&currentGrid, &currentM, &currentN, grid);
        hashFree(&exist);
    }

    if (currentGrid != grid) {
        freeGrid(currentGrid, currentM);
    }

    return false;
}

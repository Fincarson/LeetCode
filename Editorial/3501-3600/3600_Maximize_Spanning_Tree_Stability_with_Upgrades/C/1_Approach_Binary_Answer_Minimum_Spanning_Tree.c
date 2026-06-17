#define MAX_STABILITY 200000

typedef struct {
    int* parent;
} DSU;

DSU* dsu_create(int* parent, int n) {
    DSU* d = (DSU*)malloc(sizeof(DSU));
    d->parent = (int*)malloc(n * sizeof(int));
    memcpy(d->parent, parent, n * sizeof(int));
    return d;
}

void dsu_free(DSU* d) {
    free(d->parent);
    free(d);
}

int dsu_find(DSU* d, int x) {
    if (d->parent[x] != x) {
        d->parent[x] = dsu_find(d, d->parent[x]);
    }
    return d->parent[x];
}

void dsu_join(DSU* d, int x, int y) {
    int px = dsu_find(d, x);
    int py = dsu_find(d, y);
    d->parent[px] = py;
}

int cmp_desc(const void* a, const void* b) {
    int* edgeA = (int*)a;
    int* edgeB = (int*)b;
    return edgeB[2] - edgeA[2];
}

int maxStability(int n, int** edges, int edgesSize, int* edgesColSize, int k) {
    int ans = -1;
    if (edgesSize < n - 1) {
        return -1;
    }

    int (*mustEdges)[4] = (int (*)[4])malloc(edgesSize * sizeof(int[4]));
    int (*optionalEdges)[4] = (int (*)[4])malloc(edgesSize * sizeof(int[4]));
    int mustCnt = 0, optCnt = 0;
    for (int i = 0; i < edgesSize; i++) {
        if (edges[i][3] == 1) {
            mustEdges[mustCnt][0] = edges[i][0];
            mustEdges[mustCnt][1] = edges[i][1];
            mustEdges[mustCnt][2] = edges[i][2];
            mustCnt++;
        } else {
            optionalEdges[optCnt][0] = edges[i][0];
            optionalEdges[optCnt][1] = edges[i][1];
            optionalEdges[optCnt][2] = edges[i][2];
            optCnt++;
        }
    }

    if (mustCnt > n - 1) {
        free(mustEdges);
        free(optionalEdges);
        return -1;
    }

    qsort(optionalEdges, optCnt, sizeof(int[4]), cmp_desc);
    int selectedInit = 0;
    int mustMinStability = MAX_STABILITY;
    int* initParent = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        initParent[i] = i;
    }
    DSU* dsuInit = dsu_create(initParent, n);
    free(initParent);

    for (int i = 0; i < mustCnt; i++) {
        int u = mustEdges[i][0], v = mustEdges[i][1], s = mustEdges[i][2];
        if (dsu_find(dsuInit, u) == dsu_find(dsuInit, v) ||
            selectedInit == n - 1) {
            dsu_free(dsuInit);
            free(mustEdges);
            free(optionalEdges);
            return -1;
        }
        dsu_join(dsuInit, u, v);
        selectedInit++;
        if (s < mustMinStability) {
            mustMinStability = s;
        }
    }

    int l = 0, r = mustMinStability;
    while (l < r) {
        int mid = l + (r - l + 1) / 2;

        int* currentParent = (int*)malloc(n * sizeof(int));
        memcpy(currentParent, dsuInit->parent, n * sizeof(int));
        DSU* dsu = dsu_create(currentParent, n);
        free(currentParent);

        int selected = selectedInit;
        int doubledCount = 0;

        for (int i = 0; i < optCnt; i++) {
            int u = optionalEdges[i][0], v = optionalEdges[i][1],
                s = optionalEdges[i][2];
            if (dsu_find(dsu, u) == dsu_find(dsu, v)) {
                continue;
            }
            if (s >= mid) {
                dsu_join(dsu, u, v);
                selected++;
            } else if (doubledCount < k && s * 2 >= mid) {
                doubledCount++;
                dsu_join(dsu, u, v);
                selected++;
            } else {
                break;
            }

            if (selected == n - 1) {
                break;
            }
        }

        dsu_free(dsu);
        if (selected != n - 1) {
            r = mid - 1;
        } else {
            ans = mid;
            l = mid;
        }
    }

    dsu_free(dsuInit);
    free(mustEdges);
    free(optionalEdges);

    return ans;
}

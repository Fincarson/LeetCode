static int compare(const void* a, const void* b) {
    int x = *(const int*)a;
    int y = *(const int*)b;
    return (x > y) - (x < y);
}

static int* getEdges(int* fences, int fencesSize, int border, int* outSize) {
    int arrSize = fencesSize + 2;
    int* arr = (int*)malloc(sizeof(int) * arrSize);
    memcpy(arr, fences, sizeof(int) * fencesSize);
    arr[fencesSize] = 1;
    arr[fencesSize + 1] = border;
    qsort(arr, arrSize, sizeof(int), compare);

    int maxEdges = arrSize * (arrSize - 1) / 2;
    int* edges = (int*)malloc(sizeof(int) * maxEdges);
    int idx = 0;
    for (int i = 0; i < arrSize; i++) {
        for (int j = i + 1; j < arrSize; j++) {
            edges[idx++] = arr[j] - arr[i];
        }
    }
    free(arr);
    qsort(edges, idx, sizeof(int), compare);

    int k = 0;
    for (int i = 0; i < idx; i++) {
        if (i == 0 || edges[i] != edges[i - 1]) {
            edges[k++] = edges[i];
        }
    }
    *outSize = k;
    return edges;
}

int maximizeSquareArea(int m, int n, int* hFences, int hFencesSize,
                       int* vFences, int vFencesSize) {
    int hSize = 0, vSize = 0;
    int* hEdges = getEdges(hFences, hFencesSize, m, &hSize);
    int* vEdges = getEdges(vFences, vFencesSize, n, &vSize);

    int i = 0, j = 0;
    int res = 0;
    while (i < hSize && j < vSize) {
        if (hEdges[i] == vEdges[j]) {
            if (hEdges[i] > res) res = hEdges[i];
            i++;
            j++;
        } else if (hEdges[i] < vEdges[j]) {
            i++;
        } else {
            j++;
        }
    }

    free(hEdges);
    free(vEdges);

    if (res == 0) return -1;
    long long ans = (long long)res * res % 1000000007;
    return (int)ans;
}

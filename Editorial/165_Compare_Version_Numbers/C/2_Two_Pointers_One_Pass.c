typedef struct st {
    int i;
    int p;
} Pair;

Pair getNextChunk(char *version, int n, int p) {
    if (p > n - 1) {
        return (Pair){0, p};
    }
    int pEnd = p;
    while (pEnd < n && version[pEnd] != '.') {
        pEnd++;
    }
    int subLength = pEnd != n - 1 ? pEnd - p : n - p;
    char substr[subLength + 1];
    strncpy(substr, &version[p], subLength);
    substr[subLength] = '\0';

    int i = atoi(substr);
    p = pEnd + 1;

    return (Pair){i, p};
}

int compareVersion(char *version1, char *version2) {
    int p1 = 0, p2 = 0;
    int n1 = strlen(version1), n2 = strlen(version2);

    Pair pair1, pair2;
    while (p1 < n1 || p2 < n2) {
        pair1 = getNextChunk(version1, n1, p1);
        p1 = pair1.p;
        pair2 = getNextChunk(version2, n2, p2);
        p2 = pair2.p;
        if (pair1.i != pair2.i) {
            return pair1.i > pair2.i ? 1 : -1;
        }
    }
    return 0;
}

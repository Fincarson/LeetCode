struct key {
    int row;
    int col;
};
struct hash_table {
    struct key k;
    int val;
    UT_hash_handle hh;
};
struct hash_table* memotable = NULL;
void add(struct key k, int val) {
    struct hash_table* s;
    HASH_FIND(hh, memotable, &k, sizeof(struct key), s);
    if (s == NULL) {
        s = (struct hash_table*)malloc(sizeof *s);
        s->k = k;
        s->val = val;
        HASH_ADD(hh, memotable, k, sizeof(struct key), s);
    } else {  // add this condition when element already exists just overwrite
              // its value
        s->val = val;
    }
}
int find(struct key k) {
    struct hash_table* s;
    HASH_FIND(hh, memotable, &k, sizeof(struct key), s);
    if (s == NULL) return -1;
    return s->val;
}
int** triangle;
int triangleRowSize;
int* triangleColSize;
int minPath(int row, int col) {
    struct key k;
    k.row = row;
    k.col = col;
    int stored = find(k);
    if (stored != -1) {
        return stored;
    }
    int path = triangle[row][col];
    if (row < triangleRowSize - 1) {
        path += fmin(minPath(row + 1, col), minPath(row + 1, col + 1));
    }
    add(k, path);
    return path;
}
int minimumTotal(int** tri, int triRowSize, int* triColSize) {
    triangle = tri;
    triangleRowSize = triRowSize;
    triangleColSize = triColSize;
    memotable = NULL;  // add this to reset memo table before new query
    return minPath(0, 0);
}

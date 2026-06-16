typedef struct {
    int key[2];
    struct TreeNode **value;
    int size;
    UT_hash_handle hh;
} kv;
void add_kv(kv **head, int key1, int key2, struct TreeNode **value, int size) {
    kv *s;
    s = malloc(sizeof(kv));
    s->key[0] = key1;
    s->key[1] = key2;
    s->value = value;
    s->size = size;
    HASH_ADD(hh, *head, key, sizeof(int) * 2, s);
}
kv *find_kv(kv **head, int key1, int key2) {
    if (*head == NULL) return NULL;
    kv *s;
    int keys[2];
    keys[0] = key1;
    keys[1] = key2;
    HASH_FIND(hh, *head, keys, sizeof(int) * 2, s);
    return s;
}
struct TreeNode **allPossibleBST(int start, int end, kv **memo, int *size) {
    struct TreeNode **res =
        (struct TreeNode **)malloc(sizeof(struct TreeNode *) * 5000);
    int count = 0;
    if (start > end) {
        res[count] = NULL;
        *size = count + 1;
        return res;
    }
    kv *memEntry = find_kv(memo, start, end);
    if (memEntry) {
        *size = memEntry->size;
        return memEntry->value;
    }
    for (int i = start; i <= end; ++i) {
        int sizeLeft, sizeRight;
        struct TreeNode **leftSubTrees =
            allPossibleBST(start, i - 1, memo, &sizeLeft);
        struct TreeNode **rightSubTrees =
            allPossibleBST(i + 1, end, memo, &sizeRight);
        for (int k1 = 0; k1 < sizeLeft; k1++) {
            for (int k2 = 0; k2 < sizeRight; k2++) {
                struct TreeNode *root =
                    (struct TreeNode *)malloc(sizeof(struct TreeNode));
                root->val = i;
                root->left = leftSubTrees[k1];
                root->right = rightSubTrees[k2];
                res[count++] = root;
            }
        }
    }
    add_kv(memo, start, end, res, count);
    *size = count;
    return res;
}
struct TreeNode **generateTrees(int n, int *returnSize) {
    kv *memo = NULL;
    return allPossibleBST(1, n, &memo, returnSize);
}

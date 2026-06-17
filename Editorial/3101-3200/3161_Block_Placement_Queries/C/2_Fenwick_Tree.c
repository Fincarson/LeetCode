gint int_compare(gconstpointer a, gconstpointer b) {
    int ia = *(int*)a;
    int ib = *(int*)b;
    return ia - ib;
}

void update(int* bt, int mx, int x, int v) {
    for (; x <= mx; x += x & -x) {
        if (v > bt[x]) {
            bt[x] = v;
        }
    }
}

int query(int* bt, int x) {
    int res = 0;
    for (; x > 0; x -= x & -x) {
        if (bt[x] > res) {
            res = bt[x];
        }
    }
    return res;
}

int get_node_key(GTreeNode* node) { return *(int*)g_tree_node_key(node); }

int floor_value(GTree* tree, int x) {
    GTreeNode* node = g_tree_lower_bound(tree, &x);
    if (node == NULL) {
        return 0;
    }

    int key = get_node_key(node);
    return key <= x ? key : get_node_key(g_tree_node_previous(node));
}

int lower_value(GTree* tree, int x) {
    GTreeNode* node = g_tree_lower_bound(tree, &x);
    if (node == NULL) {
        return 0;
    }
    int key = get_node_key(node);
    return key < x ? key : get_node_key(g_tree_node_previous(node));
}

int higher_value(GTree* tree, int x, int mx) {
    GTreeNode* node = g_tree_upper_bound(tree, &x);
    if (node == NULL) {
        return mx;
    }
    int key = get_node_key(node);
    return key > x ? key : get_node_key(g_tree_node_next(node));
}

bool* getResults(int** queries, int queriesSize, int* queriesColSize,
                 int* returnSize) {
    int mx = 50000;
    GTree* st = g_tree_new((GCompareFunc)int_compare);
    int* key0 = g_new(int, 1);
    int* keyMx = g_new(int, 1);
    *key0 = 0;
    *keyMx = mx;
    g_tree_insert(st, key0, key0);
    g_tree_insert(st, keyMx, keyMx);

    for (int i = 0; i < queriesSize; i++) {
        if (queries[i][0] == 1) {
            int* key = g_new(int, 1);
            *key = queries[i][1];
            g_tree_insert(st, key, key);
        }
    }

    int* bt = (int*)calloc(mx + 1, sizeof(int));
    int pre = 0;
    GTreeNode* node = g_tree_node_first(st);
    while (node != NULL) {
        int x = get_node_key(node);
        if (x != 0) {
            update(bt, mx, x, x - pre);
            pre = x;
        }
        node = g_tree_node_next(node);
    }

    bool* ans = (bool*)malloc(queriesSize * sizeof(bool));
    int ansIndex = 0;
    for (int i = queriesSize - 1; i >= 0; i--) {
        int* q = queries[i];
        if (q[0] == 2) {
            int x = q[1];
            int sz = q[2];

            int preVal = floor_value(st, x);
            int maxSpace = query(bt, preVal);
            maxSpace = fmax(maxSpace, x - preVal);
            ans[ansIndex++] = maxSpace >= sz;
        } else {
            int x = q[1];
            int preVal = lower_value(st, x);
            int nxt = higher_value(st, x, mx);

            update(bt, mx, nxt, nxt - preVal);
            g_tree_remove(st, &x);
        }
    }

    for (int i = 0; i < ansIndex / 2; i++) {
        bool temp = ans[i];
        ans[i] = ans[ansIndex - 1 - i];
        ans[ansIndex - 1 - i] = temp;
    }

    *returnSize = ansIndex;
    g_tree_destroy(st);
    free(bt);

    return ans;
}

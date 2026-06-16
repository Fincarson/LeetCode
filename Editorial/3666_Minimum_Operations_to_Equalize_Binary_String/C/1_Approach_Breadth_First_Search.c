typedef struct AVLNode {
    int val;
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
} AVLNode;

typedef struct {
    AVLNode* root;
    int size;
} AVLTree;

typedef struct {
    int* data;
    int front;
    int rear;
    int capacity;
} Queue;

int getHeight(AVLNode* node) { return node ? node->height : 0; }

int max(int a, int b) { return a > b ? a : b; }

AVLNode* createAVLNode(int val) {
    AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

AVLNode* rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

AVLNode* rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

int getBalance(AVLNode* node) {
    if (!node) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

AVLNode* insertNode(AVLNode* node, int val) {
    if (!node) {
        return createAVLNode(val);
    }
    if (val < node->val) {
        node->left = insertNode(node->left, val);
    } else if (val > node->val) {
        node->right = insertNode(node->right, val);
    } else {
        return node;
    }

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int balance = getBalance(node);
    if (balance > 1 && val < node->left->val) {
        return rotateRight(node);
    }
    if (balance < -1 && val > node->right->val) {
        return rotateLeft(node);
    }
    if (balance > 1 && val > node->left->val) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (balance < -1 && val < node->right->val) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

AVLNode* minValueNode(AVLNode* node) {
    AVLNode* current = node;
    while (current && current->left) {
        current = current->left;
    }
    return current;
}

AVLNode* deleteNode(AVLNode* root, int val) {
    if (!root) {
        return NULL;
    }
    if (val < root->val) {
        root->left = deleteNode(root->left, val);
    } else if (val > root->val) {
        root->right = deleteNode(root->right, val);
    } else {
        if (!root->left || !root->right) {
            AVLNode* temp = root->left ? root->left : root->right;
            if (!temp) {
                free(root);
                return NULL;
            } else {
                AVLNode* child = temp;
                *root = *child;
                free(child);
            }
        } else {
            AVLNode* temp = minValueNode(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
    }

    if (!root) {
        return NULL;
    }

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = getBalance(root);
    if (balance > 1 && getBalance(root->left) >= 0) {
        return rotateRight(root);
    }
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0) {
        return rotateLeft(root);
    }
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

int lowerBound(AVLNode* root, int val) {
    int result = -1;
    AVLNode* current = root;

    while (current) {
        if (current->val >= val) {
            result = current->val;
            current = current->left;
        } else {
            current = current->right;
        }
    }

    return result;
}

AVLTree* createAVLTree() {
    AVLTree* tree = (AVLTree*)malloc(sizeof(AVLTree));
    tree->root = NULL;
    tree->size = 0;
    return tree;
}

void avlInsert(AVLTree* tree, int val) {
    tree->root = insertNode(tree->root, val);
    tree->size++;
}

void avlRemove(AVLTree* tree, int val) {
    tree->root = deleteNode(tree->root, val);
    tree->size--;
}

Queue* createQueue(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->data = (int*)malloc(capacity * sizeof(int));
    q->front = 0;
    q->rear = 0;
    q->capacity = capacity;
    return q;
}

void enqueue(Queue* q, int val) {
    if (q->rear < q->capacity) {
        q->data[q->rear++] = val;
    }
}

int dequeue(Queue* q) {
    if (q->front < q->rear) {
        return q->data[q->front++];
    }
    return -1;
}

int isQueueEmpty(Queue* q) { return q->front >= q->rear; }

void freeQueue(Queue* q) {
    if (q) {
        free(q->data);
        free(q);
    }
}

void freeAVLNode(AVLNode* node) {
    if (node) {
        freeAVLNode(node->left);
        freeAVLNode(node->right);
        free(node);
    }
}

void freeAVLTree(AVLTree* tree) {
    if (tree) {
        freeAVLNode(tree->root);
        free(tree);
    }
}

int minOperations(char* s, int k) {
    int n = strlen(s);
    int m = 0;

    int* dist = (int*)malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++) {
        dist[i] = INT_MAX;
    }

    AVLTree* trees[2];
    trees[0] = createAVLTree();
    trees[1] = createAVLTree();
    for (int i = 0; i <= n; i++) {
        avlInsert(trees[i % 2], i);
        if (i < n && s[i] == '0') {
            m++;
        }
    }

    Queue* q = createQueue(n + 1);
    enqueue(q, m);
    dist[m] = 0;
    avlRemove(trees[m % 2], m);

    while (!isQueueEmpty(q)) {
        m = dequeue(q);
        int c1 = (k - n + m) > 0 ? (k - n + m) : 0;
        int c2 = m < k ? m : k;
        int lnode = m + k - 2 * c2;
        int rnode = m + k - 2 * c1;

        AVLTree* currentTree = trees[lnode % 2];
        while (true) {
            int nodeVal = lowerBound(currentTree->root, lnode);
            if (nodeVal == -1 || nodeVal > rnode) {
                break;
            }
            dist[nodeVal] = dist[m] + 1;
            enqueue(q, nodeVal);
            avlRemove(currentTree, nodeVal);
            lnode = nodeVal + 1;
        }
    }

    int result = dist[0] == INT_MAX ? -1 : dist[0];
    free(dist);
    freeQueue(q);
    freeAVLTree(trees[0]);
    freeAVLTree(trees[1]);

    return result;
}

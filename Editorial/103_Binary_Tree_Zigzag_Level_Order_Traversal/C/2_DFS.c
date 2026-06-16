typedef struct Node {
    int value;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct Deque {
    Node *head;
    Node *tail;
    int size;
} Deque;

// Deque functions
Deque *createDeque() {
    Deque *dq = (Deque *)malloc(sizeof(Deque));
    if (!dq) return NULL;
    dq->head = dq->tail = NULL;
    dq->size = 0;
    return dq;
}

void pushFront(Deque *dq, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) return;
    newNode->value = value;
    newNode->next = dq->head;
    newNode->prev = NULL;
    if (dq->head)
        dq->head->prev = newNode;
    else
        dq->tail = newNode;
    dq->head = newNode;
    dq->size++;
}

void pushBack(Deque *dq, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) return;
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = dq->tail;
    if (dq->tail)
        dq->tail->next = newNode;
    else
        dq->head = newNode;
    dq->tail = newNode;
    dq->size++;
}

// Free deque memory
void freeDeque(Deque *dq) {
    Node *current = dq->head, *tmp;
    while (current) {
        tmp = current;
        current = current->next;
        free(tmp);
    }
    free(dq);
}

// DFS function to fill the deque according to the zigzag order
void DFS(struct TreeNode *node, int level, Deque **levels, int *maxLevel) {
    if (!node) return;
    if (level > *maxLevel) {
        *maxLevel = level;
        levels[level] = createDeque();
    }
    if (level % 2 == 0)
        pushBack(levels[level], node->val);
    else
        pushFront(levels[level], node->val);

    DFS(node->left, level + 1, levels, maxLevel);
    DFS(node->right, level + 1, levels, maxLevel);
}

int **zigzagLevelOrder(struct TreeNode *root, int *returnSize,
                       int **returnColumnSizes) {
    Deque *levels[1000];  // Max 1000 levels for simplicity
    int maxLevel = -1;
    if (!root) {
        *returnSize = 0;
        return NULL;
    }
    DFS(root, 0, levels, &maxLevel);
    *returnSize = maxLevel + 1;
    int **results = malloc(*returnSize * sizeof(int *));
    *returnColumnSizes = malloc(*returnSize * sizeof(int));

    for (int i = 0; i <= maxLevel; i++) {
        (*returnColumnSizes)[i] = levels[i]->size;
        results[i] = malloc(levels[i]->size * sizeof(int));
        Node *current = levels[i]->head;
        for (int j = 0; j < levels[i]->size; j++) {
            results[i][j] = current->value;
            current = current->next;
        }
        freeDeque(levels[i]);
    }
    return results;
}

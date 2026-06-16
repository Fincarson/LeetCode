struct QueueNode {
    struct TreeNode* node;
    struct QueueNode* next;
};
struct Queue {
    struct QueueNode* head;
    struct QueueNode* tail;
    int size;
};
void queuePush(struct Queue* q, struct TreeNode* node) {
    struct QueueNode* newNode = malloc(sizeof(struct QueueNode));
    newNode->node = node;
    newNode->next = NULL;
    if (!q->head) {
        q->head = newNode;
        q->tail = newNode;
    } else {
        q->tail->next = newNode;
        q->tail = newNode;
    }
    q->size++;
}
struct TreeNode* queuePop(struct Queue* q) {
    struct QueueNode* temp = q->head;
    struct TreeNode* node = temp->node;
    q->head = temp->next;
    if (!q->head) {
        q->tail = NULL;
    }
    free(temp);
    q->size--;
    return node;
}
bool queueIsEmpty(struct Queue* q) { return q->size == 0; }
int minDepth(struct TreeNode* root) {
    if (!root) {
        return 0;
    }
    struct Queue q = {0};
    queuePush(&q, root);
    int depth = 1;
    while (!queueIsEmpty(&q)) {
        int qSize = q.size;
        for (int i = 0; i < qSize; i++) {
            struct TreeNode* node = queuePop(&q);
            // The first leaf node would be at minimum depth, hence return it.
            if (!node->left && !node->right) {
                return depth;
            }
            if (node->left) {
                queuePush(&q, node->left);
            }
            if (node->right) {
                queuePush(&q, node->right);
            }
        }
        depth++;
    }
    return -1;
}

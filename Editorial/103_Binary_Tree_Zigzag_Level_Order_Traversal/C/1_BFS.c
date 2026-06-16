struct QueueNode {
    struct TreeNode* tree_node;
    struct QueueNode* next;
};

struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
    int size;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    q->size = 0;
    return q;
}

void enqueue(struct Queue* q, struct TreeNode* node) {
    struct QueueNode* temp =
        (struct QueueNode*)malloc(sizeof(struct QueueNode));
    temp->tree_node = node;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
    q->size++;
}

struct TreeNode* dequeue(struct Queue* q) {
    if (q->front == NULL) return NULL;

    struct QueueNode* temp = q->front;
    struct TreeNode* node = temp->tree_node;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    q->size--;
    return node;
}

int isEmpty(struct Queue* q) { return q->front == NULL; }

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize,
                       int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    struct Queue* nodeQueue = createQueue();
    enqueue(nodeQueue, root);
    enqueue(nodeQueue, NULL);  // Delimiter for levels

    int** result = NULL;
    *returnSize = 0;
    *returnColumnSizes = NULL;
    bool leftToRight = true;

    int* currentLevel =
        malloc(1000 * sizeof(int));  // Assuming level width max is 1000
    int currentLevelSize = 0;

    while (!isEmpty(nodeQueue)) {
        struct TreeNode* node = dequeue(nodeQueue);

        if (node) {
            if (leftToRight) {
                currentLevel[currentLevelSize++] = node->val;
            } else {
                memmove(&currentLevel[1], &currentLevel[0],
                        currentLevelSize * sizeof(int));
                currentLevel[0] = node->val;
                currentLevelSize++;
            }

            if (node->left) enqueue(nodeQueue, node->left);
            if (node->right) enqueue(nodeQueue, node->right);
        } else {
            int* newLevel = malloc(currentLevelSize * sizeof(int));
            memcpy(newLevel, currentLevel, currentLevelSize * sizeof(int));

            int** tempResult =
                realloc(result, (*returnSize + 1) * sizeof(int*));
            result = tempResult;
            result[*returnSize] = newLevel;

            int* tempCols =
                realloc(*returnColumnSizes, (*returnSize + 1) * sizeof(int));
            *returnColumnSizes = tempCols;
            (*returnColumnSizes)[*returnSize] = currentLevelSize;
            (*returnSize)++;

            currentLevelSize = 0;  // Reset for next level
            leftToRight = !leftToRight;
            if (!isEmpty(nodeQueue))
                enqueue(nodeQueue, NULL);  // Delimiter for new level
        }
    }

    free(currentLevel);
    free(nodeQueue);
    return result;
}

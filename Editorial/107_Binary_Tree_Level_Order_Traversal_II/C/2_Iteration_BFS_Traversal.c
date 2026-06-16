struct Node {
    struct TreeNode* val;
    struct Node* next;
};
struct Queue {
    struct Node *front, *rear;
};
struct Node* newNode(struct TreeNode* v) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->val = v;
    temp->next = NULL;
    return temp;
};
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
};
void enQueue(struct Queue* q, struct TreeNode* v) {
    struct Node* temp = newNode(v);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}
void deQueue(struct Queue* q) {
    if (q->front == NULL) return;
    struct Node* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
}
int** levelOrderBottom(struct TreeNode* root, int* returnSize,
                       int** returnColumnSizes) {
    int** result = malloc(sizeof(int*) * 10000);
    *returnColumnSizes = malloc(sizeof(int) * 10000);
    *returnSize = 0;
    if (root == NULL) return result;
    struct Queue* q = createQueue();
    enQueue(q, root);
    while (q->front != NULL) {
        struct Queue* temp_q = createQueue();
        result[*returnSize] = malloc(sizeof(int) * 2000);
        (*returnColumnSizes)[*returnSize] = 0;
        while (q->front != NULL) {
            struct TreeNode* v = q->front->val;
            deQueue(q);
            result[*returnSize][(*returnColumnSizes)[*returnSize]] = v->val;
            (*returnColumnSizes)[*returnSize]++;
            if (v->left) enQueue(temp_q, v->left);
            if (v->right) enQueue(temp_q, v->right);
        }
        *returnSize += 1;
        q = temp_q;
    }
    int s = 0, e = *returnSize - 1;
    while (s < e) {
        int tempSize = (*returnColumnSizes)[s];
        int* temp = result[s];
        (*returnColumnSizes)[s] = (*returnColumnSizes)[e];
        result[s] = result[e];
        (*returnColumnSizes)[e] = tempSize;
        result[e] = temp;
        s++;
        e--;
    }
    return result;
}

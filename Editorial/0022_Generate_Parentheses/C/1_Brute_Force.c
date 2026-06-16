bool isValid(char* pString) {
    int leftCount = 0;
    for (int i = 0; i < strlen(pString); i++) {
        if (pString[i] == '(') {
            leftCount++;
        } else {
            leftCount--;
        }
        if (leftCount < 0) {
            return false;
        }
    }
    return leftCount == 0;
}
typedef struct queueNode {
    char* str;
    struct queueNode* next;
} QueueNode;
QueueNode* newNode(char* str) {
    QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
    node->str = str;
    node->next = NULL;
    return node;
}
typedef struct queue {
    QueueNode *front, *rear;
} Queue;
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}
void enQueue(Queue* q, char* str) {
    QueueNode* node = newNode(str);
    if (q->rear == NULL) {
        q->front = q->rear = node;
        return;
    }
    q->rear->next = node;
    q->rear = node;
}
void deQueue(Queue* q) {
    if (q->front == NULL) return;
    QueueNode* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
}
bool isQueueEmpty(Queue* q) { return q->rear == NULL; }
char* front(Queue* q) { return q->front->str; }
char** generateParenthesis(int n, int* returnSize) {
    char** answer = (char**)malloc(sizeof(char*) * 10000);
    Queue* queue = createQueue();
    enQueue(queue, "");
    int index = 0;
    while (!isQueueEmpty(queue)) {
        char* curString = front(queue);
        deQueue(queue);
        if (strlen(curString) == 2 * n) {
            if (isValid(curString)) {
                answer[index] = curString;
                index++;
            }
            continue;
        }
        char* appendStringR = (char*)malloc(strlen(curString) + 2);
        strcpy(appendStringR, curString);
        strcat(appendStringR, ")");
        enQueue(queue, appendStringR);
        char* appendStringL = (char*)malloc(strlen(curString) + 2);
        strcpy(appendStringL, curString);
        strcat(appendStringL, "(");
        enQueue(queue, appendStringL);
    }
    *returnSize = index;
    return answer;
}

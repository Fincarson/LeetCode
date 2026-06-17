#define MOD 1000000007LL

typedef struct {
    int* data;
    int front;
    int rear;
    int capacity;
} Deque;

Deque* createDeque(int capacity) {
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    dq->data = (int*)malloc(capacity * sizeof(int));
    dq->front = 0;
    dq->rear = -1;
    dq->capacity = capacity;
    return dq;
}

int isEmpty(Deque* dq) { return dq->rear < dq->front; }

void pushBack(Deque* dq, int value) {
    if (dq->rear < dq->capacity - 1) {
        dq->data[++dq->rear] = value;
    }
}

void popBack(Deque* dq) {
    if (!isEmpty(dq)) {
        dq->rear--;
    }
}

void popFront(Deque* dq) {
    if (!isEmpty(dq)) {
        dq->front++;
    }
}

int front(Deque* dq) { return isEmpty(dq) ? -1 : dq->data[dq->front]; }

int back(Deque* dq) { return isEmpty(dq) ? -1 : dq->data[dq->rear]; }

int countPartitions(int* nums, int numsSize, int k) {
    long long* dp = (long long*)malloc((numsSize + 1) * sizeof(long long));
    long long* prefix = (long long*)malloc((numsSize + 1) * sizeof(long long));
    Deque* minQ = createDeque(numsSize);
    Deque* maxQ = createDeque(numsSize);

    dp[0] = 1;
    prefix[0] = 1;
    int j = 0;

    for (int i = 0; i < numsSize; i++) {
        // maintain the maximum value queue
        while (!isEmpty(maxQ) && nums[back(maxQ)] <= nums[i]) {
            popBack(maxQ);
        }
        pushBack(maxQ, i);

        // maintain the minimum value queue
        while (!isEmpty(minQ) && nums[back(minQ)] >= nums[i]) {
            popBack(minQ);
        }
        pushBack(minQ, i);

        // adjust window
        while (!isEmpty(maxQ) && !isEmpty(minQ) &&
               nums[front(maxQ)] - nums[front(minQ)] > k) {
            if (front(maxQ) == j) {
                popFront(maxQ);
            }
            if (front(minQ) == j) {
                popFront(minQ);
            }
            j++;
        }

        if (j > 0) {
            dp[i + 1] = (prefix[i] - prefix[j - 1] + MOD) % MOD;
        } else {
            dp[i + 1] = prefix[i] % MOD;
        }
        prefix[i + 1] = (prefix[i] + dp[i + 1]) % MOD;
    }

    int result = (int)dp[numsSize];

    free(dp);
    free(prefix);
    free(minQ->data);
    free(minQ);
    free(maxQ->data);
    free(maxQ);

    return result;
}

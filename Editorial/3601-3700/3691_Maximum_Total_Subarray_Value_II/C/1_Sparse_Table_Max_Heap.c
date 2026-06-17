typedef struct {
    int val, l, r;
} Tuple;

typedef struct {
    Tuple* data;
    int size;
} MaxHeap;

void heapPush(MaxHeap* h, Tuple t) {
    int i = h->size++;
    while (i > 0) {
        int p = (i - 1) >> 1;
        if (h->data[p].val >= t.val) {
            break;
        }
        h->data[i] = h->data[p];
        i = p;
    }
    h->data[i] = t;
}

Tuple heapPop(MaxHeap* h) {
    Tuple top = h->data[0];
    Tuple last = h->data[--h->size];
    if (h->size > 0) {
        h->data[0] = last;
        int i = 0;
        while (1) {
            int largest = i;
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            if (l < h->size && h->data[l].val > h->data[largest].val) {
                largest = l;
            }
            if (r < h->size && h->data[r].val > h->data[largest].val) {
                largest = r;
            }
            if (largest == i) {
                break;
            }
            Tuple tmp = h->data[i];
            h->data[i] = h->data[largest];
            h->data[largest] = tmp;
            i = largest;
        }
    }
    return top;
}

long long maxTotalValue(int* nums, int numsSize, int k) {
    int n = numsSize;
    int logn = 32 - __builtin_clz(n);
    int (*stMax)[logn] = malloc(n * logn * sizeof(int));
    int (*stMin)[logn] = malloc(n * logn * sizeof(int));
    for (int i = 0; i < n; i++) {
        stMax[i][0] = stMin[i][0] = nums[i];
    }
    for (int j = 1; j < logn; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            stMax[i][j] =
                (int)fmax(stMax[i][j - 1], stMax[i + (1 << (j - 1))][j - 1]);
            stMin[i][j] =
                (int)fmin(stMin[i][j - 1], stMin[i + (1 << (j - 1))][j - 1]);
        }
    }
    MaxHeap heap;
    heap.data = malloc(n * sizeof(Tuple));
    heap.size = 0;
    for (int l = 0; l < n; l++) {
        int j = 31 - __builtin_clz(n - 1 - l + 1);
        int mx = (int)fmax(stMax[l][j], stMax[n - 1 - (1 << j) + 1][j]);
        int mn = (int)fmin(stMin[l][j], stMin[n - 1 - (1 << j) + 1][j]);
        heapPush(&heap, (Tuple){mx - mn, l, n - 1});
    }
    long long ans = 0;
    while (k--) {
        Tuple t = heapPop(&heap);
        ans += t.val;
        if (t.r > t.l) {
            int j = 31 - __builtin_clz(t.r - 1 - t.l + 1);
            int mx = (int)fmax(stMax[t.l][j], stMax[t.r - 1 - (1 << j) + 1][j]);
            int mn = (int)fmin(stMin[t.l][j], stMin[t.r - 1 - (1 << j) + 1][j]);
            heapPush(&heap, (Tuple){mx - mn, t.l, t.r - 1});
        }
    }
    free(heap.data);
    free(stMax);
    free(stMin);
    return ans;
}

typedef struct {
    int* maxv;
    int* minv;
    int n;
} SegTree;

void segBuild(SegTree* seg, int node, int l, int r, int* nums) {
    if (l == r) {
        seg->maxv[node] = seg->minv[node] = nums[l];
        return;
    }
    int m = (l + r) / 2;
    segBuild(seg, node * 2, l, m, nums);
    segBuild(seg, node * 2 + 1, m + 1, r, nums);
    seg->maxv[node] = (int)fmax(seg->maxv[node * 2], seg->maxv[node * 2 + 1]);
    seg->minv[node] = (int)fmin(seg->minv[node * 2], seg->minv[node * 2 + 1]);
}

SegTree* segTreeCreate(int* nums, int n) {
    SegTree* seg = malloc(sizeof(SegTree));
    seg->n = n;
    seg->maxv = calloc(n * 4, sizeof(int));
    seg->minv = calloc(n * 4, sizeof(int));
    segBuild(seg, 1, 0, n - 1, nums);
    return seg;
}

int segQueryMax(SegTree* seg, int node, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
        return seg->maxv[node];
    }
    int m = (l + r) / 2, res = INT_MIN;
    if (ql <= m) {
        res = (int)fmax(res, segQueryMax(seg, node * 2, l, m, ql, qr));
    }
    if (qr > m) {
        res = (int)fmax(res, segQueryMax(seg, node * 2 + 1, m + 1, r, ql, qr));
    }
    return res;
}

int segQueryMin(SegTree* seg, int node, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
        return seg->minv[node];
    }
    int m = (l + r) / 2, res = INT_MAX;
    if (ql <= m) {
        res = (int)fmin(res, segQueryMin(seg, node * 2, l, m, ql, qr));
    }
    if (qr > m) {
        res = (int)fmin(res, segQueryMin(seg, node * 2 + 1, m + 1, r, ql, qr));
    }
    return res;
}

void segTreeFree(SegTree* seg) {
    free(seg->maxv);
    free(seg->minv);
    free(seg);
}

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
            int lc = 2 * i + 1, rc = 2 * i + 2;
            if (lc < h->size && h->data[lc].val > h->data[largest].val) {
                largest = lc;
            }
            if (rc < h->size && h->data[rc].val > h->data[largest].val) {
                largest = rc;
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
    SegTree* seg = segTreeCreate(nums, n);
    MaxHeap heap;
    heap.data = malloc(n * sizeof(Tuple));
    heap.size = 0;
    for (int l = 0; l < n; l++) {
        int mx = segQueryMax(seg, 1, 0, n - 1, l, n - 1);
        int mn = segQueryMin(seg, 1, 0, n - 1, l, n - 1);
        heapPush(&heap, (Tuple){mx - mn, l, n - 1});
    }
    long long ans = 0;
    while (k--) {
        Tuple t = heapPop(&heap);
        ans += t.val;
        if (t.r > t.l) {
            int mx = segQueryMax(seg, 1, 0, n - 1, t.l, t.r - 1);
            int mn = segQueryMin(seg, 1, 0, n - 1, t.l, t.r - 1);
            heapPush(&heap, (Tuple){mx - mn, t.l, t.r - 1});
        }
    }
    free(heap.data);
    segTreeFree(seg);
    return ans;
}

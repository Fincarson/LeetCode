#define MOD 1000000007

typedef struct {
    int* data;
    int size;
    int capacity;
} Vector;

Vector* vectorCreate() {
    Vector* vec = (Vector*)malloc(sizeof(Vector));
    vec->size = 0;
    vec->capacity = 16;
    vec->data = (int*)malloc(vec->capacity * sizeof(int));
    return vec;
}

void vectorPushBack(Vector* vec, int val) {
    if (vec->size >= vec->capacity) {
        vec->capacity *= 2;
        vec->data = (int*)realloc(vec->data, vec->capacity * sizeof(int));
    }
    vec->data[vec->size++] = val;
}

int vectorBack(Vector* vec) {
    if (vec->size == 0) return 0;
    return vec->data[vec->size - 1];
}

void vectorSetBack(Vector* vec, int val) {
    if (vec->size == 0) {
        vectorPushBack(vec, val);
    } else {
        vec->data[vec->size - 1] = val;
    }
}

int vectorAt(Vector* vec, int idx) {
    if (idx < 0 || idx >= vec->size) {
        return 0;
    }
    return vec->data[idx];
}

int vectorSize(Vector* vec) { return vec->size; }

void vectorFree(Vector* vec) {
    free(vec->data);
    free(vec);
}

typedef struct {
    Vector* v;
    Vector* a;
    Vector* b;
} Fancy;

// 创建 Fancy 对象
Fancy* fancyCreate() {
    Fancy* obj = (Fancy*)malloc(sizeof(Fancy));
    obj->v = vectorCreate();
    obj->a = vectorCreate();
    obj->b = vectorCreate();
    // 初始化 a[0] = 1, b[0] = 0
    vectorPushBack(obj->a, 1);
    vectorPushBack(obj->b, 0);

    return obj;
}

// fast exponentiation
int quickMul(int x, int y) {
    long long ret = 1;
    long long cur = x;
    while (y) {
        if (y & 1) {
            ret = ret * cur % MOD;
        }
        cur = cur * cur % MOD;
        y >>= 1;
    }
    return (int)ret;
}

// multiplicative inverse
int inv(int x) { return quickMul(x, MOD - 2); }

// 添加值
void fancyAppend(Fancy* obj, int val) {
    if (!obj || !obj->v || !obj->a || !obj->b) {
        return;
    }
    vectorPushBack(obj->v, val);
    vectorPushBack(obj->a, vectorBack(obj->a));
    vectorPushBack(obj->b, vectorBack(obj->b));
}

// 增加所有值
void fancyAddAll(Fancy* obj, int inc) {
    if (!obj || !obj->b) {
        return;
    }
    if (vectorSize(obj->b) > 0) {
        int last = (vectorBack(obj->b) + inc) % MOD;
        vectorSetBack(obj->b, last);
    }
}

// 乘以所有值
void fancyMultAll(Fancy* obj, int m) {
    if (!obj || !obj->a || !obj->b) {
        return;
    }
    if (vectorSize(obj->a) > 0 && vectorSize(obj->b) > 0) {
        int a_last = (int)((long long)vectorBack(obj->a) * m % MOD);
        int b_last = (int)((long long)vectorBack(obj->b) * m % MOD);
        vectorSetBack(obj->a, a_last);
        vectorSetBack(obj->b, b_last);
    }
}

// 获取索引处的值
int fancyGetIndex(Fancy* obj, int idx) {
    if (!obj || !obj->v || !obj->a || !obj->b) {
        return -1;
    }
    if (idx >= vectorSize(obj->v)) {
        return -1;
    }

    long long ao =
        (long long)inv(vectorAt(obj->a, idx)) * vectorBack(obj->a) % MOD;
    long long bo = (vectorBack(obj->b) -
                    (long long)vectorAt(obj->b, idx) * ao % MOD + MOD) %
                   MOD;
    long long ans = (ao * vectorAt(obj->v, idx) % MOD + bo) % MOD;

    return (int)ans;
}

// 释放 Fancy 对象
void fancyFree(Fancy* obj) {
    if (!obj) {
        return;
    }
    if (obj->v) {
        vectorFree(obj->v);
    }
    if (obj->a) {
        vectorFree(obj->a);
    }
    if (obj->b) {
        vectorFree(obj->b);
    }
    free(obj);
}

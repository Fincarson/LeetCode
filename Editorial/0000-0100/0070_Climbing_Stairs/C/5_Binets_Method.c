/* C */
int64_t mult(int64_t a, int64_t b) { return a * b; }
int64_t** multiply(int64_t** a, int64_t** b) {
    int64_t** c = (int64_t**)malloc(2 * sizeof(int64_t*));
    for (int i = 0; i < 2; i++) c[i] = (int64_t*)malloc(2 * sizeof(int64_t));
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            c[i][j] = mult(a[i][0], b[0][j]) + mult(a[i][1], b[1][j]);
    return c;
}
int64_t** pow_matrix(int64_t** a, int n) {
    int64_t** ret = (int64_t**)malloc(2 * sizeof(int64_t*));
    for (int i = 0; i < 2; i++) ret[i] = (int64_t*)malloc(2 * sizeof(int64_t));
    ret[0][0] = 1;
    ret[0][1] = 0;
    ret[1][0] = 0;
    ret[1][1] = 1;
    while (n > 0) {
        if ((n & 1) == 1) ret = multiply(ret, a);
        n >>= 1;
        a = multiply(a, a);
    }
    return ret;
}
int climbStairs(int n) {
    int64_t** q = (int64_t**)malloc(2 * sizeof(int64_t*));
    for (int i = 0; i < 2; i++) q[i] = (int64_t*)malloc(2 * sizeof(int64_t));
    q[0][0] = 1;
    q[0][1] = 1;
    q[1][0] = 1;
    q[1][1] = 0;
    int64_t** res = pow_matrix(q, n);
    return (int)res[0][0];
}

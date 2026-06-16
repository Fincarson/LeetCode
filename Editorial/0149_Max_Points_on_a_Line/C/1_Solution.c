struct hash_map {
    double key;
    int val;
    UT_hash_handle hh;
};
int maxPoints(int **points, int pointsSize, int *pointsColSize) {
    if (pointsSize == 1) {
        return 1;
    }
    int result = 2;
    for (int i = 0; i < pointsSize; i++) {
        struct hash_map *cnt = NULL, *tmp;
        for (int j = 0; j < pointsSize; j++) {
            if (j != i) {
                double key = atan2((double)(points[j][1] - points[i][1]),
                                   (double)(points[j][0] - points[i][0]));
                HASH_FIND(hh, cnt, &key, sizeof(double), tmp);
                if (tmp == NULL) {
                    tmp = (struct hash_map *)malloc(sizeof(struct hash_map));
                    tmp->key = key;
                    tmp->val = 1;
                    HASH_ADD(hh, cnt, key, sizeof(double), tmp);
                } else {
                    tmp->val++;
                }
            }
        }
        struct hash_map *s;
        int maxCnt = 0;
        for (s = cnt; s != NULL; s = s->hh.next) {
            if (s->val > maxCnt) {
                maxCnt = s->val;
            }
        }
        result = result > maxCnt + 1 ? result : maxCnt + 1;
        HASH_CLEAR(hh, cnt);
    }
    return result;
}

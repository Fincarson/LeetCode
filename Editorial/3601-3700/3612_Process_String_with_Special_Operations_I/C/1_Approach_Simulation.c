char* processStr(const char* s) {
    size_t cap = 16;
    size_t len = 0;
    char* res = malloc(cap);
    if (!res) return NULL;
    res[0] = '\0';
    for (const char* p = s; *p; ++p) {
        char c = *p;
        if (c == '*') {
            if (len) {
                len--;
                res[len] = '\0';
            }
        } else if (c == '#') {
            size_t need = len * 2 + 1;
            if (need > cap) {
                while (cap < need) cap *= 2;
                res = realloc(res, cap);
                if (!res) return NULL;
            }
            memcpy(res + len, res, len);
            len *= 2;
            res[len] = '\0';
        } else if (c == '%') {
            for (size_t i = 0; i < len / 2; ++i) {
                char t = res[i];
                res[i] = res[len - 1 - i];
                res[len - 1 - i] = t;
            }
            res[len] = '\0';
        } else {
            if (len + 2 > cap) {
                while (cap < len + 2) cap *= 2;
                res = realloc(res, cap);
                if (!res) return NULL;
            }
            res[len++] = c;
            res[len] = '\0';
        }
    }
    return res;
}

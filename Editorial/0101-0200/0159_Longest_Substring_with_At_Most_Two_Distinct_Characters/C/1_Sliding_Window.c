struct hash {
    char key;
    int val;
    UT_hash_handle hh;
};

int lengthOfLongestSubstringTwoDistinct(char *s) {
    size_t n = strlen(s);
    if (n < 3) {
        return n;
    }

    int left = 0, right = 0;
    struct hash *hashmap = NULL, *element, *tmp;
    int max_len = 2;

    while (right < n) {
        HASH_FIND(hh, hashmap, &s[right], sizeof(char), element);
        if (element != NULL) {
            HASH_DEL(hashmap, element);
            free(element);
        }

        element = (struct hash *)malloc(sizeof(*element));
        if (element == NULL) return -1;

        element->key = s[right];
        element->val = right;
        HASH_ADD_KEYPTR(hh, hashmap, &element->key, sizeof(char), element);
        right++;

        if (HASH_COUNT(hashmap) == 3) {
            int del_idx = INT_MAX;
            HASH_ITER(hh, hashmap, element, tmp) {
                del_idx = del_idx < element->val ? del_idx : element->val;
            }

            HASH_FIND(hh, hashmap, &s[del_idx], sizeof(char), element);
            if (element != NULL) {
                HASH_DEL(hashmap, element);
                free(element);
            }
            left = del_idx + 1;
        }
        max_len = max_len > (right - left) ? max_len : (right - left);
    }
    return max_len;
}

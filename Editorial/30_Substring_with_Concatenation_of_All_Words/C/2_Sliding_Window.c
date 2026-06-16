struct hash {
    char key[1024];
    int val;
    UT_hash_handle hh;
};
void change_hash(struct hash **myhash, char *key, int change) {
    struct hash *s;
    HASH_FIND_STR(*myhash, key, s); /* id already in the hash? */
    s->val += change;
}
void add_hash(struct hash **myhash, char *key, int val) {
    struct hash *s;
    HASH_FIND_STR(*myhash, key, s); /* id already in the hash? */
    if (s == NULL) {
        s = (struct hash *)malloc(sizeof(struct hash));
        strncpy(s->key, key, strlen(key) + 1); /* copy id to new struct */
        HASH_ADD_STR(*myhash, key, s);         /* id: name of key field */
    }
    s->val = val; /* store it */
}
bool exists_in_hash(struct hash *myhash, char *key) {
    struct hash *s;
    HASH_FIND_STR(myhash, key, s); /* id already in the hash? */
    if (s) {
        return true;
    }
    return false;
}
int find_in_hash(struct hash *myhash, char *key) {
    struct hash *s;
    HASH_FIND_STR(myhash, key, s); /* id already in the hash? */
    if (s) {
        return s->val;
    }
    return 0;
}
void reset_hash(struct hash **myhash) {
    struct hash *s, *tmp;
    HASH_ITER(hh, *myhash, s, tmp) {
        HASH_DEL(*myhash, s);
        free(s);
    }
    *myhash = NULL;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findSubstring(char *s, char **words, int wordsSize, int *returnSize) {
    int n = strlen(s);
    int k = wordsSize;
    int word_length = strlen(words[0]);
    int substring_size = word_length * k;
    struct hash *word_count = NULL;
    for (int i = 0; i < wordsSize; ++i) {
        add_hash(&word_count, words[i], find_in_hash(word_count, words[i]) + 1);
    }
    int *answer = (int *)malloc(sizeof(int) * 0);
    int answerSize = 0;
    for (int i = 0; i < word_length; i++) {
        struct hash *words_found = NULL;
        int words_used = 0;
        bool excess_word = false;
        char *sub = (char *)malloc(word_length + 1);
        sub[word_length] = '\0';
        int left = i;
        for (int right = i; right < n; right += word_length) {
            if (right + word_length > n) break;
            strncpy(sub, &s[right], word_length);
            if (!exists_in_hash(word_count, sub)) {
                reset_hash(&words_found);
                words_used = 0;
                excess_word = false;
                left = right + word_length;
            } else {
                char *leftmost_word = (char *)malloc(word_length + 1);
                leftmost_word[word_length] = '\0';
                while (right - left == substring_size || excess_word) {
                    strncpy(leftmost_word, &s[left], word_length);
                    left += word_length;
                    change_hash(&words_found, leftmost_word, -1);
                    if (find_in_hash(words_found, leftmost_word) ==
                        find_in_hash(word_count, leftmost_word)) {
                        excess_word = false;
                    } else {
                        words_used -= 1;
                    }
                }
                add_hash(&words_found, sub, find_in_hash(words_found, sub) + 1);
                if (find_in_hash(words_found, sub) <=
                    find_in_hash(word_count, sub)) {
                    words_used += 1;
                } else {
                    excess_word = true;
                }
                if (words_used == k && !excess_word) {
                    answer =
                        (int *)realloc(answer, sizeof(int) * (++answerSize));
                    answer[answerSize - 1] = left;
                }
            }
        }
    }
    *returnSize = answerSize;
    return answer;
}

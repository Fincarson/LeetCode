struct map {
    int index; /* key */
    int result;
    UT_hash_handle hh; /* makes this structure hashable */
};
struct map *memo = NULL;
void add_num(int index, int result) {
    struct map *s;
    s = malloc(sizeof(struct map));
    s->index = index;
    s->result = result;
    HASH_ADD_INT(memo, index, s); /* index: name of key field */
}
int find_num(int index) {
    struct map *s;
    HASH_FIND_INT(memo, &index, s);
    return (s == NULL) ? -1 : s->result;
}
void delete_all() {
    struct map *curr_element, *tmp;
    HASH_ITER(hh, memo, curr_element, tmp) {
        HASH_DEL(memo, curr_element);
        free(curr_element);
    }
}
int recursiveWithMemo(int index, char *str) {
    int res;
    if ((res = find_num(index)) != -1) {
        return res;
    }
    if (index == strlen(str)) {
        return 1;
    }
    if (str[index] == '0') {
        return 0;
    }
    if (index == strlen(str) - 1) {
        return 1;
    }
    int ans = recursiveWithMemo(index + 1, str);
    if (atoi(strndup(str + index, 2)) <= 26) {
        ans += recursiveWithMemo(index + 2, str);
    }
    add_num(index, ans);
    return ans;
}
int numDecodings(char *s) {
    int res = recursiveWithMemo(0, s);
    delete_all();
    return res;
}

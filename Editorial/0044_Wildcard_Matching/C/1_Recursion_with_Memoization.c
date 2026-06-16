typedef struct {
    char* id;  // we will use the key as a string, e.g., "5,7"
    bool val;
    UT_hash_handle hh;
} hash_entry;
hash_entry* dp = NULL;
char* remove_duplicate_stars(char* p) {
    char* new_string = malloc(strlen(p) + 1);
    int j = 0;
    for (int i = 0; i < strlen(p); i++) {
        if (j == 0 || p[i] != '*')
            new_string[j++] = p[i];
        else if (new_string[j - 1] != '*')
            new_string[j++] = p[i];
    }
    new_string[j] = '\0';
    return new_string;
}
bool helper(int si, int pi, char* s, char* p) {
    char key[20];
    sprintf(key, "%d,%d", si, pi);
    hash_entry* result;
    HASH_FIND_STR(dp, key, result);
    if (result) return result->val;
    hash_entry* entry = malloc(sizeof(hash_entry));
    entry->id = strdup(key);
    if (pi == strlen(p))
        entry->val = (si == strlen(s));
    else if (si == strlen(s))
        entry->val = (pi + 1 == strlen(p) && p[pi] == '*');
    else if (p[pi] == s[si] || p[pi] == '?')
        entry->val = helper(si + 1, pi + 1, s, p);
    else if (p[pi] == '*')
        entry->val = helper(si, pi + 1, s, p) || helper(si + 1, pi, s, p);
    else
        entry->val = false;
    HASH_ADD_STR(dp, id, entry);
    return entry->val;
}
bool isMatch(char* s, char* p) {
    // Clear the hashmap
    hash_entry* curr_entry;
    hash_entry* tmp_entry;
    HASH_ITER(hh, dp, curr_entry, tmp_entry) {
        HASH_DEL(dp, curr_entry);
        free(curr_entry->id);
        free(curr_entry);
    }
    p = remove_duplicate_stars(p);
    return helper(0, 0, s, p);
}

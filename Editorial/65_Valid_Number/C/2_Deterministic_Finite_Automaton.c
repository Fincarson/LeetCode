struct hash_struct {
    int val;
    char id[20];
    UT_hash_handle hh;
};
bool isNumber(char *s) {
    struct hash_struct *hash_table[8];
    for (int i = 0; i < 8; i++) hash_table[i] = NULL;
    void add_item(struct hash_struct * *head, char *string, int number) {
        struct hash_struct *s = malloc(sizeof(struct hash_struct));
        strcpy(s->id, string);
        s->val = number;
        HASH_ADD_STR(*head, id, s);
    }
    add_item(&hash_table[0], "digit", 1);
    add_item(&hash_table[0], "sign", 2);
    add_item(&hash_table[0], "dot", 3);
    add_item(&hash_table[1], "digit", 1);
    add_item(&hash_table[1], "dot", 4);
    add_item(&hash_table[1], "exponent", 5);
    add_item(&hash_table[2], "digit", 1);
    add_item(&hash_table[2], "dot", 3);
    add_item(&hash_table[3], "digit", 4);
    add_item(&hash_table[4], "digit", 4);
    add_item(&hash_table[4], "exponent", 5);
    add_item(&hash_table[5], "sign", 6);
    add_item(&hash_table[5], "digit", 7);
    add_item(&hash_table[6], "digit", 7);
    add_item(&hash_table[7], "digit", 7);
    int current_state = 0;
    struct hash_struct *hash_item;
    for (int i = 0; s[i] != '\0'; i++) {
        char group[10];
        if (isdigit(s[i])) {
            strcpy(group, "digit");
        } else if (s[i] == '+' || s[i] == '-') {
            strcpy(group, "sign");
        } else if (s[i] == 'e' || s[i] == 'E') {
            strcpy(group, "exponent");
        } else if (s[i] == '.') {
            strcpy(group, "dot");
        } else {
            return false;
        }
        HASH_FIND_STR(hash_table[current_state], group, hash_item);
        if (hash_item == NULL) {
            return false;
        }
        current_state = hash_item->val;
    }
    return current_state == 1 || current_state == 4 || current_state == 7;
}

// Translated C solution
struct Node {
    char word[1000];
    struct Node* next;
};

void reverse(char* begin, char* end) {
    char temp;
    while (begin < end) {
        temp = *begin;
        *begin++ = *end;
        *end-- = temp;
    }
}

void add(struct Node** head_ref, char* new_word) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    strcpy(new_node->word, new_word);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

char* reverseWords(char* s) {
    int i = 0, j = 0;
    char temp[1000];
    struct Node* words = NULL;

    while (1) {
        if (s[i] == ' ' || s[i] == '\0') {
            if (j != 0) {
                temp[j] = '\0';
                add(&words, temp);
                j = 0;
            }

            if (s[i] == '\0') break;
        } else {
            temp[j] = s[i];
            j++;
        }
        i++;
    }

    char* ans = (char*)malloc(10000 * sizeof(char));
    struct Node* temp_node = words;
    int k = 0;

    while (temp_node != NULL) {
        for (int m = 0; m < strlen(temp_node->word); m++)
            ans[k++] = temp_node->word[m];
        if (temp_node->next != NULL)
            ans[k++] = ' ';
        else
            ans[k++] = '\0';

        temp_node = temp_node->next;
    }

    return ans;
}

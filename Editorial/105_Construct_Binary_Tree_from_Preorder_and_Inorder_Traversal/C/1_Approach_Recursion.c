struct HASHMAP_ENTRY {
    int key;
    int value;
    UT_hash_handle hh;
};
struct TreeNode* arrayToTree(int* preorder, int* inorder,
                             struct HASHMAP_ENTRY** index_map,
                             int* preorderIndex, int left, int right) {
    if (left > right) return NULL;
    int rootValue = preorder[(*preorderIndex)++];
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = rootValue;
    struct HASHMAP_ENTRY* entry;
    HASH_FIND_INT(*index_map, &rootValue, entry);
    root->left = arrayToTree(preorder, inorder, index_map, preorderIndex, left,
                             entry->value - 1);
    root->right = arrayToTree(preorder, inorder, index_map, preorderIndex,
                              entry->value + 1, right);
    return root;
}
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder,
                           int inorderSize) {
    struct HASHMAP_ENTRY* index_map = NULL;
    for (int i = 0; i < inorderSize; i++) {
        struct HASHMAP_ENTRY* entry =
            (struct HASHMAP_ENTRY*)malloc(sizeof(struct HASHMAP_ENTRY));
        entry->key = inorder[i];
        entry->value = i;
        HASH_ADD_INT(index_map, key, entry);
    }
    int preorderIndex = 0;
    return arrayToTree(preorder, inorder, &index_map, &preorderIndex, 0,
                       inorderSize - 1);
}

struct Item {
    struct TreeNode* node;
    int level;
};
int maxDepth(struct TreeNode* root) {
    if (!root) return 0;
    // The queue that contains the next nodes to visit, along with the
    // level/depth that each node is located.
    int max_depth = 0;
    struct Item
        next_items[10000];  // Assuming tree will not be deeper than 10K levels
    int start = 0;
    int end = 0;
    next_items[end++] = (struct Item){.node = root, .level = 0};
    while (start != end) {
        struct Item next_item = next_items[start++];
        int next_level = next_item.level + 1;
        max_depth = next_level > max_depth ? next_level : max_depth;
        // Add the nodes to visit in the following recursive calls.
        if (next_item.node->left)
            next_items[end++] = (struct Item){.node = next_item.node->left,
                                              .level = next_level};
        if (next_item.node->right)
            next_items[end++] = (struct Item){.node = next_item.node->right,
                                              .level = next_level};
    }
    return max_depth;
}

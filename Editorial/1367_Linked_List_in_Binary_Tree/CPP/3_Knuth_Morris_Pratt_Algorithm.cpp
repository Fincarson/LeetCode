class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        // Build the pattern and prefix table from the linked list
        vector<int> pattern = {head->val}, prefixTable = {0};
        int patternIndex = 0;
        head = head->next;

        while (head) {
            while (patternIndex && head->val != pattern[patternIndex])
                patternIndex = prefixTable[patternIndex - 1];
            patternIndex += head->val == pattern[patternIndex];
            pattern.push_back(head->val);
            prefixTable.push_back(patternIndex);
            head = head->next;
        }

        // Perform DFS to search for the pattern in the tree
        return searchInTree(root, 0, pattern, prefixTable);
    }

private:
    bool searchInTree(TreeNode* node, int patternIndex,
                      const vector<int>& pattern,
                      const vector<int>& prefixTable) {
        if (!node) return false;

        while (patternIndex && node->val != pattern[patternIndex])
            patternIndex = prefixTable[patternIndex - 1];
        patternIndex += node->val == pattern[patternIndex];

        // Check if the pattern is fully matched
        if (patternIndex == pattern.size()) return true;

        // Recursively search left and right subtrees
        return searchInTree(node->left, patternIndex, pattern, prefixTable) ||
               searchInTree(node->right, patternIndex, pattern, prefixTable);
    }
};

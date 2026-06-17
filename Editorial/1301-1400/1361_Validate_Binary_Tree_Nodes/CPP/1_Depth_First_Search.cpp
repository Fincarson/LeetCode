int findRoot(int n, vector<int>& left, vector<int>& right) {
    unordered_set<int> children;
    children.insert(left.begin(), left.end());
    children.insert(right.begin(), right.end());
    
    for (int i = 0; i < n; i++) {
        if (children.find(i) == children.end()) {
            return i;
        }
    }
    
    return -1;
}

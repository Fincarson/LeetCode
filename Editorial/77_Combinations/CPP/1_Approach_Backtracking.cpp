void backtrack(vector<int>& curr, int firstNum, vector<vector<int>>& ans) {
    if (curr.size() == k) {
        ans.push_back(curr);
        return;
    }

    for (int num = firstNum; num <= n; num++) {
        curr.push_back(num);
        backtrack(curr, num + 1, ans);
        curr.pop_back();
    }

    return;
}

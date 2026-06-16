class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        int m = (int)1e5 + 1;
        vector<int> tree(m * 2);

        long cost = 0;
        long MOD = (int)1e9 + 7;
        for (int x : instructions) {
            cost += min(query(0, x, tree, m), query(x + 1, m, tree, m));
            update(x, 1, tree, m);
        }
        return (int)(cost % MOD);
    }

    // implement Segment Tree
    void update(int index, int value, vector<int>& tree, int m) {
        index += m;
        tree[index] += value;
        for (index >>= 1; index > 0; index >>= 1)
            tree[index] = tree[index << 1] + tree[(index << 1) + 1];
    }

    int query(int left, int right, vector<int>& tree, int m) {
        int result = 0;
        for (left += m, right += m; left < right; left >>= 1, right >>= 1) {
            if ((left & 1) == 1) result += tree[left++];
            if ((right & 1) == 1) result += tree[--right];
        }
        return result;
    }
};

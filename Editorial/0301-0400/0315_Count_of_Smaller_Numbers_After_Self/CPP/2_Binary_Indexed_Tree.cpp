class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int offset = 1e4;        // offset negative to non-negative
        int size = 2 * 1e4 + 2;  // total possible values in nums plus one dummy
        vector<int> tree(size);
        vector<int> result;

        for (int i = nums.size() - 1; i >= 0; i--) {
            int smaller_count = query(nums[i] + offset, tree);
            result.push_back(smaller_count);
            update(nums[i] + offset, 1, tree, size);
        }
        reverse(result.begin(), result.end());
        return result;
    }

    // implement Binary Index Tree
    void update(int index, int value, vector<int>& tree, int size) {
        index++;  // index in BIT is 1 more than the original index
        while (index < size) {
            tree[index] += value;
            index += index & -index;
        }
    }

    int query(int index, vector<int>& tree) {
        // return sum of [0, index)
        int result = 0;
        while (index >= 1) {
            result += tree[index];
            index -= index & -index;
        }
        return result;
    }
};

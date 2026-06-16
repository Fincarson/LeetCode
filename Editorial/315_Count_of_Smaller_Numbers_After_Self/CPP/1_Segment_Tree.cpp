class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int offset = 1e4;        // offset negative to non-negative
        int size = 2 * 1e4 + 1;  // total possible values in nums
        vector<int> tree(size * 2);
        vector<int> result;

        for (int i = nums.size() - 1; i >= 0; i--) {
            int smaller_count = query(0, nums[i] + offset, tree, size);
            result.push_back(smaller_count);
            update(nums[i] + offset, 1, tree, size);
        }
        reverse(result.begin(), result.end());
        return result;
    }

    // implement segment tree
    void update(int index, int value, vector<int>& tree, int size) {
        index += size;  // shift the index to the leaf
        // update from leaf to root
        tree[index] += value;
        while (index > 1) {
            index /= 2;
            tree[index] = tree[index * 2] + tree[index * 2 + 1];
        }
    }

    int query(int left, int right, vector<int>& tree, int size) {
        // return sum of [left, right)
        int result = 0;
        left += size;  // shift the index to the leaf
        right += size;
        while (left < right) {
            // if left is a right node
            // bring the value and move to parent's right node
            if (left % 2 == 1) {
                result += tree[left];
                left++;
            }
            // else directly move to parent
            left /= 2;
            // if right is a right node
            // bring the value of the left node and move to parent
            if (right % 2 == 1) {
                right--;
                result += tree[right];
            }
            // else directly move to parent
            right /= 2;
        }
        return result;
    }
};

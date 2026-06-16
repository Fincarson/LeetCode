class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> K;
        for (int x: nums) K.push(x);
        for (int i = 1; i < k; ++i) K.pop();
        return K.top();
    }
};
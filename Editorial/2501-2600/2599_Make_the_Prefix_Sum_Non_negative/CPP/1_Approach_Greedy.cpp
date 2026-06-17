class Solution {
public:
    int makePrefSumNonNegative(vector<int>& nums) {
        int operations = 0;
        long prefixSum = 0;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int num : nums) {
            // Push negative elements to the mim heap.
            if (num < 0) {
                pq.push(num);
            }

            prefixSum += num;
            // Pop the minimum element from the heap and subtract from the sum.
            if (prefixSum < 0) {
                prefixSum -= pq.top();
                pq.pop();
                // Increment the operations required.
                operations++;
            }
        }

        return operations;
    }
};

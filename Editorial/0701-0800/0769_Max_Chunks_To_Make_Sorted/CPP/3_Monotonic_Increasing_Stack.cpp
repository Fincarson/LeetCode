class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        // Stack to store the maximum elements of each chunk
        stack<int> monotonicStack;
        for (int i = 0; i < n; i++) {
            // Case 1: Current element is larger, starts a new chunk
            if (monotonicStack.empty() || arr[i] > monotonicStack.top()) {
                monotonicStack.push(arr[i]);
            } else {
                // Case 2: Merge chunks
                int maxElement = monotonicStack.top();
                while (!monotonicStack.empty() &&
                       arr[i] < monotonicStack.top()) {
                    monotonicStack.pop();
                }
                monotonicStack.push(maxElement);
            }
        }
        return monotonicStack.size();
    }
};

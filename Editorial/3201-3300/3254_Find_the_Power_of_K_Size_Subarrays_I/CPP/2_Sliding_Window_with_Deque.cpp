class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int length = nums.size();
        vector<int> result(length - k + 1, -1);
        deque<int> indexDeque;

        for (int currentIndex = 0; currentIndex < length; currentIndex++) {
            // Remove elements that are out of the window
            if (!indexDeque.empty() &&
                indexDeque.front() < currentIndex - k + 1) {
                indexDeque.pop_front();
            }

            // Check if current element breaks the consecutive and sorted condition
            if (!indexDeque.empty() &&
                nums[currentIndex] != nums[currentIndex - 1] + 1) {
                indexDeque.clear();  // Invalidate the entire deque if condition breaks
            }

            // Add current element index to the deque
            indexDeque.push_back(currentIndex);

            // Check if the window is of size k and update result
            if (currentIndex >= k - 1) {
                if (indexDeque.size() == k) {  // Valid window of size k
                    result[currentIndex - k + 1] = nums[indexDeque.back()];
                } else {
                    result[currentIndex - k + 1] = -1;  // Not valid, return -1
                }
            }
        }

        return result;
    }
};

class Solution {
public:
    int minSwaps(vector<int>& data) {
        int ones = accumulate(data.begin(), data.end(), 0);
        int cntOne = 0, maxOne = 0;
        deque<int> dq;

        for (int i = 0; i < data.size(); i++) {
            // Add the new element into the deque
            dq.push_back(data[i]);
            cntOne += data[i];

            // When the deque size exceeds ones, remove the leftmost element
            if (dq.size() > ones) {
                cntOne -= dq.front();
                dq.pop_front();
            }
            maxOne = max(maxOne, cntOne);
        }
        return ones - maxOne;
    }
};

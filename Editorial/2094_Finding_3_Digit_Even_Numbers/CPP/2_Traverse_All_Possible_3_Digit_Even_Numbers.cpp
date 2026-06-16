class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> res;  // Target even number array
        unordered_map<int, int>
            freq;  // The frequency of each number in the integer array
        for (const int digit : digits) {
            ++freq[digit];
        }
        // Enumerate all three-digit even numbers, maintain the frequency of
        // each digit in the integer, and compare and judge whether it is the
        // target even number
        for (int i = 100; i < 1000; i += 2) {
            unordered_map<int, int> freq1;
            int tmp = i;
            while (tmp) {
                ++freq1[tmp % 10];
                tmp /= 10;
            }
            if (all_of(freq1.begin(), freq1.end(), [&](const auto& x) {
                    return freq[x.first] >= freq1[x.first];
                })) {
                res.push_back(i);
            }
        }
        return res;
    }
};

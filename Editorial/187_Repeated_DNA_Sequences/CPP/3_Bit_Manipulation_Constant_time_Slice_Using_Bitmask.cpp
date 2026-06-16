class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int L = 10, n = s.size();
        if (n <= L) return {};

        // convert string to array of integers
        unordered_map<char, int> toInt = {
            {'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) nums[i] = toInt[s[i]];

        int bitmask = 0;
        unordered_set<int> seen;
        unordered_set<string> output;
        // iterate over all sequences of length L
        for (int start = 0; start < n - L + 1; ++start) {
            // compute bitmask of the current sequence in O(1) time
            if (start != 0) {
                // left shift to free the last 2 bit
                bitmask <<= 2;
                // add a new 2-bits number in the last two bits
                bitmask |= nums[start + L - 1];
                // unset first two bits: 2L-bit and (2L + 1)-bit
                bitmask &= ~(3 << 2 * L);
            }
            // compute bitmask of the first sequence in O(L) time
            else {
                for (int i = 0; i < L; ++i) {
                    bitmask <<= 2;
                    bitmask |= nums[i];
                }
            }
            // update output and hashset of seen sequences
            if (seen.find(bitmask) != seen.end())
                output.insert(s.substr(start, L));
            seen.insert(bitmask);
        }
        return vector<string>(output.begin(), output.end());
    }
};

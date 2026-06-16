class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int L = 10, n = s.size();
        if (n <= L) return vector<string>();

        // rolling hash parameters: base a
        int a = 4, aL = pow(a, L);

        // convert string to array of integers
        unordered_map<char, int> to_int = {
            {'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) nums[i] = to_int[s[i]];

        int h = 0;
        unordered_set<int> seen;
        unordered_set<string> output;
        // iterate over all sequences of length L
        for (int start = 0; start < n - L + 1; ++start) {
            // compute hash of the current sequence in O(1) time
            if (start != 0)
                h = h * a - nums[start - 1] * aL + nums[start + L - 1];

            // compute hash of the first sequence in O(L) time
            else
                for (int i = 0; i < L; ++i) h = h * a + nums[i];

            // update output and hashset of seen sequences
            if (seen.find(h) != seen.end()) output.insert(s.substr(start, L));
            seen.insert(h);
        }
        return vector<string>(output.begin(), output.end());
    }
};

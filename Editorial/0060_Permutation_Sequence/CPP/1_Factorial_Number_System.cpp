class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorials(n);  // Factorial system bases
        vector<char> nums;          // Numbers
        factorials[0] =
            1;  // Generate factorial system bases 0!, 1!, ..., (n - 1)!
        nums.push_back('1');  // Generate numbers 1, 2, ..., n
        for (int i = 1; i < n; ++i) {
            factorials[i] = factorials[i - 1] * i;
            nums.push_back(char(i + 1 + '0'));
        }
        --k;  // Fit k in the interval 0 ... (n! - 1)
        // Compute the factorial representation of k
        string result = "";
        for (int i = n - 1; i > -1; --i) {
            int idx = k / factorials[i];
            k -= idx * factorials[i];
            result += nums[idx];
            nums.erase(nums.begin() + idx);
        }
        return result;
    }
};

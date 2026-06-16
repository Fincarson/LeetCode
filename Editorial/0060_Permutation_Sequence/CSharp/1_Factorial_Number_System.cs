public class Solution {
    public string GetPermutation(int n, int k) {
        int[] factorials = new int[n];               // Factorial system bases
        List<char> nums = new List<char>() { '1' };  // Numbers
        factorials[0] =
            1;  // Generate factorial system bases 0!, 1!, ..., (n - 1)!
        for (int i = 1; i < n; ++i) {
            // Generate nums 1, 2, ..., n
            factorials[i] = factorials[i - 1] * i;
            nums.Add((char)(i + 1 + '0'));
        }

        // Fit k in the interval 0 ... (n! - 1)
        k--;
        // Compute the factorial representation of k
        StringBuilder result = new StringBuilder();
        for (int i = n - 1; i > -1; --i) {
            int idx = k / factorials[i];
            k -= idx * factorials[i];
            result.Append(nums[idx]);
            nums.RemoveAt(idx);
        }

        return result.ToString();
    }
}

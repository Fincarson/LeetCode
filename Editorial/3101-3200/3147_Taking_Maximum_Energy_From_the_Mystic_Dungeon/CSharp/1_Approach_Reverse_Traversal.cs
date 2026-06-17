public class Solution {
    public int MaximumEnergy(int[] energy, int k) {
        int n = energy.Length;
        int ans = int.MinValue;
        for (int i = n - k; i < n; i++) {
            int sum = 0;
            for (int j = i; j >= 0; j -= k) {
                sum += energy[j];
                if (sum > ans)
                    ans = sum;
            }
        }
        return ans;
    }
}

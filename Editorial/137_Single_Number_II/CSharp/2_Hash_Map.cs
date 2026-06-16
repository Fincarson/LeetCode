public class Solution {
    public int SingleNumber(int[] nums) {
        Dictionary<int, int> freq = new Dictionary<int, int>();
        foreach (int num in nums) {
            if (!freq.ContainsKey(num)) {
                freq[num] = 1;
            } else {
                freq[num]++;
            }
        }

        int loner = 0;
        foreach (KeyValuePair<int, int> entry in freq) {
            if (entry.Value == 1) {
                loner = entry.Key;
                break;
            }
        }

        return loner;
    }
}

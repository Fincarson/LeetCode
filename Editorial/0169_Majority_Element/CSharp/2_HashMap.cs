public class Solution {
    private Dictionary<int, int> countNums(int[] nums) {
        var counts = new Dictionary<int, int>();
        foreach (int num in nums) {
            if (!counts.ContainsKey(num)) {
                counts.Add(num, 1);
            } else {
                counts[num]++;
            }
        }

        return counts;
    }

    public int MajorityElement(int[] nums) {
        var counts = countNums(nums);

        foreach (var count in counts) {
            if (count.Value > nums.Length / 2)
                return count.Key;
        }

        return 0;
    }
}

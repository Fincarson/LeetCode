public class Solution {
    public int MinimumPairRemoval(int[] nums) {
        var next = new int?[nums.Length];
        for (var i = 0; i < nums.Length - 1; i++) next[i] = i + 1;

        var count = 0;

        while (nums.Length - count > 1) {
            int? curr = 0;
            var target = 0;
            var targetAdjSum = nums[target] + nums[next[target]!.Value];
            var isAscending = true;

            while (curr is not null && next[curr.Value] is not null) {
                var nextVal = next[curr.Value]!.Value;

                if (nums[curr.Value] > nums[nextVal]) {
                    isAscending = false;
                }

                var currAdjSum = nums[curr.Value] + nums[nextVal];
                if (currAdjSum < targetAdjSum) {
                    target = curr.Value;
                    targetAdjSum = currAdjSum;
                }

                curr = next[curr.Value];
            }

            if (isAscending) {
                break;
            }

            count++;
            next[target] = next[next[target]!.Value];
            nums[target] = targetAdjSum;
        }

        return count;
    }
}

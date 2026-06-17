public class Solution {
    public int[] SearchRange(int[] nums, int target) {
        int firstOccurrence = this.FindBound(nums, target, true);
        if (firstOccurrence == -1) {
            return new int[] { -1, -1 };
        }

        int lastOccurrence = this.FindBound(nums, target, false);
        return new int[] { firstOccurrence, lastOccurrence };
    }

    private int FindBound(int[] nums, int target, bool isFirst) {
        int N = nums.Length;
        int begin = 0, end = N - 1;
        while (begin <= end) {
            int mid = (begin + end) / 2;
            if (nums[mid] == target) {
                if (isFirst) {
                    if (mid == begin || nums[mid - 1] != target) {
                        return mid;
                    }

                    end = mid - 1;
                } else {
                    if (mid == end || nums[mid + 1] != target) {
                        return mid;
                    }

                    begin = mid + 1;
                }
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                begin = mid + 1;
            }
        }

        return -1;
    }
}

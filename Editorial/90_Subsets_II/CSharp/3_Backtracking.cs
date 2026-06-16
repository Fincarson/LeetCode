public class Solution {
    public IList<IList<int>> SubsetsWithDup(int[] nums) {
        Array.Sort(nums);
        IList<IList<int>> subsets = new List<IList<int>>();
        IList<int> currentSubset = new List<int>();
        SubsetsWithDupHelper(subsets, currentSubset, nums, 0);
        return subsets;
    }

    private void SubsetsWithDupHelper(IList<IList<int>> subsets,
                                      IList<int> currentSubset, int[] nums,
                                      int index) {
        // Add the subset formed so far to the subsets list.
        subsets.Add(new List<int>(currentSubset));
        for (int i = index; i < nums.Length; i++) {
            // If the current element is a duplicate, ignore.
            if (i != index && nums[i] == nums[i - 1]) {
                continue;
            }

            currentSubset.Add(nums[i]);
            SubsetsWithDupHelper(subsets, currentSubset, nums, i + 1);
            currentSubset.RemoveAt(currentSubset.Count - 1);
        }
    }
}

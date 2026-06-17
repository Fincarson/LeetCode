public class Solution {
    public IList<IList<int>> SubsetsWithDup(int[] nums) {
        Array.Sort(nums);
        List<IList<int>> subsets = new List<IList<int>>();
        subsets.Add(new List<int>());
        int subsetSize = 0;
        for (int i = 0; i < nums.Length; i++) {
            // subsetSize refers to the size of the subset in the previous step.
            // This value also indicates the starting index of the subsets
            // generated in this step.
            int startingIndex =
                (i >= 1 && nums[i] == nums[i - 1]) ? subsetSize : 0;
            subsetSize = subsets.Count;
            for (int j = startingIndex; j < subsetSize; j++) {
                List<int> currentSubset = new List<int>(subsets[j]);
                currentSubset.Add(nums[i]);
                subsets.Add(currentSubset);
            }
        }

        return subsets;
    }
}

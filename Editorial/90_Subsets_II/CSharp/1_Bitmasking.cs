public class Solution {
    public IList<IList<int>> SubsetsWithDup(int[] nums) {
        IList<IList<int>> subsets = new List<IList<int>>();
        int n = nums.Length;
        // Sort the generated subset. This will help to identify duplicates.
        Array.Sort(nums);
        int maxNumberOfSubsets = (int)Math.Pow(2, n);
        // To store the previously seen sets.
        HashSet<string> seen = new HashSet<string>();
        for (int subsetIndex = 0; subsetIndex < maxNumberOfSubsets;
             subsetIndex++) {
            // Append subset corresponding to that bitmask.
            List<int> currentSubset = new List<int>();
            StringBuilder hashcode = new StringBuilder();
            for (int j = 0; j < n; j++) {
                // Generate the bitmask
                int mask = 1 << j;
                int isSet = mask & subsetIndex;
                if (isSet != 0) {
                    currentSubset.Add(nums[j]);
                    // Generate the hashcode by creating a comma separated
                    // string of numbers in the currentSubset.
                    hashcode.Append(nums[j]).Append(",");
                }
            }

            if (!seen.Contains(hashcode.ToString())) {
                seen.Add(hashcode.ToString());
                subsets.Add(currentSubset);
            }
        }

        return subsets;
    }
}

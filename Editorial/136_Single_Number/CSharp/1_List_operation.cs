public class Solution {
    public int SingleNumber(int[] nums) {
        List<int> no_duplicate_list = new List<int>();
        foreach (int i in nums) {
            if (!no_duplicate_list.Contains(i)) {
                no_duplicate_list.Add(i);
            } else {
                no_duplicate_list.Remove(i);
            }
        }

        return no_duplicate_list[0];
    }
}

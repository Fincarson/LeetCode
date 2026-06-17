public class Solution {
    public int FindSmallestInteger(int[] nums, int value) {
        int[] mp = new int[value];
        foreach (int x in nums) {
            int v = ((x % value) + value) % value;
            mp[v]++;
        }
        int mex = 0;
        while (mp[mex % value] > 0) {
            mp[mex % value]--;
            mex++;
        }
        return mex;
    }
}

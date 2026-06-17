public class Solution {
    public int SpecialTriplets(int[] nums) {
        const int MOD = 1000000007;
        Dictionary<int, int> numCnt = new Dictionary<int, int>();
        Dictionary<int, int> numPartialCnt = new Dictionary<int, int>();

        foreach (int v in nums) {
            if (numCnt.ContainsKey(v)) {
                numCnt[v]++;
            } else {
                numCnt[v] = 1;
            }
        }

        long ans = 0;
        foreach (int v in nums) {
            int target = v * 2;
            int lCnt =
                numPartialCnt.ContainsKey(target) ? numPartialCnt[target] : 0;
            if (numPartialCnt.ContainsKey(v)) {
                numPartialCnt[v]++;
            } else {
                numPartialCnt[v] = 1;
            }

            int totalCnt = numCnt.ContainsKey(target) ? numCnt[target] : 0;
            int partialCnt =
                numPartialCnt.ContainsKey(target) ? numPartialCnt[target] : 0;
            int rCnt = totalCnt - partialCnt;

            ans = (ans + (long)lCnt * rCnt) % MOD;
        }

        return (int)ans;
    }
}

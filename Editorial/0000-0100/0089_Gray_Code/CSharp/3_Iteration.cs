public class Solution {
    public IList<int> GrayCode(int n) {
        IList<int> result = new List<int>();
        result.Add(0);
        for (int i = 1; i <= n; i++) {
            int previousSequenceLength = result.Count;
            int mask = 1 << (i - 1);
            for (int j = previousSequenceLength - 1; j >= 0; j--) {
                result.Add(mask + result[j]);
            }
        }

        return result;
    }
}

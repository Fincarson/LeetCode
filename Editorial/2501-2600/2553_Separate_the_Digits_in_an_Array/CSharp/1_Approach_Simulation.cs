public class Solution {
    public int[] SeparateDigits(int[] nums) {
        List<int> res = new List<int>();
        foreach (int num in nums) {
            int x = num;
            List<int> tmp = new List<int>();
            while (x > 0) {
                tmp.Add(x % 10);
                x /= 10;
            }
            for (int i = tmp.Count - 1; i >= 0; i--) {
                res.Add(tmp[i]);
            }
        }
        return res.ToArray();
    }
}

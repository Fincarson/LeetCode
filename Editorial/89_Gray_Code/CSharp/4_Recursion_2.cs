public class Solution {
    private int nextNum = 0;

    public IList<int> GrayCode(int n) {
        List<int> result = new List<int>();
        GrayCodeHelper(result, n);
        return result;
    }

    private void GrayCodeHelper(List<int> result, int n) {
        if (n == 0) {
            result.Add(this.nextNum);
            return;
        }

        GrayCodeHelper(result, n - 1);
        // Flip the bit at (n - 1)th position from right
        this.nextNum = this.nextNum ^ (1 << (n - 1));
        GrayCodeHelper(result, n - 1);
    }
}

class Solution {
    int nextNum = 0;

    public List<Integer> grayCode(int n) {
        List<Integer> result = new ArrayList<>();
        grayCodeHelper(result, n);
        return result;
    }

    private void grayCodeHelper(List<Integer> result, int n) {
        if (n == 0) {
            result.add(nextNum);
            return;
        }
        grayCodeHelper(result, n - 1);
        // Flip the bit at (n - 1)th position from right
        nextNum = nextNum ^ (1 << (n - 1));
        grayCodeHelper(result, n - 1);
    }
}

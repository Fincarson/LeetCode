class Solution {
    public String getSmallestString(int n, int k) {
        char[] result = new char[n];
        for (int position = 0; position < n; position++) {
            int positionsLeft = (n - position - 1);
            if (k > positionsLeft * 26) {
                int add = k - (positionsLeft * 26);
                result[position] = (char) ('a' + add - 1);
                k -= add;
            } else {
                result[position] = 'a';
                k--;
            }
        }
        return new String(result);
    }
}

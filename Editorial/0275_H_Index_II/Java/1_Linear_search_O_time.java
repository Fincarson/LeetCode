class Solution {
    public int hIndex(int[] citations) {
        int n = citations.length;
        int idx = 0;
        for (int c : citations) {
            if (c >= n - idx)
                return n - idx;
            else
                idx++;
        }
        return 0;
    }
}

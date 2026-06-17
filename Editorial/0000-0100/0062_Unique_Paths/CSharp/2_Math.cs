public class Solution {
    public int UniquePaths(int m, int n) {
        long totalPlaces = m + n - 2;
        long minPlaces = Math.Min(m - 1, n - 1);
        long result = 1;
        for (int i = 0; i < minPlaces; i++) {
            result = result * (totalPlaces - i) / (i + 1);
        }

        return (int)result;
    }
}

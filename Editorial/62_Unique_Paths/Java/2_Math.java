public class Solution {
    public int uniquePaths(int m, int n) {
        long answer = 1;
        for (int i = n; i < (m + n - 1); i++) {
            answer *= i;
            answer /= (i - n + 1);
        }
        return (int) answer;
    }
}

public class Solution {
    public int TotalWaviness(int num1, int num2) {
        int total = 0;
        for (int i = num1; i <= num2; i++) {
            total += GetWaviness(i);
        }
        return total;
    }

    private int GetWaviness(int x) {
        string s = x.ToString();
        int waviness = 0;

        for (int i = 1; i < s.Length - 1; i++) {
            bool isPeak = s[i] > s[i - 1] && s[i] > s[i + 1];
            bool isValley = s[i] < s[i - 1] && s[i] < s[i + 1];
            if (isPeak || isValley) {
                waviness++;
            }
        }

        return waviness;
    }
}

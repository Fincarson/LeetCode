public class Solution {
    public int MaxDiff(int num) {
        // Replace characters in the string.
        void Replace(ref string s, char x, char y) {
            s = s.Replace(x, y);
        }
        string minNum = num.ToString();
        string maxNum = num.ToString();
        // Find a high position and replace it with 9.
        foreach (char digit in maxNum) {
            if (digit != '9') {
                Replace(ref maxNum, digit, '9');
                break;
            }
        }
        // Replace the most significant bit with 1
        // Or find a high-order digit that is not equal to the highest digit and
        // replace it with 0.
        for (int i = 0; i < minNum.Length; ++i) {
            char digit = minNum[i];
            if (i == 0) {
                if (digit != '1') {
                    Replace(ref minNum, digit, '1');
                    break;
                }
            } else {
                if (digit != '0' && digit != minNum[0]) {
                    Replace(ref minNum, digit, '0');
                    break;
                }
            }
        }
        return int.Parse(maxNum) - int.Parse(minNum);
    }
}

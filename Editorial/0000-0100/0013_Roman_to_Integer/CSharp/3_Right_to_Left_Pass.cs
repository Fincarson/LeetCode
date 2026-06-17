public class Solution {
    static Dictionary<char, int> values = new Dictionary<char, int> {
        { 'I', 1 },   { 'V', 5 },   { 'X', 10 },   { 'L', 50 },
        { 'C', 100 }, { 'D', 500 }, { 'M', 1000 },
    };

    public int RomanToInt(string s) {
        char lastSymbol = s[s.Length - 1];
        int lastValue = values[lastSymbol];
        int total = lastValue;

        for (int i = s.Length - 2; i >= 0; i--) {
            char currentSymbol = s[i];
            int currentValue = values[currentSymbol];
            if (currentValue < lastValue) {
                total -= currentValue;
            } else {
                total += currentValue;
            }

            lastValue = currentValue;
        }

        return total;
    }
}

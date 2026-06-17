public class Solution {
    public int[] FindEvenNumbers(int[] digits) {
        List<int> res = new List<int>();
        Dictionary<int, int> freq = new Dictionary<int, int>();
        // Count the number of occurrences of each number in the integer array
        foreach (int d in digits) {
            freq[d] = freq.ContainsKey(d) ? freq[d] + 1 : 1;
        }
        // Enumerate all three-digit even numbers
        for (int i = 100; i < 1000; i += 2) {
            Dictionary<int, int> freq1 = new Dictionary<int, int>();
            int num = i;
            // Count the frequency of each digit of the current even number
            while (num > 0) {
                int d = num % 10;
                freq1[d] = freq1.ContainsKey(d) ? freq1[d] + 1 : 1;
                num /= 10;
            }
            // Check if the conditions are met
            bool isValid = true;
            foreach (var entry in freq1) {
                if (!freq.ContainsKey(entry.Key) ||
                    freq[entry.Key] < entry.Value) {
                    isValid = false;
                    break;
                }
            }
            if (isValid) {
                res.Add(i);
            }
        }
        return res.ToArray();
    }
}

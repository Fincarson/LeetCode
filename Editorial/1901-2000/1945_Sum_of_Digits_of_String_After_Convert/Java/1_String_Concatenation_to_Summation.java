class Solution {

    public int getLucky(String s, int k) {
        // Convert each character to its numerical value and build a string
        String numericString = "";
        for (char ch : s.toCharArray()) {
            numericString += Integer.toString(ch - 'a' + 1);
        }

        // Apply digit sum transformations k times
        while (k-- > 0) {
            int digitSum = 0;
            for (char digit : numericString.toCharArray()) {
                digitSum += digit - '0';
            }
            // If the digit sum is less than 10, we can break early
            if (digitSum < 10) {
                return digitSum;
            }
            numericString = Integer.toString(digitSum);
        }

        // Convert the final string to integer and return
        return Integer.parseInt(numericString);
    }
}

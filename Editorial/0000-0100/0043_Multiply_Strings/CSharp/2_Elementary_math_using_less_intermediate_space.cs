class Solution {
    // Function to add two strings.
    private List<int> AddStrings(List<int> num1, List<int> num2) {
        List<int> ans = new List<int>();
        int carry = 0;

        for (int i = 0; i < num1.Count || i < num2.Count || carry != 0; ++i) {
            // If num2 is shorter than num1 or vice versa, use 0 as the current
            // digit.
            int digit1 = i < num1.Count ? num1[i] : 0;
            int digit2 = i < num2.Count ? num2[i] : 0;

            // Add current digits of both numbers.
            int sum = digit1 + digit2 + carry;
            // Set carry equal to the tens place digit of sum.
            carry = sum / 10;
            // Append the ones place digit of sum to answer.
            ans.Add(sum % 10);
        }

        if (carry != 0) {
            ans.Add(carry);
        }

        return ans;
    }

    // Multiply the current digit of secondNumber with firstNumber.
    private List<int> MultiplyOneDigit(StringBuilder firstNumber,
                                       char secondNumberDigit, int numZeros) {
        // Insert zeros at the beginning based on the current digit's place.
        List<int> currentResult = new List<int>(new int[numZeros]);

        int carry = 0;

        // Multiply firstNumber with the current digit of secondNumber.
        for (int i = 0; i < firstNumber.Length; ++i) {
            int multiplication =
                (secondNumberDigit - '0') * (firstNumber[i] - '0') + carry;
            // Set carry equal to the tens place digit of multiplication.
            carry = multiplication / 10;
            // Append last digit to the current result.
            currentResult.Add(multiplication % 10);
        }

        if (carry != 0) {
            currentResult.Add(carry);
        }

        return currentResult;
    }

    public string Multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        // Reverse both the numbers.
        StringBuilder firstNumber =
            new StringBuilder(new string(num1.Reverse().ToArray()));
        StringBuilder secondNumber =
            new StringBuilder(new string(num2.Reverse().ToArray()));

        // To store the multiplication result of each digit of secondNumber with
        // firstNumber.
        int N = firstNumber.Length + secondNumber.Length;
        List<int> ans = new List<int>(new int[N]);

        // For each digit in secondNumber, multiply the digit by firstNumber and
        // add the multiplication result to ans.
        for (int i = 0; i < secondNumber.Length; ++i) {
            // Add the current result to final ans.
            ans = AddStrings(MultiplyOneDigit(firstNumber, secondNumber[i], i),
                             ans);
        }

        // Pop excess 0 from the rear of ans.
        if (ans[ans.Count - 1] == 0) {
            ans.RemoveAt(ans.Count - 1);
        }

        // Ans is in the reversed order.
        // Copy it in reverse order to get the final ans.
        StringBuilder answer = new StringBuilder();
        for (int i = ans.Count - 1; i >= 0; --i) {
            answer.Append(ans[i]);
        }

        return answer.ToString();
    }
}

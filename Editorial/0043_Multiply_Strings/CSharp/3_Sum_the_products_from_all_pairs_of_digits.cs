public class Solution {
    public string Multiply(string num1, string num2) {
        if (num1.Equals("0") || num2.Equals("0")) {
            return "0";
        }

        char[] firstNumber = num1.ToCharArray();
        char[] secondNumber = num2.ToCharArray();
        Array.Reverse(firstNumber);
        Array.Reverse(secondNumber);
        // To store the multiplication result of each digit of secondNumber with
        // firstNumber.
        int firstNumLength = firstNumber.Length;
        int secondNumLength = secondNumber.Length;
        int resultArrayLength = firstNumLength + secondNumLength;
        int[] resultArray = new int[resultArrayLength];
        for (int place2 = 0; place2 < secondNumLength; place2++) {
            int digit2 = secondNumber[place2] - '0';
            // For each digit in secondNumber multiply the digit by all digits
            // in firstNumber.
            for (int place1 = 0; place1 < firstNumLength; place1++) {
                int digit1 = firstNumber[place1] - '0';
                // The number of zeros from multiplying to digits depends on the
                // place of digit2 in secondNumber and the place of the digit1
                // in firstNumber.
                int numZeros = place1 + place2;
                int multiplication = digit1 * digit2 + resultArray[numZeros];
                // Set the ones place of the multiplication result.
                resultArray[numZeros] = multiplication % 10;
                // Carry the tens place of the multiplication result by
                // adding it to the next position in the answer array.
                resultArray[numZeros + 1] += multiplication / 10;
            }
        }

        // Pop excess 0s from the rear of answer.
        if (resultArray[resultArray.Length - 1] == 0) {
            resultArray = resultArray.Take(resultArray.Length - 1).ToArray();
        }

        // Ans is in the reversed order.
        // Reverse it to get the final ans.
        Array.Reverse(resultArray);
        return string.Join(
            string.Empty,
            resultArray.Select(digit => digit.ToString()).ToArray());
    }
}

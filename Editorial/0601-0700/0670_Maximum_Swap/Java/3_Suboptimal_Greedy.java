public class Solution {

    public int maximumSwap(int num) {
        String numStr = Integer.toString(num);
        int n = numStr.length();
        int[] lastSeen = new int[10]; // Store the last occurrence of each digit

        // Record the last occurrence of each digit
        for (int i = 0; i < n; ++i) {
            lastSeen[numStr.charAt(i) - '0'] = i;
        }

        // Traverse the string to find the first digit that can be swapped with a larger one
        for (int i = 0; i < n; ++i) {
            for (int d = 9; d > numStr.charAt(i) - '0'; --d) {
                if (lastSeen[d] > i) {
                    //Perform the swap
                    char[] arr = numStr.toCharArray();
                    char temp = arr[i];
                    arr[i] = arr[lastSeen[d]];
                    arr[lastSeen[d]] = temp;
                    numStr = new String(arr);

                    return Integer.parseInt(numStr); // Return the new number immediately after the swap
                }
            }
        }

        return num; // Return the original number if no swap can maximize it
    }
}

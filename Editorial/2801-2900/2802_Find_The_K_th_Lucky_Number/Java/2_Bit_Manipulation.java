public class Solution {

    public String kthLuckyNumber(int k) {
        // Increment k to account for 1-based indexing
        k = k + 1;

        // For each digit in the binary representation of k except the most significant
        // Prepend 4 to the result if the digit is 0 and 7 otherwise
        StringBuilder kthLuckyNumBuilder = new StringBuilder();
        while (k > 1) {
            kthLuckyNumBuilder.insert(0, ((k & 1) == 1 ? "7" : "4"));
            k >>= 1;
        }
        return kthLuckyNumBuilder.toString();
    }
}

public class Solution {

    public String kthLuckyNumber(int k) {
        // Increment k to account for 1-based indexing
        k = k + 1;

        // Convert k to a binary string (up to the most significant '1')
        String binaryString = Integer.toBinaryString(k).substring(1);

        char[] kthLuckyNum = binaryString.toCharArray();

        // Replace '0' with '4' and '1' with '7' in the binary string
        for (int i = 0; i < kthLuckyNum.length; i++) {
            kthLuckyNum[i] = (kthLuckyNum[i] == '1') ? '7' : '4';
        }

        return new String(kthLuckyNum);
    }
}

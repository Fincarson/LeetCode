class Solution {

    public boolean checkStrings(String s1, String s2) {
        int[] count = new int[256];

        for (int i = 0; i < s1.length(); i++) {
            int offset = (i & 1) << 7;
            count[offset + s1.charAt(i)]++;
            count[offset + s2.charAt(i)]--;
        }

        for (int i = 0; i < 256; i++) {
            if (count[i] != 0) {
                return false;
            }
        }

        return true;
    }
}

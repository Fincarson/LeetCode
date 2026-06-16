class Solution {
    public String firstPalindrome(String[] words) {
        for (String s : words) {
            String reversed = new StringBuilder(s).reverse().toString();

            if (s.equals(reversed)) {
                return s;
            }
        }
        return "";
    }
}

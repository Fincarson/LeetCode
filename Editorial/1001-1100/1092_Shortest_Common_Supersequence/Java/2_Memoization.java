class Solution {

    public String shortestCommonSupersequence(String str1, String str2) {
        Map<String, String> memo = new HashMap<>();
        return helper(str1, str2, memo);
    }

    private String helper(String str1, String str2, Map<String, String> memo) {
        String memoKey = str1 + " " + str2;

        // Check if result is already computed
        if (memo.containsKey(memoKey)) {
            return memo.get(memoKey);
        }

        // Base case: both strings are empty
        if (str1.isEmpty() && str2.isEmpty()) {
            return "";
        }

        // Base case: one string is empty, append the other string
        if (str1.isEmpty()) {
            return str2;
        }
        if (str2.isEmpty()) {
            return str1;
        }

        // If the first characters match, include it in the supersequence
        if (str1.charAt(0) == str2.charAt(0)) {
            String result =
                str1.charAt(0) +
                helper(str1.substring(1), str2.substring(1), memo);
            memo.put(memoKey, result);
            return result;
        }

        // Try both options: picking from str1 or str2, and choose the shorter one
        String pickStr1 =
            str1.charAt(0) + helper(str1.substring(1), str2, memo);
        String pickStr2 =
            str2.charAt(0) + helper(str1, str2.substring(1), memo);

        String result = (pickStr1.length() < pickStr2.length())
            ? pickStr1
            : pickStr2;
        memo.put(memoKey, result);
        return result;
    }
}

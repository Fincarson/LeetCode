class Solution {
    public int shortestWay(String source, String target) {

        // Boolean array to mark all characters of source
        boolean[] sourceChars = new boolean[26];
        for (char c : source.toCharArray()) {
            sourceChars[c - 'a'] = true;
        }

        // Check if all characters of target are present in source
        // If any character is not present, return -1
        for (char c : target.toCharArray()) {
            if (!sourceChars[c - 'a']) {
                return -1;
            }
        }

        // Optimal Answer for a given ending index. Memoizing using an Array
        int[] memo = new int[target.length()];
        Arrays.fill(memo, Integer.MAX_VALUE);
        memo[0] = 1;

        for (int endingIndex = 1; endingIndex < target.length(); endingIndex++) {
            if (isSubsequence(0, endingIndex, source, target)) {
                memo[endingIndex] = 1;
            } else {
                for (int partitionIndex = endingIndex - 1; partitionIndex >= 0; partitionIndex--) {
                    if (memo[partitionIndex] != Integer.MAX_VALUE &&
                            isSubsequence(partitionIndex + 1, endingIndex, source, target)) {
                        memo[endingIndex] = Math.min(memo[endingIndex], memo[partitionIndex] + 1);
                    }
                }
            }
        }

        return memo[target.length() - 1];
    }

    // For to_check, passing indices of target, both included.
    public boolean isSubsequence(int start, int end, String source, String target) {
        int i = start;
        int j = 0;

        while (i <= end && j < source.length()) {
            if (target.charAt(i) == source.charAt(j)) {
                i++;
            }
            j++;
        }

        return i == end + 1;
    }
}

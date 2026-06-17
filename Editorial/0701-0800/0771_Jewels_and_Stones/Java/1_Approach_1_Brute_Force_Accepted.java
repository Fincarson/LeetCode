class Solution {
    public int numJewelsInStones(String J, String S) {
        int ans = 0;
        for (char s: S.toCharArray()) // For each stone...
            for (char j: J.toCharArray()) // For each jewel...
                if (j == s) {  // If the stone is a jewel...
                    ans++;
                    break; // Stop searching whether this stone 's' is a jewel
                }
        return ans;
    }
}

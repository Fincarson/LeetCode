class Solution {
    char[] ca, cb;
    public int numMatchingSubseq(String S, String[] words) {
        int ans = 0;
        ca = S.toCharArray();
        for (String word: words)
            if (subseq(word)) ans++;
        return ans;
    }

    public boolean subseq(String word) {
        int i = 0;
        cb = word.toCharArray();
        for (char c: ca) {
            if (i < cb.length && c == cb[i]) i++;
        }
        return (i == cb.length);
    }
}

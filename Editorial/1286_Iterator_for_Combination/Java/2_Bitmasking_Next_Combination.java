class CombinationIterator {
    int bitmask, n, k;
    String chars;

    public CombinationIterator(String characters, int combinationLength) {
        n = characters.length();
        k = combinationLength;
        chars = characters;

        // generate first bitmask 1(k)0(n - k)
        bitmask = (1 << n) - (1 << n - k);
    }

    public String next() {
        // convert bitmask into combination
        // 111 --> "abc", 000 --> ""
        // 110 --> "ab", 101 --> "ac", 011 --> "bc"
        StringBuilder curr = new StringBuilder();
        for (int j = 0; j < n; j++) {
            if ((bitmask & (1 << n - j - 1)) != 0) {
                curr.append(chars.charAt(j));
            }
        }

        // generate next bitmask
        bitmask--;
        while (bitmask > 0 && Integer.bitCount(bitmask) != k) {
            bitmask--;
        }

        return curr.toString();
    }

    public boolean hasNext() {
        return bitmask > 0;
    }
}

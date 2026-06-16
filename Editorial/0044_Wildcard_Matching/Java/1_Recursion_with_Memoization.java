class Solution {
    Map<String, Boolean> dp = new HashMap<>();
    String s;
    String p;

    String remove_duplicate_stars(String p) {
        StringBuilder new_string = new StringBuilder();
        for (char c : p.toCharArray()) {
            if (new_string.length() == 0 || c != '*') new_string.append(c);
            else if (
                new_string.charAt(new_string.length() - 1) != '*'
            ) new_string.append(c);
        }
        return new_string.toString();
    }

    boolean helper(int si, int pi) {
        String key = si + "," + pi;
        if (dp.containsKey(key)) return dp.get(key);
        if (pi == p.length()) dp.put(key, si == s.length());
        else if (si == s.length()) dp.put(
            key,
            (pi + 1 == p.length() && p.charAt(pi) == '*')
        );
        else if (p.charAt(pi) == s.charAt(si) || p.charAt(pi) == '?') dp.put(
            key,
            helper(si + 1, pi + 1)
        );
        else if (p.charAt(pi) == '*') dp.put(
            key,
            helper(si, pi + 1) || helper(si + 1, pi)
        );
        else dp.put(key, false);
        return dp.get(key);
    }

    public boolean isMatch(String s, String p) {
        dp.clear();
        this.s = s;
        this.p = remove_duplicate_stars(p);
        return helper(0, 0);
    }
}

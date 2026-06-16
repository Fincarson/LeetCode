class Solution {

    public List<String> beforeAndAfterPuzzles(String[] phrases) {
        int n = phrases.length;
        String[][] sp = new String[n][2];
        for (int i = 0; i < n; i++) {
            String[] words = phrases[i].split(" ");
            sp[i][0] = words[0];
            sp[i][1] = words[words.length - 1];
        }

        Set<String> m = new HashSet<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (sp[i][0].equals(sp[j][1])) {
                    String combined =
                        phrases[j] + phrases[i].substring(sp[i][0].length());
                    m.add(combined);
                }
            }
        }

        List<String> ret = new ArrayList<>(m);
        Collections.sort(ret);
        return ret;
    }
}

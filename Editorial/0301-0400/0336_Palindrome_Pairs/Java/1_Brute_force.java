class Solution {
    public List<List<Integer>> palindromePairs(String[] words) {

        List<List<Integer>> pairs = new ArrayList<>();

        for (int i = 0; i < words.length; i++) {
            for (int j = 0; j < words.length; j++) {
                if (i == j) continue;
                String combined = words[i].concat(words[j]);
                String reversed = new StringBuilder(combined).reverse().toString();
                if (combined.equals(reversed)) {
                    pairs.add(Arrays.asList(i, j));
                }
            }   
        }

        return pairs;
    }
}

class Solution {
    public int maxLength(List<String> arr) {
        // Initialize results with an empty string
        // from which to build all future results
        List<String> results = new ArrayList<>();
        results.add("");
        int best = 0;
        for (String word : arr) {
            // We only want to iterate through results
            // that existed prior to this loop
            int resultsLen = results.size();
            for (int i = 0; i < resultsLen; i++) {
                // Form a new result combination and
                // use a set to check for duplicate characters
                String newRes = results.get(i) + word;
                Set<Character> newResSet = new HashSet<>();
                for (char c : newRes.toCharArray())
                    newResSet.add(c);
                if (newRes.length() != newResSet.size())
                    continue;

                // Add valid options to results and
                // keep track of the longest so far
                results.add(newRes);
                best = Math.max(best, newRes.length());
            }
        }
        return best;
    }
}

class Solution {
    public int maxLength(List<String> arr) {    
        // Use depth first search recursion through arr
        // with backracking and a map for results
        return backtracking(arr, 0, new HashMap<Character, Integer>());
    }
    
    private int backtracking(List<String> arr, int pos, Map<Character, Integer> resMap) {    
        // Check for duplicate characters
        for (Integer val : resMap.values())
            if (val > 1)
                return 0;

        // Recurse through each possible next option
        // and find the best answer
        int best = resMap.size();
        for (int i = pos; i < arr.size(); i++) {
            // Add the current word to the result map
            // and recurse to the next position
            char[] wordArr = arr.get(i).toCharArray();
            for (char c : wordArr)
                resMap.put(c, resMap.getOrDefault(c, 0) + 1);
            best = Math.max(best, backtracking(arr, i + 1, resMap));

            // Backtrack the result map before continuing
            for (char c : wordArr) {
                if (resMap.get(c) == 1) {
                    resMap.remove(c);
                } else {
                    resMap.put(c, resMap.get(c) - 1);
                }
            }
        }
        return best;
    }
}

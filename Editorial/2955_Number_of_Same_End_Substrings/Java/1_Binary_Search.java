class Solution {

    public int[] sameEndSubstringCount(String s, int[][] queries) {
        // Map to store each character and its positions in the string 's'
        Map<Character, List<Integer>> charPositionsMap = new HashMap<>();

        // Traverse the string and store the index of each character in the map
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            charPositionsMap.putIfAbsent(c, new ArrayList<>());
            charPositionsMap.get(c).add(i);
        }

        int numQueries = queries.length;
        int[] result = new int[numQueries]; // Array to store the result for each query

        // Process each query
        for (int i = 0; i < numQueries; i++) {
            int leftIndex = queries[i][0];
            int rightIndex = queries[i][1];
            int countSameEndSubstrings = 0;

            // For each unique character in the string, calculate the number of same-end substrings
            for (char c : charPositionsMap.keySet()) {
                List<Integer> positions = charPositionsMap.get(c);

                // Get the number of occurrences of the character within the range [leftIndex, rightIndex]
                int leftBound = findFirstGE(positions, leftIndex);
                int rightBound = findFirstGT(positions, rightIndex);
                int numOccurrences = rightBound - leftBound;

                // Calculate the number of same-end substrings for this character
                countSameEndSubstrings +=
                    (numOccurrences * (numOccurrences + 1)) / 2;
            }

            // Store the result for this query
            result[i] = countSameEndSubstrings;
        }

        return result;
    }

    // Custom binary search to find the first index in 'arr' where element >= 'target'
    private int findFirstGE(List<Integer> arr, int target) {
        int left = 0;
        int right = arr.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr.get(mid) < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

    // Custom binary search to find the first index in 'arr' where element > 'target'
    private int findFirstGT(List<Integer> arr, int target) {
        int left = 0;
        int right = arr.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr.get(mid) <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
}

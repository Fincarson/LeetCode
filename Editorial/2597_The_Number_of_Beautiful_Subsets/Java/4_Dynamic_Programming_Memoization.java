class Solution {

    public int beautifulSubsets(int[] nums, int k) {
        int totalCount = 1;
        Map<Integer, Map<Integer, Integer>> freqMap = new TreeMap<>();

        // Calculate frequencies based on remainder
        for (int num : nums) {
            int remainder = num % k;
            Map<Integer, Integer> fr = freqMap.getOrDefault(
                remainder,
                new TreeMap<>()
            );
            fr.put(num, fr.getOrDefault(num, 0) + 1);
            freqMap.put(remainder, fr);
        }

        // Calculate subsets for each remainder group
        for (Map.Entry<
            Integer,
            Map<Integer, Integer>
        > entry : freqMap.entrySet()) {
            List<Pair<Integer, Integer>> subsets = new ArrayList<>();
            for (Map.Entry<Integer, Integer> subset : entry
                .getValue()
                .entrySet()) {
                subsets.add(new Pair<>(subset.getKey(), subset.getValue()));
            }
            int[] counts = new int[subsets.size()]; // Store counts of subsets for memoization
            Arrays.fill(counts, -1);
            totalCount *=
            countBeautifulSubsets(subsets, subsets.size(), k, 0, counts);
        }
        return totalCount - 1;
    }

    private int countBeautifulSubsets(
        List<Pair<Integer, Integer>> subsets,
        int numSubsets,
        int difference,
        int i,
        int[] counts
    ) {
        // Base case: Return 1 for a subset of size 1
        if (i == numSubsets) {
            return 1;
        }

        // If the count is already calculated, return it
        if (counts[i] != -1) {
            return counts[i];
        }

        // Calculate subsets where the current subset is not taken
        int skip = countBeautifulSubsets(
            subsets,
            numSubsets,
            difference,
            i + 1,
            counts
        );

        // Calculate subsets where the current subset is taken
        int take = (1 << subsets.get(i).getValue()) - 1; // take the current subset

        // If the next number has a difference of 'difference',
        // calculate subsets accordingly
        if (
            i + 1 < numSubsets &&
            subsets.get(i + 1).getKey() - subsets.get(i).getKey() == difference
        ) {
            take *=
            countBeautifulSubsets(
                subsets,
                numSubsets,
                difference,
                i + 2,
                counts
            );
        } else {
            take *=
            countBeautifulSubsets(
                subsets,
                numSubsets,
                difference,
                i + 1,
                counts
            );
        }

        return counts[i] = skip + take; // Store and return total count of subsets
    }
}

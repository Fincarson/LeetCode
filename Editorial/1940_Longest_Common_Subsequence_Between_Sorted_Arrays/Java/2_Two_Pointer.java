class Solution {

    public List<Integer> longestCommonSubsequence(int[][] arrays) {
        List<Integer> longestCommonSubseq = new ArrayList<>();
        for (int num : arrays[0]) {
            longestCommonSubseq.add(num);
        }

        // Iterate through the rest of the arrays and
        // If the common subsequence is empty, return immediately
        // Else update the longest common subsequence
        for (int i = 1; i < arrays.length; i++) {
            if (longestCommonSubseq.isEmpty()) {
                return longestCommonSubseq;
            }
            longestCommonSubseq = longestSeq(longestCommonSubseq, arrays[i]);
        }

        return longestCommonSubseq;
    }

    private List<Integer> longestSeq(List<Integer> nums1, int[] nums2) {
        List<Integer> longestCommonSeq = new ArrayList<>();
        int first = 0;
        int second = 0;

        // Traverse through both arrays with two pointers
        // Increment the pointer with a smaller value at that index
        // When the values are equal, add to the longest common subsequence
        while (first < nums1.size() && second < nums2.length) {
            if (nums1.get(first) < nums2[second]) {
                first++;
            } else if (nums1.get(first) > nums2[second]) {
                second++;
            } else {
                longestCommonSeq.add(nums1.get(first));
                first++;
                second++;
            }
        }
        return longestCommonSeq;
    }
}

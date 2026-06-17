class Solution {

    public String[] sortPeople(String[] names, int[] heights) {
        int numberOfPeople = names.length;

        // Create an array of indices
        Integer[] sortedIndices = new Integer[numberOfPeople];
        for (int i = 0; i < numberOfPeople; i++) {
            sortedIndices[i] = i;
        }

        // Sort indices based on heights in descending order
        Arrays.sort(sortedIndices, (a, b) -> heights[b] - heights[a]);

        // Apply the sorted indices to rearrange names
        String[] sortedNames = new String[numberOfPeople];
        for (int i = 0; i < numberOfPeople; i++) {
            sortedNames[i] = names[sortedIndices[i]];
        }

        return sortedNames;
    }
}

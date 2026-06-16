class Solution {

    public String[] sortPeople(String[] names, int[] heights) {
        int numberOfPeople = names.length;

        // Create a map to store height-name pairs
        Map<Integer, String> heightToNameMap = new HashMap<>();

        // Populate the map with height as key and name as value
        for (int i = 0; i < numberOfPeople; i++) {
            heightToNameMap.put(heights[i], names[i]);
        }

        Arrays.sort(heights);

        String[] sortedNames = new String[numberOfPeople];

        // Populate sortedNames array in descending order of height
        for (int i = numberOfPeople - 1; i >= 0; i--) {
            sortedNames[numberOfPeople - i - 1] = heightToNameMap.get(
                heights[i]
            );
        }

        return sortedNames;
    }
}

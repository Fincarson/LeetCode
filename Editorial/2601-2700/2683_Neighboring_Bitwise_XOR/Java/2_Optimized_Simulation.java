class Solution {

    public boolean doesValidArrayExist(int[] derived) {
        // Initialize the original array with 0 as the first element.
        List<Integer> original = new ArrayList<>();
        original.add(0);

        // Generate the original array based on derived and original[0] = 0.
        for (int i = 0; i < derived.length; i++) {
            original.add(derived[i] ^ original.get(i));
        }

        // Check if the array is valid by comparing the first and last elements.
        return original.get(0).equals(original.get(original.size() - 1));
    }
}

public int findLucky(int[] arr) {
    Arrays.sort(arr);
    int currentStreak = 0;
    // In Java, it's best to just go backwards, as we can't
    // trivially reverse-sort an Array of primitives. 
    // We could also have used the Stream API to box the ints and then
    // sort using a library comparator.
    for (int i = arr.length - 1; i >= 0; i--) {
        currentStreak++;
        // If this is the last element in the current streak (as the next is
        // different, or we're at the start of the array).
        if (i == 0 || arr[i] != arr[i - 1]) {
            // If this is a lucky number
            if (currentStreak == arr[i]) {
                return currentStreak;
            }
            currentStreak = 0;
        }
    }
    return -1;
}

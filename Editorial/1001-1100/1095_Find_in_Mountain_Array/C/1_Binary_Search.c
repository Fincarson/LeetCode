int findInMountainArray(int target, MountainArray *mountainArr) {
    // Save the length of the mountain array
    int size = length(mountainArr);

    // 1. Find the index of the peak element
    int low = 1;
    int high = size - 2;
    while (low != high) {
        int testIndex = (low + high) / 2;
        if (get(mountainArr, testIndex) < get(mountainArr, testIndex + 1)) {
            low = testIndex + 1;
        } else {
            high = testIndex;
        }
    }

    int peakIndex = low;

    // 2. Search in the strictly increasing part of the array
    low = 0;
    high = peakIndex;
    while (low != high) {
        int testIndex = (low + high) / 2;
        if (get(mountainArr, testIndex) < target) {
            low = testIndex + 1;
        } else {
            high = testIndex;
        }
    } 
    // Check if the target is present in the strictly increasing part
    if (get(mountainArr, low) == target) {
        return low;
    }

    // 3. Otherwise, search in the strictly decreasing part
    low = peakIndex + 1;
    high = size - 1;
    while (low != high) {
        int testIndex = (low + high) / 2;
        if (get(mountainArr, testIndex) > target) {
            low = testIndex + 1;
        } else {
            high = testIndex;
        }
    }
    // Check if the target is present in the strictly decreasing part
    if (get(mountainArr, low) == target) {
        return low;
    }

    // Target is not present in the mountain array
    return -1;
}

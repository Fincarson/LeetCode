var findInMountainArray = function(target, mountainArr) {
    // Save the length of the mountain array
    const length = mountainArr.length();

    // 1. Find the index of the peak element
    let low = 1;
    let high = length - 2;
    while (low !== high) {
        const testIndex = (low + high) / 2;
        if (mountainArr.get(testIndex) < mountainArr.get(testIndex + 1)) {
            low = testIndex + 1;
        } else {
            high = testIndex;
        }
    }
    const peakIndex = low;

    // 2. Search in the strictly increasing part of the array
    low = 0;
    high = peakIndex;
    while (low !== high) {
        const testIndex = (low + high) / 2;
        if (mountainArr.get(testIndex) < target) {
            low = testIndex + 1;
        } else {
            high = testIndex;
        }
    }
    // Check if the target is present in the strictly increasing part
    if (mountainArr.get(low) === target) {
        return low;
    }

    // 3. Otherwise, search in the strictly decreasing part
    low = peakIndex + 1;
    high = length - 1;
    while (low !== high) {
        const testIndex = (low + high) / 2;
        if (mountainArr.get(testIndex) > target) {
            low = testIndex + 1;
        } else {
            high = testIndex;
        }
    }
    // Check if the target is present in the strictly decreasing part
    if (mountainArr.get(low) === target) {
        return low;
    }

    // Target is not present in the mountain array
    return -1;
}

/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function (haystack, needle) {
    let m = needle.length;
    let n = haystack.length;

    if (n < m) return -1;

    // PREPROCESSING
    // longest_border array
    let longest_border = new Array(m);
    longest_border[0] = 0;
    // Length of Longest Border for prefix before it.
    let prev = 0;
    // Iterating from index-1. longest_border[0] will always be 0
    let i = 1;

    while (i < m) {
        if (needle[i] == needle[prev]) {
            // Length of Longest Border Increased
            prev += 1;
            longest_border[i] = prev;
            i += 1;
        } else {
            // Only empty border exist
            if (prev == 0) {
                longest_border[i] = 0;
                i += 1;
            }
            // Try finding longest border for this i with reduced prev
            else {
                prev = longest_border[prev - 1];
            }
        }
    }

    // SEARCHING
    // Pointer for haystack
    let haystackPointer = 0;
    // Pointer for needle.
    // Also indicates number of characters matched in current window.
    let needlePointer = 0;

    while (haystackPointer < n) {
        if (haystack[haystackPointer] == needle[needlePointer]) {
            // Matched Increment Both
            needlePointer += 1;
            haystackPointer += 1;
            // All characters matched
            if (needlePointer == m) {
                // m characters behind last matching will be start of window
                return haystackPointer - m;
            }
        } else {
            if (needlePointer == 0) {
                // Zero Matched
                haystackPointer += 1;
            } else {
                // Optimally shift left needlePointer. Don't change haystackPointer
                needlePointer = longest_border[needlePointer - 1];
            }
        }
    }

    return -1;
};

//JavaScript
var merge = function (nums1, m, nums2, n) {
    // Write the elements of num2 into the end of nums1.
    for (let i = 0; i < n; i++) {
        nums1[i + m] = nums2[i];
    }
    // Sort nums1 array in-place.
    nums1.sort((a, b) => a - b);
};

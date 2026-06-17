function merge(nums1: number[], m: number, nums2: number[], n: number): void {
    // Make a copy of the first m elements of nums1.
    let nums1Copy: number[] = nums1.splice(0, m);
    // Read pointers for nums1Copy and nums2 respectively.
    let p1: number = 0;
    let p2: number = 0;
    // Compare elements from nums1Copy and nums2 and write the smallest to nums1.
    for (let p = 0; p < m + n; p++) {
        // We also need to ensure that p1 and p2 aren't over the boundaries
        // of their respective arrays.
        if (p2 >= n || (p1 < m && nums1Copy[p1] < nums2[p2])) {
            nums1[p] = nums1Copy[p1++];
        } else {
            nums1[p] = nums2[p2++];
        }
    }
}

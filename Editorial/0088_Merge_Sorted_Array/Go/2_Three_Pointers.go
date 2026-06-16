func merge(nums1 []int, m int, nums2 []int, n int) {
    // Make a copy of the first m elements of nums1.
    nums1Copy := append([]int(nil), nums1[:m]...)
    // Read pointers for nums1Copy and nums2 respectively.
    p1 := 0
    p2 := 0
    // Compare elements from nums1Copy and nums2 and write the smallest to nums1.
    for p := 0; p < m+n; p++ {
        // We also need to ensure that p1 and p2 aren't over the boundaries
        // of their respective arrays.
        if p2 >= n || (p1 < m && nums1Copy[p1] < nums2[p2]) {
            nums1[p] = nums1Copy[p1]
            p1++
        } else {
            nums1[p] = nums2[p2]
            p2++
        }
    }
}

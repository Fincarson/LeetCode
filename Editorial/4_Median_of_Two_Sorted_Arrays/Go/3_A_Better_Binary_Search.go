func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
    if len(nums1) > len(nums2) {
        temp := nums1
        nums1 = nums2
        nums2 = temp
    }

    m, n := len(nums1), len(nums2)
    left, right := 0, m

    for left <= right {
        partitionA := (left + right) / 2
        partitionB := (m+n+1)/2 - partitionA

        maxLeftA := math.MinInt64
        if partitionA != 0 {
            maxLeftA = nums1[partitionA-1]
        }
        minRightA := math.MaxInt64
        if partitionA != m {
            minRightA = nums1[partitionA]
        }

        maxLeftB := math.MinInt64
        if partitionB != 0 {
            maxLeftB = nums2[partitionB-1]
        }
        minRightB := math.MaxInt64
        if partitionB != n {
            minRightB = nums2[partitionB]
        }

        if maxLeftA <= minRightB && maxLeftB <= minRightA {
            if (m+n)%2 == 0 {
                maxLeft := math.Max(float64(maxLeftA), float64(maxLeftB))
                minRight := math.Min(float64(minRightA), float64(minRightB))
                return (maxLeft + minRight) / 2.0
            } else {
                return math.Max(float64(maxLeftA), float64(maxLeftB))
            }
        } else if maxLeftA > minRightB {
            right = partitionA - 1
        } else {
            left = partitionA + 1
        }
    }
    return 0.0
}

func solve(
    A []int,
    aStart int,
    aEnd int,
    B []int,
    bStart int,
    bEnd int,
    k int,
) int {
    // If the segment of on array is empty, it means we have passed all
    // its element, just return the corresponding element in the other array.
    if aEnd < aStart {
        return B[k-aStart]
    }
    if bEnd < bStart {
        return A[k-bStart]
    }

    // Get the middle indexes and middle values of A and B.
    aIndex, bIndex := (aStart+aEnd)/2, (bStart+bEnd)/2
    aValue, bValue := A[aIndex], B[bIndex]

    // If k is in the right half of A + B, remove the smaller left half.
    if aIndex+bIndex < k {
        if aValue > bValue {
            return solve(A, aStart, aEnd, B, bIndex+1, bEnd, k)
        }
        return solve(A, aIndex+1, aEnd, B, bStart, bEnd, k)
    }

    // Otherwise, remove the larger right half.
    if aValue > bValue {
        return solve(A, aStart, aIndex-1, B, bStart, bEnd, k)
    }
    return solve(A, aStart, aEnd, B, bStart, bIndex-1, k)
}

func findMedianSortedArrays(A []int, B []int) float64 {
    na, nb := len(A), len(B)
    n := na + nb
    if n%2 == 1 {
        return float64(solve(A, 0, na-1, B, 0, nb-1, n/2))
    }
    return (float64(solve(A, 0, na-1, B, 0, nb-1, n/2)) + float64(solve(A, 0, na-1, B, 0, nb-1, n/2-1))) / 2
}

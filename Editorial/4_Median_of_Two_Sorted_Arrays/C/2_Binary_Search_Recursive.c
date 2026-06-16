int solve(int* A, int aStart, int aEnd, int* B, int bStart, int bEnd, int k) {
    // If the segment of on array is empty, it means we have passed all
    // its element, just return the corresponding element in the other array.
    if (aEnd < aStart) {
        return B[k - aStart];
    }
    if (bEnd < bStart) {
        return A[k - bStart];
    }

    // Get the middle indexes and middle values of A and B.
    int aIndex = (aStart + aEnd) / 2, bIndex = (bStart + bEnd) / 2;
    int aValue = A[aIndex], bValue = B[bIndex];

    // If k is in the right half of A + B, remove the smaller left half.
    if (aIndex + bIndex < k) {
        if (aValue > bValue) {
            return solve(A, aStart, aEnd, B, bIndex + 1, bEnd, k);
        } else {
            return solve(A, aIndex + 1, aEnd, B, bStart, bEnd, k);
        }
    }
    // Otherwise, remove the larger right half.
    else {
        if (aValue > bValue) {
            return solve(A, aStart, aIndex - 1, B, bStart, bEnd, k);
        } else {
            return solve(A, aStart, aEnd, B, bStart, bIndex - 1, k);
        }
    }
}

double findMedianSortedArrays(int* A, int na, int* B, int nb) {
    int n = na + nb;
    if (n % 2 == 1) {
        return solve(A, 0, na - 1, B, 0, nb - 1, n / 2);
    } else {
        return (solve(A, 0, na - 1, B, 0, nb - 1, n / 2) +
                solve(A, 0, na - 1, B, 0, nb - 1, n / 2 - 1)) /
               2.0;
    }
}
